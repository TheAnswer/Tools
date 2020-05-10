import pathlib

from functools import partial
from lupa import LuaRuntime
from PIL import Image, ImageTk
from tkinter import Canvas, IntVar, PhotoImage, StringVar, Tk, BOTTOM, DISABLED, E, HORIZONTAL, N, NORMAL, NW, RIGHT, S, VERTICAL, W, X, Y
from tkinter.ttk import Checkbutton, Combobox, Entry, Frame, Label, LabelFrame, Radiobutton, Scrollbar

ALL_PLANETS = ["Corellia", "Dantooine", "Dathomir", "Endor", "Lok", "Naboo", "Rori", "Tatooine", "Yavin4"]
MAP_PATH = "../WorldSpawnerTool/release/ui_map_"
SPAWN_AREA = 0x1
SPAWN_AREA_STR = "Spawn area"
NO_SPAWN_AREA = 0x2
NO_SPAWN_AREA_STR = "No spawn area"
WORLD_SPAWN_AREA = 0x10
WORLD_SPAWN_AREA_STR = "World spawn area"
NO_WORLD_SPAWN_AREA = 0x20
NO_WORLD_SPAWN_AREA_STR = "No world spawn area"
NO_BUILD_AREA = 0x100
NO_BUILD_AREA_STR = "No build zone area"
UNDEFINED_AREA = 0


class TwoCells:
    ANYTHING = 0
    INTEGERS = 1
    NON_NEGATIVE_INTEGERS = 2

    def __init__(self, parent, validation_type=ANYTHING, **kwargs):
        self.validation_type = validation_type
        self.frame = Frame(parent)
        self.frame.grid(columnspan=2, sticky=N, **kwargs)
        self.validate_command = (self.frame.register(self._on_validate), "%P")

    def _on_validate(self, new_value):
        try:
            if self.validation_type == self.INTEGERS:
                if new_value not in ["", "-"]:
                    int(new_value)
            elif self.validation_type == self.NON_NEGATIVE_INTEGERS:
                if new_value != "":
                    value = int(new_value)
                    if value < 0:
                        return False
            return True
        except Exception:
            return False


class Attribute(TwoCells):
    def __init__(self, parent, text, value, **kwargs):
        super().__init__(parent, **kwargs)
        self.label_text = StringVar()
        self.label_text.set(text)
        self.label = Label(self.frame, textvariable=self.label_text)
        self.label.grid(column=0, row=0, padx=5, pady=5, sticky=W)
        self.current_value = StringVar(self.frame)
        self.current_value.set(value)
        self.value = Entry(self.frame, textvariable=self.current_value, validate="key", validatecommand=self.validate_command)
        self.value.grid(column=1, row=0, padx=5, pady=5, sticky=E)

    def hide(self):
        self.label.grid_remove()
        self.value.grid_remove()
        return self

    def show(self, text):
        self.label_text.set(text)
        self.label.grid()
        self.value.grid()
        return self

    def disable(self):
        self.value.configure(state=DISABLED)
        return self

    def enable(self):
        self.value.configure(state=NORMAL)
        return self

    def set(self, value):
        self.current_value.set(value)
        if str(value) == "":
            self.disable()
        else:
            self.enable()


class Option(TwoCells):
    def __init__(self, parent, values, callback, **kwargs):
        super().__init__(parent, **kwargs)
        self.callback = callback
        self.selected_option = StringVar(self.frame)
        self.selected_option.set(values[0])
        self.options = []
        column = 0
        row = 0
        for value in values:
            option = Radiobutton(self.frame, text=value, value=value, variable=self.selected_option, command=self._option_changed)
            option.grid(column=column, row=row, padx=5, pady=5)
            self.options.append(option)
            column += 1
            if column > 5:
                column = 0
                row += 1

    def _option_changed(self):
        self.callback(self.selected_option.get())

    def set(self, value):
        self.selected_option.set(value)


class Select(TwoCells):
    def __init__(self, parent, values, callback, **kwargs):
        super().__init__(parent, **kwargs)
        self.callback = callback
        self.options = []
        self.values = {}

        column = 0
        row = 0
        for value in values:
            option_selected = IntVar(self.frame)
            option = Checkbutton(self.frame, text=value, variable=option_selected, command=partial(self._option_changed, value))
            option.grid(column=column, row=row, padx=5, pady=5)
            self.options.append((value, option_selected))
            self.values[value] = option_selected
            column += 1
            if column > 1:
                column = 0
                row += 1

    def _option_changed(self, option_name):
        self.callback(self.options, option_name)

    def set_option_value(self, option_name, value):
        self.values[option_name].set(1 if value else 0)


class Selection(TwoCells):
    def __init__(self, parent, text, values, callback, **kwargs):
        super().__init__(parent, **kwargs)
        self.callback = callback
        self.label = Label(self.frame, text=text)
        self.label.grid(column=0, row=0, padx=5, pady=5, sticky=W)
        self.combobox = Combobox(self.frame)
        self.combobox["values"]= values
        self.combobox.current(0)
        self.combobox.grid(column=1, row=0, padx=5, pady=5, sticky=E)
        self.combobox.bind("<<ComboboxSelected>>", self._selection_changed)
        self._selection_changed(values[0])

    def _selection_changed(self, value):
        self.callback(self.combobox.get())

    def update_values(self, values):
        self.combobox["values"] = values
        self.combobox.current(0)
        self._selection_changed(values[0])

    def select(self, name):
        for index, value_text in enumerate(self.combobox["values"]):
            if value_text == name:
                self.combobox.current(index)
                self._selection_changed(value_text)


class WorldSpawnerWindow:
    def __init__(self):
        self.window = Tk()

        self.window.title("SWGEmu World Spawner Tool")
        self.window.columnconfigure(0, weight=1)
        self.window.rowconfigure(0, weight=1)

        self.planet_frame = Frame(self.window)
        self.planet_frame.grid(column=0, row=0, padx=5, pady=5, sticky=E + N + S + W)
        self.planet_frame.columnconfigure(0, weight=1)
        self.planet_frame.rowconfigure(0, weight=1)

        self.planet = Canvas(self.planet_frame, scrollregion=(0, 0, 1024, 1024))
        self.planet.grid(column=0, row=0, sticky=E + N + S + W)
        self.hbar = Scrollbar(self.planet_frame, orient=HORIZONTAL)
        self.hbar.grid(column=0, row=1, sticky=E + W)
        self.hbar.config(command=self.planet.xview)
        self.vbar = Scrollbar(self.planet_frame, orient=VERTICAL)
        self.vbar.grid(column=1, row=0, sticky=N + S)
        self.vbar.config(command=self.planet.yview)
        self.planet.config(xscrollcommand=self.hbar.set, yscrollcommand=self.vbar.set)
        self.planet.bind("<Motion>", self._on_planet_mouse_over)
        self.planet.bind("<ButtonPress-1>", self._on_planet_select)

        self.options_frame = Frame(self.window)
        self.options_frame.grid(column=1, row=0, sticky=N + S)
        self.options_frame.columnconfigure(0, weight=1)
        self.options_frame.rowconfigure(0, weight=1)

        self.selected_region = None
        self.selected_planet = Selection(self.options_frame, "Selected planet:", values=ALL_PLANETS, callback=self._on_planet_change)

        self.region_frame = LabelFrame(self.options_frame, text="Region")
        self.region_frame.grid(columnspan=2, padx=5, pady=5, sticky=N + S)

        self.selected_region = Selection(self.region_frame, "Selected region:", values=["-"], callback=self._on_region_change)

        self.x_value = Attribute(self.region_frame, text="X:", value="1234", validation_type=TwoCells.INTEGERS)
        self.y_value = Attribute(self.region_frame, text="Y:", value="2345", validation_type=TwoCells.INTEGERS)

        self.region_shape = Option(self.region_frame, values=["Circle", "Rectangle", "Ring"], callback=self._on_shape_change)

        self.dimension_frame = Frame(self.region_frame)
        self.dimension_frame.grid(columnspan=2)
        self.value_1 = Attribute(self.dimension_frame, text="Radius:", value="345", row=0, validation_type=TwoCells.INTEGERS)
        self.value_2 = Attribute(self.dimension_frame, text="Width:", value="456", row=1, validation_type=TwoCells.INTEGERS).hide()

        self.region_types = Select(self.region_frame, values=[WORLD_SPAWN_AREA_STR, NO_WORLD_SPAWN_AREA_STR, SPAWN_AREA_STR, NO_SPAWN_AREA_STR, NO_BUILD_AREA_STR],
                                   callback=self._on_type_change)

        self.spawn_groups = Attribute(self.region_frame, text="Spawn group:", value="Unknown").disable()
        self.maximum_no_spawns = Attribute(self.region_frame, text="Maximum number of spaws:", value="1024", validation_type=TwoCells.NON_NEGATIVE_INTEGERS).disable()

        self.planet_info = StringVar()
        self.planet_info.set("")
        self.planet_info_label = Label(self.options_frame, textvariable=self.planet_info)
        self.planet_info_label.grid(columnspan=2, padx=5, pady=5, sticky=S + W)

        self._on_planet_change(ALL_PLANETS[0])
        self._on_shape_change("Circle")

        self.window.mainloop()

    def _on_planet_mouse_over(self, event):
        world_x = event.x * 16 - 8192
        world_y = 8192 - event.y * 16
        element_id = event.widget.find_withtag("current")
        tags = [tag for tag in event.widget.gettags(element_id) if tag != "current"]
        name = tags[0] if tags else ""
        self.planet_info.set("X: {x}, Y: {y} - {name}".format(x=world_x, y=world_y, name=name))

    def _on_planet_select(self, event):
        element_id = event.widget.find_withtag("current")
        tags = [tag for tag in event.widget.gettags(element_id) if tag != "current"]
        if tags:
            self.selected_region.select(tags[0])

    def _on_shape_change(self, new_shape):
        if new_shape == "Circle":
            self.value_1.show(text="Radius:")
            self.value_2.hide()
        elif new_shape == "Rectangle":
            self.value_1.show(text="Width:")
            self.value_2.show(text="Height:")
        elif new_shape == "Ring":
            self.value_1.show(text="Outer radius:")
            self.value_2.show(text="Inner radius:")

    def _on_type_change(self, area_types, changed_type):
        new_value = [value for area_type, value in area_types if area_type == changed_type][0].get()
        if new_value == 1:
            if changed_type == WORLD_SPAWN_AREA_STR:
                self.region_types.set_option_value(SPAWN_AREA_STR, 1)
                self.region_types.set_option_value(NO_WORLD_SPAWN_AREA_STR, 0)
                self.region_types.set_option_value(NO_SPAWN_AREA_STR, 0)
            if changed_type == NO_WORLD_SPAWN_AREA_STR:
                self.region_types.set_option_value(WORLD_SPAWN_AREA_STR, 0)
            if changed_type == SPAWN_AREA_STR:
                self.region_types.set_option_value(NO_SPAWN_AREA_STR, 0)
            if changed_type == NO_SPAWN_AREA_STR:
                self.region_types.set_option_value(SPAWN_AREA_STR, 0)
                self.region_types.set_option_value(WORLD_SPAWN_AREA_STR, 0)
        else:
            if changed_type == SPAWN_AREA_STR:
                self.region_types.set_option_value(WORLD_SPAWN_AREA_STR, 0)

        self.spawn_groups.disable()
        self.maximum_no_spawns.disable()
        for area_type, value in area_types:
            if (area_type == SPAWN_AREA_STR or area_type == WORLD_SPAWN_AREA_STR) and value.get() == 1:
                self.spawn_groups.enable()
                self.maximum_no_spawns.enable()

    def _on_planet_change(self, new_planet):
        image = Image.open(MAP_PATH + new_planet.lower() + ".jpg")
        self.photo = ImageTk.PhotoImage(image)
        self._load_planet_regions(new_planet)
        if self.selected_region:
            self.selected_region.update_values(self.planet_regions.get_region_names())
        self._refresh()

    def _refresh(self):
        self.planet.delete("all")
        self.planet.create_image(0,0, image=self.photo, anchor=NW)
        self.planet_regions.draw(self.planet, self.selected_region.combobox.get() if self.selected_region else "")

    def _on_region_change(self, new_region):
        if new_region in self.planet_regions.regions:
            region = self.planet_regions.regions[new_region]
            self.x_value.set(str(region.x))
            self.y_value.set(str(region.y))
            if region.shape[0] == 1:
                self.region_shape.set("Circle")
                self.value_1.set(str(region.shape[1]))
                self.value_1.validation_type = TwoCells.INTEGERS
            elif region.shape[0] == 2:
                self.region_shape.set("Rectangle")
                self.value_1.set(str(region.shape[1]))
                self.value_1.validation_type = TwoCells.NON_NEGATIVE_INTEGERS
                self.value_2.set(str(region.shape[2]))
                self.value_2.validation_type = TwoCells.NON_NEGATIVE_INTEGERS
            elif region.shape[0] == 3:
                self.region_shape.set("Ring")
                self.value_1.set(str(region.shape[1]))
                self.value_1.validation_type = TwoCells.INTEGERS
                self.value_2.set(str(region.shape[2]))
                self.value_2.validation_type = TwoCells.INTEGERS
            else:
                print("Incorrect region shape: " + str(region.shape[0]))
            self.region_types.set_option_value(SPAWN_AREA_STR, region.type & SPAWN_AREA)
            self.region_types.set_option_value(NO_SPAWN_AREA_STR, region.type & NO_SPAWN_AREA)
            self.region_types.set_option_value(WORLD_SPAWN_AREA_STR, region.type & WORLD_SPAWN_AREA)
            self.region_types.set_option_value(NO_WORLD_SPAWN_AREA_STR, region.type & NO_WORLD_SPAWN_AREA)
            self.region_types.set_option_value(NO_BUILD_AREA_STR, region.type & NO_BUILD_AREA)
            self.spawn_groups.set(" ".join(region.spawn_groups))
            self.maximum_no_spawns.set(region.spawn_limit)
        self._refresh()

    def _load_planet_regions(self, planet):
        self.planet_regions = PlanetRegions(planet.lower())


class Region:
    def __init__(self, region_table):
        self.table = list(region_table.values())
        self.name = self.table[0]
        self.x = self.table[1]
        self.y = self.table[2]
        self.shape = list(self.table[3].values())
        self.type = self.table[4]
        self.spawn_groups = list(self.table[5].values()) if len(self.table) > 5 else []
        self.spawn_limit = str(self.table[6]) if len(self.table) > 6 else ""

    def draw(self, canvas, selected_region):
        width = 3 if selected_region == self.name else 1
        color = "black"
        stipple = ""
        if (self.type & (SPAWN_AREA + WORLD_SPAWN_AREA)):
            color = "SteelBlue1"
        if (self.type & NO_SPAWN_AREA):
            color = "tomato"
        if (self.type & NO_BUILD_AREA):
            color = "red3"
            stipple = "gray25"
        stipple = "gray12" if selected_region == self.name else stipple

        canvas.create_oval(
            self.world_coord_to_canvas_coord_x(self.x - self.shape[1]),
            self.world_coord_to_canvas_coord_y(self.y - self.shape[1]),
            self.world_coord_to_canvas_coord_x(self.x + self.shape[1]),
            self.world_coord_to_canvas_coord_y(self.y + self.shape[1]),
            width = width,
            outline = color,
            stipple = stipple,
            fill = color if stipple else "",
            activewidth = 2,
            activedash = (5, 5),
            activefill = color,
            activestipple = "gray12",
            tags = self.name,
        )

    def world_coord_to_canvas_coord_x(self, world_coord):
        canvas_coord = world_coord / 16
        canvas_coord += 512
        return canvas_coord

    def world_coord_to_canvas_coord_y(self, world_coord):
        canvas_coord = world_coord / 16
        canvas_coord = 512 - canvas_coord
        return canvas_coord


class PlanetRegions:
    def __init__(self, planet):
        lua = LuaRuntime()
        planet_regions_file = "../../Core3/MMOCoreORB/bin/scripts/managers/spawn_manager/" + planet + "_regions.lua"
        package_path_setup = 'package.path = package.path .. ";../../Core3/MMOCoreORB/bin/?.lua"\n'
        return_statement = "\nreturn " + planet + "_regions"
        regions = lua.execute(package_path_setup + pathlib.Path(planet_regions_file).read_text() + return_statement)
        self.regions = {}
        for lua_region in regions.values():
            region = Region(lua_region)
            self.regions[region.name] = region

    def draw(self, canvas, selected_region):
        for region in self.regions.values():
            region.draw(canvas, selected_region)

    def get_region_names(self):
        return sorted([region.name for region in self.regions.values()])