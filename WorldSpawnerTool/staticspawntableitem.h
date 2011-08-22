#ifndef STATICSPAWNTABLEITEM_H
#define STATICSPAWNTABLEITEM_H

#include <QTableWidgetItem>

#include "staticspawn.h"

class StaticSpawnTableItem : public QTableWidgetItem {
protected:
    StaticSpawn* spawn;

public:
    const static int POSITIONX = 0;
    const static int POSITIONZ = 1;
    const static int POSITIONY = 2;
    const static int HEADING = 3;
    const static int RESPAWN = 4;
    const static int PARENTID = 5;
public:
    StaticSpawnTableItem(StaticSpawn* sp, const QString& text);

public:
    inline StaticSpawn* getSpawn() {
        return spawn;
    }
};

#endif // STATICSPAWNTABLEITEM_H
