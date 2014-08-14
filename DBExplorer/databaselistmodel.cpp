#include "databaselistmodel.h"
#include "databasemodel.h"
#include "database.h"
#include <QByteArray>

DatabaseListModel::DatabaseListModel(QObject *parent) :
    QAbstractListModel(parent)
{
    dbList = new QHash<unsigned short, DatabaseListEntry>();
}

// Must implement these three abstract methods
int DatabaseListModel::rowCount(const QModelIndex & /*parent*/) const {
    if (dbList == NULL)
        return 0;

    return dbList->size();
}

QVariant DatabaseListModel::data(const QModelIndex &index, int role) const {
    if (role != Qt::DisplayRole || dbList == NULL)
        return QVariant();

    return dbList->values().at(index.row()).name;
}

// reimpliment this so we can have column headers
QVariant DatabaseListModel::headerData(int /*section*/, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("Databases");

    return QVariant();
}

void DatabaseListModel::populateList(QDir& baseDir) {
    QString path = baseDir.filePath("databases.db");
    if (!QFileInfo(path).exists())
        return;

    beginResetModel();

    dbPath = baseDir.absolutePath();

    dbList->clear();

    Database listDb(path);

    for (int i = 0; i < listDb.getSize(); ++i) {
        unsigned long long key = listDb.getKey(i);
        QByteArray data = listDb.getData(i, true);

        unsigned int tableType = (unsigned int)(key >> 32);
        key -= (unsigned long long)((unsigned long long)tableType << 32);

        if (tableType == 0xFFFFFFFF) { // special type of table here, look at these for values
            unsigned long long val = DatabaseModel::instance()->getUnsignedLong(&data);

            switch (key) {
            case 0xFFFFFFFD:
                MANAGED_OBJECTS_HASHCODE_MEMBERS = val;
                break;
            case 0xFFFFFFFE:
                VERSIONKEY = val;
                break;
            case 0xFFFFFFFF:
                LASTOBJECTIDKEY = val;
                break;
            }

            continue; // these don't contain references to databases
        }

        bool compressed = tableType & 0x80000000;
        bool objectDB = (tableType & 0x7FFFFFFF) == 2;

        QString dbName = DatabaseModel::instance()->getString(&data);

        DatabaseListEntry entry;
        entry.name = dbName;
        entry.compressed = compressed;
        entry.objectDB = objectDB;

        //if (objectDB)
            dbList->insert(key, entry);

        endResetModel();
    }
}
