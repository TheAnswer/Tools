#ifndef PLANETSPAWNREGION_H
#define PLANETSPAWNREGION_H

#include <QVector>
#include <QString>
#include "region.h"
#include "spawn.h"

class PlanetSpawnRegion : public Region, public Spawn {
    QString regionName;
    float radius;
    int tier, constant;

    QVector<QString> spawns;
protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant& value);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void wheelEvent(QGraphicsSceneWheelEvent* event);
public:
    PlanetSpawnRegion();

    QString toLua();

    void setWorldX(float v);
    void setWorldY(float v);

    void setRadius(float v);

    void setTier(int v);
    void setConstant(int v);

    inline QVector<QString>* getSpawns() {
        return &spawns;
    }

    inline QString& getRegionName() {
        return regionName;
    }

    inline float getRadius() {
        return radius;
    }

    inline int getTier() {
        return tier;
    }

    inline int getConstant() {
        return constant;
    }

    inline void setRegionName(const QString& name) {
        regionName = name;
    }

    inline void addSpawn(const QString& sp) {
        spawns.append(sp);
    }



};

#endif // PLANETSPAWNREGION_H
