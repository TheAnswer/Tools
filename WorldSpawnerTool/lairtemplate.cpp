#include "lairtemplate.h"
#include "lairluamanager.h"
#include <QVector>
#include <QString>

#include <QTextStream>

#include "LuaSerializerHelper.h"

LairTemplate::LairTemplate(const QString& name) {
    for (uint32 i = VERYEASY; i <= VERYHARD; ++i) {
        QVector<QString>* buildings = new QVector<QString>();
        this->buildings.insert(i, buildings);
    }

    spawnLimit = 0;

    luaObjectName = name;
}

LairTemplate::~LairTemplate() {
    QMapIterator<uint32, QVector<QString>*> i(buildings);

    while (i.hasNext()) {
        i.next();

        delete i.value();
    }
}


QString LairTemplate::serializeMobileData() {
    QString data;
    QTextStream stream(&data);

    stream << "mobiles = {";

    QMapIterator<QString, uint32> i(mobiles);

    while (i.hasNext()) {
        i.next();

        stream << "{\"" << i.key() << "\", " << i.value() << "}";

        if (i.hasNext())
            stream << ",";
    }

    stream << "}";

    return data;
}

QString LairTemplate::serializeToLua() {
    QString data;
    QTextStream stream(&data);

    stream << luaObjectName << " = Lair:new {" << endl;

    stream << "\t" << serializeMobileData() << "," << endl;

    LuaSerializerHelper::addIntVariableToText(stream, "spawnLimit", spawnLimit);
    stream << "," << endl;

    LuaSerializerHelper::addStringVectorToText(stream, "buildingsVeryEasy", *buildings.value(VERYEASY));
    stream << "," << endl;

    LuaSerializerHelper::addStringVectorToText(stream, "buildingsEasy", *buildings.value(EASY));
    stream << "," << endl;

    LuaSerializerHelper::addStringVectorToText(stream, "buildingsMedium", *buildings.value(MEDIUM));
    stream << "," << endl;

    LuaSerializerHelper::addStringVectorToText(stream, "buildingsHard", *buildings.value(HARD));
    stream << "," << endl;

    LuaSerializerHelper::addStringVectorToText(stream, "buildingsVeryHard", *buildings.value(VERYHARD));

    stream << endl << "}" << endl << endl;
    stream << "addLairTemplate(\"" << luaObjectName << "\", " << luaObjectName << ")";

    return data;
}

void LairTemplate::readObject(lua_State* l) {
    spawnLimit = LuaParser::getIntField(l, "spawnLimit");

    lua_pushstring(l, "mobiles");
    lua_gettable(l, -2);

    int mobsTableSize = luaL_getn(l, -1);

    for (int i = 1; i <= mobsTableSize; ++i) {
        lua_rawgeti(l, -1, i);

        lua_rawgeti(l, -1, 1);
        QString mob(lua_tostring(l, -1));
        lua_pop(l, 1);

        lua_rawgeti(l, -1, 2);
        int level = lua_tonumber(l, -1);
        lua_pop(l, 1);

        mobiles[mob] = level;

       lua_pop(l, 1);
    }

    lua_pop(l, 1);

    lua_pushstring(l, "buildingsVeryEasy");
    lua_gettable(l, -2);

    int veryEasyTableSize = luaL_getn(l, -1);
    QVector<QString>* buildings = this->buildings.value(VERYEASY, NULL);

    if (buildings == NULL) {
        buildings = new QVector<QString>();
        this->buildings.insert(VERYEASY, buildings);
    }

    for (int i = 1; i <= veryEasyTableSize; ++i) {
        lua_rawgeti(l, -1, i);
        QString res(lua_tostring(l, -1));
        lua_pop(l, 1);

        buildings->append(res);
    }

    lua_pop(l, 1);

    lua_pushstring(l, "buildingsEasy");
    lua_gettable(l, -2);

    veryEasyTableSize = luaL_getn(l, -1);
    buildings = this->buildings.value(EASY, NULL);

    if (buildings == NULL) {
        buildings = new QVector<QString>();
        this->buildings.insert(EASY, buildings);
    }

    for (int i = 1; i <= veryEasyTableSize; ++i) {
        lua_rawgeti(l, -1, i);
        QString res(lua_tostring(l, -1));
        lua_pop(l, 1);

        buildings->append(res);
    }

    lua_pop(l, 1);

    lua_pushstring(l, "buildingsMedium");
    lua_gettable(l, -2);

    veryEasyTableSize = luaL_getn(l, -1);
    buildings = this->buildings.value(MEDIUM, NULL);

    if (buildings == NULL) {
        buildings = new QVector<QString>();
        this->buildings.insert(MEDIUM, buildings);
    }

    for (int i = 1; i <= veryEasyTableSize; ++i) {
        lua_rawgeti(l, -1, i);
        QString res(lua_tostring(l, -1));
        lua_pop(l, 1);

        buildings->append(res);
    }

    lua_pop(l, 1);


    lua_pushstring(l, "buildingsHard");
    lua_gettable(l, -2);

    veryEasyTableSize = luaL_getn(l, -1);
    buildings = this->buildings.value(HARD, NULL);

    if (buildings == NULL) {
        buildings = new QVector<QString>();
        this->buildings.insert(HARD, buildings);
    }

    for (int i = 1; i <= veryEasyTableSize; ++i) {
        lua_rawgeti(l, -1, i);
        QString res(lua_tostring(l, -1));
        lua_pop(l, 1);

        buildings->append(res);
    }

    lua_pop(l, 1);

    lua_pushstring(l, "buildingsVeryHard");
    lua_gettable(l, -2);

    veryEasyTableSize = luaL_getn(l, -1);
    buildings = this->buildings.value(VERYHARD, NULL);

    if (buildings == NULL) {
        buildings = new QVector<QString>();
        this->buildings.insert(VERYHARD, buildings);
    }

    for (int i = 1; i <= veryEasyTableSize; ++i) {
        lua_rawgeti(l, -1, i);
        QString res(lua_tostring(l, -1));
        lua_pop(l, 1);

        buildings->append(res);
    }

    lua_pop(l, 1);

}
