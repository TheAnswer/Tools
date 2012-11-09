#include "lootitemtemplate.h"
#include "LuaParser.h"
#include "mainwindow.h"
#include "QTextStream"

LootItemTemplate::LootItemTemplate(const QString& itemName) {
    itemTemplate = itemName;

    minimumLevel = 0;
    maximumLevel = -1;
}

LootItemTemplate::~LootItemTemplate() {
}

void LootItemTemplate::readObject(lua_State* L) {
    minimumLevel = LuaParser::getIntField(L, "minimumLevel");
    maximumLevel = LuaParser::getIntField(L, "maximumLevel");
    customObjectName = LuaParser::getStringField(L, "customObjectName");
    directObjectTemplate = LuaParser::getStringField(L, "directObjectTemplate");

    lua_pushstring(L, "craftingValues");
    lua_gettable(L, -2);

    if (lua_istable(L, -1) == 1) {
        int n = luaL_getn(L, -1);

        for (int i = 1; i <= n; ++i) {
            lua_rawgeti(L, -1, i);

            if (lua_istable(L, -1) == 1) {
                lua_rawgeti(L, -1, 1);

                QString subGroupTitle(lua_tostring(L, -1));
                experimentalSubGroupTitles.append(subGroupTitle);

                lua_pop(L, 1);

                lua_rawgeti(L, -1, 2);

                float min = lua_tonumber(L, -1);
                experimentalMin.append(min);

                lua_pop(L, 1);

                lua_rawgeti(L, -1, 3);

                float max = lua_tonumber(L, -1);
                experimentalMax.append(max);

                lua_pop(L, 1);

                if (luaL_getn(L, -1) > 3) {
                    lua_rawgeti(L, -1, 4);

                    float max = lua_tonumber(L, -1);
                    experimentalPrecision.append(max);

                    lua_pop(L, 1);
                } else
                    experimentalPrecision.append(0);
            }

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
                int c = luaL_getn(L, -1);
                for (int j = 1; j <= c; ++j) {
                    lua_rawgeti(L, -1, j);

                    if (j == 1) {
                        quint8 min = lua_tonumber(L, -1);
                        customizationValueMin.append(min);
                    } else if (j == c) {
                        quint8 max = lua_tonumber(L, -1);
                        customizationValueMax.append(max);
                    }

                    lua_pop(L, 1);
                }
            }

            lua_pop(L, 1);
        }
    }

    lua_pop(L, 1);

    lua_pushstring(L, "skillMods");
    lua_gettable(L, -2);

    if (lua_istable(L, -1) == 1) {
        int n = luaL_getn(L, -1);

        for (int i = 1; i <= n; ++i) {
            lua_rawgeti(L, -1, i);

            if (lua_istable(L, -1) == 1) {
                int c = luaL_getn(L, -1);
                for (int j = 1; j <= c; ++j) {
                    lua_rawgeti(L, -1, j);

                    if (j == 1) {
                        QString skillName = lua_tostring(L, -1);
                        skillModsNames.append(skillName);
                    } else if (j == 2) {
                        quint8 value = lua_tonumber(L, -1);
                        skillModsValues.append(value);
                    }

                    lua_pop(L, 1);
                }
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

    stream << "\tcraftingValues = {" << endl;

    for (int i = 0; i < experimentalSubGroupTitles.count(); ++i) {
        stream << "\t\t{\"" << experimentalSubGroupTitles.at(i) << "\"," << experimentalMin.at(i) << "," << experimentalMax.at(i) << "," << experimentalPrecision.at(i) << "}," << endl;
    }

    stream << "\t}," << endl;

    QString customizationStrings;
    QString customizationValues;

    for (int i = 0; i < customizationStringNames.count(); ++i) {
        customizationStrings.append("\"" + customizationStringNames.at(i) + "\",");
        customizationValues.append("{");
        if (customizationValueMin.at(i) < customizationValueMax.at(i)) {
            for (int j = customizationValueMin.at(i); j <= customizationValueMax.at(i); j++) {
                customizationValues.append(QString::number(j) + ",");
            }
            customizationValues.chop(1); //Remove trailing comma
        }
        customizationValues.append("},");
    }

    customizationStrings.chop(1); //Remove trailing comma
    customizationValues.chop(1); //Remove trailing comma

    stream << "\tcustomizationStringNames = {" << customizationStrings << "}," << endl;
    stream << "\tcustomizationValues = {" << customizationValues << "}," << endl;

    stream << "\tskillMods = {" << endl;

    QString skillModsString;
    for (int i = 0; i < skillModsNames.count(); ++i) {
        skillModsString.append("\t\t{\"" + skillModsNames.at(i) + "\"," + QString::number(skillModsValues.at(i)) + "},\n");
    }
    skillModsString.chop(2); // Remove trailing new line and comma

    stream << skillModsString << endl << "\t}" << endl;

    stream << "}" << endl << endl;

    stream << "addLootItemTemplate(\"" << itemTemplate << "\", " << itemTemplate << ")";

    return data;
}

void LootItemTemplate::clearAllExperimentalProperties() {
    experimentalSubGroupTitles.clear();
    experimentalMin.clear();
    experimentalMax.clear();
    experimentalPrecision.clear();
}

void LootItemTemplate::clearAllCustomizationVariables() {
    customizationStringNames.clear();
    customizationValueMin.clear();
    customizationValueMax.clear();
}

void LootItemTemplate::clearAllSkillMods() {
    skillModsNames.clear();
    skillModsValues.clear();
}

void LootItemTemplate::addExperimentalProperty(const QString& property, float min, float max, float precision) {
    experimentalSubGroupTitles.append(property);
    experimentalMin.append(min);
    experimentalMax.append(max);
    experimentalPrecision.append(precision);
}

void LootItemTemplate::addCustomizationVariable(const QString& property, quint8 min, quint8 max) {
    customizationStringNames.append(property);
    customizationValueMin.append(min);
    customizationValueMax.append(max);
}

void LootItemTemplate::addSkillMod(const QString& skillName, quint8 value) {
    skillModsNames.append(skillName);
    skillModsValues.append(value);
}

