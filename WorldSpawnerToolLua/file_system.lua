-- File System
--
-- Various functions for interacting with the file system, like listing files in a directory, writing
-- and reading files etc.

require("object")
StringOperations = require("string_operations")
require("table_or_item")

LEFT_PART = 1
RIGHT_PART = 2

FileSystem = Object:new {}

-- Return the file name of a file path.
--  * param filePath the full file path. Supports table of file paths as well.
--  * returns the file name.
function FileSystem:getFileName(filePath)
    return tableOrItem(filePath, function (fp) return StringOperations:splitString(fp, RIGHT_PART, "/") end)
end

-- Return the file name without extension of a file path.
--  * param filePath the full file path. Supports table of file paths as well.
--  * returns the file name without extension.
function FileSystem:getFileNameWithoutExtension(filePath)
    filePath = self:getFileName(filePath)
    return tableOrItem(filePath, function (fp) return StringOperations:splitString(fp, LEFT_PART, "%.", 1) end)
end

-- List the files in a directory.
--  * param directory the directory to list the files in.
--  * returns a list of the files in the directory.
function FileSystem:listFiles(directory, pattern)
    local files = {}
    local dir = io.popen('find "' .. directory .. '" -maxdepth 1 -name "' .. pattern .. '" -type f')
    for f in dir:lines() do
        table.insert(files, f)
    end
    dir:close()
    return files
end

return FileSystem
