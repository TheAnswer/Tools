#ifndef PLANET_H
#define PLANET_H

#include <QVector>


class PlanetSpawnRegion;

class Planet {
    QVector<PlanetSpawnRegion*> regions;

public:
    Planet();

    void addRegion(const QString& regionData);

};

#endif // PLANET_H
