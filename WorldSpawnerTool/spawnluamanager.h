#ifndef SPAWNLUAMANAGER_H
#define SPAWNLUAMANAGER_H

#include "LuaParser.h"
#include <QSharedPointer>
#include <QMap>

class PlanetSpawnRegion;
class StaticSpawn;
class LairGroup;

class SpawnLuaManager : public LuaParser {
    static QString currentFile;
    static SpawnLuaManager* runningInstance;

    QMap<QString, LairGroup*> lairGroups;
public:
    SpawnLuaManager();
    ~SpawnLuaManager();

    static int includeFile(lua_State* L);
    static int addDynamicGroup(lua_State* L);
    static int addStaticGroup(lua_State* L);
    static int addLairGroup(lua_State* L);

    QVector<PlanetSpawnRegion*> loadPlanetRegions(const QString& planetName, const QString& serverDirectory);
    QVector<StaticSpawn* > loadStaticSpawns(const QString& planetName, const QString& serverDirectory);
    void loadSpawnGroups(const QString& serverDirectory);

    void saveLairGroups();

    QString serializePlanetRegions(const QList<PlanetSpawnRegion*>& regions, const QString& planet);
    QString serializeStaticSpawns(const QList<QVector<StaticSpawn* >* >& regions, const QString& planet);

    LairGroup* getLairGroup(const QString& name) {
        return lairGroups.value(name, NULL);
    }

    void insertLairGroup(const QString& name, LairGroup* group) {
        lairGroups.insert(name, group);
    }


};

#endif // SPAWNLUAMANAGER_H
