#include "staticspawn.h"
#include <QBrush>
#include <QPen>
#include "mainwindow.h"
#include "worldmap.h"
#include "commands.h"
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include "mainwindow.h"
#include "creaturemanager.h"
#include "CreatureObject.h"

StaticSpawn::StaticSpawn() : QGraphicsEllipseItem(-1/2, -1/2, 1, 1) {
    setFlag(QGraphicsItem::ItemIsSelectable, true);

    QBrush brush(Qt::FDiagPattern);
    brush.setColor(Qt::blue);

    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidthF(1);

    setBrush(brush);
    setPen(pen);

    respawnTimer = 0;
    heading = 0;
    parentID = 0;

    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    //setFlag(QGraphicsItem::Item)
}

void StaticSpawn::contextMenuEvent(QGraphicsSceneContextMenuEvent *event) {
    event->accept();

    QMenu menu;


   /* menu.addAction("Insert static spawn", MainWindow::instance, SLOT(showInsertStaticSpawnWindow()));
    menu.addAction("Insert badge", MainWindow::instance, SLOT(showInsertBadgeWindow()));*/
    menu.addAction("View 3d model", this, SLOT(show3dModel()));
    //menu.addAction("Remove");

    menu.exec(event->screenPos());
}

void StaticSpawn::show3dModel() {
    //MainWindow::startSwgOSG(mobile);
    CreatureObject* creature = MainWindow::instance->getCreatureManager()->getMobile(mobile);

    if (creature == NULL)
        return;

    QVector<QString>* templates = creature->getTemplates();

    if (templates->size() == 0) {
        MainWindow::instance->warning("This mobile doesnt have any templates specified");
    }

    QString file = templates->at(0);

    int idx = file.lastIndexOf("/");

    if (idx < 0)
        return;

    file = file.insert(idx + 1, "shared_");

    MainWindow::instance->startSwgOSG(file);
}

void StaticSpawn::setWorldX(float v) {
    if (v == worldX)
        return;

    Spawn::setWorldX(v);

    WorldMap* map = dynamic_cast<WorldMap*>(scene());

    if (map != NULL) {
        map->updateStaticSpawnView(this);
    }

    MainWindow::instance->updateStaticSpawnTableItem(this);
}

void StaticSpawn::setWorldY(float v) {
    if (v == worldY)
        return;

    Spawn::setWorldY(v);

    WorldMap* map = dynamic_cast<WorldMap*>(scene());

    if (map != NULL) {
        map->updateStaticSpawnView(this);
    }

    MainWindow::instance->updateStaticSpawnTableItem(this);
}

void StaticSpawn::setRespawnTimer(unsigned int timer) {
    if (respawnTimer == timer)
        return;

    respawnTimer = timer;

    MainWindow::instance->updateStaticSpawnTableItem(this);
}

void StaticSpawn::setHeading(float head) {
    if (heading == head)
        return;

    heading = head;

    MainWindow::instance->updateStaticSpawnTableItem(this);
}

void StaticSpawn::setParentID(unsigned long long id) {
    if (parentID == id)
        return;

    parentID = id;

    WorldMap* map = dynamic_cast<WorldMap*>(scene());

    if (map != NULL) {
        map->updateStaticSpawnView(this);
    } else if (id == 0 && map == NULL) {
        map = MainWindow::instance->getCurrentWorldMap();

        map->updateStaticSpawnView(this);
    }

    MainWindow::instance->updateStaticSpawnTableItem(this);
}

QVariant StaticSpawn::itemChange(GraphicsItemChange change, const QVariant& value) {
    //MainWindow::instance->outputToConsole("blia");

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
        if (value.toBool() == true) {
            MainWindow::instance->updateCurrentStaticSpawnSelection(this);
            MainWindow::instance->updateCurrentItemPosition(worldX, worldY);
        }
    }

    return value;
}

QString StaticSpawn::toLua() {
    QString data;
    QTextStream stream(&data);

    /*
    QString mobile;
    unsigned int respawnTimer;
    float heading;
    unsigned long long parentID;
    */

    stream << "{\"" << mobile << "\"," << respawnTimer << "," << getWorldX() << "," << getWorldZ() << "," << getWorldY() << "," << heading << "," << parentID << "}";

    return data;
}
