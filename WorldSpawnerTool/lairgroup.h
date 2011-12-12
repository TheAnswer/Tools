#ifndef LAIRGROUP_H
#define LAIRGROUP_H

#include <QString>
#include <QVector>

#include "LuaParser.h"

class LairGroup;

class LairSpawnEntry {
protected:
    QString lairTemplateName;
    int spawnLimit;
    int minDifficulty;
    int maxDifficulty;
    int numberToSpawn;
    int weighting;
    int size;

public:
    LairSpawnEntry(const QString& name) {
        lairTemplateName = name;
        spawnLimit = 0;
        minDifficulty = 0;
        maxDifficulty = 0;
        numberToSpawn = 0;
        weighting = 0;
        size = 0;
    }

    void setSpawnLimit(int lim) {
        spawnLimit = lim;
    }

    void setMinDifficulty(int val) {
        minDifficulty = val;
    }

    void setMaxDifficulty(int val) {
        maxDifficulty = val;
    }

    void setNumberToSpawn(int val) {
        numberToSpawn = val;
    }

    void setWeighting(int val) {
        weighting = val;
    }

    void setSize(int val) {
        size = val;
    }

    void setLairTemplateName(const QString& name) {
        lairTemplateName = name;
    }

    int getSpawnLimit() const {
        return spawnLimit;
    }

    int getMinDifficulty() const {
        return minDifficulty;
    }

    int getMaxDifficulty() const {
        return maxDifficulty;
    }

    int getNumberToSpawn() const {
        return numberToSpawn;
    }

    int getWeighting() const {
        return weighting;
    }

    int getSize() const {
        return size;
    }

    QString getLairTemplateName() const {
        return lairTemplateName;
    }


    friend class LairGroup;
};

class LairGroup {
    int maxSpawnLimit;
    QString name;
    QVector<LairSpawnEntry*> spawnEntries;

    QString fileName;

public:
    LairGroup(const QString& name);
    ~LairGroup();

    void readObject(lua_State* L);
    QString serializeToLua();

    LairSpawnEntry* getSpawnEntry(const QString& name) {
        int find = findSpawnEntry(name);

        if (find == -1)
            return NULL;
        else
            return spawnEntries.at(find);
    }

    int findSpawnEntry(const QString& name) {
        for (int i = 0; i < spawnEntries.size(); ++i) {
            if (spawnEntries.at(i)->getLairTemplateName() == name)
                return i;
        }

        return -1;
    }

    void removeSpawnEntry(const QString& name) {
        int find = findSpawnEntry(name);


        if (find == -1)
            return;
        else {
            delete spawnEntries.at(find);

            spawnEntries.remove(find);
        }
    }

    void addSpawnEntry(LairSpawnEntry* entry) {
        spawnEntries.append(entry);
    }

    QVector<LairSpawnEntry*>* getSpawnEntries() {
        return &spawnEntries;
    }

    QString getName() {
        return name;
    }

    QString getFileName() {
        return fileName;
    }

    void setFileName(const QString& file) {
        fileName = file;
    }

    int getMaxSpawnLimit() {
        return maxSpawnLimit;
    }

    void setMaxSpawnLimit(int val) {
        maxSpawnLimit = val;
    }


};

#endif // LAIRGROUP_H
