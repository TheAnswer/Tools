

CIRCLE = 1
RECTANGLE = 2
RING = 3
SPAWN_AREA = 0x1
NO_SPAWN_AREA = 0x2
WORLD_SPAWN_AREA = 0x10
NO_WORLD_SPAWN_AREA = 0x20
NO_BUILD_AREA = 0x100
UNDEFINED_AREA = 0


class Region:
    def __init__(self, region_table):
        self.table = list(region_table.values())
        self.name = self.table[0]
        self.x = self.table[1]
        self.y = self.table[2]
        self.shape_list = list(self.table[3].values())
        self.shape = self.shape_list[0]
        self.value_1 = self.shape_list[1]
        self.value_2 = self.shape_list[2] if len(self.shape_list) > 2 else None
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

        if self.shape == CIRCLE:
            radius = self.value_1
            canvas.create_oval(
                self.world_coord_to_canvas_coord_x(self.x - radius),
                self.world_coord_to_canvas_coord_y(self.y - radius),
                self.world_coord_to_canvas_coord_x(self.x + radius),
                self.world_coord_to_canvas_coord_y(self.y + radius),
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
        elif self.shape == RECTANGLE:
            top_x = self.value_1
            top_y = self.value_2
            canvas.create_rectangle(
                self.world_coord_to_canvas_coord_x(self.x),
                self.world_coord_to_canvas_coord_y(self.y),
                self.world_coord_to_canvas_coord_x(top_x),
                self.world_coord_to_canvas_coord_y(top_y),
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
        elif self.shape == RING:
            region_width = max((self.value_1 - self.value_2) / 16, 0)
            outer_radius = self.value_1
            inner_radius = self.value_2
            center_radius = (outer_radius + inner_radius) / 2
            if region_width > 0:
                canvas.create_oval(
                    self.world_coord_to_canvas_coord_x(self.x - outer_radius),
                    self.world_coord_to_canvas_coord_y(self.y - outer_radius),
                    self.world_coord_to_canvas_coord_x(self.x + outer_radius),
                    self.world_coord_to_canvas_coord_y(self.y + outer_radius),
                    width = width,
                    outline = color,
                    activewidth = 2,
                    activedash = (5, 5),
                    activefill = color,
                    activestipple = "gray12",
                    tags = self.name,
                )
                canvas.create_oval(
                    self.world_coord_to_canvas_coord_x(self.x - inner_radius),
                    self.world_coord_to_canvas_coord_y(self.y - inner_radius),
                    self.world_coord_to_canvas_coord_x(self.x + inner_radius),
                    self.world_coord_to_canvas_coord_y(self.y + inner_radius),
                    width = width,
                    outline = color,
                    activewidth = 2,
                    activedash = (5, 5),
                    activefill = color,
                    activestipple = "gray12",
                    tags = self.name,
                )
                canvas.create_oval(
                    self.world_coord_to_canvas_coord_x(self.x - center_radius),
                    self.world_coord_to_canvas_coord_y(self.y - center_radius),
                    self.world_coord_to_canvas_coord_x(self.x + center_radius),
                    self.world_coord_to_canvas_coord_y(self.y + center_radius),
                    width = region_width,
                    outline = color,
                    outlinestipple = stipple,
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

    def _shape_export(self):
        if self.shape == CIRCLE:
            values = ["CIRCLE", str(self.value_1)]
        elif self.shape == RECTANGLE:
            values = ["RECTANGLE", str(self.value_1), str(self.value_2)]
        else:
            values = ["RING", str(self.value_1), str(self.value_2)]
        return ["{" + ", ".join(values) + "}"]

    def _type_export(self):
        values = []
        if self.type & SPAWN_AREA:
            values.append("SPAWNAREA")
        if self.type & WORLD_SPAWN_AREA:
            values.append("WORLDSPAWNAREA")
        if self.type & NO_SPAWN_AREA:
            values.append("NOSPAWNAREA")
        if self.type & NO_WORLD_SPAWN_AREA:
            values.append("NOWORLDSPAWNAREA")
        if self.type & NO_BUILD_AREA:
            values.append("NOBUILDZONEAREA")
        if not values:
            values.append("UNDEFINEDAREA")
        return [" + ".join(values)]

    def _spawn_export(self):
        if self.spawn_groups:
            return ['{"' + '", "'.join(self.spawn_groups) + '"}', str(self.spawn_limit)]
        else:
            return []

    def __str__(self):
        values = ['"' + self.name + '"', str(self.x), str(self.y)] + self._shape_export() + self._type_export() + self._spawn_export()
        return "{" + ", ".join(values) + "}"