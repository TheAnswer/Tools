#ifndef DYNAMICSPAWNAREA_H
#define DYNAMICSPAWNAREA_H

#include "region.h"

#include <QVector>
#include <QString>

class DynamicSpawnArea : public Region {
    QVector<QString> templates;

    int maxCreaturesToSpawn;
public:
    DynamicSpawnArea(qreal radius);
};

#endif // DYNAMICSPAWNAREA_H
