#ifndef COMMANDS_H
#define COMMANDS_H

#include <QUndoCommand>
#include "utils.h"

using namespace utils;

class StaticSpawn;
class Spawn;
class PlanetSpawnRegion;
class Badge;

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
    QString oldMood, newMood;
    QString oldName, newName;

public:
    StaticSpawnChangeCommand(StaticSpawn* spawn, uint32 newRespawnTimer, float newHeading, uint64 newParentID, const QString& newMood, const QString& newName);

    void undo();
    void redo();

};

class BadgeChangedCommand : public QUndoCommand {
    Badge* badge;

    float oldRadius, newRadius;
    int oldID, newID;

public:
    BadgeChangedCommand(Badge* badge, int newID, float newRadius);

    void undo();
    void redo();
};

class InsertBadgeCommand : public QUndoCommand {
    Badge* badge;
    bool undid;
public:
    InsertBadgeCommand(Badge* badge);
    ~InsertBadgeCommand();

    void undo();
    void redo();
};

class RemoveBadgeCommand : public QUndoCommand {
  Badge* badge;
  bool undid;
public:
  RemoveBadgeCommand(Badge* badge);
  ~RemoveBadgeCommand();

  void undo();
  void redo();
};

#endif // COMMANDS_H
