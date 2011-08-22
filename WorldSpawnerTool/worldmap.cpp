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

WorldMap::WorldMap(const QString& name) {
    //connect(this, SIGNAL(selectionChanged()), this, SLOT(selectItem()));
    //connect()
    //connect(this, SIGNAL(updateCurrentItemPosition(float, float)), MainWindow::instance, SLOT(updateCurrentItemPosition(float, float)));

    selectedRegion = NULL;

    mapName = name;

    loadPlanetImage();

    //this->set
}

WorldMap::~WorldMap() {
    QMapIterator<QString, QVector<StaticSpawn*>* > mapIterator(staticSpawns);

    while (mapIterator.hasNext()) {
        mapIterator.next();

        QVector<StaticSpawn*>* spawns = mapIterator.value();

        for (int i = 0; i < spawns->size(); ++i) {
            StaticSpawn* spawn = spawns->at(i);

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
}

void WorldMap::loadPlanetImage() {
    QString fileName = "ui_map_" + mapName + ".jpg";

    QImage image(fileName);
    addPixmap(QPixmap::fromImage(image));
}

void WorldMap::clearMap() {
    QMapIterator<QString, PlanetSpawnRegion* > mapIteratorRegions(spawnRegions);

    while (mapIteratorRegions.hasNext()) {
        mapIteratorRegions.next();

        QGraphicsItem* item = mapIteratorRegions.value();
        removeItem(item);
        delete item;
    }

    spawnRegions.clear();

    QMapIterator<QString, QVector<StaticSpawn*>* > mapIterator(staticSpawns);

    while (mapIterator.hasNext()) {
        mapIterator.next();

        QVector<StaticSpawn*>* spawns = mapIterator.value();

        for (int i = 0; i < spawns->size(); ++i) {
            StaticSpawn* spawn = spawns->at(i);

            removeItem(spawn);
            delete spawn;
        }

        delete spawns;
    }

    staticSpawns.clear();

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

void WorldMap::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    /*if (mouseEvent->button() != Qt::LeftButton)
        return;*/

    QPointF point = mouseEvent->scenePos();

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
    }

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

void WorldMap::updateSpawnRegionView(PlanetSpawnRegion* region) {
    float x = region->getWorldX();
    float y = region->getWorldY();
    float radius = region->getRadius() / 16.f;

    region->setPos((MAXX + x) / 16, (MAXY - y) / 16);
    region->setRect(-radius/2, -radius/2, radius, radius);
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


