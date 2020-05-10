import pathlib

from functools import partial
from lupa import LuaRuntime
from PIL import Image, ImageTk
from tkinter import Canvas, IntVar, PhotoImage, StringVar, Tk, BOTTOM, DISABLED, E, HORIZONTAL, N, NORMAL, NW, RIGHT, S, VERTICAL, W, X, Y
from tkinter.ttk import Checkbutton, Combobox, Entry, Frame, Label, LabelFrame, Radiobutton, Scrollbar

MAP_PATH = "../WorldSpawnerTool/release/ui_map_"
ALL_PLANETS = ["Corellia", "Dantooine", "Dathomir", "Endor", "Lok", "Naboo", "Rori", "Tatooine", "Yavin4"]


class TwoCells:
    def __init__(self, parent, **kwargs):
        self.frame = Frame(parent)
        self.frame.grid(columnspan=2, **kwargs)


class Attribute(TwoCells):
    def __init__(self, parent, text, value, **kwargs):
        super().__init__(parent, **kwargs)
        self.label_text = StringVar()
        self.label_text.set(text)
        self.label = Label(self.frame, textvariable=self.label_text)
        self.label.grid(column=0, row=0, padx=5, pady=5, sticky=W)
        self.current_value = StringVar(self.frame)
        self.current_value.set(value)
        self.value = Entry(self.frame, textvariable=self.current_value)
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


class Select(TwoCells):
    def __init__(self, parent, values, callback, **kwargs):
        super().__init__(parent, **kwargs)
        self.callback = callback
        self.options = []
        self.values = []

        column = 0
        row = 0
        for value in values:
            option_selected = IntVar(self.frame)
            option = Checkbutton(self.frame, text=value, variable=option_selected, command=partial(self._option_changed, value))
            option.grid(column=column, row=row, padx=5, pady=5)
            self.options.append((value, option_selected))
            self.values.append(0)
            column += 1
            if column > 1:
                column = 0
                row += 1

    def _option_changed(self, value):
        self.callback(self.options, value)


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


class WorldSpawnerWindow:
    def __init__(self):
        self.window = Tk()

        self.window.title("SWGEmu World Spawner Tool")
        self.window.columnconfigure(0, weight=1)
        self.window.rowconfigure(0, weight=1)

        self.planet_frame = LabelFrame(self.window, text="Naboo")
        self.planet_frame.grid(column=0, row=0, sticky=E + N + S + W)
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

        self.options_frame = Frame(self.window)
        self.options_frame.grid(column=1, row=0)

        self.selected_planet = Selection(self.options_frame, "Selected planet:", values=ALL_PLANETS, callback=self._on_planet_change)

        self.region_frame = LabelFrame(self.options_frame, text="Region")
        self.region_frame.grid(column=0, row=1, columnspan=2, padx=5, pady=5)

        self.selected_region = Selection(self.region_frame, "Selected region:", values=["DifferentRegion", "OtherRegion", "SomeRegion"], callback=self._on_region_change)

        self.x_value = Attribute(self.region_frame, text="X:", value="1234")
        self.y_value = Attribute(self.region_frame, text="Y:", value="2345")

        self.region_shape = Option(self.region_frame, values=["Circle", "Rectangle", "Ring"], callback=self._on_shape_change)

        self.dimension_frame = Frame(self.region_frame)
        self.dimension_frame.grid(columnspan=2)
        self.value_1 = Attribute(self.dimension_frame, text="Radius:", value="345", row=0)
        self.value_2 = Attribute(self.dimension_frame, text="Width:", value="456", row=1).hide()
        self._on_shape_change("Circle")

        self.region_types = Select(self.region_frame, values=["World spawn area", "No world spawn area", "Spawn area", "No spawn area", "No build zone area"],
                                   callback=self._on_type_change)

        self.spawn_groups = Attribute(self.region_frame, text="Spawn group:", value="Unknown").disable()
        self.maximum_no_spawns = Attribute(self.region_frame, text="Maximum number of spaws:", value="1024").disable()

        self.window.mainloop()

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
        type_to_clear = []
        type_to_set = []
        if new_value == 1:
            if changed_type == "World spawn area":
                type_to_set.append("Spawn area")
                type_to_clear.append("No world spawn area")
                type_to_clear.append("No spawn area")
            if changed_type == "No world spawn area":
                type_to_clear.append("World spawn area")
            if changed_type == "Spawn area":
                type_to_clear.append("No spawn area")
            if changed_type == "No spawn area":
                type_to_clear.append("Spawn area")
                type_to_clear.append("World spawn area")
        else:
            if changed_type == "Spawn area":
                type_to_clear.append("World spawn area")

        for to_set in type_to_set:
            for area_type, value in area_types:
                if area_type == to_set:
                    value.set(1)

        for to_clear in type_to_clear:
            for area_type, value in area_types:
                if area_type == to_clear:
                    value.set(0)

        self.spawn_groups.disable()
        self.maximum_no_spawns.disable()
        for area_type, value in area_types:
            if (area_type == "Spawn area" or area_type == "World spawn area") and value.get() == 1:
                self.spawn_groups.enable()
                self.maximum_no_spawns.enable()

    def _on_planet_change(self, new_planet):
        image = Image.open(MAP_PATH + new_planet.lower() + ".jpg")
        self.photo = ImageTk.PhotoImage(image)
        self.planet.create_image(0,0, image=self.photo, anchor=NW)
        self._load_planet_regions(new_planet)

    def _on_region_change(self, new_region):
        print(new_region)

    def _load_planet_regions(self, planet):
        #planet_regions_file = "../../Core3/MMOCoreORB/bin/scripts/managers/spawn_manager/" + planet.lower() + "_regions.lua"
        planet_regions_file = "../../Core3/MMOCoreORB/bin/scripts/managers/spawn_manager/tatooine_regions.lua"
        planet_regions = PlanetRegions(planet.lower())


class Region:
    def __init__(self, region_table):
        self.table = list(region_table.values())
        self.name = self.table[0]
        self.x = self.table[1]
        self.y = self.table[2]
        self.shape = list(self.table[3].values())
        self.type = self.table[4]
        self.spawn_groups = list(self.table[5].values()) if len(self.table) > 5 else []
        self.spawn_limit = self.table[6] if len(self.table) > 6 else 0

    def __str__(self):
        return "[" + self.name + ", " + str(self.x) + ", " + str(self.y) + ", " + str(self.shape) + ", " + str(self.spawn_groups) + "," + str(self.spawn_limit) + "]"

class PlanetRegions:
    def __init__(self, planet):
        lua = LuaRuntime()
        planet_regions_file = "../../Core3/MMOCoreORB/bin/scripts/managers/spawn_manager/" + planet + "_regions.lua"
        package_path_setup = 'package.path = package.path .. ";../../Core3/MMOCoreORB/bin/?.lua"\n'
        return_statement = "\nreturn " + planet + "_regions"
        regions = lua.execute(package_path_setup + pathlib.Path(planet_regions_file).read_text() + return_statement)
        for region in regions.values():
            print(Region(region))