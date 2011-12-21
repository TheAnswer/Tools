#include "lootluamanager.h"

LootLuaManager::LootLuaManager()
{
}


int LootLuaManager::includeFile(lua_State* L) {
    /*QString filename = Lua::getStringParameter(L);

    runFile("scripts/loot/" + filename, L);*/

    return 0;
}

int LootLuaManager::addLootGroupTemplate(lua_State* L) {
  /*  String ascii = lua_tostring(L, -2);
    LuaObject obj(L);

    LuaObject luaItems = obj.getObjectField("lootItems");

    Reference<LootGroup*> group = new LootGroup();

    for (int i = 1; i <= luaItems.getTableSize(); ++i) {
        group->add(luaItems.getStringAt(i));
    }

    luaItems.pop();

    if (instance()->put(ascii, group) != NULL) {
        Logger::console.warning("duplicate loot group template with name " + ascii);
    }*/

    //printf("added loot group template\n");

    return 0;
}

int LootLuaManager::addLootItemTemplate(lua_State* L) {
  /*  String ascii = lua_tostring(L, -2);
    LuaObject obj(L);

    Reference<LootItemTemplate*> item = new LootItemTemplate(ascii);
    item->readObject(&obj);

    if (instance()->lootItemMap.put(ascii, item) != NULL)
        Logger::console.warning("duplicate loot item template with name " + ascii);

    //printf("added loot item template\n");
*/
    return 0;
}
