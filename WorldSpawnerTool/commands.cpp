#include "commands.h"
#include <QtGui>
#include "mainwindow.h"
#include "staticspawn.h"
#include "worldmap.h"
#include "planetspawnregion.h"

InsertStaticSpawnCommand::InsertStaticSpawnCommand(StaticSpawn* spawn, QUndoCommand* parent) : QUndoCommand(parent) {
    this->spawn = spawn;

    undid = false;

    setText("Insert: static spawn " + spawn->getMobile());
}

InsertStaticSpawnCommand::~InsertStaticSpawnCommand() {
    if (undid) {
        delete spawn;
        spawn = NULL;
    }
}

void InsertStaticSpawnCommand::undo() {
    MainWindow::instance->removeStaticSpawn(spawn);

    undid = true;
}

void InsertStaticSpawnCommand::redo() {
    MainWindow::instance->insertStaticSpawn(spawn);

    undid = false;
}

RemoveStaticSpawnCommand::RemoveStaticSpawnCommand(StaticSpawn* spawn, QUndoCommand* parent) : QUndoCommand(parent) {
    this->spawn = spawn;

    undid = false;

    setText("Remove: static spawn " + spawn->getMobile());
}

RemoveStaticSpawnCommand::~RemoveStaticSpawnCommand() {
    if (!undid) {
        delete spawn;
        spawn = NULL;
    }
}

void RemoveStaticSpawnCommand::undo() {
    MainWindow::instance->insertStaticSpawn(spawn);

    undid = true;
}

void RemoveStaticSpawnCommand::redo() {
    MainWindow::instance->removeStaticSpawn(spawn);

    undid = false;
}

SpawnMoveCommand::SpawnMoveCommand(Spawn* spawn, float newX, float newY, float newZ) : QUndoCommand(NULL) {
    this->spawn = spawn;
    setText("Move Spawn");

    newWorldX = newX;
    newWorldY = newY;
    newWorldZ = newZ;
    oldWorldX = spawn->getWorldX();
    oldWorldZ = spawn->getWorldZ();
    oldWorldY = spawn->getWorldY();
}

void SpawnMoveCommand::undo() {
    if (oldWorldX != spawn->getWorldX())
        spawn->setWorldX(oldWorldX);

    if (oldWorldZ != spawn->getWorldZ())
        spawn->setWorldZ(oldWorldZ);

    if (oldWorldY != spawn->getWorldY())
        spawn->setWorldY(oldWorldY);
}

void SpawnMoveCommand::redo() {
    if (newWorldX != spawn->getWorldX())
        spawn->setWorldX(newWorldX);

    if (newWorldY != spawn->getWorldY())
        spawn->setWorldY(newWorldY);

    if (newWorldZ != spawn->getWorldZ())
        spawn->setWorldZ(newWorldZ);
}

PlanetSpawnRegionChangeCommand::PlanetSpawnRegionChangeCommand(PlanetSpawnRegion* region, int newTier, int newConstant, float newRadius) {
    this->region = region;

    oldTier = region->getTier();
    this->newTier = newTier;

    oldConstant = region->getConstant();
    this->newConstant = newConstant;

    oldRadius = region->getRadius();
    this->newRadius = newRadius;

    setText("PlanetSpawnRegion Change");
}

void PlanetSpawnRegionChangeCommand::undo() {
    if (oldTier != region->getTier())
        region->setTier(oldTier);

    if (oldConstant != region->getConstant())
        region->setConstant(oldConstant);

    if (oldRadius != region->getRadius())
        region->setRadius(oldRadius);
}

void PlanetSpawnRegionChangeCommand::redo() {
    if (newTier != region->getTier()) {
        region->setTier(newTier);
    }

    if (newConstant != region->getConstant()) {
        region->setConstant(newConstant);
    }

    if (newRadius != region->getRadius())
        region->setRadius(newRadius);
}

StaticSpawnChangeCommand::StaticSpawnChangeCommand(StaticSpawn* spawn, uint32 newRespawnTimer, float newHeading, uint64 newParentID) {
    setText("StaticSpawn change");

    this->spawn = spawn;

    oldRespawnTimer = spawn->getRespawnTimer();
    oldHeading = spawn->getHeading();
    oldParentID = spawn->getParentID();

    this->newHeading = newHeading;
    this->newParentID = newParentID;
    this->newRespawnTimer = newRespawnTimer;
}

void StaticSpawnChangeCommand::undo() {
    if (oldRespawnTimer != spawn->getRespawnTimer())
        spawn->setRespawnTimer(oldRespawnTimer);

    if (oldHeading != spawn->getHeading())
        spawn->setHeading(oldHeading);

    if (oldParentID != spawn->getParentID())
        spawn->setParentID(oldParentID);
}

void StaticSpawnChangeCommand::redo() {
    if (newRespawnTimer != spawn->getRespawnTimer())
        spawn->setRespawnTimer(newRespawnTimer);

    if (newHeading != spawn->getHeading())
        spawn->setHeading(newHeading);

    if (newParentID != spawn->getParentID())
        spawn->setParentID(newParentID);
}

