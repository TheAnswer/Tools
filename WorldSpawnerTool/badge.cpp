#include "badge.h"
#include <QBrush>
#include <QPen>
#include "worldmap.h"
#include "mainwindow.h"
#include <QTextStream>
#include "commands.h"

Badge::Badge(const QString& name) : Region(10) {
  QBrush brush(Qt::FDiagPattern);
  brush.setColor(Qt::yellow);

  this->name = name;

  setToolTip(name);

  QPen pen;
  pen.setColor(Qt::yellow);
  pen.setWidthF(1);

  setBrush(brush);
  setPen(pen);

  //setAcceptDrops(true);
  setFlag(QGraphicsItem::ItemIsSelectable, true);
  setFlag(QGraphicsItem::ItemIsMovable, true);
  setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

void Badge::setRadius(float val) {
  if (radius == val)
      return;

  WorldMap* map = dynamic_cast<WorldMap*>(scene());

  if (map == NULL)
      return;

  map->removeBadge(this);

  regionShape = Circle;
  radius = val;
  width = 0;
  height = 0;

  map->addBadge(this);

  map->updateSpawnRegionView(this);
  MainWindow::instance->updateCurrentBadgeSelection(name);
}

void Badge::setDimensions(float width, float height) {
    if (this->width == width && this->height == height)
        return;

    WorldMap* map = dynamic_cast<WorldMap*>(scene());

    if (map == NULL)
        return;

    map->removeBadge(this);

    regionShape = Rectangle;
    this->width = width;
    this->height = height;
    radius = 0;

    map->addBadge(this);

    map->updateSpawnRegionView(this);
    MainWindow::instance->updateCurrentBadgeSelection(name);
}

void Badge::setWorldX(float v) {
    if (v == worldX)
        return;

    Spawn::setWorldX(v);

    WorldMap* map = dynamic_cast<WorldMap*>(scene());

    if (map == NULL)
        return;

    map->updateSpawnRegionView(this);
    MainWindow::instance->updateCurrentBadgeSelection(name);
}

void Badge::setWorldY(float v) {
    if (v == worldY)
        return;

    Spawn::setWorldY(v);

    WorldMap* map = dynamic_cast<WorldMap*>(scene());

    if (map == NULL)
        return;

    map->updateSpawnRegionView(this);
    MainWindow::instance->updateCurrentBadgeSelection(name);
}


void Badge::setBadgeID(int id) {
  badgeID = id;
}

QVariant Badge::itemChange(GraphicsItemChange change, const QVariant& value) {
    WorldMap* map = dynamic_cast<WorldMap*>(scene());

    if (map == NULL)
        return value;

    if (change == QGraphicsItem::ItemPositionChange) {
        QPointF newPos = value.toPointF();


        float newWorldX, newWorldY;
        map->toWorldPos(newPos.x(), newPos.y(), newWorldX, newWorldY);

        if (newWorldX != worldX || newWorldY != worldY) {
            MainWindow::instance->pushUndoCommand(new SpawnMoveCommand(this, newWorldX, newWorldY, worldZ));

            //map->up
            MainWindow::instance->updateCurrentItemPosition(newWorldX, newWorldY);
        }


    } else if (change == QGraphicsItem::ItemSelectedChange) {
        if (!isSelected() && value.toBool() == true) {
            MainWindow::instance->updateCurrentBadgeSelection(name);
            MainWindow::instance->updateCurrentItemPosition(worldX, worldY);
        }
    }

    return value;
    //return QGraphicsEllipseItem::itemChange(change, value);
}

QString Badge::toLua() {
  QString data;
  QTextStream stream(&data);

  /*
  QString regionName;
  float radius;
  int tier, constant;

  QVector<QString> spawns;
  */

  stream << "{\"" << name << "\"," << getWorldX() << "," << getWorldY() << "," << getRadius() << "," << badgeID;

  stream << "}";

  return data;
}
