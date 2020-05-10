import pathlib

from functools import partial
from PIL import Image, ImageTk
from tkinter import (
    Canvas, IntVar, Listbox, PhotoImage, StringVar, Tk, BOTTOM, DISABLED, E, HORIZONTAL, MULTIPLE, N, NORMAL, NW,
    RIGHT, S, VERTICAL, W, X, Y
)
from tkinter.ttk import Checkbutton, Combobox, Entry, Frame, Label, LabelFrame, Radiobutton, Scrollbar

from planet import Planet
from region import CIRCLE, NO_BUILD_AREA, NO_SPAWN_AREA, NO_WORLD_SPAWN_AREA, RECTANGLE, RING, SPAWN_AREA, WORLD_SPAWN_AREA

MAP_PATH = "../WorldSpawnerTool/release/ui_map_"

NO_BUILD_AREA_STR = "No build zone area"
NO_SPAWN_AREA_STR = "No spawn area"
NO_WORLD_SPAWN_AREA_STR = "No world spawn area"
SPAWN_AREA_STR = "Spawn area"
WORLD_SPAWN_AREA_STR = "World spawn area"

SHAPES = {"Circle": CIRCLE, "Rectangle": RECTANGLE, "Ring": RING}
TYPES = {
    SPAWN_AREA_STR: SPAWN_AREA,
    NO_SPAWN_AREA_STR: NO_SPAWN_AREA,
    WORLD_SPAWN_AREA_STR: WORLD_SPAWN_AREA,
    NO_WORLD_SPAWN_AREA_STR: NO_WORLD_SPAWN_AREA,
    NO_BUILD_AREA_STR: NO_BUILD_AREA
}


class TwoCells:
    ANYTHING = 0
    INTEGERS = 1
    NON_NEGATIVE_INTEGERS = 2
    STATIC = 3

    def __init__(self, parent, validation_type=ANYTHING, **kwargs):
        self.validation_type = validation_type
        self.frame = Frame(parent)
        self.frame.grid(columnspan=2, sticky=E + N + S + W, **kwargs)
        self.frame.columnconfigure(0, weight=1)
        self.frame.rowconfigure(0, weight=1)
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
            elif self.validation_type == self.STATIC:
                return False
            return True
        except Exception:
            return False


class Attribute(TwoCells):
    def __init__(self, parent, text, value, callback=None, **kwargs):
        super().__init__(parent, **kwargs)
        self.callback = callback
        self.label_text = StringVar()
        self.label_text.set(text)
        self.label = Label(self.frame, textvariable=self.label_text)
        self.label.grid(column=0, row=0, padx=5, pady=5, sticky=W)
        self.current_value = StringVar(self.frame)
        self.current_value.set(value)
        self.value = Entry(self.frame, textvariable=self.current_value, validate="key", validatecommand=self.validate_command)
        self.value.grid(column=1, row=0, padx=5, pady=5, sticky=E)
        if self.callback:
            self.value.bind("<KeyRelease>", self._on_entry_changed)

    def _on_entry_changed(self, event):
        self.callback()

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

    def get(self):
        value = self.current_value.get()
        if self.validation_type in [TwoCells.INTEGERS, TwoCells.NON_NEGATIVE_INTEGERS]:
            return int(value) if value not in ["", "-"] else 0
        else:
            return value


class SelectOneOption(TwoCells):
    def __init__(self, parent, values, callback, **kwargs):
        super().__init__(parent, **kwargs)
        self.callback = callback
        self.selected_option = StringVar(self.frame)
        self.selected_option.set(values[0])
        self.options = []
        for value in values:
            option = Radiobutton(self.frame, text=value, value=value, variable=self.selected_option, command=self._option_changed)
            option.grid(padx=5, pady=5, sticky=W)
            self.options.append(option)

    def _option_changed(self):
        self.callback(self.selected_option.get())

    def set(self, value):
        self.selected_option.set(value)

    def get(self):
        return self.selected_option.get()


class SelectMultipleOptions(TwoCells):
    def __init__(self, parent, values, callback, **kwargs):
        super().__init__(parent, **kwargs)
        self.callback = callback
        self.options = []
        self.values = {}

        for value in values:
            option_selected = IntVar(self.frame)
            option = Checkbutton(self.frame, text=value, variable=option_selected, command=partial(self._option_changed, value))
            option.grid(padx=5, pady=5, sticky=W)
            self.options.append((value, option_selected))
            self.values[value] = option_selected

    def _option_changed(self, option_name):
        self.callback(self.options, option_name)

    def set_option_value(self, option_name, value):
        self.values[option_name].set(1 if value else 0)

    def get(self):
        selected_values = []
        for value_name, option in self.values.items():
            if option.get():
                selected_values.append(value_name)
        return selected_values



class SelectWithDropDown(TwoCells):
    def __init__(self, parent, text, values, callback, width=30, **kwargs):
        super().__init__(parent, **kwargs)
        self.callback = callback
        self.label = Label(self.frame, text=text)
        self.label.grid(column=0, row=0, padx=5, pady=5, sticky=W)
        self.combobox = Combobox(self.frame, validate="key", validatecommand=self.validate_command, width=width)
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

    def get(self):
        return self.combobox["values"][self.combobox.current()]


class SelectMultiple(TwoCells):
    def __init__(self, parent, text, values, **kwargs):
        super().__init__(parent, **kwargs)
        self.label = Label(self.frame, text=text)
        self.label.grid(column=0, row=0, padx=5, pady=5, sticky=W)
        self.selected_options = StringVar(self.frame)
        self.selected_options.set(values)
        self.listbox = Listbox(self.frame, listvariable=self.selected_options, selectmode=MULTIPLE)
        self.listbox.grid(column=1, row=0, padx=5, pady=5, sticky=E)

    def disable(self):
        self.listbox.configure(state=DISABLED)
        return self

    def enable(self):
        self.listbox.configure(state=NORMAL)
        return self

    def set(self, values):
        if values:
            self.enable()
        else:
            self.disable()
        self.listbox.selection_clear(0, self.listbox.size())
        for value in values:
            for index in range(self.listbox.size()):
                if value == self.listbox.get(index):
                    self.listbox.selection_set(index)
                    self.listbox.event_generate("<<ListboxSelect>>")

    def get(self):
        return [self.listbox.get(i) for i in self.listbox.curselection()]


class WorldSpawnerWindow:
    def __init__(self):
        self.initialized = False
        self.all_planets = _get_all_planets()
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

        self.selected_region = None
        self.selected_planet = SelectWithDropDown(self.options_frame, "Selected planet:", values=self.all_planets, callback=self._on_planet_change,
                                                  validation_type=TwoCells.STATIC)

        self.region_frame = LabelFrame(self.options_frame, text="Region")
        self.region_frame.grid(columnspan=2, padx=5, pady=5, sticky=N + S)

        self.selected_region = SelectWithDropDown(self.region_frame, "Selected region:", values=["-"], callback=self._on_region_change,
                                                  validation_type=TwoCells.STATIC)

        self.x_value = Attribute(self.region_frame, text="X:", value="1234", validation_type=TwoCells.INTEGERS, callback=self._on_properties_changed)
        self.y_value = Attribute(self.region_frame, text="Y:", value="2345", validation_type=TwoCells.INTEGERS, callback=self._on_properties_changed)

        self.region_shape = SelectOneOption(self.region_frame, values=["Circle", "Rectangle", "Ring"], callback=self._on_shape_change)

        self.dimension_frame = Frame(self.region_frame)
        self.dimension_frame.columnconfigure(0, weight=1)
        self.dimension_frame.rowconfigure(0, weight=1)
        self.dimension_frame.grid(columnspan=2, sticky=E + N + S + W)
        self.value_1 = Attribute(self.dimension_frame, text="Radius:", value="345", row=0, validation_type=TwoCells.INTEGERS,
                                 callback=self._on_properties_changed)
        self.value_2 = Attribute(self.dimension_frame, text="Width:", value="456", row=1, validation_type=TwoCells.INTEGERS,
                                 callback=self._on_properties_changed).hide()

        self.region_types = SelectMultipleOptions(self.region_frame, values=[WORLD_SPAWN_AREA_STR, NO_WORLD_SPAWN_AREA_STR, SPAWN_AREA_STR, NO_SPAWN_AREA_STR, NO_BUILD_AREA_STR],
                                   callback=self._on_type_change)

        self.spawn_groups = SelectMultiple(self.region_frame, text="Spawn group:", values=_get_all_spawn_groups()).disable()
        self.maximum_no_spawns = Attribute(self.region_frame, text="Maximum number of spaws:", value="1024",
                                           validation_type=TwoCells.NON_NEGATIVE_INTEGERS).disable()

        self.planet_info = StringVar()
        self.planet_info.set("")
        self.planet_info_label = Label(self.planet_frame, textvariable=self.planet_info)
        self.planet_info_label.grid(padx=5, pady=5, sticky=S + W)

        self._on_planet_change(self.all_planets[0])
        self._on_shape_change("Circle")
        self.initialized = True

        self.window.mainloop()

    def _to_type(self, types):
        value = 0
        for type_name in types:
            value += TYPES[type_name]
        return value

    def _on_properties_changed(self):
        if self.initialized:
            active_region = self.planet_regions.get(self.selected_region.get())
            active_region.x = self.x_value.get()
            active_region.y = self.y_value.get()
            active_region.shape = SHAPES[self.region_shape.get()]
            active_region.value_1 = self.value_1.get()
            active_region.value_2 = self.value_2.get()
            active_region.type = self._to_type(self.region_types.get())
            active_region.spawn_groups = self.spawn_groups.get()
            active_region.maximum_no_spawns = self.maximum_no_spawns.get()
            self._refresh()
            self.planet_regions.save()

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
        self._on_properties_changed()

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
        self._on_properties_changed()

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
        region = self.planet_regions.get(new_region)
        if region:
            self.x_value.set(str(region.x))
            self.y_value.set(str(region.y))
            if region.shape == CIRCLE:
                self.region_shape.set("Circle")
                self.value_1.set(str(region.value_1))
                self.value_1.validation_type = TwoCells.INTEGERS
            elif region.shape == RECTANGLE:
                self.region_shape.set("Rectangle")
                self.value_1.set(str(region.value_1))
                self.value_1.validation_type = TwoCells.INTEGERS
                self.value_2.set(str(region.value_2))
                self.value_2.validation_type = TwoCells.INTEGERS
            elif region.shape == RING:
                self.region_shape.set("Ring")
                self.value_1.set(str(region.value_1))
                self.value_1.validation_type = TwoCells.INTEGERS
                self.value_2.set(str(region.value_2))
                self.value_2.validation_type = TwoCells.INTEGERS
            else:
                print("Incorrect region shape: " + str(region.shape[0]))
            self.region_types.set_option_value(SPAWN_AREA_STR, region.type & SPAWN_AREA)
            self.region_types.set_option_value(NO_SPAWN_AREA_STR, region.type & NO_SPAWN_AREA)
            self.region_types.set_option_value(WORLD_SPAWN_AREA_STR, region.type & WORLD_SPAWN_AREA)
            self.region_types.set_option_value(NO_WORLD_SPAWN_AREA_STR, region.type & NO_WORLD_SPAWN_AREA)
            self.region_types.set_option_value(NO_BUILD_AREA_STR, region.type & NO_BUILD_AREA)
            self.spawn_groups.set(region.spawn_groups)
            self.maximum_no_spawns.set(region.spawn_limit)
        self._refresh()

    def _load_planet_regions(self, planet):
        self.planet_regions = Planet(planet.lower())


def _get_all_planets():
    planets_path = pathlib.Path("../../Core3/MMOCoreORB/bin/scripts/managers/spawn_manager/")
    planets = []
    for planet_file in planets_path.glob("*_regions.lua"):
        planet_name = planet_file.name.replace("_regions.lua", "")
        planet_name = planet_name[0].upper() + planet_name[1:]
        planets.append(planet_name)
    return sorted(planets)


def _get_all_spawn_groups():
    spawn_groups_path = pathlib.Path("../../Core3/MMOCoreORB/bin/scripts/mobile/spawn/")
    spawn_groups = []
    for spawn_group_file in spawn_groups_path.glob("*.lua"):
        spawn_group_name = spawn_group_file.name.replace(".lua", "")
        spawn_groups.append(spawn_group_name)
    return sorted(spawn_groups)


def _main():
    world_spawner_window = WorldSpawnerWindow()

if __name__ == "__main__":
    _main()