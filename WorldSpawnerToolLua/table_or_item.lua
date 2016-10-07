-- Table or single item.

-- Function to process a table of items or a single item.
-- Can handle nested tables.
--  * param tableOrSingleItem the table or the item to perform the operation on.
--  * param operation a function that transforms the item.
--  * returns the transformed item(s).
function tableOrItem(tableOrSingleItem, operation)
    if type(tableOrSingleItem) == "table" then
        for key, value in pairs(tableOrSingleItem) do
            tableOrSingleItem[key] = tableOrItem(value, operation)
        end
    else
        tableOrSingleItem = operation(tableOrSingleItem)
    end
    return tableOrSingleItem
end