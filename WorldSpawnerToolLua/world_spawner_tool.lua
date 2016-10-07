-- World Spawner Tool
--
-- The tool is responsible for modifying all spawn related files in the Core3 repository.
-- Currently supports:
--  * World Spawn Areas

CORE3_PATH = "/home/vagrant/workspace/Core3"
CORE3_BIN_PATH = CORE3_PATH .. "/MMOCoreORB/bin"
SPAWN_MANAGER_PATH = CORE3_BIN_PATH .. "/scripts/managers/spawn_manager"
SPAWN_GROUPS_PATH = CORE3_BIN_PATH .. "/scripts/mobile/spawn"
MAP_PATH = "../WorldSpawnerTool/release/ui_map_"
WORLD_SPAWN_MULTIPLIER = 16
BUILDINGS_MULTIPLIER = 256

package.path = package.path .. ";" .. CORE3_BIN_PATH .. "/?.lua"

FileSystem = require("file_system")
StringOperations = require("string_operations")
WorldSpawnerWindow = require("world_spawner_window")

areaTable = nil
selectedAreaIndex = -1

local function regionToAreaShape(area)
    return {
        x = area[2],
        y = area[3],
        shape = area[4][1],
        size1 = area[4][2],
        size2 = area[4][3] or 0,
        type = bit.band(area[5], 0xF),
        worldspawn = bit.band(area[5], 0xF0) / WORLD_SPAWN_MULTIPLIER,
        buildings = bit.band(area[5], 0xF00) / BUILDINGS_MULTIPLIER,
        spawngroups = area[6] or {}
    }
end

local function loadAreas(planet)
    planet = planet:lower()
    dofile(SPAWN_MANAGER_PATH .. "/" .. planet .. "_regions.lua")
    areaTable = _G[planet .. "_regions"]
end

local function getAreaNames()
    local areaNames = {}
    for i,area in pairs(areaTable) do
        table.insert(areaNames, area[1])
    end
    table.sort(areaNames)
    return areaNames
end

local function getAreaShapes()
    local areaShapes = {}
    for i,area in pairs(areaTable) do
        table.insert(areaShapes, regionToAreaShape(area))
    end
   	return areaShapes
end

local function changedPlanetEventHandler(planet)
		loadAreas(planet)
    WorldSpawnerWindow:setAreaNames(getAreaNames())
    WorldSpawnerWindow:setAreaShapes(getAreaShapes())
    WorldSpawnerWindow:setMapFile(MAP_PATH .. planet:lower() .. ".jpg")
end

local function selectedAreaEventHandler(areaName)
    for i, area in pairs(areaTable) do
        if area[1] == areaName then
        		selectedAreaIndex = i
            WorldSpawnerWindow:setSelectedArea(regionToAreaShape(area))
            break
        end
    end
end

local function changedAreaEventHandler()
		local selectedArea = WorldSpawnerWindow:getSelectedArea()
		local areaShape = {selectedArea["shape"], selectedArea["size1"]}
		if selectedArea["shape"] ~= 1 then
				table.insert(areaShape, selectedArea["size2"])
		end
		areaTable[selectedAreaIndex][2] = selectedArea["x"]
		areaTable[selectedAreaIndex][3] = selectedArea["y"]
		areaTable[selectedAreaIndex][4] = areaShape
		areaTable[selectedAreaIndex][5] = selectedArea["type"] + selectedArea["worldspawn"] * WORLD_SPAWN_MULTIPLIER + selectedArea["buildings"] * BUILDINGS_MULTIPLIER
		areaTable[selectedAreaIndex][6] = selectedArea["spawngroups"]
    WorldSpawnerWindow:setAreaShapes(getAreaShapes())
		WorldSpawnerWindow:setSelectedArea(regionToAreaShape(areaTable[selectedAreaIndex]))
end

local function getPlanetList()
    local planetFiles = FileSystem:listFiles(SPAWN_MANAGER_PATH, "*_regions.lua")
    planetFiles = FileSystem:getFileNameWithoutExtension(planetFiles)
    planetFiles = StringOperations:splitString(planetFiles, LEFT_PART, "_")
    planetFiles = StringOperations:capitalizeFirstCharacter(planetFiles)
    table.sort(planetFiles)
    return planetFiles
end

local function getSpawnGroupList()
    local spawnGroups = FileSystem:listFiles(SPAWN_GROUPS_PATH, "*.lua")
    spawnGroups = FileSystem:getFileNameWithoutExtension(spawnGroups)
    table.sort(spawnGroups)
    -- Break out function.
    local removeIndex = -1
    for i, spawnGroup in pairs(spawnGroups) do
    		if spawnGroup == "serverobjects" then
    			  removeIndex = i
    		end
    end
    table.remove(spawnGroups, removeIndex)
    return spawnGroups
end

local function main()
    WorldSpawnerWindow:create()
    WorldSpawnerWindow:setPlanets(getPlanetList())
    WorldSpawnerWindow:setSpawnGroups(getSpawnGroupList())
    WorldSpawnerWindow:registerSelectedPlanetEventHandler(changedPlanetEventHandler)
    WorldSpawnerWindow:registerSelectedAreaEventHandler(selectedAreaEventHandler)
    WorldSpawnerWindow:registerAreaUpdatedEventHandler(changedAreaEventHandler)
    WorldSpawnerWindow:show()
end

main()
