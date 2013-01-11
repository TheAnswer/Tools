#include "planetspawnregion.h"
#include <QBrush>
#include <QPen>
#include <QTextStream>
#include "mainwindow.h"
#include <QGraphicsItem>
#include "worldmap.h"
#include <QGraphicsSceneMouseEvent>
#include "commands.h"

PlanetSpawnRegion::PlanetSpawnRegion(qreal radius) : Region(radius) {
    QBrush brush(Qt::FDiagPattern);
    brush.setColor(Qt::green);

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::green);
    pen.setWidthF(1);

    setBrush(brush);
    setPen(pen);

    //setAcceptDrops(true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

PlanetSpawnRegion::PlanetSpawnRegion(qreal width, qreal height) : Region(height, width) {
    QBrush brush(Qt::FDiagPattern);
    brush.setColor(Qt::green);

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::green);
    pen.setWidthF(1);

    setBrush(brush);
    setPen(pen);

    //setAcceptDrops(true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

void PlanetSpawnRegion::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    //if (event->)
    QGraphicsEllipseItem::mousePressEvent(event);
}

void PlanetSpawnRegion::setWorldX(float v) {
    if (v == worldX)
        return;

    Spawn::setWorldX(v);

    WorldMap* map = dynamic_cast<WorldMap*>(scene());

    if (map == NULL)
        return;

    map->updateSpawnRegionView(this);
    MainWindow::instance->updateCurrentSpawnRegionSelection(regionName);
}

void PlanetSpawnRegion::setWorldY(float v) {
    if (v == worldY)
        return;

    Spawn::setWorldY(v);

    WorldMap* map = dynamic_cast<WorldMap*>(scene());

    if (map == NULL)
        return;

    map->updateSpawnRegionView(this);
    MainWindow::instance->updateCurrentSpawnRegionSelection(regionName);
}

void PlanetSpawnRegion::setRadius(float v) {
    if (v == radius || v > 20000)
        return;

    WorldMap* map = dynamic_cast<WorldMap*>(scene());

    if (map == NULL)
        return;

    map->removeItem(getQGraphicsItem());

    regionShape = Circle;
    radius = v;
    width = 0;
    height = 0;

    map->addItem(getQGraphicsItem());

    map->updateSpawnRegionView(this);
    MainWindow::instance->updateCurrentSpawnRegionSelection(regionName);
}

void PlanetSpawnRegion::setDimensions(float width, float height) {
    if (this->width == width && this->height == height || width > 20000 || height > 20000)
        return;

    WorldMap* map = dynamic_cast<WorldMap*>(scene());

    if (map == NULL)
        return;

    map->removeItem(getQGraphicsItem());

    regionShape = Rectangle;
    this->width = width;
    this->height = height;
    radius = 0;

    map->addItem(getQGraphicsItem());

    map->updateSpawnRegionView(this);
    MainWindow::instance->updateCurrentSpawnRegionSelection(regionName);
}

void PlanetSpawnRegion::setTier(int v) {
    if (tier == v)
        return;

    tier = v;

    MainWindow::instance->updateCurrentSpawnRegionSelection(regionName);
}

void PlanetSpawnRegion::setConstant(int v) {
    if (constant == v)
        return;

    constant = v;

    MainWindow::instance->updateCurrentSpawnRegionSelection(regionName);
}

/*void PlanetSpawnRegion::wheelEvent(QGraphicsSceneWheelEvent* event) {
    WorldMap* map = dynamic_cast<WorldMap*>(scene());

    if (map == NULL) {
        QGraphicsEllipseItem::wheelEvent(event);

        return;
    }

    int delta = event->delta();

    float newRadius = getRadius() + delta;

    if (radius != newRadius) {
        MainWindow::instance->pushUndoCommand(new PlanetSpawnRegionChangeCommand(this, tier, constant, newRadius));

        event->accept();
    }
}*/

QVariant PlanetSpawnRegion::itemChange(GraphicsItemChange change, const QVariant& value) {
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
            MainWindow::instance->updateCurrentSpawnRegionSelection(getRegionName());
            MainWindow::instance->updateCurrentItemPosition(worldX, worldY);
        }
    }

    return value;
    //return QGraphicsEllipseItem::itemChange(change, value);
}

QString PlanetSpawnRegion::toLua() {
    QString data;
    QTextStream stream(&data);

    /*
    QString regionName;
    float radius;
    int tier, constant;

    QVector<QString> spawns;
    */

    stream << "{\"" << regionName << "\"," << getWorldX() << "," << getWorldY() << ",{";
    if (regionShape == Circle) {
        stream << "1," << getRadius();
    } else {
        stream << "2," << getWidth() << "," << getHeight();
    }
    stream << "}," << getTier() << "," << getConstant();

    for (int i = 0; i < spawns.size(); ++i) {
        stream << ",\"" << spawns.at(i) << "\"";
    }

    stream << "}";

    return data;
}
