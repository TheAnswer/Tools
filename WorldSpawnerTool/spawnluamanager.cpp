#include "spawnluamanager.h"
#include "planetspawnregion.h"
#include "staticspawn.h"
#include "mainwindow.h"
#include "utils.h"

using namespace utils;

SpawnLuaManager::SpawnLuaManager() {
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
