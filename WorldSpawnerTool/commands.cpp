#include "commands.h"
#include <QtGui>
#include "mainwindow.h"
#include "staticspawn.h"
#include "worldmap.h"
#include "planetspawnregion.h"
#include "badge.h"

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

InsertBadgeCommand::InsertBadgeCommand(Badge* badge) {
  this->badge = badge;
  undid = false;

  setText("Insert: badge " + badge->getName());
}

InsertBadgeCommand::~InsertBadgeCommand() {
  if (undid) {
      delete badge;
      badge = NULL;
  }
}

void InsertBadgeCommand::undo() {
  MainWindow::instance->removeBadge(badge);

  undid = true;
}

void InsertBadgeCommand::redo() {
  MainWindow::instance->insertBadge(badge);

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

RemoveBadgeCommand::RemoveBadgeCommand(Badge* badge) {
  this->badge = badge;

  undid = false;

  setText("Remove: badge " + badge->getName());
}

RemoveBadgeCommand::~RemoveBadgeCommand() {
  if (!undid) {
      delete badge;
      badge = NULL;
  }
}

void RemoveBadgeCommand::undo() {
  MainWindow::instance->insertBadge(badge);

  undid = true;
}

void RemoveBadgeCommand::redo() {
  MainWindow::instance->removeBadge(badge);

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

StaticSpawnChangeCommand::StaticSpawnChangeCommand(StaticSpawn* spawn, uint32 newRespawnTimer, float newHeading, uint64 newParentID, const QString& newMood, const QString& newName) {
    setText("StaticSpawn change");

    this->spawn = spawn;

    oldRespawnTimer = spawn->getRespawnTimer();
    oldHeading = spawn->getHeading();
    oldParentID = spawn->getParentID();
    oldName = spawn->getCustomName();
    oldMood = spawn->getMoodString();

    this->newHeading = newHeading;
    this->newParentID = newParentID;
    this->newRespawnTimer = newRespawnTimer;
    this->newMood = newMood;
    this->newName = newName;
}

void StaticSpawnChangeCommand::undo() {
    if (oldRespawnTimer != spawn->getRespawnTimer())
        spawn->setRespawnTimer(oldRespawnTimer);

    if (oldHeading != spawn->getHeading())
        spawn->setHeading(oldHeading);

    if (oldParentID != spawn->getParentID())
        spawn->setParentID(oldParentID);

    if (oldMood != spawn->getMoodString())
        spawn->setMoodString(oldMood);

    if (oldName != spawn->getCustomName())
        spawn->setCustomName(oldName);
}

void StaticSpawnChangeCommand::redo() {
    if (newRespawnTimer != spawn->getRespawnTimer())
        spawn->setRespawnTimer(newRespawnTimer);

    if (newHeading != spawn->getHeading())
        spawn->setHeading(newHeading);

    if (newParentID != spawn->getParentID())
        spawn->setParentID(newParentID);

    if (newName != spawn->getCustomName())
        spawn->setCustomName(newName);

    if (newMood != spawn->getMoodString())
        spawn->setMoodString(newMood);
}

BadgeChangedCommand::BadgeChangedCommand(Badge* badge, int newID, float newRadius){
    setText("Badge change");

    this->badge = badge;

    oldRadius = badge->getRadius();
    oldID = badge->getBadgeID();

    this->newID = newID;
    this->newRadius = newRadius;
}

void BadgeChangedCommand::undo(){
  if (oldRadius != badge->getRadius())
    badge->setRadius(oldRadius);

  if (oldID != badge->getBadgeID())
    badge->setBadgeID(oldID);
}

void BadgeChangedCommand::redo() {
  if (newRadius != badge->getRadius())
    badge->setRadius(newRadius);

  if (newID != badge->getBadgeID())
    badge->setBadgeID(newID);
}
