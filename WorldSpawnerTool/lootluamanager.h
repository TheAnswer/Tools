#ifndef LOOTLUAMANAGER_H
#define LOOTLUAMANAGER_H

#include "LuaParser.h"
#include <QMap>
#include <QExplicitlySharedDataPointer>
#include "lootitemtemplate.h"
#include "lootgroup.h"

class LootLuaManager : public LuaParser {
    static QString currentFile;

    QMap<QString, QExplicitlySharedDataPointer<LootItemTemplate> > lootItems;
    QMap<QString, QExplicitlySharedDataPointer<LootGroup> > lootGroups;

    int totalCreatedItemTemplates;

public:
    LootLuaManager();

    void reload();

    void registerGlobals();

    static int includeFile(lua_State* L);
    static int addLootGroupTemplate(lua_State* L);
    static int addLootItemTemplate(lua_State* L);

    void writeLootGroups();
    void writeLootItemTemplates();

    QExplicitlySharedDataPointer<LootItemTemplate> createLootItemTemplate();
    void deleteLootItemTemplate(QExplicitlySharedDataPointer<LootItemTemplate>);

    QExplicitlySharedDataPointer<LootGroup> createLootGroup(const QString& groupName);
    void deleteLootGroup(const QString& groupName);

    void addLootGroup(QExplicitlySharedDataPointer<LootGroup> group);
    void addLootItemTemplate(QExplicitlySharedDataPointer<LootItemTemplate> item);

    void removeItemFromGroup(const QString& itemName, const QString& groupName);

    void saveLootGroup(QExplicitlySharedDataPointer<LootGroup> group);

    inline QExplicitlySharedDataPointer<LootItemTemplate> getItemTemplate(const QString& itemName) {
        return lootItems.value(itemName);
    }

    inline QExplicitlySharedDataPointer<LootGroup> getLootGroup(const QString& groupName) {
        return lootGroups.value(groupName);
    }

    inline bool itemTemplateExists(const QString& itemName) {
        return lootItems.contains(itemName);
    }

    inline bool lootGroupExists(const QString& groupName) {
        return lootGroups.contains(groupName);
    }

    void loadLootData();

    inline int getTotalGroups() {
        return lootGroups.count();
    }

    inline QMap<QString, QExplicitlySharedDataPointer<LootGroup> > getLootGroups() {
        return lootGroups;
    }

    inline QMap<QString, QExplicitlySharedDataPointer<LootItemTemplate> > getLootItems() {
        return lootItems;
    }
};

#endif // LOOTLUAMANAGER_H
