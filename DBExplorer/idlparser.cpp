#include "idlparser.h"
#include "crccalculator.h"
#include <QFile>
#include <QTextStream>
#include <QRegExp>
#include <QDebug>

IDLParser::IDLParser()
{
}

// returns a QHash of IDLVars indexed by calculated CRCs
void IDLParser::parseIDLs(QDir baseDir, QHash<unsigned int, IDLVar>* hashTable) {
    qDebug() << "parsing idl" << baseDir;

    QFileInfoList list = baseDir.entryInfoList();
    for (int i = 0; i < list.size(); i++) {
        QFileInfo fileInfo = list.at(i);
        if (fileInfo.fileName() == ".." || fileInfo.fileName() == ".")
            continue;

        if (fileInfo.isDir())
            parseIDLs(QDir(fileInfo.absoluteFilePath()), hashTable);
        else if (fileInfo.isSymLink())
            parseIDLs(QDir(fileInfo.symLinkTarget()), hashTable);
        else if (fileInfo.isFile())
            IDLParser::parseIDL(fileInfo, hashTable);
    }
}

void IDLParser::parseIDL(QFileInfo fileName, QHash<unsigned int, IDLVar>* hashTable) {
    if (!fileName.exists() || fileName.fileName().indexOf(".idl") == -1)
        return;

    QFile idlFile(fileName.absoluteFilePath());
    if (!idlFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&idlFile);
    QString line, className;
    bool comment = false;
    do {
        line = in.readLine().simplified();

        if (comment) {
            int endIdx = -1;
            if ((endIdx = line.indexOf("*/")) != -1) {
                comment = false;
                line.remove(0, endIdx + 2);
            } else
                continue;
        }

        int commentIdx = -1;
        if ((commentIdx = line.indexOf("/*")) != -1) {
            comment = true;
            line.remove(commentIdx, line.length());
        }

        if (line.contains("class")) {
            className = line.section(' ', 1, 1, QString::SectionSkipEmpty);
            continue;
        }

        QRegExp filterEx("[\\{\\}\\(\\)=]|^include |^import |^package |^class ");
        QRegExp matchEx("^protected |^public ");
        if (!line.contains(matchEx) || line.contains(filterEx) || line.isEmpty() )
            continue;

        if ((commentIdx = line.indexOf("//")) != -1) {
            line.remove(commentIdx, line.length());
        }

        line = line.remove(matchEx).simplified();
        line = line.remove("transient ").simplified();
        line = line.remove("static ").simplified();
        line = line.remove(";").simplified();
        IDLVar idlVar;
        idlVar.className = className;
        idlVar.varName = line.section(' ', -1, -1, QString::SectionSkipEmpty);
        idlVar.varType = line.section(' ', 0, -2, QString::SectionSkipEmpty);
        QString stringToHash = idlVar.className + "." + idlVar.varName;
        idlVar.hashCode = CRCCalculator::hashCode(stringToHash.toStdString().c_str(), stringToHash.size());

        hashTable->insert(idlVar.hashCode, idlVar);
    } while (!line.isNull());
}
