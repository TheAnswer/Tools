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
AREA_TYPE_ID = 12345672
LABEL1_ID = 12345673
LABEL2_ID = 12345674
XCOORD_ID = 12345675
YCOORD_ID = 12345676
INFO1_ID = 12345677
INFO2_ID = 12345678

SCALE_FACTOR = 16
OFFSET = 512

-- Definition of the WorldSpawnerWindow class.
WorldSpawnerWindow = Object:new {
}

local function drawArea(dc, area)
    if area then
        x = 270 + OFFSET + area["x"] / SCALE_FACTOR
        y = 10 + OFFSET + area["y"] / SCALE_FACTOR
        r1w = math.max(area["size1"] / SCALE_FACTOR, 1)
        r2h = math.max(area["size2"] / SCALE_FACTOR, 1)
        if area["type"] == 1 then
            dc:DrawCircle(x, y, r1w)
        elseif area["type"] == 2 then
            dc:DrawRectangle(x, y, r1w, r2h)
        elseif area["type"] == 3 then
            dc:DrawCircle(x, y, r1w)
            dc:DrawCircle(x, y, r2h)
        end
    end
end

local function onPaintEventHandler(event)
    local dc = wx.wxPaintDC(WorldSpawnerWindow.panel)
    WorldSpawnerWindow.panel:PrepareDC(dc)
    dc:SetBrush(wx.wxTRANSPARENT_BRUSH)
    dc:DrawBitmap(WorldSpawnerWindow.mapBitmap, 270, 10, false)

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

local function disableAreaInfoControls()
    WorldSpawnerWindow.xCoord:Enable(false)
    WorldSpawnerWindow.yCoord:Enable(false)
    WorldSpawnerWindow.areaType:Enable(false)
    WorldSpawnerWindow.areaType:SetSelection(0)
    WorldSpawnerWindow.areaInfo1Value:Enable(false)
    WorldSpawnerWindow.areaInfo2Value:Enable(false)
    WorldSpawnerWindow.areaInfo2Text:Show(false)
    WorldSpawnerWindow.areaInfo2Value:Show(false)
end

local function enableAreaInfoControls()
    WorldSpawnerWindow.xCoord:Enable(true)
    WorldSpawnerWindow.yCoord:Enable(true)
    WorldSpawnerWindow.areaType:Enable(true)
    WorldSpawnerWindow.areaInfo1Value:Enable(true)
    WorldSpawnerWindow.areaInfo2Value:Enable(true)
    if WorldSpawnerWindow.areaType:GetSelection() == 0 then
        WorldSpawnerWindow.areaInfo1Text:SetLabel("Radius")
        WorldSpawnerWindow.areaInfo2Text:Show(false)
        WorldSpawnerWindow.areaInfo2Value:Show(false)
    elseif WorldSpawnerWindow.areaType:GetSelection() == 1 then
        WorldSpawnerWindow.areaInfo1Text:SetLabel("Width")
        WorldSpawnerWindow.areaInfo2Text:SetLabel("Height")
        WorldSpawnerWindow.areaInfo2Text:Show(true)
        WorldSpawnerWindow.areaInfo2Value:Show(true)
    elseif WorldSpawnerWindow.areaType:GetSelection() == 2 then
        WorldSpawnerWindow.areaInfo1Text:SetLabel("Inner Radius")
        WorldSpawnerWindow.areaInfo2Text:SetLabel("Outer Radius")
        WorldSpawnerWindow.areaInfo2Text:Show(true)
        WorldSpawnerWindow.areaInfo2Value:Show(true)
    end
end

local function areaUpdatedEventHandler()
		WorldSpawnerWindow.areaUpdatedEventHandler()
end

function WorldSpawnerWindow:create()
    wx.wxInitAllImageHandlers()

    self.window = wx.wxFrame(wx.NULL, wx.wxID_ANY, "SWGEmu World Spawner Tool",
                             wx.wxDefaultPosition, wx.wxSize(1300, 600))

    WorldSpawnerWindow.panel = wx.wxScrolledWindow(self.window, wx.wxID_ANY)
    WorldSpawnerWindow.panel:SetScrollbars(40, 40, 26, 26, 0, 0, true);
    WorldSpawnerWindow.panel:Connect(wx.wxEVT_PAINT, onPaintEventHandler)

    wx.wxStaticText(WorldSpawnerWindow.panel, wx.wxID_ANY, "Selected Planet", wx.wxPoint(10, 10))
    self.planetSelect = wx.wxComboBox(WorldSpawnerWindow.panel, PLANET_SELECT_ID, "Select a planet",
                                      wx.wxPoint(10, 30), wx.wxSize(250, 24))
    self.planetSelect:Connect(PLANET_SELECT_ID, wx.wxEVT_COMMAND_COMBOBOX_SELECTED,
                              function(event)
                                  self.planetSelectEventHandler(event:GetString())
                              end)

    wx.wxStaticText(WorldSpawnerWindow.panel, wx.wxID_ANY, "Selected Area", wx.wxPoint(10, 60))
    self.areaSelect = wx.wxComboBox(WorldSpawnerWindow.panel, AREA_SELECT_ID, "Select an area",
                                    wx.wxPoint(10, 80), wx.wxSize(250, 24))
    self.areaSelect:Enable(false)
    self.areaSelect:Connect(AREA_SELECT_ID, wx.wxEVT_COMMAND_COMBOBOX_SELECTED,
                            function(event)
                                self.areaSelectEventHandler(event:GetString())
                            end)

    wx.wxStaticText(WorldSpawnerWindow.panel, wx.wxID_ANY, "X", wx.wxPoint(10, 110))
    self.xCoord = wx.wxTextCtrl(WorldSpawnerWindow.panel, XCOORD_ID, "-", wx.wxPoint(10, 130),
                                wx.wxSize(120, 24))
		self.xCoord:Connect(XCOORD_ID, wx.wxEVT_COMMAND_TEXT_UPDATED, areaUpdatedEventHandler)

    wx.wxStaticText(WorldSpawnerWindow.panel, wx.wxID_ANY, "Y", wx.wxPoint(140, 110))
    self.yCoord = wx.wxTextCtrl(WorldSpawnerWindow.panel, YCOORD_ID, "-", wx.wxPoint(140, 130),
                                wx.wxSize(120, 24))
		self.yCoord:Connect(YCOORD_ID, wx.wxEVT_COMMAND_TEXT_UPDATED, areaUpdatedEventHandler)

    self.areaType = wx.wxRadioBox(WorldSpawnerWindow.panel, AREA_TYPE_ID, "Area Shape",
                                  wx.wxPoint(10, 160), wx.wxSize(250, 48),
                                  {"Circle", "Rectangle", "Ring"},
                                  1, wx.wxRA_SPECIFY_ROWS)
    self.areaType:Connect(AREA_TYPE_ID, wx.wxEVT_COMMAND_RADIOBOX_SELECTED,
                          function (event)
                          		areaUpdatedEventHandler(event)
                          		enableAreaInfoControls()
                          end)

    self.areaInfo1Text = wx.wxStaticText(WorldSpawnerWindow.panel, LABEL1_ID, "Radius",
                                         wx.wxPoint(10, 210))
    self.areaInfo1Value = wx.wxTextCtrl(WorldSpawnerWindow.panel, INFO1_ID, "-", wx.wxPoint(10, 230),
                                        wx.wxSize(120, 24))
		self.areaInfo1Value:Connect(INFO1_ID, wx.wxEVT_COMMAND_TEXT_UPDATED, areaUpdatedEventHandler)

    self.areaInfo2Text = wx.wxStaticText(WorldSpawnerWindow.panel, LABEL2_ID, "Radius",
                                         wx.wxPoint(140, 210))
    self.areaInfo2Value = wx.wxTextCtrl(WorldSpawnerWindow.panel, INFO2_ID, "-", wx.wxPoint(140, 230),
                                        wx.wxSize(120, 24))
		self.areaInfo2Value:Connect(INFO2_ID, wx.wxEVT_COMMAND_TEXT_UPDATED, areaUpdatedEventHandler)

    disableAreaInfoControls()

    self.mapBitmap = wx.wxBitmap()

    self.areaInfo = nil
end

function WorldSpawnerWindow:getSelectedArea()
		return {
				name = self.areaSelect:GetValue(),
				x = self.xCoord:GetValue(),
				y = self.yCoord:GetValue(),
				size1 = self.areaInfo1Value:GetValue(),
				size2 = self.areaInfo2Value:GetValue(),
				type = self.areaType:GetSelection() + 1
		}
end

function WorldSpawnerWindow:registerAreaUpdatedEventHandler(areaUpdatedEventHandler)
    self.areaUpdatedEventHandler = areaUpdatedEventHandler
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
    self.areaSelect:Enable(true)
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
    enableAreaInfoControls()
    self.selectedArea = area
    self.xCoord:ChangeValue(tostring(area["x"]))
    self.yCoord:ChangeValue(tostring(area["y"]))
    self.areaType:SetSelection(area["type"] - 1)
    self.areaInfo1Value:ChangeValue(tostring(area["size1"]))
    self.areaInfo2Value:ChangeValue(tostring(area["size2"]))
    self.window:Refresh()
end

function WorldSpawnerWindow:show()
    self.window:Show(true)
end

return WorldSpawnerWindow
