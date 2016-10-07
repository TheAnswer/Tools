-- World Spawner Tool
--
-- The tool is responsible for modifying all spawn related files in the Core3 repository.
-- Currently supports:
--  * World Spawn Areas

FileSystem = require("file_system")
StringOperations = require("string_operations")
WorldSpawnerWindow = require("world_spawner_window")

areaTable = nil
areaShapes = {}

SCALE_FACTOR = 16
OFFSET = 512

CORE3_PATH = "/home/vagrant/workspace/Core3"
SPAWN_MANAGER_PATH = CORE3_PATH .. "/MMOCoreORB/bin/scripts/managers/spawn_manager"
MAP_PATH = "../WorldSpawnerTool/release/ui_map_"

local function regionToAreaShape(area)
    return {
        x = OFFSET + area[2] / SCALE_FACTOR,
        realx = area[2],
        y = OFFSET - area[3] / SCALE_FACTOR,
        realy = area[3],
        type = area[4][1], 
        size1 = area[4][2] / SCALE_FACTOR,
        realsize1 = area[4][2],
        size2 = 0 or area[4][3] / SCALE_FACTOR,
        realsize2 = 0 or area[4][3]
    }
end

local function loadAreas(planet)
    planet = planet:lower()
    dofile(SPAWN_MANAGER_PATH .. "/" .. planet .. ".lua")
    areaTable = _G[planet .. "_regions"]
    local areaNames = {}
    for i,area in pairs(areaTable) do
        table.insert(areaNames, area[1])
        table.insert(areaShapes, regionToAreaShape(area))
    end
    table.sort(areaNames)
    return areaNames
end

local function changedPlanetEventHandler(planet)
    WorldSpawnerWindow:setAreaNames(loadAreas(planet))
    WorldSpawnerWindow:setAreaShapes(areaShapes)
    WorldSpawnerWindow:setMapFile(MAP_PATH .. planet:lower() .. ".jpg")
end

local function changedAreaEventHandler(areaName)
    for i, area in pairs(areaTable) do
        if area[1] == areaName then
            WorldSpawnerWindow:setSelectedArea(regionToAreaShape(area))
            break
        end
    end
end

local function getPlanetList()
    local planetFiles = FileSystem:listFiles(SPAWN_MANAGER_PATH)
    planetFiles = FileSystem:getFileNameWithoutExtension(planetFiles)
    planetFiles = StringOperations:capitalizeFirstCharacter(planetFiles)
    table.sort(planetFiles)
    return planetFiles
end

local function main()
    WorldSpawnerWindow:create()
    WorldSpawnerWindow:setPlanets(getPlanetList())
    WorldSpawnerWindow:registerSelectedPlanetEventHandler(changedPlanetEventHandler)
    WorldSpawnerWindow:registerSelectedAreaEventHandler(changedAreaEventHandler)
    WorldSpawnerWindow:show()
end

main()