#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "LuaParser.h"
#include "QMap"
#include "QMutex"
#include "QVector"

class swgRepository;
class QComboBox;

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

private:
    void loadLootData();

signals:
    void loadingResource(const QString&);

private:
    swgRepository* repo;
    QMap<QString, QVector<QString> > treDirectories;
    QMutex* mutex;
};

#endif // DATAMANAGER_H
