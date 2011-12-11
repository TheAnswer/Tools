#ifndef LAIRTEMPLATE_H
#define LAIRTEMPLATE_H

#include <QMap>
#include "lairluamanager.h"
#include "utils.h"

using namespace utils;

class LairTemplate {
protected:
    QMap<QString, uint32> mobiles;
    int spawnLimit;

    QMap<uint32, QVector<QString>* > buildings;

    QString luaObjectName;

    QString fileName;

public:
    enum {VERYEASY = 0, EASY, MEDIUM, HARD, VERYHARD};

    LairTemplate(const QString& name);

    virtual ~LairTemplate();

    void readObject(lua_State* l);

    QString serializeToLua();

    QString serializeMobileData();

    void setSpawnLimit(int lim) {
        spawnLimit = lim;
    }

    void setFileName(const QString& file) {
        fileName = file;
    }

    QMap<QString, uint32>* getMobiles() {
        return &mobiles;
    }

    int getSpawnLimit() {
        return spawnLimit;
    }

    QVector<QString>* getBuildings(int type) {
        return buildings.value(type, NULL);
    }

    QString getFileName() {
        return fileName;
    }

    QString getName() {
        return luaObjectName;
    }

};

#endif // LAIRTEMPLATE_H
