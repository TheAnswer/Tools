#include "creatureluamanager.h"
#include "CreatureObject.h"
#include "utils.h"
#include "mainwindow.h"
#include "creaturemanager.h"
#include "settings.h"

using namespace utils;

QString CreatureLuaManager::currentFile;

CreatureLuaManager::CreatureLuaManager() {
    registerGlobals();
}


void CreatureLuaManager::registerGlobals() {
    lua_register(L, "includeFile", includeFile);
    lua_register(L, "addTemplate", addTemplate);
    lua_register(L, "addWeapon", addWeapon);
    lua_register(L, "addDynamicGroup", addDynamicGroup);
    lua_register(L, "addStaticGroup", addStaticGroup);
    lua_register(L, "addConversationTemplate", addConversationTemplate);

    setGlobalInt("NONE", 0);
    setGlobalInt("ATTACKABLE", CreatureObject::ATTACKABLE);
    setGlobalInt("AGGRESSIVE", CreatureObject::AGGRESSIVE);
    setGlobalInt("OVERT", CreatureObject::OVERT);
    //setGlobalInt("TEF", CreatureObject::TEF);
    //setGlobalInt("PLAYER", CreatureObject::PLAYER);
    setGlobalInt("ENEMY", CreatureObject::ENEMY);
    /*setGlobalInt("CHANGEFACTIONSTATUS", CreatureObject::CHANGEFACTIONSTATUS);
    setGlobalInt("BLINK_GREEN", CreatureObject::BLINK_GREEN);*/

    setGlobalInt("PACK", CreatureObject::PACK);
    setGlobalInt("HERD", CreatureObject::HERD);
    setGlobalInt("KILLER", CreatureObject::KILLER);
    setGlobalInt("STALKER", CreatureObject::STALKER);
    setGlobalInt("BABY", CreatureObject::BABY);
    setGlobalInt("LAIR", CreatureObject::LAIR);
    setGlobalInt("HEALER", CreatureObject::HEALER);

    setGlobalInt("CARNIVORE", CreatureObject::CARNIVORE);
    setGlobalInt("HERBIVORE", CreatureObject::HERBIVORE);

}

int CreatureLuaManager::includeFile(lua_State* L) {
    QString filename = lua_tostring(L, -1);
    lua_pop(L, 1);

    //MainWindow::instance->getCreatureManager()->setCurrentFileName()
    currentFile = filename;

    QString fullDir = MainWindow::instance->getSettings()->getServerDirectory() + "/bin/scripts/mobile/" + filename;

   // MainWindow::instance->outputToConsole(fullDir);

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

int CreatureLuaManager::addWeapon(lua_State *L) {
    QString ascii = lua_tostring(L, -2);
    //unsigned int crc = (unsigned int) Utils::hashCode(ascii);

    QVector<QString> weps;

    int weaponsTableSize = luaL_getn(L, -1);

    for (int i = 1; i <= weaponsTableSize; ++i) {
        lua_rawgeti(L, -1, i);
        const char* result = lua_tostring(L, -1);
        lua_pop(L, 1);

        weps.append(QString(result));
    }

    /*CreatureTemplateManager::instance()->weaponMap.put(crc, weps);
    }*/

    return 0;
}

int CreatureLuaManager::addDynamicGroup(lua_State* L) {
    /*String ascii = lua_tostring(L, -2);
    uint32 crc = (uint32) ascii.hashCode();

    LuaObject obj(L);
    CreatureTemplateManager::instance()->dynamicGroupMap.put(crc, new DynamicSpawnGroup(ascii, obj));*/

    return 0;
}

int CreatureLuaManager::addStaticGroup(lua_State* L) {
    /*String ascii = lua_tostring(L, -2);
    uint32 crc = (uint32) ascii.hashCode();

    LuaObject obj(L);
    CreatureTemplateManager::instance()->staticGroupMap.put(crc, new StaticSpawnGroup(ascii, obj));*/

    return 0;
}

int CreatureLuaManager::addTemplate(lua_State* L) {
    QString ascii =  lua_tostring(L, -2);
    //unsigned int crc = (unsigned int) Utils::hashCode(ascii);

    CreatureObject* creature = new CreatureObject(ascii);
    creature->setFileName(currentFile);
    creature->readObject(L);
    //creature->

    MainWindow::instance->getCreatureManager()->addCreatureObject(ascii, creature);

    //MainWindow::instance->outputToConsole(ascii);

    /*LuaObject obj(L);
        CreatureTemplate* newTemp = new CreatureTemplate();
        newTemp->setTemplateName(ascii);
        newTemp->readObject(&obj);

        CreatureTemplateManager::instance()->put(crc, newTemp);*/

    return 0;
}

int CreatureLuaManager::addConversationTemplate(lua_State* L) {
    return 0;
}
