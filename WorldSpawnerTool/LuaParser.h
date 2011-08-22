#ifndef LUAPARSER_H
#define LUAPARSER_H

#include <QFile>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

class LuaParser {
protected:
    lua_State* L;
public:
    LuaParser() {
        L = lua_open();
        luaL_openlibs(L);
    }

    ~LuaParser() {
        lua_close(L);
    }

    void runFile(const QString& str);

    void setGlobalInt(const QString& name, int v);

    static QString getStringField(lua_State* L, const QString& key);
    static unsigned int getIntField(lua_State* L, const QString& key);
    static float getFloatField(lua_State* L, const QString& key);

    QString getStringAt(int idx);
    float getFloatAt(int idx);
    unsigned int getIntAt(int idx);

};

#endif // LUAPARSER_H
