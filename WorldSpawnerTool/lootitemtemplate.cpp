#include "lootitemtemplate.h"
#include "LuaParser.h"
#include "mainwindow.h"
#include "QTextStream"

LootItemTemplate::LootItemTemplate(const QString& itemName) {
    itemTemplate = itemName;

    minimumLevel = 0;
    maximumLevel = -1;

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

            float min = lua_tonumber(L, -1);
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

            float max = lua_tonumber(L, -1);
            experimentalMax.append(max);

            lua_pop(L, 1);
        }
    }

    lua_pop(L, 1);

    lua_pushstring(L, "customizationStringNames");
    lua_gettable(L, -2);

    if (lua_istable(L, -1) == 1) {
        int n = luaL_getn(L, -1);

        for (int i = 1; i <= n; ++i) {
            lua_rawgeti(L, -1, i);

            QString stringName(lua_tostring(L, -1));
            customizationStringNames.append(stringName);

            lua_pop(L, 1);
        }
    }

    lua_pop(L, 1);

    lua_pushstring(L, "customizationValues");
    lua_gettable(L, -2);

    if (lua_istable(L, -1) == 1) {
        int n = luaL_getn(L, -1);

        for (int i = 1; i <= n; ++i) {
            lua_rawgeti(L, -1, i);

            if (lua_istable(L, -1) == 1) {
                lua_rawgeti(L, -1, i);

                quint8 min = lua_tonumber(L, -1);
                customizationValueMin.append(min);

                lua_pop(L, 1);

                lua_rawgeti(L, -1, i);

                quint8 max = lua_tonumber(L, -1);
                customizationValueMax.append(max);

                lua_pop(L, 1);
            }

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
    stream << "\tdraftSchematic = \"" << draftSchematic << "\"," << endl;

    QString expTitles;
    QString expMins;
    QString expMaxs;

    for (int i = 0; i < experimentalSubGroupTitles.count(); ++i) {
        expTitles.append("\"" + experimentalSubGroupTitles.at(i) + "\",");
        expMins.append(QString::number(experimentalMin.at(i)) + ",");
        expMaxs.append(QString::number(experimentalMax.at(i)) + ",");
    }

    expTitles.chop(1);
    expMins.chop(1);
    expMaxs.chop(1);

    stream << "\texperimentalSubGroupTitles = {" << expTitles << "}," << endl;
    stream << "\texperimentalMin = {" << expMins << "}," << endl;
    stream << "\texperimentalMax = {" << expMaxs << "}," << endl;

    //TODO: Insert assembly success.
    stream << "\tqualityRangeMin = " << qualityRangeMin << "," << endl;
    stream << "\tqualityRangeMax = " << qualityRangeMax << "," << endl;

    QString customizationStrings;
    QString customizationValues;

    for (int i = 0; i < customizationStringNames.count(); ++i) {
        customizationStrings.append("\"" + customizationStringNames.at(i) + "\",");
        customizationValues.append("{" + QString::number(customizationValueMin.at(i)) + "," + QString::number(customizationValueMax.at(i)) + "},");
    }

    customizationStrings.chop(1); //Remove trailing comma
    customizationValues.chop(1); //Remove trailing comma

    stream << "\tcustomizationStringNames = {" << customizationStrings << "}," << endl;
    stream << "\tcustomizationValues = {" << customizationValues << "}" << endl;

    stream << "}" << endl << endl;

    stream << "addLootItemTemplate(\"" << itemTemplate << "\", " << itemTemplate << ")";

    return data;
}

void LootItemTemplate::clearAllExperimentalProperties() {
    experimentalSubGroupTitles.clear();
    experimentalMin.clear();
    experimentalMax.clear();
}

void LootItemTemplate::clearAllCustomizationVariables() {
    customizationStringNames.clear();
    customizationValueMin.clear();
    customizationValueMax.clear();
}

void LootItemTemplate::addExperimentalProperty(const QString& property, float min, float max) {
    experimentalSubGroupTitles.append(property);
    experimentalMin.append(min);
    experimentalMax.append(max);
}

void LootItemTemplate::addCustomizationVariable(const QString& property, quint8 min, quint8 max) {
    customizationStringNames.append(property);
    customizationValueMin.append(min);
    customizationValueMax.append(max);
}

