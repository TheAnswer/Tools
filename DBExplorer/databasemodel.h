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
    bool compressed;
    bool objectDB;
    QHash<unsigned int, IDLVar>* hashTable;
    QList<QPair<unsigned long long, QString> > displayList;
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

    QByteArray getData(int i) { return db->getData(i, compressed); }
    QHash<unsigned int, IDLVar>* getHashTable() { return hashTable; }

    void setObjectDB(bool b) { objectDB = b; }
    void setCompressed(bool b) {compressed = b; }

    bool hasStringEntries() { return !objectDB; }

    void open(QString &path);
    void close();

    // seralization methods
    QMap<IDLVar, QByteArray> getVariableList(const QByteArray &data);
    QByteArray getVariable(const QByteArray &data, QString varKey);

    QVariant getDataByType(QByteArray *data, QString varType);

    bool getBoolean(QByteArray *data) { bool retVal = *(bool*)data->left(1).data(); data->remove(0, 1); return retVal; }
    char getByte(QByteArray *data) { char retVal = *(char*)data->left(1).data(); data->remove(0, 1); return retVal; }

    unsigned short getUnsignedShort(QByteArray *data) { unsigned short retVal = *(unsigned short*)data->left(2).data(); data->remove(0, 2); return retVal; }
    short getShort(QByteArray *data) { short retVal = *(short*)data->left(2).data(); data->remove(0, 2); return retVal; }

    unsigned int getUnsignedInt(QByteArray *data) { unsigned int retVal = *(unsigned int*)data->left(4).data(); data->remove(0, 4); return retVal; }
    int getInt(QByteArray *data) { int retVal = *(int*)data->left(4).data(); data->remove(0, 4); return retVal; }
    float getFloat(QByteArray *data) { float retVal = *(float*)data->left(4).data(); data->remove(0, 4); return retVal; }

    double getDouble(QByteArray *data) { double retVal = *(double*)data->left(8).data(); data->remove(0, 8); return retVal; }
    unsigned long long getUnsignedLong(QByteArray *data) { unsigned long long retVal = *(unsigned long long*)data->left(8).data(); data->remove(0, 8); return retVal; }
    long long getLong(QByteArray *data) { long long retVal = *(long long*)data->left(8).data(); data->remove(0, 8); return retVal; }

    QString getString(QByteArray *data);
    QString getUnicode(QByteArray *data);

signals:

public slots:

};

#endif // DATABASEMODEL_H
