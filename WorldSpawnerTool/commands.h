#ifndef COMMANDS_H
#define COMMANDS_H

#include <QUndoCommand>
#include "utils.h"

using namespace utils;

class StaticSpawn;
class Spawn;
class PlanetSpawnRegion;

class InsertStaticSpawnCommand : public QUndoCommand {
    StaticSpawn* spawn;
    bool undid;

public:
    InsertStaticSpawnCommand(StaticSpawn* spawn, QUndoCommand* parent = NULL);
    ~InsertStaticSpawnCommand();

    void undo();
    void redo();
};

class RemoveStaticSpawnCommand : public QUndoCommand {
    StaticSpawn* spawn;
    bool undid;

public:
    RemoveStaticSpawnCommand(StaticSpawn* spawn, QUndoCommand* parent = NULL);
    ~RemoveStaticSpawnCommand();

    void undo();
    void redo();
};

class SpawnMoveCommand : public QUndoCommand {
    float newWorldX, newWorldY, newWorldZ;
    float oldWorldX, oldWorldY, oldWorldZ;
    Spawn* spawn;
public:
    SpawnMoveCommand(Spawn* spawn, float newX, float newY, float newZ);

    void undo();
    void redo();

};

class PlanetSpawnRegionChangeCommand : public QUndoCommand {
    int oldTier;
    int newTier;
    int oldConstant;
    int newConstant;
    float oldRadius, newRadius;
    PlanetSpawnRegion* region;

public:
    PlanetSpawnRegionChangeCommand(PlanetSpawnRegion* region, int newTier, int newConstant, float newRadius);

    void undo();
    void redo();
};

class StaticSpawnChangeCommand : public QUndoCommand {
    StaticSpawn* spawn;

    uint32 oldRespawnTimer, newRespawnTimer;
    float oldHeading, newHeading;
    uint64 oldParentID, newParentID;

public:
    StaticSpawnChangeCommand(StaticSpawn* spawn, uint32 newRespawnTimer, float newHeading, uint64 newParentID);

    void undo();
    void redo();

};



#endif // COMMANDS_H
