#ifndef WORLDMAP_H
#define WORLDMAP_H

#include <QGraphicsScene>
#include <QVector>
#include <QMap>

class PlanetSpawnRegion;
class StaticSpawn;

class WorldMap : public QGraphicsScene {
    Q_OBJECT

    QMap<QString, PlanetSpawnRegion*> spawnRegions;
    PlanetSpawnRegion* selectedRegion;
    QMap<QString, QVector<StaticSpawn* >* > staticSpawns;
    QString mapName;

public:
    const static int MAXX = 8192;
    const static int MAXY = 8192;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent);
   // void dragMoveEvent(QGraphicsSceneDragDropEvent* event);
    void loadPlanetImage();

public:
    WorldMap(const QString& name);
    ~WorldMap();

    void loadCityRegions();
    void loadNoBuildZones();

    void addSpawnRegion(const QString& regionName, PlanetSpawnRegion* newRegion);

  //  void generateSpawnRegions();

    void addStaticSpawns(const QVector<StaticSpawn* >& vec);
    void addStaticSpawn(StaticSpawn* spawn);
    void removeStaticSpawn(StaticSpawn* spawn);

    void updateStaticSpawnView(StaticSpawn* spawn);
    void updateSpawnRegionView(PlanetSpawnRegion* region);

    void clearMap();

    void toWorldPos(qreal x, qreal y, float& worldX, float& worldY);

    inline QMap<QString, PlanetSpawnRegion*>* getSpawnRegions() {
        return &spawnRegions;
    }

    inline PlanetSpawnRegion* getSpawnRegion(const QString& name) {
        return spawnRegions.value(name, NULL);
    }

    inline QVector<StaticSpawn* >* getMobileStaticSpawns(const QString& mobile) {
        return staticSpawns.value(mobile, NULL);
    }

    inline QMap<QString, QVector<StaticSpawn* >* >* getStaticSpawns() {
        return &staticSpawns;
    }

public slots:
    //void selectItem();

    void selectPlanetSpawnRegion(const QString& name);
};

#endif // WORLDMAP_H
