#ifndef WORLDMAP_H
#define WORLDMAP_H

#include <QGraphicsScene>
#include <QVector>
#include <QMap>

class PlanetSpawnRegion;
class StaticSpawn;
class Badge;
class Region;
class WorldSnapshotObject;

class WorldMap : public QGraphicsScene {
    Q_OBJECT

    QMap<QString, PlanetSpawnRegion*> spawnRegions;
    PlanetSpawnRegion* selectedRegion;
    QMap<QString, QVector<StaticSpawn* >* > staticSpawns;
    QString mapName;
    QMap<QString, Badge*> badges;
    QMap<unsigned int, WorldSnapshotObject*> worldSnapshotObjects;

public:
    const static int MAXX = 8192;
    const static int MAXY = 8192;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent);
   // void dragMoveEvent(QGraphicsSceneDragDropEvent* event);
    void loadPlanetImage();
    void wheelEvent(QGraphicsSceneWheelEvent* event);

    void clearSpawnedObjects();

public:
    WorldMap(const QString& name);
    ~WorldMap();

    void loadCityRegions();
    void loadNoBuildZones();

    void addSpawnRegion(const QString& regionName, PlanetSpawnRegion* newRegion);

  //  void generateSpawnRegions();

    void addStaticSpawns(const QVector<StaticSpawn* >& vec);
    void addStaticSpawn(StaticSpawn* spawn);
    void addBadges(const QVector<Badge*>& vec);
    void addBadge(Badge* badge);
    void removeStaticSpawn(StaticSpawn* spawn);
    void removeBadge(Badge* badge);
    void updateStaticSpawnView(StaticSpawn* spawn);
    void updateSpawnRegionView(Region* region);
    void addWorldSnapshotObject(WorldSnapshotObject* object);

    void clearMap();

    void toWorldPos(qreal x, qreal y, float& worldX, float& worldY);
    void toScenePos(qreal x, qreal y, float& sceneX, float& sceneY);

    inline QMap<QString, PlanetSpawnRegion*>* getSpawnRegions() {
        return &spawnRegions;
    }

    inline Badge* getBadge(const QString& name) {
      return badges.value(name, NULL);
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

    inline QMap<QString, Badge*>* getBadges() {
        return &badges;
    }
public slots:
    //void selectItem();

    void selectPlanetSpawnRegion(const QString& name);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
};

#endif // WORLDMAP_H
