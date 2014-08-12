#ifndef IDLPARSER_H
#define IDLPARSER_H

#include <QString>
#include <QDir>
#include <QFileInfo>
#include <QHash>

class IDLVar {
public:
    unsigned int hashCode;
    QString varType;
    QString className;
    QString varName;

    bool operator<(const IDLVar & var) const {
        return className + "." + varName < var.className + "." + var.varName;
    }
};

class IDLParser
{
public:
    IDLParser();
    static void parseIDLs(QDir baseDir, QHash<unsigned int, IDLVar>* hashTable);
    static void parseIDL(QFileInfo fileName, QHash<unsigned int, IDLVar>* hashTable);

private:
};

#endif // IDLPARSER_H
