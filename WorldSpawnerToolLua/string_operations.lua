-- String Operations
--
-- Various functions for string manipulations.

require("object")
require("table_or_item")

StringOperations = Object:new {}

function StringOperations:capitalizeFirstCharacter(text)
    return tableOrItem(text, function (t) return t:gsub("^%l", string.upper) end)
end

-- Check if a text ends with a specific pattern.
--  * param text the text to search for the pattern in.
--  * param pattern the pattern to search for.
--  * returns true if the pattern is found in the end of the text.
function StringOperations:endswith(text, pattern)
    return string.sub(text, -pattern:len()) == pattern
end

-- Check if a text starts with a specific pattern.
--  * param text the text to search for the pattern in.
--  * param pattern the pattern to search for.
--  * returns true if the pattern is found in the beginning of the text.
function StringOperations:startswith(text, pattern)
    return string.sub(text, 1, pattern:len()) == pattern
end

return StringOperations
