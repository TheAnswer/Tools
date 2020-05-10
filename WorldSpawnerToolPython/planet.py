import pathlib
import textwrap

from lupa import LuaRuntime

from region import Region


class Planet:
    def __init__(self, planet):
        lua = LuaRuntime()
        self.planet = planet
        self.planet_regions_file = pathlib.Path("../../Core3/MMOCoreORB/bin/scripts/managers/spawn_manager/" + planet + "_regions.lua")
        package_path_setup = 'package.path = package.path .. ";../../Core3/MMOCoreORB/bin/?.lua"\n'
        return_statement = "\nreturn " + planet + "_regions"
        regions = lua.execute(package_path_setup + self.planet_regions_file.read_text() + return_statement)
        self.regions = []
        for lua_region in regions.values():
            region = Region(lua_region)
            self.regions.append(region)

    def draw(self, canvas, selected_region):
        for region in self.regions:
            region.draw(canvas, selected_region)

    def get(self, region_name):
        for region in self.regions:
            if region.name == region_name:
                return region
        return None

    def get_region_names(self):
        return [region.name for region in self.regions]

    def __str__(self):
        return ",\n\t".join([str(region) for region in self.regions])

    def save(self):
        top = textwrap.dedent("""\
            -- Planet Region Definitions
            --
            -- {"regionName", x, y, shape and size, tier, {"spawnGroup1", ...}, maxSpawnLimit}
            -- For circle and ring, x and y are the center point
            -- For rectangles, x and y are the bottom left corner. x2 and y2 (see below) are the upper right corner
            -- Shape and size is a table with the following format depending on the shape of the area:
            --   - Circle: {CIRCLE, radius}
            --   - Rectangle: {RECTANGLE, x2, y2}
            --   - Ring: {RING, inner radius, outer radius}
            -- Tier is a bit mask with the following possible values where each hexadecimal position is one possible configuration.
            -- That means that it is not possible to have both a spawn area and a no spawn area in the same region, but
            -- a spawn area that is also a no build zone is possible.

            require("scripts.managers.spawn_manager.regions")

            """)
        self.planet_regions_file.write_text(top + self.planet + "_regions = {\n\t" + str(self) + "\n}\n")