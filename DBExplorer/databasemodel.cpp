#include "databasemodel.h"
#include <algorithm>
#include <cwchar>
#include <QMessageBox>

DatabaseModel::DatabaseModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    db = NULL;
    hashTable = new QHash<unsigned int, IDLVar>();
}

int DatabaseModel::rowCount(const QModelIndex & /*parent*/) const {
    if (db == NULL)
        return 0;

    DB_HASH_STAT* stats = new DB_HASH_STAT();

    db->getDb().stat(NULL, &stats, 0);

    int size = stats->hash_ndata;

    delete stats;

    return size;
}

int DatabaseModel::columnCount(const QModelIndex & /*parent*/) const {
    return 2;
}

QVariant DatabaseModel::data(const QModelIndex &index, int role) const {
    if (role != Qt::DisplayRole || db == NULL)
        return QVariant();

    unsigned long long int oid = db->getKey(index.row());
    try {
        if (index.column() == 0) // display the key
            return "0x" + QByteArray::number(oid, 16).toUpper();

        if (index.column() == 1) {// display the data
            if (instance()->hasStringEntries()) {
                QByteArray ba = db->getData(index.row());
                return instance()->getString(ba);
            }

            IDLVar _className;
            _className.className = "";
            _className.hashCode = 0x76457CCA;
            _className.varName = "_className";
            _className.varType = "string";

            QByteArray ba = db->getData(index.row());

            return instance()->getString(instance()->getVariableList(ba).value(_className));
        }

    } catch (DatabaseException &e) {
        QMessageBox::critical(NULL, "Error decompressing data", e.getMsg());

        exit(-1);
    }

    return QVariant();
}

QVariant DatabaseModel::headerData(int section, Qt::Orientation orientation, int role) const {
        if (role != Qt::DisplayRole)
            return QVariant();

        if (orientation == Qt::Horizontal) {
            if (section == 0) return QString("OID");
            if (section == 1) return QString("ClassName");
        } else
            return QString("%1").arg(section);

        return QVariant();
 }

void DatabaseModel::open(QString& path) {
    if (db != NULL)
        delete db;

    dbName = path;

    beginResetModel();
    db = new Database(path);
    endResetModel();
}

void DatabaseModel::close() {
    if (db != NULL) {
        delete db;
        db = NULL;
    }
}

// Begin serialization methods
QMap<IDLVar, QByteArray> DatabaseModel::getVariableList(const QByteArray &data) {
    QMap<IDLVar, QByteArray> variableList;
    if (instance()->hasStringEntries())
        return variableList;

    unsigned short numVariables = instance()->getUnsignedShort(data);

    for (unsigned int offset = 2; offset < (unsigned int)data.size() && numVariables > variableList.size();) {
        // first get name (4 bytes)
        unsigned int nameHash = instance()->getUnsignedInt(data.mid(offset, 4));
        offset += 4;
        // then get size (4 bytes)
        unsigned int size = instance()->getUnsignedInt(data.mid(offset, 4));
        offset += 4;
        // then get the actual data
        QByteArray var(data.mid(offset, size).data(), size);
        offset += size;

        IDLVar varInfo = hashTable->value(nameHash);

        variableList[varInfo] = var;
    }

    return variableList;
}

QString DatabaseModel::getString(const QByteArray &data) {
    QByteArray myData(data);
    int size = *(short*)myData.left(2).data();

    return QString::fromAscii(myData.remove(0, 2).data(), size);
}

QString DatabaseModel::getUnicode(const QByteArray &data) {
    QByteArray myData(data);
    int size = *(int*)myData.left(4).data();

    return QString::fromWCharArray((wchar_t*)myData.remove(0, 4).data(), size);
}
