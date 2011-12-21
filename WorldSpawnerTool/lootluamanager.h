#ifndef LOOTLUAMANAGER_H
#define LOOTLUAMANAGER_H

#include "LuaParser.h"
#include <QMap>
#include "lootitemtemplate.h"

class LootLuaManager : public LuaParser {
    static QString currentFile;

    QMap<QString, LootItemTemplate*> lairTemplates;

public:
    LootLuaManager();

    void reload();

    void registerGlobals();

    static int includeFile(lua_State* L);
    static int addLootGroupTemplate(lua_State* L);
    static int addLootItemTemplate(lua_State* L);

  /*  void addLair(LairTemplate* lair, const QString& name);

    QMap<QString, LairTemplate*>* getLairTemplates() {
        return &lairTemplates;
    }*/


};

#endif // LOOTLUAMANAGER_H
