#include "lootitemtemplate.h"
#include "LuaParser.h"
#include "mainwindow.h"
#include "QTextStream"

LootItemTemplate::LootItemTemplate(const QString& itemName) {
    itemTemplate = itemName;

    minimumLevel = 0;
    maximumLevel = 0;

    qualityRangeMin = CRITICALFAILURE;
    qualityRangeMax = AMAZINGSUCCESS;
}

LootItemTemplate::~LootItemTemplate() {
}

void LootItemTemplate::readObject(lua_State* L) {
    minimumLevel = LuaParser::getIntField(L, "minimumLevel");
    maximumLevel = LuaParser::getIntField(L, "maximumLevel");
    customObjectName = LuaParser::getStringField(L, "customObjectName");
    directObjectTemplate = LuaParser::getStringField(L, "directObjectTemplate");
    draftSchematic = LuaParser::getStringField(L, "draftSchematic");

    qualityRangeMin = LuaParser::getIntField(L, "qualityRangeMin");
    qualityRangeMax = LuaParser::getIntField(L, "qualityRangeMax");

    lua_pushstring(L, "experimentalSubGroupTitles");
    lua_gettable(L, -2);

    if (lua_istable(L, -1) == 1) {
        int n = luaL_getn(L, -1);

        for (int i = 1; i <= n; ++i) {
            lua_rawgeti(L, -1, i);

            QString subGroupTitle(lua_tostring(L, -1));
            experimentalSubGroupTitles.append(subGroupTitle);

            lua_pop(L, 1);
        }
    }

    lua_pop(L, 1);

    lua_pushstring(L, "experimentalMin");
    lua_gettable(L, -2);

    if (lua_istable(L, -1) == 1) {
        int n = luaL_getn(L, -1);

        for (int i = 1; i <= n; ++i) {
            lua_rawgeti(L, -1, i);

            int min = lua_tonumber(L, -1);
            experimentalMin.append(min);

            lua_pop(L, 1);
        }
    }

    lua_pop(L, 1);

    lua_pushstring(L, "experimentalMax");
    lua_gettable(L, -2);

    if (lua_istable(L, -1) == 1) {
        int n = luaL_getn(L, -1);

        for (int i = 1; i <= n; ++i) {
            lua_rawgeti(L, -1, i);

            int max = lua_tonumber(L, -1);
            experimentalMax.append(max);

            lua_pop(L, 1);
        }
    }

    lua_pop(L, 1);
}

QString LootItemTemplate::toString() const {
    return QString("{}");
}

QString LootItemTemplate::serializeToLua() {
    QString data;
    QTextStream stream(&data);

    stream << itemTemplate << " = {" << endl;
    stream << "\tminimumLevel = " << minimumLevel << "," << endl;
    stream << "\tmaximumLevel = " << maximumLevel << "," << endl;
    stream << "\tcustomObjectName = \"" << customObjectName << "\"," << endl;
    stream << "\tdirectObjectTemplate = \"" << directObjectTemplate << "\"," << endl;
    stream << "\tdraftSchematic = \"" << directObjectTemplate << "\"" << endl; //TODO: Add back in the comma later.

    /*
    stream << "\tlootItems = {" << endl;
    QMapIterator<QString, int> i(entries);

    while (i.hasNext()) {
        i.next();

        stream << "\t\t{itemTemplate = \"" << i.key() << "\", weight = " << i.value() << "}";

        if (i.hasNext())
            stream << ",";

        stream << endl;
    }

    stream << "\t}" << endl;*/

    stream << "}" << endl << endl;

    stream << "addLootItemTemplate(\"" << itemTemplate << "\", " << itemTemplate << ")";

    return data;
}
