-- Metatable setup to be able to create classes in other files.

Object = {}

-- For creation of new instances
function Object:new (o)
	o = o or { }
	setmetatable(o, self)
    self.__index = self
    return o
end
