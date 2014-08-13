#ifndef DATABASEMODEL_H
#define DATABASEMODEL_H

#include "database.h"
#include "idlparser.h"
#include <QAbstractTableModel>
#include <QMap>
#include <QHash>
#include <QPair>

class DatabaseModel : public QAbstractTableModel
{
    Q_OBJECT
protected:
    Database* db;
    QHash<unsigned int, IDLVar>* hashTable;
    QHash<unsigned int, QPair<unsigned long long, QString> > displayList;
    QString dbName;

public:
    explicit DatabaseModel(QObject *parent = 0);
    ~DatabaseModel() { delete hashTable; close(); }

    // Must implement these three abstract methods
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    // reimpliment this so we can have column headers
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    // this is our accessor method:
    static DatabaseModel* instance() {
        static DatabaseModel* p = new DatabaseModel(0);
        return p;
    }

    QByteArray getData(int i) { return db->getData(i); }
    QHash<unsigned int, IDLVar>* getHashTable() { return hashTable; }

    bool hasStringEntries() { return dbName.contains("databases.db") || dbName.contains("strings.db"); }

    void open(QString &path);
    void close();

    // seralization methods
    QMap<IDLVar, QByteArray> getVariableList(const QByteArray &data);
    QByteArray getVariable(const QByteArray &data, QString varKey);
    bool getBoolean(const QByteArray &data) { return *(bool*)data.left(1).data(); }
    char getByte(const QByteArray &data) { return *(char*)data.left(1).data(); }

    unsigned short getUnsignedShort(const QByteArray &data) { return *(unsigned short*)data.left(2).data(); }
    short getShort(const QByteArray & data) { return *(short*)data.left(2).data(); }

    unsigned int getUnsignedInt(const QByteArray &data) { return *(unsigned int*)data.left(4).data(); }
    int getInt(const QByteArray &data) { return *(int*)data.left(4).data(); }
    float getFloat(const QByteArray &data) { return *(float*)data.left(4).data(); }

    double getDouble(const QByteArray &data) { return *(double*)data.left(8).data(); }
    unsigned long long getUnsignedLong(const QByteArray &data) { return *(unsigned long long*)data.left(8).data(); }
    long long getLong(const QByteArray &data) { return *(long long*)data.left(8).data(); }

    QString getString(const QByteArray &data);
    QString getUnicode(const QByteArray & data);

signals:

public slots:

};

#endif // DATABASEMODEL_H
