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
selectedPlanet = nil

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
    selectedPlanet = planet:lower()
    dofile(SPAWN_MANAGER_PATH .. "/" .. selectedPlanet .. "_regions.lua")
    areaTable = _G[selectedPlanet .. "_regions"]
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

local function tableToString(t, separator, prefix, suffix, newLineStart, newLineEnd)
		separator = separator or ', '
		prefix = prefix or '{'
		suffix = suffix or '}'
		newLineStart = newLineStart or ''
		newLineEnd = newLineEnd or ''

		local str = prefix .. newLineStart

		for i = 1, table.getn(t), 1 do
				str = str .. t[i]
				if i < table.getn(t) then
						str = str .. separator
				end
		end

		str = str .. newLineEnd .. suffix
		return str
end

local function saveToFile()
		local f = io.open(SPAWN_MANAGER_PATH .. '/' .. selectedPlanet .. '_regions.lua', 'w')
		f:write('-- Planet Region Definitions\n')
		f:write('-- This file has been generated with the SWGEmu World Spawner Tool and should not be edited manually.\n')
		f:write('\n')
		f:write('require("scripts.managers.spawn_manager.regions")')
		f:write('\n')
		f:write(selectedPlanet .. '_regions = ')
		local regions = {}
		for i = 1, table.getn(areaTable), 1 do
				local row = {}
				table.insert(row, '"' .. areaTable[i][1] .. '"')
				table.insert(row, tostring(areaTable[i][2]))
				table.insert(row, tostring(areaTable[i][3]))
				local shape = {}
				for j = 1, table.getn(areaTable[i][4]), 1 do
						table.insert(shape, tostring(areaTable[i][4][j]))
				end
				table.insert(row, tableToString(shape))
				local tier = {}
				if bit.band(areaTable[i][5], 0xF) == 0x1 then
						table.insert(tier, 'SPAWNAREA')
				elseif bit.band(areaTable[i][5], 0xF) == 0x2 then
						table.insert(tier, 'NOSPAWNAREA')
				end
				if bit.band(areaTable[i][5], 0xF0) == 0x10 then
						table.insert(tier, 'WORLDSPAWNAREA')
				elseif bit.band(areaTable[i][5], 0xF0) == 0x20 then
						table.insert(tier, 'NOWORLDSPAWNAREA')
				end
				if bit.band(areaTable[i][5], 0xF00) == 0x100 then
						table.insert(tier, 'NOBUILDZONEAREA')
				end
				if table.getn(tier) == 0 then
					  table.insert(tier, 'UNDEFINEDAREA')
				end
				table.insert(row, tableToString(tier, ' + ', '', ''))
				if table.getn(areaTable[i][6] or {}) > 0 then
						local spawnGroups = {}
						for j = 1, table.getn(areaTable[i][6] or {}), 1 do
								table.insert(spawnGroups, '"' .. areaTable[i][6][j] .. '"')
						end
						table.insert(row, tableToString(spawnGroups))
				end
				table.insert(regions, tableToString(row))
		end
		f:write(tableToString(regions, ',\n\t', '{', '}', '\n\t', '\n'))
		f:write('\n')
		f:close()
end

local function main()
    WorldSpawnerWindow:create()
    WorldSpawnerWindow:setPlanets(getPlanetList())
    WorldSpawnerWindow:setSpawnGroups(getSpawnGroupList())
    WorldSpawnerWindow:registerSelectedPlanetEventHandler(changedPlanetEventHandler)
    WorldSpawnerWindow:registerSelectedAreaEventHandler(selectedAreaEventHandler)
    WorldSpawnerWindow:registerAreaUpdatedEventHandler(changedAreaEventHandler)
    WorldSpawnerWindow:registerSavePlanetEventHandler(saveToFile)
    WorldSpawnerWindow:show()
end

main()
