#include "lootgroup.h"
#include "mainwindow.h"
#include "QVector"
#include "LuaParser.h"
#include "lootluamanager.h"
#include "QTextStream"

LootGroup::LootGroup(const QString& name) {
    minimumLevel = 0;
    maximumLevel = 0;

    groupName = name;
}

LootGroup::~LootGroup() {
}

void LootGroup::readObject(lua_State* L) {
    LootLuaManager* luaManager = MainWindow::instance->getLootLuaManager();

    description = LuaParser::getStringField(L, "description");
    minimumLevel = LuaParser::getIntField(L, "minimumLevel");
    maximumLevel = LuaParser::getIntField(L, "maximumLevel");

    lua_pushstring(L, "lootItems");
    lua_gettable(L, -2);

    int totalItems = luaL_getn(L, -1);

    for (int i = 1; i <= totalItems; ++i) {
        lua_rawgeti(L, -1, i);

        QString itemTemplate = LuaParser::getStringField(L, "itemTemplate");
        int weight = LuaParser::getIntField(L, "weight");

        if (!luaManager->itemTemplateExists(itemTemplate))
            continue;

        QExplicitlySharedDataPointer<LootItemTemplate> lootItemTemplate = luaManager->getItemTemplate(itemTemplate);
        lootItemTemplate->registerLootGroup(groupName);

        addLootItemTemplate(itemTemplate, weight);

        lua_pop(L, 1);
    }

    lua_pop(L, 1);
}

QString LootGroup::toString() const {
    return QString(groupName + " {Minimum Level: %1 Maximum Level: %2 Total Entries: %3}").arg(minimumLevel).arg(maximumLevel).arg(entries.count());
}

void LootGroup::addLootItemTemplate(const QString& templateName, int chance) {
    entries.insert(templateName, chance);
}

void LootGroup::removeLootItemTemplate(const QString& templateName) {
    entries.remove(templateName);
}

QString LootGroup::serializeToLua() {
    QString data;
    QTextStream stream(&data);

    stream << groupName << " = {" << endl;
    stream << "\tdescription = \"" << description << "\"," << endl;
    stream << "\tminimumLevel = " << minimumLevel << "," << endl;
    stream << "\tmaximumLevel = " << maximumLevel << "," << endl;
    stream << "\tlootItems = {" << endl;

    QMapIterator<QString, int> i(entries);

    while (i.hasNext()) {
        i.next();

        stream << "\t\t{itemTemplate = \"" << i.key() << "\", weight = " << i.value() << "}";

        if (i.hasNext())
            stream << ",";

        stream << endl;
    }

    stream << "\t}" << endl;
    stream << "}" << endl << endl;

    stream << "addLootGroupTemplate(\"" << groupName << "\", " << groupName << ")";

    return data;
}
