#include "worldmap.h"
#include <QGraphicsSceneMouseEvent>

#include <iostream>
#include "region.h"
#include "mainwindow.h"
#include "databaseconnection.h"
#include <QSqlQuery>
#include "cityregion.h"
#include <QTextStream>
#include "nobuildzone.h"
#include <QList>
#include "planetspawnregion.h"
#include "staticspawn.h"
#include "badge.h"
#include <QGraphicsView>
#include <QMenu>
#include "worldsnapshotobject.h"

WorldMap::WorldMap(const QString& name) {
    selectedRegion = NULL;

    mapName = name;

    loadPlanetImage();
}

WorldMap::~WorldMap() {
   clearSpawnedObjects();
}

void WorldMap::wheelEvent(QGraphicsSceneWheelEvent* event) {
    int delta = event->delta();

    QList<QGraphicsView*> view = views();

    if (view.size() == 0) {
        QGraphicsScene::wheelEvent(event);

        return;
    }

    float val = delta > 0 ? 1.1 : 0.9;

    for (int i = 0; i < view.size(); ++i) {
        view.at(i)->scale(val, val);
    }

    event->accept();
}

void WorldMap::loadPlanetImage() {
    QString fileName = "ui_map_" + mapName + ".jpg";

    QImage image;

    if (!image.load(fileName)) {
        MainWindow::instance->outputToConsole("could not load imagefile " + fileName);
        return;
    } else
        MainWindow::instance->outputToConsole("loaded " + fileName);

    addPixmap(QPixmap::fromImage(image));
}

void WorldMap::clearSpawnedObjects() {
    QMapIterator<QString, QVector<StaticSpawn*>* > mapIterator(staticSpawns);

    while (mapIterator.hasNext()) {
        mapIterator.next();

        QVector<StaticSpawn*>* spawns = mapIterator.value();

        for (int i = 0; i < spawns->size(); ++i) {
            StaticSpawn* spawn = spawns->at(i);

            if (spawn->scene() != NULL)
                removeItem(spawn);
            delete spawn;
        }

        delete spawns;

    }

    QMapIterator<QString, PlanetSpawnRegion* > mapIteratorRegions(spawnRegions);

    while (mapIteratorRegions.hasNext()) {
        mapIteratorRegions.next();

        delete mapIteratorRegions.value();
    }

    QMapIterator<QString, Badge* > mapIteratorBadges(badges);

    while (mapIteratorBadges.hasNext()) {
        mapIteratorBadges.next();

        Badge* badge = mapIteratorBadges.value();

        if (badge->scene() != NULL)
            removeItem(badge);

        delete badge;
    }

    QMapIterator<unsigned int, WorldSnapshotObject*> wsIterator(worldSnapshotObjects);

    while (wsIterator.hasNext()) {
        wsIterator.next();

        WorldSnapshotObject* obj = wsIterator.value();

        if (obj->scene() != NULL)
            removeItem(obj);

        delete obj;
    }
}

void WorldMap::clearMap() {
    clearSpawnedObjects();

    selectedRegion = NULL;

    clear();

    loadPlanetImage();
}

void WorldMap::mouseMoveEvent (QGraphicsSceneMouseEvent* mouseEvent) {
    QList<QGraphicsItem *> list = selectedItems();

    if (list.size() == 0) {
        QPointF point = mouseEvent->scenePos();

        qreal x = point.x();
        qreal y = point.y();

        float worldPosX, worldPosY;;

        toWorldPos(x, y, worldPosX, worldPosY);

        MainWindow::instance->updateCurrentItemPosition(worldPosX, worldPosY);
    }

    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

/*void WorldMap::dragMoveEvent(QGraphicsSceneDragDropEvent* event) {
    //event->accept();

    QPointF point = event->pos();

    float worldPosX, worldPosY;

    toWorldPos(point.x(), point.y(), worldPosX, worldPosY);

    QString data;
    QTextStream stream(&data);

    stream << "x:" << worldPosX << " y:" << worldPosY;

    MainWindow::instance->outputToConsole(data);

    QGraphicsScene::dragMoveEvent(event);
}*/

void WorldMap::toWorldPos(qreal x, qreal y, float& worldX, float& worldY) {
    worldX = (x * 16) - MAXX;
    worldY = ((y * 16) - MAXY) * -1;
}

void WorldMap::contextMenuEvent(QGraphicsSceneContextMenuEvent *event) {
    QGraphicsScene::contextMenuEvent(event);

    if (event->isAccepted())
        return;

    event->accept();

    QPointF point = event->scenePos();

    qreal x = point.x();
    qreal y = point.y();

    float worldPosX;
    float worldPosY;

    toWorldPos(x, y, worldPosX, worldPosY);

    QMenu menu;
    MainWindow::instance->setInsertWindowStaticSpawnCoordinates(worldPosX, worldPosY);
    MainWindow::instance->setInsertWindowBadgeSpawnCoordinates(worldPosX, worldPosY);

    menu.addAction("Insert static spawn", MainWindow::instance, SLOT(showInsertStaticSpawnWindow()));
    menu.addAction("Insert badge", MainWindow::instance, SLOT(showInsertBadgeWindow()));
    menu.exec(event->screenPos());
}

void WorldMap::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    /*if (mouseEvent->button() != Qt::LeftButton)
        return;*/

    /*QPointF point = mouseEvent->scenePos();

    if (mouseEvent->button() == Qt::RightButton) {
        QPointF point = mouseEvent->scenePos();

        qreal x = point.x();
        qreal y = point.y();

        float worldPosX;
        float worldPosY;

        toWorldPos(x, y, worldPosX, worldPosY);

        MainWindow::instance->updateCurrentItemPosition(worldPosX, worldPosY);
        MainWindow::instance->showInsertWindow(worldPosX, worldPosY);

        //mouseEvent->accept();
    }*/

    QGraphicsScene::mousePressEvent(mouseEvent);
}

void WorldMap::selectPlanetSpawnRegion(const QString& name) {
    if (!spawnRegions.contains(name))
        return;

    PlanetSpawnRegion* spawnRegion = spawnRegions.value(name);

    /*QPainterPath path;
    path.addEllipse(spawnRegion->x(), spawnRegion->y(), 0.5, 0.5);

    selectedRegion = spawnRegion;

    setSelectionArea(path, Qt::IntersectsItemShape);*/

    if (selectedRegion != NULL)
        selectedRegion->setSelected(false);

    selectedRegion = spawnRegion;

    /*if (!spawnRegion->isSelected())
        spawnRegion->setSelected(true);*/
}

/*void WorldMap::selectItem() {
    QList<QGraphicsItem *> list = selectedItems();

    if (list.size() == 0)
        return;

    QGraphicsItem* item = NULL;

    if (selectedRegion != NULL) {
        item = selectedRegion;
    } else
        item = list.at(0);

    StaticSpawn* staticSpawn = NULL;

    if (dynamic_cast<PlanetSpawnRegion*>(item) != NULL) {
        PlanetSpawnRegion* planetSpawnRegion = (PlanetSpawnRegion*) item;

        MainWindow::instance->updateCurrentSpawnRegionSelection(planetSpawnRegion->getRegionName());
    } else if ((staticSpawn = dynamic_cast<StaticSpawn*>(item)) != NULL) {
        MainWindow::instance->updateCurrentStaticSpawnSelection(staticSpawn);
    }

    qreal x = item->x();
    qreal y = item->y();

    float worldPosX;
    float worldPosY;

    toWorldPos(x, y, worldPosX, worldPosY);

    MainWindow::instance->updateCurrentItemPosition(worldPosX, worldPosY);
}*/

void WorldMap::addStaticSpawns(const QVector<StaticSpawn* >& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        StaticSpawn* spawn = vec.at(i);

        addStaticSpawn(spawn);
    }

    //staticSpawns += vec;
}

void WorldMap::addBadges(const QVector<Badge*>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        Badge* badge = vec.at(i);

        addBadge(badge);
    }
}

void WorldMap::addBadge(Badge* badge) {
    badges.insert(badge->getName(), badge);

    float x = badge->getWorldX();
    float y = badge->getWorldY();
    float radius = badge->getRadius() / 16.f;

    badge->setPos((MAXX + x) / 16, (MAXY - y) / 16);
    badge->setRect(-radius/2, -radius/2, radius, radius);

    addItem(badge);
}

void WorldMap::addWorldSnapshotObject(WorldSnapshotObject* object) {
    //if ()
    worldSnapshotObjects.insert(object->getSnapshotID(), object);

    float sceneX, sceneY;

    toScenePos(object->getWorldX(), object->getWorldY(), sceneX, sceneY);

    //object->setPos(sceneX, sceneY);
    object->setRect(sceneX, sceneY, 0.5, 0.5);

    addItem(object);
}

void WorldMap::removeBadge(Badge* badge) {
    if (!badges.contains(badge->getName()))
        return;

    removeItem(badge);

    badges.remove(badge->getName());

    update((MAXX + badge->getWorldX()) / 16 - 1, (MAXY + badge->getWorldY()) / 16 - 1, 256, 256);
}

void WorldMap::removeStaticSpawn(StaticSpawn* spawn) {
    if (staticSpawns.contains(spawn->getMobile())) {
        QVector<StaticSpawn* >* spawns = staticSpawns.value(spawn->getMobile());

        for (int i = 0; i < spawns->size(); ++i) {
            if (spawns->at(i) == spawn) {
                spawns->remove(i);

                break;
            }
        }

        removeItem(spawn);

        //redraw
        update((MAXX + spawn->getWorldX()) / 16 - 1, (MAXY + spawn->getWorldY()) / 16 - 1, 2, 2);
    }
}

void WorldMap::updateStaticSpawnView(StaticSpawn* spawn) {
    if (spawn->getParentID() == 0) {
        if (spawn->scene() == NULL)
            addItem(spawn);

        float x = spawn->getWorldX();
        float y = spawn->getWorldY();

        spawn->setPos((MAXX + x) / 16, (MAXY - y) / 16);
        spawn->setRect(-2.f/2, -2.f/2, 2.f, 2.f);
    } else {
        if (spawn->scene() != NULL) {
            removeItem(spawn);

            //redraw
            update((MAXX + spawn->getWorldX()) / 16 - 1, (MAXY + spawn->getWorldY()) / 16 - 1, 2, 2);
        }
    }

}

void WorldMap::updateSpawnRegionView(Region* region) {
    float x = region->getWorldX();
    float y = region->getWorldY();
    float radius = region->getRadius() / 16.f;

    region->setPos((MAXX + x) / 16, (MAXY - y) / 16);
    region->setRect(-radius/2, -radius/2, radius, radius);
}

void WorldMap::toScenePos(qreal x, qreal y, float& sceneX, float& sceneY) {
    sceneX = (MAXX + x) / 16;
    sceneY = (MAXY - y) / 16;
}

void WorldMap::addStaticSpawn(StaticSpawn* spawn) {
    if (spawn->getParentID() == 0) {
        float x = spawn->getWorldX();
        float y = spawn->getWorldY();

        //Region* graphicRegion = new Region(radius / 16);

        /*MainWindow::instance->outputToConsole(QString::number(x));
        MainWindow::instance->outputToConsole(QString::number(y));*/

        spawn->setPos((MAXX + x) / 16, (MAXY - y) / 16);
        spawn->setRect(-2.f/2, -2.f/2, 2.f, 2.f);

        //MainWindow::instance->outputToConsole("adding static spawn");

        addItem(spawn);
    }

    if (staticSpawns.contains(spawn->getMobile())) {
        QVector<StaticSpawn* >* spawns = staticSpawns.value(spawn->getMobile());

        spawns->append(spawn);
    } else {
        QVector<StaticSpawn* >* spawns = new QVector<StaticSpawn* >();
        spawns->append(spawn);
        staticSpawns.insert(spawn->getMobile(), spawns);
    }
}

void WorldMap::loadCityRegions() {
    MainWindow* mainWindow = MainWindow::instance;

    DatabaseConnection* database = mainWindow->getDatabase();

    if (!database->isOpen())
        return;

    QSqlQuery query("SELECT * FROM clientregion_" + mapName);

    while (query.next()) {
        QString name = query.value(0).toString();
        qreal posX = query.value(1).toFloat();
        qreal posY = query.value(2).toFloat();
        qreal radius = query.value(3).toFloat();
        //doSomething(country);

        CityRegion* region = new CityRegion(radius / 16);
        region->setPos((MAXX + posX) / 16, (MAXY - posY) / 16);

        addItem(region);
    }
}

void WorldMap::loadNoBuildZones() {
    /*MainWindow* mainWindow = MainWindow::instance;

    DatabaseConnection* database = mainWindow->getDatabase();

    if (!database->isOpen())
        return;

    QSqlQuery query("SELECT * FROM no_build_zones WHERE planet_id = 5");

    while (query.next()) {
        //QString name = query.value(0).toString();
        qreal posX = query.value(5).toFloat();
        qreal posY = query.value(6).toFloat();
        qreal radius = query.value(7).toFloat();
        //doSomething(country);

        NoBuildZone* region = new NoBuildZone(radius / 16);
        region->setPos((MAXX + posX) / 16, (MAXY - posY) / 16);

        addItem(region);
    }*/
}

void WorldMap::addSpawnRegion(const QString& regionName, PlanetSpawnRegion* newRegion) {
    spawnRegions[regionName] = newRegion;

    float x = newRegion->getWorldX();
    float y = newRegion->getWorldY();
    float radius = newRegion->getRadius() / 16.f;

    //Region* graphicRegion = new Region(radius / 16);

    /*MainWindow::instance->outputToConsole(QString::number(x));
    MainWindow::instance->outputToConsole(QString::number(y));*/

    newRegion->setPos((MAXX + x) / 16, (MAXY - y) / 16);
    newRegion->setRect(-radius/2, -radius/2, radius, radius);

    addItem(newRegion);
}


