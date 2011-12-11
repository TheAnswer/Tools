#include "LuaSerializerHelper.h"
#include <QVector>
#include <QString>

void LuaSerializerHelper::addStringVectorToText(QTextStream& stream, const QString& varName, QVector<QString>& var) {
    stream << "\t" << varName << " = {";

    for (int i = 0; i < var.size(); ++i) {
        QString value = var.at(i);

        stream << "\"" << value << "\"";

        if (i + 1 < var.size())
            stream << ",";
    }

    stream << "}";
}

void LuaSerializerHelper::addStringVariableToText(QTextStream& stream, const QString& varName, const QString& var) {
    stream << "\t" << varName << " = \"" << var << "\"";
}

void LuaSerializerHelper::addIntVariableToText(QTextStream& stream, const QString& varName, int var) {
    stream << "\t" << varName << " = " << var << "";
}

void LuaSerializerHelper::addFloatVariableToText(QTextStream& stream, const QString& varName, float var) {
    stream << "\t" << varName << " = " << var << "";
}
