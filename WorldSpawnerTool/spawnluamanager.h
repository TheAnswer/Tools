#ifndef SPAWNLUAMANAGER_H
#define SPAWNLUAMANAGER_H

#include "LuaParser.h"
#include <QSharedPointer>

class PlanetSpawnRegion;
class StaticSpawn;

class SpawnLuaManager : public LuaParser {
public:
    SpawnLuaManager();

    QVector<PlanetSpawnRegion*> loadPlanetRegions(const QString& planetName, const QString& serverDirectory);
    QVector<StaticSpawn* > loadStaticSpawns(const QString& planetName, const QString& serverDirectory);

    QString serializePlanetRegions(const QList<PlanetSpawnRegion*>& regions, const QString& planet);
    QString serializeStaticSpawns(const QList<QVector<StaticSpawn* >* >& regions, const QString& planet);
};

#endif // SPAWNLUAMANAGER_H
