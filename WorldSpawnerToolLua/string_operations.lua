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

-- Split a string and return the text to the left or to the right of the last occurance of the
-- specified pattern.
--  * param text the text to search and return the remainder of.
--  * param left indication if it is the left part that should be returned (LEFT_PART) or
--               right part (RIGHT_PART).
--  * param pattern the pattern to split the string at.
--  * param patternLength the length of the pattern, if string.len does not work in case of
--                        escape characters
--  * returns the remainder of the string.
function StringOperations:splitString(text, leftRight, pattern, patternLength)
    patternLength = patternLength or pattern:len() -- Default value for patternLength.

		return tableOrItem(text, function (text)
		    local lastPatternPosition = 0
		    local done = false
		    while not done do
		        local patternPosition = string.find(text, pattern, lastPatternPosition)
		        if patternPosition then
		            lastPatternPosition = patternPosition + patternLength
		        else
		            done = true
		        end
		    end

		    if leftRight == LEFT_PART then
		        return text:sub(1, lastPatternPosition - 1 - patternLength)
		    else
		        return text:sub(lastPatternPosition)
		    end
		end)
end

-- Check if a text starts with a specific pattern.
--  * param text the text to search for the pattern in.
--  * param pattern the pattern to search for.
--  * returns true if the pattern is found in the beginning of the text.
function StringOperations:startswith(text, pattern)
    return string.sub(text, 1, pattern:len()) == pattern
end

return StringOperations
