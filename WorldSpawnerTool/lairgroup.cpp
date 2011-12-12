#include "lairgroup.h"
#include "LuaParser.h"
#include <QTextStream>

LairGroup::LairGroup(const QString& name) {
    this->name = name;

    maxSpawnLimit = 0;
}

LairGroup::~LairGroup() {
    for (int i = 0; i < spawnEntries.size(); ++i)
        delete spawnEntries.at(i);
}

QString LairGroup::serializeToLua() {
    QString data;
    QTextStream stream(&data);

    stream << name << " = {" << endl;
    stream << "\twanderRadius = 10," << endl;
    stream << "\tcommandLevel = 0," << endl << endl;
    stream << "\ttype = LAIR," << endl;

    stream << "\tmaxSpawnLimit = " << maxSpawnLimit << "," << endl << endl;

    stream << "\tlairSpawns = {" << endl;

    for (int i = 0; i < spawnEntries.size(); ++i) {
        LairSpawnEntry* entry = spawnEntries.at(i);

        stream << "\t\t{" << endl;

        stream << "\t\t\tlairTemplateName = \"" << entry->lairTemplateName << "\"," << endl;
        stream << "\t\t\tspawnLimit = "<< entry->spawnLimit << "," << endl;
        stream << "\t\t\tminDifficulty = "<< entry->minDifficulty << "," << endl;
        stream << "\t\t\tmaxDifficulty = "<< entry->maxDifficulty << "," << endl;
        stream << "\t\t\tnumberToSpawn = "<< entry->numberToSpawn << "," << endl;
        stream << "\t\t\tweighting = "<< entry->weighting << "," << endl;
        stream << "\t\t\tsize = "<< entry->size << endl;

        stream << "\t\t}";

        if (i + 1 < spawnEntries.size())
            stream << ",";

        stream << endl;
    }

    stream << "\t}" << endl;
    stream << "}" << endl << endl;

    stream << "addLairGroup(\"" << name << "\", " << name << ");" << endl;

    return data;
}

void LairGroup::readObject(lua_State* L) {
    maxSpawnLimit = LuaParser::getIntField(L, "maxSpawnLimit");

    lua_pushstring(L, "lairSpawns");
    lua_gettable(L, -2);

    int tableSize = luaL_getn(L, -1);

    for (int i = 1; i <= tableSize; ++i) {
        lua_rawgeti(L, -1, i);

        if (lua_istable(L, -1)) {
            LairSpawnEntry* entry = new LairSpawnEntry(LuaParser::getStringField(L, "lairTemplateName"));

            entry->spawnLimit = LuaParser::getIntField(L, "spawnLimit");
            entry->minDifficulty = LuaParser::getIntField(L, "minDifficulty");
            entry->maxDifficulty = LuaParser::getIntField(L, "maxDifficulty");
            entry->numberToSpawn = LuaParser::getIntField(L, "numberToSpawn");
            entry->weighting = LuaParser::getIntField(L, "weighting");
            entry->size = LuaParser::getIntField(L, "size");

            spawnEntries.append(entry);
        }

        lua_pop(L, 1);
    }

    lua_pop(L, 1);
}
