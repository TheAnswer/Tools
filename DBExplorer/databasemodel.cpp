#include "databasemodel.h"
#include "databaseexception.h"
#include <algorithm>
#include <cwchar>
#include <QMessageBox>

DatabaseModel::DatabaseModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    db = NULL;
    hashTable = new QHash<unsigned int, IDLVar>();
    compressed = false;
    objectDB = false;
}

int DatabaseModel::rowCount(const QModelIndex & /*parent*/) const {
    return displayList.size();
}

int DatabaseModel::columnCount(const QModelIndex & /*parent*/) const {
    return 2;
}

QVariant DatabaseModel::data(const QModelIndex &index, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (index.column() == 0) // display the key
        return "0x" + QString("%1").arg(displayList.at(index.row()).first, 8, 16, QChar('0')).toUpper();

    if (index.column() == 1) // display the data
        return displayList.at(index.row()).second;

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

    try {
        db = new Database(path);
        displayList.clear();

        for (int i = 0; i < db->getSize(); ++i) {
            QByteArray ba = db->getData(i, compressed);
            unsigned long long int oid = db->getKey(i);
            if (objectDB) {
                ba = instance()->getVariable(ba, "_className");
                displayList.append(QPair<unsigned long long, QString>(oid, instance()->getString(&ba)));
            } else
                displayList.append(QPair<unsigned long long, QString>(oid, instance()->getUnicode(&ba)));
        }
    } catch (DatabaseException &e) {
        QMessageBox::critical(NULL, "Error decompressing data", e.getMsg());

        exit(-1);
    }

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

    QByteArray myData(data);

    unsigned short numVariables = instance()->getUnsignedShort(&myData);

    while (numVariables > variableList.size()) {
        // first get name (4 bytes)
        unsigned int nameHash = instance()->getUnsignedInt(&myData);
        IDLVar varInfo = hashTable->value(nameHash);
        if (varInfo.hashCode == 0) {
            varInfo.varName = "0x" + QString::number(nameHash, 16).toUpper();
            varInfo.hashCode = nameHash;
        }

        // then get size (4 bytes)
        unsigned int size = instance()->getUnsignedInt(&myData);

        // then get the actual data
        QByteArray var(myData.left(size).data(), size);
        myData.remove(0, size);

        variableList[varInfo] = var;
    }

    return variableList;
}
// Begin serialization methods
QByteArray DatabaseModel::getVariable(const QByteArray &data, QString varKey) {
    QByteArray myData(data);
    myData.remove(0, 2);

    for (unsigned int offset = 2; offset < (unsigned int)data.size();) {
        // first get name (4 bytes)
        unsigned int nameHash = instance()->getUnsignedInt(&myData);
        offset += 4;
        // then get size (4 bytes)
        unsigned int size = instance()->getUnsignedInt(&myData);
        offset += 4;
        // then get the actual data
        QByteArray var(myData.left(size).data(), size);
        myData.remove(0, size);
        offset += size;

        IDLVar varInfo = hashTable->value(nameHash);

        if (varInfo.varName == varKey)
            return var;
    }

    return QByteArray();
}

QVariant DatabaseModel::getDataByType(QByteArray *data, QString varType) {
    if (varType.contains(QRegExp("^Vector<")) || varType.contains(QRegExp("^SortedVector<"))) {
        QString subVarType = varType.section('<', 1, -1, QString::SectionSkipEmpty).simplified();
        subVarType.chop(1);

        int size = DatabaseModel::instance()->getInt(data);

        QString retVal("<");
        int i = 0;
        for (; i < size; i++) {
            retVal += instance()->getDataByType(data, subVarType).toString() + QString(":");
        }

        if (i > 0)
            retVal.chop(1);

        retVal += ">";

        return retVal;
    }

    if (varType.contains(QRegExp("^DeltaVector<"))) {
        QString subVarType = varType.section('<', 1, -1, QString::SectionSkipEmpty).simplified();
        subVarType.chop(1);

        short size = DatabaseModel::instance()->getShort(data);

        QString retVal;
        for (int i = 0; i < size; i++) {
            QString varName = instance()->getString(data);

            retVal += varName + " (";

            /*unsigned int serializedSize = */instance()->getInt(data);

            if (varName == "vector")
                retVal += instance()->getDataByType(data, "Vector<" + subVarType + ">").toString() + "); ";
            else if (varName == "updateCounter")
                retVal += QString::number(instance()->getInt(data)) + "); ";
            else if (varName == "_className")
                retVal += ");";
        }

        return retVal;
    }

    if (varType.contains(QRegExp("^VectorMapEntry<"))) {
        QString subVarType = varType.section('<', 1, -1, QString::SectionSkipEmpty).simplified();
        subVarType.chop(1);

        QString key = subVarType.section(',', 0, 0, QString::SectionSkipEmpty).simplified();

        QString value = subVarType.section(',', 1, -1, QString::SectionSkipEmpty).simplified();

        QString retVal = instance()->getDataByType(data, key).toString();
        retVal += "," + instance()->getDataByType(data, value).toString();

        return retVal;
    }

    if (varType.contains(QRegExp("^VectorMap<"))) {
        QString subVarType = varType.section('<', 1, -1, QString::SectionSkipEmpty).simplified();
        subVarType.chop(1);

        return instance()->getDataByType(data, "Vector<VectorMapEntry<" + subVarType + "> >");
    }

    if (varType.contains(QRegExp("^DeltaVectorMap<"))) {
        QString subVarType = varType.section('<', 1, -1, QString::SectionSkipEmpty).simplified();
        subVarType.chop(1);

        short size = DatabaseModel::instance()->getShort(data);

        QString retVal;
        for (int i = 0; i < size; i++) {
            QString varName = instance()->getString(data);

            retVal += varName + " (";

            /*unsigned int serializedSize = */instance()->getInt(data);

            if (varName == "vectorMap")
                retVal += instance()->getDataByType(data, "VectorMap<" + subVarType + ">").toString() + "); ";
            else if (varName == "updateCounter")
                retVal += QString::number(instance()->getInt(data)) + "); ";
            else if (varName == "_className")
                retVal += ");";
        }

        return retVal;
    }

    QVariant val;
    if (varType == "string")
        val = DatabaseModel::instance()->getString(data);
    else if (varType == "unicode")
        val = DatabaseModel::instance()->getUnicode(data);
    else if (varType == "unsigned int")
        val = DatabaseModel::instance()->getUnsignedInt(data);
    else if (varType == "unsigned short")
        val = DatabaseModel::instance()->getUnsignedShort(data);
    else if (varType == "boolean")
        val = DatabaseModel::instance()->getBoolean(data);
    else if (varType == "byte")
        val = DatabaseModel::instance()->getByte(data);
    else if (varType == "short")
        val = DatabaseModel::instance()->getShort(data);
    else if (varType == "int")
        val = DatabaseModel::instance()->getInt(data);
    else if (varType == "float")
        val = DatabaseModel::instance()->getFloat(data);
    else if (varType == "double")
        val = DatabaseModel::instance()->getDouble(data);
    else if (varType == "unsigned long")
        val = DatabaseModel::instance()->getUnsignedLong(data);
    else if (varType == "long")
        val = DatabaseModel::instance()->getLong(data);
    else
        val = "0x" + QString::number(DatabaseModel::instance()->getUnsignedLong(data), 16).toUpper();

    return val;
}

QString DatabaseModel::getString(QByteArray *data) {
    int size = *(short*)data->left(2).data();

    QString retVal = QString::fromLatin1(data->remove(0, 2).data(), size);
    data->remove(0, size);

    return retVal;
}

QString DatabaseModel::getUnicode(QByteArray *data) {
    int size = *(int*)data->left(4).data();

    QString retVal = QString::fromUtf16((ushort*)data->remove(0, 4).data(), size);
    data->remove(0, size * 2);

    return retVal;
}
