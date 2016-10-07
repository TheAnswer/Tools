-- File System
-- 
-- Various functions for interacting with the file system, like listing files in a directory, writing
-- and reading files etc.

require("object")
require("table_or_item")

LEFT_PART = 1
RIGHT_PART = 2

FileSystem = Object:new {}

-- Split a string and return the text to the left or to the right of the last occurance of the 
-- specified pattern.
--  * param text the text to search and return the remainder of.
--  * param left indication if it is the left part that should be returned (LEFT_PART) or 
--               right part (RIGHT_PART).
--  * param pattern the pattern to split the string at.
--  * param patternLength the length of the pattern, if string.len does not work in case of 
--                        escape characters
--  * returns the remainder of the string.
local function splitString(text, leftRight, pattern, patternLength)
    patternLength = patternLength or pattern:len() -- Default value for patternLength.
    
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
end

-- Return the file name of a file path.
--  * param filePath the full file path. Supports table of file paths as well.
--  * returns the file name.
function FileSystem:getFileName(filePath)
    return tableOrItem(filePath, function (fp) return splitString(fp, RIGHT_PART, "/") end)
end

-- Return the file name without extension of a file path.
--  * param filePath the full file path. Supports table of file paths as well.
--  * returns the file name without extension.
function FileSystem:getFileNameWithoutExtension(filePath)
    filePath = self:getFileName(filePath)
    return tableOrItem(filePath, function (fp) return splitString(fp, LEFT_PART, "%.", 1) end)
end

-- List the files in a directory.
--  * param directory the directory to list the files in.
--  * returns a list of the files in the directory.
function FileSystem:listFiles(directory)
    local files = {}
    local dir = io.popen('find "' .. directory .. '" -maxdepth 1 -type f')
    for f in dir:lines() do
        table.insert(files, f)
    end
    dir:close()
    return files
end

return FileSystem