#ifndef LUASERIALIZERHELPER_H
#define LUASERIALIZERHELPER_H

#include <QTextStream>
#include <QString>

class LuaSerializerHelper {
public:
    static void addStringVariableToText(QTextStream& stream, const QString& varName, const QString& var);
    static void addIntVariableToText(QTextStream& stream, const QString& varName, int var);
    static void addFloatVariableToText(QTextStream& stream, const QString& varName, float var);

    static void addStringVectorToText(QTextStream& stream, const QString& varName, QVector<QString>& var);


    template<typename V>
    static void addVectorToText(QTextStream& stream, const QString& varName, QVector<V>& var) {
        stream << "\t" << varName << " = {";

        for (int i = 0; i < var.size(); ++i) {
            V value = var.at(i);

            stream << value;

            if (i + 1 < var.size())
                stream << ",";
        }

        stream << "}";
    }
};

#endif // LUASERIALIZERHELPER_H
