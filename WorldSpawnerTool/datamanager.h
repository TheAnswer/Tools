#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "LuaParser.h"
#include "QMap"
#include "QMutex"
#include "QVector"

class swgRepository;
class QComboBox;
class LootItemTemplate;
class LootGroupTemplate;
class LootLuaManager;

class DataManager : public QObject, public LuaParser
{
    Q_OBJECT

public:
    DataManager();
    ~DataManager();

    void loadTreData(QString treDirectory);
    void loadLuaData();

    inline QMap<QString, QVector<QString> > getDirectories() {
        return treDirectories;
    }

    inline QVector<QString> getFiles(const QString& directory) {
        return treDirectories.value(directory);
    }

    static void loadLootGroupTemplate(lua_State* L);
    static void loadLootItemTemplate(lua_State* L);

private:
    void registerGlobals();

signals:
    void loadingMessage(const QString&);

private:
    swgRepository* repo;
    QMap<QString, QVector<QString> > treDirectories;
    QMutex* mutex;

    LootLuaManager* lootManager;

public:
    static DataManager* instance;
};

#endif // DATAMANAGER_H
