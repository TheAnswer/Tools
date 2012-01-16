#include "lootluamanager.h"
#include "mainwindow.h"
#include "utils.h"
#include "settings.h"
#include "lootgroup.h"

QString LootLuaManager::currentFile;

LootLuaManager::LootLuaManager()
{
    registerGlobals();

    totalCreatedItemTemplates = 0;
}


int LootLuaManager::includeFile(lua_State* L) {
    QString filename = lua_tostring(L, -1);
    lua_pop(L, 1);

    currentFile = filename;

    QString fullDir = MainWindow::instance->getSettings()->getServerDirectory() + "/bin/scripts/loot/" + filename;

    MainWindow::instance->outputToConsole(fullDir);

    if (luaL_loadfile(L, fullDir.toAscii()) || lua_pcall(L, 0, 0, 0)) {
        const char* err = lua_tostring(L, -1);
        lua_pop(L,1);

        QString data;
        QTextStream msg(&data);

        msg << "file:" << filename << " ERROR " << err;

        MainWindow::instance->outputToConsole(data);
    }


    return 0;
}

void LootLuaManager::registerGlobals() {
    lua_register(L, "includeFile", includeFile);
    lua_register(L, "addLootGroupTemplate", addLootGroupTemplate);
    lua_register(L, "addLootItemTemplate", addLootItemTemplate);

    //Set Globals
    setGlobalInt("AMAZINGSUCCESS", LootItemTemplate::AMAZINGSUCCESS);
    setGlobalInt("GREATSUCCESS", LootItemTemplate::GREATSUCCESS);
    setGlobalInt("GOODSUCCESS", LootItemTemplate::GOODSUCCESS);
    setGlobalInt("MODERATESUCCESS", LootItemTemplate::MODERATESUCCESS);
    setGlobalInt("SUCCESS", LootItemTemplate::SUCCESS);
    setGlobalInt("MARGINALSUCCESS", LootItemTemplate::MARGINALSUCCESS);
    setGlobalInt("OK", LootItemTemplate::OK);
    setGlobalInt("BARELYSUCCESSFUL", LootItemTemplate::BARELYSUCCESSFUL);
    setGlobalInt("CRITICALFAILURE", LootItemTemplate::CRITICALFAILURE);
}

void LootLuaManager::loadLootData() {
    QString serverDirectory = MainWindow::instance->getSettings()->getServerDirectory();

    //Load all the loot items and groups
    runFile(serverDirectory + "/bin/scripts/loot/serverobjects.lua");
}

int LootLuaManager::addLootGroupTemplate(lua_State* L) {
    QString groupName = lua_tostring(L, -2);

    QExplicitlySharedDataPointer<LootGroup> lootGroup(new LootGroup(groupName));
    lootGroup->readObject(L);

    MainWindow::instance->getLootLuaManager()->addLootGroup(lootGroup);

    return 0;
}

void LootLuaManager::addLootGroup(QExplicitlySharedDataPointer<LootGroup> group) {
    lootGroups.insert(group->getGroupName(), group);
}

int LootLuaManager::addLootItemTemplate(lua_State* L) {
    QString itemName = lua_tostring(L, -2);

    QExplicitlySharedDataPointer<LootItemTemplate> lootItemTemplate(new LootItemTemplate(itemName));
    lootItemTemplate->readObject(L);

    MainWindow::instance->getLootLuaManager()->addLootItemTemplate(lootItemTemplate);

    return 0;
}

void LootLuaManager::addLootItemTemplate(QExplicitlySharedDataPointer<LootItemTemplate> item) {
    lootItems.insert(item->getItemName(), item);
}

void LootLuaManager::saveLootGroup(QExplicitlySharedDataPointer<LootGroup> group) {
    //Save the group to the map.
    lootGroups[group->getGroupName()] = group;

    //Write the group to script.
}


QExplicitlySharedDataPointer<LootItemTemplate> LootLuaManager::createLootItemTemplate() {
    QString name("untitled");

    if (totalCreatedItemTemplates > 0)
        name += "_" + QString::number(totalCreatedItemTemplates);

    QExplicitlySharedDataPointer<LootItemTemplate> newTemplate(new LootItemTemplate(name));

    lootItems.insert(name, newTemplate);

    ++totalCreatedItemTemplates;

    return newTemplate;
}

QExplicitlySharedDataPointer<LootGroup> LootLuaManager::createLootGroup(const QString& groupName) {
    QExplicitlySharedDataPointer<LootGroup> group(new LootGroup(groupName));
    lootGroups.insert(groupName, group);
    return group;
}

void LootLuaManager::deleteLootItemTemplate(QExplicitlySharedDataPointer<LootItemTemplate> item) {
    lootItems.remove(item->getItemName());

    QVector<QString> groups = item->getLootGroups();

    for (int i = 0; i < groups.count(); ++i) {
        QExplicitlySharedDataPointer<LootGroup> group = lootGroups.value(groups.at(i));

        group->removeLootItemTemplate(item->getItemName());
    }
}

void LootLuaManager::deleteLootGroup(const QString& groupName) {
    lootGroups.remove(groupName);
}

void LootLuaManager::removeItemFromGroup(const QString& itemName, const QString& groupName) {
    QExplicitlySharedDataPointer<LootItemTemplate> itemTemplate = getItemTemplate(itemName);
    QExplicitlySharedDataPointer<LootGroup> lootGroup = getLootGroup(groupName);

    itemTemplate->unregisterLootGroup(groupName);
    lootGroup->removeLootItemTemplate(itemName);
}

void LootLuaManager::writeLootGroups() {
    QString outputDirectory = MainWindow::instance->getSettings()->getServerDirectory() + "/bin/scripts/loot/";

    QString fileName = outputDirectory + "groups.lua";

    QFile groupsFile(fileName);

    if (!groupsFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        MainWindow::instance->outputToConsole("WARNING: Could not open groups.lua for writing. Exiting...");
        return;
    }

    QTextStream outGroups(&groupsFile);

    QMapIterator<QString, QExplicitlySharedDataPointer<LootGroup> > i(lootGroups);

    while (i.hasNext()) {
        i.next();

        QExplicitlySharedDataPointer<LootGroup> group = i.value();
        QString groupFileName = outputDirectory + "groups/" + i.key() + ".lua";

        QFile groupFile(groupFileName);

        if (!groupFile.open(QIODevice::WriteOnly | QIODevice::Text))
            continue;

        QString data = group->serializeToLua();

        QTextStream out(&groupFile);
        out << "--Automatically generated by " << MainWindow::instance->getApplicationFullName() << " loot editor." << endl << endl;
        out << data;

        groupFile.close();

        outGroups << "includeFile(\"groups/" + i.key() + ".lua\")" << endl;
    }

    groupsFile.close();

}

void LootLuaManager::writeLootItemTemplates() {
    QString outputDirectory = MainWindow::instance->getSettings()->getServerDirectory() + "/bin/scripts/loot/";

    QString fileName = outputDirectory + "items.lua";

    QFile itemsFile(fileName);

    if (!itemsFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        MainWindow::instance->outputToConsole("WARNING: Could not open items.lua for writing. Exiting...");
        return;
    }

    QTextStream outItems(&itemsFile);

    QMapIterator<QString, QExplicitlySharedDataPointer<LootItemTemplate> > i(lootItems);

    while (i.hasNext()) {
        i.next();

        QExplicitlySharedDataPointer<LootItemTemplate> item = i.value();
        QString itemFileName = outputDirectory + "items/" + i.key() + ".lua";

        QFile itemFile(itemFileName);

        if (!itemFile.open(QIODevice::WriteOnly | QIODevice::Text))
            continue;
        QString data = item->serializeToLua();

        QTextStream out(&itemFile);
        out << "--Automatically generated by " << MainWindow::instance->getApplicationFullName() << " loot editor." << endl << endl;
        out << data;

        itemFile.close();

        outItems << "includeFile(\"items/" + i.key() + ".lua\")" << endl;
    }

    itemsFile.close();
}
