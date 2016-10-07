-- World Spawner Tool
--
-- The tool is responsible for modifying all spawn related files in the Core3 repository.
-- Currently supports:
--  * World Spawn Areas

CORE3_PATH = "/home/vagrant/workspace/Core3"
CORE3_BIN_PATH = CORE3_PATH .. "/MMOCoreORB/bin"
SPAWN_MANAGER_PATH = CORE3_BIN_PATH .. "/scripts/managers/spawn_manager"
MAP_PATH = "../WorldSpawnerTool/release/ui_map_"

package.path = package.path .. ";" .. CORE3_BIN_PATH .. "/?.lua"

FileSystem = require("file_system")
StringOperations = require("string_operations")
WorldSpawnerWindow = require("world_spawner_window")

areaTable = nil
selectedAreaIndex = -1

local function regionToAreaShape(area)
		local xOffset = 0
		local yOffset = 0
		if area[4][1] == 2 then
			xOffset = -area[4][2] / 2
			yOffset = -area[4][3] / 2
		end
    return {
        x = OFFSET + area[2] + xOffset,
        y = OFFSET - area[3] + yOffset,
        type = area[4][1],
        size1 = area[4][2],
        size2 = area[4][3] or 0
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
		print("New change")
		local selectedArea = WorldSpawnerWindow:getSelectedArea()
		local areaShape = {selectedArea["type"], selectedArea["size1"]}
		if selectedArea["type"] ~= 1 then
				table.insert(areaShape, selectedArea["size2"])
		end
		areaTable[selectedAreaIndex][2] = selectedArea["x"]
		areaTable[selectedAreaIndex][3] = selectedArea["y"]
		areaTable[selectedAreaIndex][4] = areaShape
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

local function main()
    WorldSpawnerWindow:create()
    WorldSpawnerWindow:setPlanets(getPlanetList())
    WorldSpawnerWindow:registerSelectedPlanetEventHandler(changedPlanetEventHandler)
    WorldSpawnerWindow:registerSelectedAreaEventHandler(selectedAreaEventHandler)
    WorldSpawnerWindow:registerAreaUpdatedEventHandler(changedAreaEventHandler)
    WorldSpawnerWindow:show()
end

main()
