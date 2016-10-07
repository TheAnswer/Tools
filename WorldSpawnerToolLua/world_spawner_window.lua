-- World Spawner Window
--
-- This window handles the world spawn areas. It is possible to select a planet, a map of that planet
-- is then shown together with the areas defined on that planet. Areas can be added, removed or
-- modified in this window.
--
-- This file should not contain any logic other than the creation and layout of the window and the 
-- mapping of events for each control in the window.

require("object")
require("wx")

-- Control Id's, used to identify specific controls.
PLANET_SELECT_ID = 12345670
AREA_SELECT_ID = 12345671

-- Definition of the WorldSpawnerWindow class.
WorldSpawnerWindow = Object:new {
}

local function drawArea(dc, area)    
    if area then
        x = 210 + area["x"]
        y = 10 + area["y"]
        if area["type"] == 1 then
            r = area["size1"]
            dc:DrawCircle(x, y, r)
        elseif area["type"] == 2 then
            w = area["size1"]
            h = area["size2"]
            dc:DrawRectangle(x, y, w, h)
        elseif area["type"] == 3 then
            r1 = area["size1"]
            r2 = area["size2"]
            dc:DrawCircle(x, y, r1)
            dc:DrawCircle(x, y, r2)
        end
    end
end

local function onPaintEventHandler(event)
    local dc = wx.wxPaintDC(WorldSpawnerWindow.panel)
    WorldSpawnerWindow.panel:PrepareDC(dc)
    dc:SetBrush(wx.wxTRANSPARENT_BRUSH)
    dc:DrawBitmap(WorldSpawnerWindow.mapBitmap, 210, 10, false)
        
    dc:SetPen(wx.wxPen(wx.wxColour(255, 255, 0), 1, 0))
    if WorldSpawnerWindow.areaShapes then
        for i, area in pairs(WorldSpawnerWindow.areaShapes) do
            drawArea(dc, area)
        end
    end
    
    dc:SetPen(wx.wxPen(wx.wxRED, 3, 0))
    if WorldSpawnerWindow.selectedArea then
        drawArea(dc, WorldSpawnerWindow.selectedArea)
    end
end

function WorldSpawnerWindow:create()
    wx.wxInitAllImageHandlers()
    
    self.window = wx.wxFrame(wx.NULL, wx.wxID_ANY, "SWGEmu World Spawner Tool",
                             wx.wxDefaultPosition, wx.wxSize(1300, 600))
    
    WorldSpawnerWindow.panel = wx.wxScrolledWindow(self.window, wx.wxID_ANY)
    WorldSpawnerWindow.panel:SetScrollbars(40, 40, 26, 26, 0, 0, true);
    WorldSpawnerWindow.panel:Connect(wx.wxEVT_PAINT, onPaintEventHandler)
    
    self.planetSelect = wx.wxComboBox(WorldSpawnerWindow.panel, PLANET_SELECT_ID, "Select a planet", 
                                      wx.wxPoint(10, 10), wx.wxSize(150, 24))
    self.window:Connect(PLANET_SELECT_ID, wx.wxEVT_COMMAND_COMBOBOX_SELECTED,
                        function(event)
                            self.planetSelectEventHandler(event:GetString())
                        end)
    
    self.areaSelect = wx.wxComboBox(WorldSpawnerWindow.panel, AREA_SELECT_ID, "Select an area", 
                                    wx.wxPoint(10, 40), wx.wxSize(150, 24))
    self.window:Connect(AREA_SELECT_ID, wx.wxEVT_COMMAND_COMBOBOX_SELECTED,
                        function(event)
                            self.areaSelectEventHandler(event:GetString())
                        end)
                        
    self.mapBitmap = wx.wxBitmap()
    
    self.areaInfo = nil
    self.info = wx.wxStaticText(WorldSpawnerWindow.panel, wx.wxID_ANY, "TestText", wx.wxPoint(10, 70))
end

function WorldSpawnerWindow:registerSelectedPlanetEventHandler(planetSelectEventHandler)
    self.planetSelectEventHandler = planetSelectEventHandler
end

function WorldSpawnerWindow:registerSelectedAreaEventHandler(areaSelectEventHandler)
    self.areaSelectEventHandler = areaSelectEventHandler
end

function WorldSpawnerWindow:setAreaNames(areaNames)
    self.areaSelect:Clear()
    self.areaSelect:Append(areaNames)
end

function WorldSpawnerWindow:setAreaShapes(areaShapes)
    self.areaShapes = areaShapes
    self.window:Refresh()
end

function WorldSpawnerWindow:setMapFile(mapFile)
    self.mapBitmap:LoadFile(mapFile, wx.wxBITMAP_TYPE_JPEG)
    self.window:Refresh()
end

function WorldSpawnerWindow:setPlanets(planets)
    self.planetSelect:Clear()
    self.planetSelect:Append(planets)
end

function WorldSpawnerWindow:setSelectedArea(area)
    self.selectedArea = area
    self.window:Refresh()
end

function WorldSpawnerWindow:show()
    self.window:Show(true)
end

function WorldSpawnerWindow:updateInfo(planet)
    self.info:SetLabel(planet)
end

return WorldSpawnerWindow