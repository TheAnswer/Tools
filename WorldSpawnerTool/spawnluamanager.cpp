#include "spawnluamanager.h"
#include "planetspawnregion.h"
#include "staticspawn.h"
#include "mainwindow.h"
#include "utils.h"
#include "CreatureObject.h"
#include "settings.h"
#include "lairgroup.h"

using namespace utils;

QString SpawnLuaManager::currentFile;
SpawnLuaManager* SpawnLuaManager::runningInstance = NULL;

SpawnLuaManager::SpawnLuaManager() {
    runningInstance = this;

    lua_register(L, "includeFile", includeFile);
    lua_register(L, "addDynamicGroup", addDynamicGroup);
    lua_register(L, "addStaticGroup", addStaticGroup);
    lua_register(L, "addLairGroup", addLairGroup);

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

    setGlobalInt("CARNIVORE", CreatureObject::CARNIVORE);
    setGlobalInt("HERBIVORE", CreatureObject::HERBIVORE);
}

SpawnLuaManager::~SpawnLuaManager() {
    QMapIterator<QString, LairGroup*> i(lairGroups);

    while (i.hasNext()) {
       i.next();

       delete i.value();
    }
}

QVector<PlanetSpawnRegion*> SpawnLuaManager::loadPlanetRegions(const QString& planetName, const QString& serverDirectory) {
    QVector<PlanetSpawnRegion*> regions;

    runFile(serverDirectory + "/bin/scripts/managers/spawn_manager/" + planetName + ".lua");

    lua_getglobal(L, QString(planetName + "_regions").toAscii());

    if (!lua_istable(L, -1)) {
        lua_pop(L, 1);
        return regions;
    }

    int tableSize = luaL_getn(L, -1);

    for (int i = 1; i <= tableSize; ++i) {
        lua_rawgeti(L, -1, i);

        if (lua_istable(L, -1)) {
            QString name = getStringAt(1);
            float x = getFloatAt(2);
            float y = getFloatAt(3);
            float radius = getFloatAt(4);
            int tier = getIntAt(5);
            int constant = getIntAt(6);

            PlanetSpawnRegion* region = new PlanetSpawnRegion();
            region->setRegionName(name);
            region->setWorldX(x);
            region->setWorldY(y);
            region->setRadius(radius);
            region->setTier(tier);
            region->setConstant(constant);

            int spawnsSize = luaL_getn(L, -1);

            for (int j = 7; j <= spawnsSize; ++j)
                region->addSpawn(getStringAt(j));

            regions.append(region);
        }

        lua_pop(L, 1);
    }

    lua_pop(L, 1);

    return regions;
}

void SpawnLuaManager::saveLairGroups() {
    QString serverDir = MainWindow::instance->getSettings()->getServerDirectory();


    QFile objectFile(serverDir + "/bin/scripts/mobile/spawn/serverobjects.lua");
    if (!objectFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
        MainWindow::instance->warning("could not open file " + serverDir + "/bin/scripts/mobile/spawn/serverobjects.lua");
    }

    QByteArray oldData = objectFile.readAll();

    QMapIterator<QString, LairGroup*> i(lairGroups);

    while (i.hasNext()) {
        i.next();

        LairGroup* lairGroup = i.value();

        QString fileName = lairGroup->getFileName();

        if (fileName.isEmpty())
            fileName = "spawn/" + i.key() + ".lua";

        QString data = lairGroup->serializeToLua();

        if (oldData.contains(fileName.toAscii())) {
            MainWindow::instance->outputToConsole("include contains " + fileName);
        } else {
            objectFile.seek(objectFile.size() - 1);

            QTextStream stream(&objectFile);
            stream << endl;
            stream << "includeFile(\"" + fileName + "\")";
        }

        /*MainWindow::instance->outputToConsole(fileName);
        MainWindow::instance->outputToConsole(data);*/

        QString fullFileName = serverDir + "/bin/scripts/mobile/" + fileName;

        QFile file(fullFileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            MainWindow::instance->outputToConsole(data);

            QTextStream outFile(&file);
            outFile << data;

            file.close();

            //templ->setFileName(fileName);
        } else {
            MainWindow::instance->warning("could not open file " + fullFileName);
        }

        MainWindow::instance->outputToConsole(fullFileName);

        //QStri
    }

    /*QTextStream outInclude(&objectFile);
    objectFile << oldData;*/

    objectFile.close();

}

QVector<StaticSpawn* > SpawnLuaManager::loadStaticSpawns(const QString& planetName, const QString& serverDirectory) {
    QVector<StaticSpawn* > spawns;

    lua_getglobal(L, QString(planetName + "_static_spawns").toAscii());

    if (!lua_istable(L, -1)) {
        lua_pop(L, 1);
        return spawns;
    }

    int tableSize = luaL_getn(L, -1);

    for (int i = 1; i <= tableSize; ++i) {
        lua_rawgeti(L, -1, i);

        if (lua_istable(L, -1)) {
            QString name = getStringAt(1);
            unsigned int respawn = getIntAt(2);
            float x = getFloatAt(3);
            float z = getFloatAt(4);
            float y = getFloatAt(5);
            float heading = getFloatAt(6);
            lua_rawgeti(L, -1, 7);
            uint64 parentID = (uint64)lua_tonumber(L, -1);
            lua_pop(L, 1);

            StaticSpawn* spawn(new StaticSpawn());
            spawn->setMobile(name);
            spawn->setWorldX(x);
            spawn->setWorldY(y);
            spawn->setWorldZ(z);
            spawn->setHeading(heading);
            spawn->setParentID(parentID);
            spawn->setRespawnTimer(respawn);

            spawns.append(spawn);
        }

        lua_pop(L, 1);
    }

    lua_pop(L, 1);

    return spawns;
}

void SpawnLuaManager::loadSpawnGroups(const QString& serverDirectory) {
    runFile(serverDirectory + "/bin/scripts/mobile/spawn/serverobjects.lua");
}

QString SpawnLuaManager::serializePlanetRegions(const QList<PlanetSpawnRegion*>& regions, const QString& planet) {
    QString data;
    QTextStream stream(&data);

    stream << planet << "_regions = {" << endl;

    for (int i = 0; i < regions.size(); ++i) {
        stream << "\t" << regions.at(i)->toLua() << "," << endl;
    }

    stream << "}";

    return data;
}

QString SpawnLuaManager::serializeStaticSpawns(const QList<QVector<StaticSpawn* >* >& regions, const QString& planet) {
    QString data;
    QTextStream stream(&data);

    stream << planet << "_static_spawns = {" << endl;

    for (int i = 0; i < regions.size(); ++i) {
        QVector<StaticSpawn*>* spawns = regions.at(i);

        for (int j = 0; j < spawns->size(); ++j) {
            stream << "\t" << spawns->at(j)->toLua() << "," << endl;
        }
    }

    stream << "}";

    return data;
}

int SpawnLuaManager::includeFile(lua_State* L) {
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


int SpawnLuaManager::addDynamicGroup(lua_State* L) {
    /*String ascii = lua_tostring(L, -2);
    uint32 crc = (uint32) ascii.hashCode();

    LuaObject obj(L);
    CreatureTemplateManager::instance()->dynamicGroupMap.put(crc, new DynamicSpawnGroup(ascii, obj));*/

    return 0;
}

int SpawnLuaManager::addStaticGroup(lua_State* L) {
    /*String ascii = lua_tostring(L, -2);
    uint32 crc = (uint32) ascii.hashCode();

    LuaObject obj(L);
    CreatureTemplateManager::instance()->staticGroupMap.put(crc, new StaticSpawnGroup(ascii, obj));*/

    return 0;
}

int SpawnLuaManager::addLairGroup(lua_State* L) {
    QString ascii =  lua_tostring(L, -2);
    //unsigned int crc = (unsigned int) Utils::hashCode(ascii);

    MainWindow::instance->outputToConsole("inserting lair group " + ascii);

    LairGroup* group = new LairGroup(ascii);
    group->setFileName(currentFile);
    group->readObject(L);

    SpawnLuaManager::runningInstance->lairGroups.insert(ascii, group);

    return 0;
}

