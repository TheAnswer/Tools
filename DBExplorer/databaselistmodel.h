#ifndef DATABASELISTMODEL_H
#define DATABASELISTMODEL_H

#include <QAbstractListModel>
#include <QHash>
#include <QString>
#include <QDir>

class DatabaseListEntry {
public:
    DatabaseListEntry() {
        compressed = true;
        objectDB = false;
    }

    QString name;
    bool compressed;
    bool objectDB;
};

class DatabaseListModel : public QAbstractListModel
{
    Q_OBJECT
private:
    QHash<unsigned short, DatabaseListEntry>* dbList;
    QString dbPath;
    unsigned long long MANAGED_OBJECTS_HASHCODE_MEMBERS;
    unsigned long long VERSIONKEY;
    unsigned long long LASTOBJECTIDKEY;

public:
    explicit DatabaseListModel(QObject *parent = 0);
    ~DatabaseListModel() { delete dbList; }

    // Must implement these three abstract methods
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    // reimpliment this so we can have column headers
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    // this is our accessor method:
    static DatabaseListModel* instance() {
        static DatabaseListModel* p = new DatabaseListModel(0);
        return p;
    }

    void populateList(QDir& baseDir);
    QHash<unsigned short, DatabaseListEntry>* getDbList() { return dbList; }
    QString getDbPath() { return dbPath; }

signals:

public slots:

};

#endif // DATABASELISTMODEL_H
