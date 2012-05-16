#include "LuaParser.h"
#include "mainwindow.h"
#include <QTextStream>

void LuaParser::runFile(const QString& filename) {
    //luaL_loadfile(L, str.toAscii());

    MainWindow::instance->outputToConsole(filename);

    if (luaL_loadfile(L, filename.toAscii()) || lua_pcall(L, 0, 0, 0)) {
        const char* err = lua_tostring(L, -1);
        lua_pop(L,1);

        QString data;
        QTextStream msg(&data);

        msg << "file:" << filename << " ERROR " << err;

        MainWindow::instance->outputToConsole(data);
    }
}

float LuaParser::getFloatField(lua_State* L, const QString& key) {
    float result = 0;

    lua_pushstring(L, key.toAscii());
    lua_gettable(L, -2);

    result = (float)lua_tonumber(L, -1);
    lua_pop(L, 1);

    return result;
}

QString LuaParser::getStringField(lua_State* L, const QString& key) {
    const char* result = NULL;

    lua_pushstring(L, key.toAscii());
    lua_gettable(L, -2);

    result = lua_tostring(L, -1);
    lua_pop(L, 1);

    if (result == NULL)
        result = "";

    return QString(result);
}

unsigned int LuaParser::getIntField(lua_State* L, const QString& key) {
    unsigned int result = 0;

    lua_pushstring(L, key.toAscii());
    lua_gettable(L, -2);

    result = (unsigned int)lua_tonumber(L, -1);
    lua_pop(L, 1);

    return result;
}

void LuaParser::setGlobalInt(const QString& name, int v) {
    lua_pushnumber(L, v);
    lua_setglobal(L, name.toAscii());
}

QString LuaParser::getStringAt(int idx) {
    lua_rawgeti(L, -1, idx);
    const char* result = lua_tostring(L, -1);
    lua_pop(L, 1);

    return result;
}

float LuaParser::getFloatAt(int idx) {
    float result = 0.f;

    lua_rawgeti(L, -1, idx);
    result = (float)lua_tonumber(L, -1);
    lua_pop(L, 1);

    return result;
}

unsigned int LuaParser::getIntAt(int idx) {
    unsigned int result = 0;

    lua_rawgeti(L, -1, idx);
    result = (unsigned int)lua_tonumber(L, -1);
    lua_pop(L, 1);

    return result;
}
