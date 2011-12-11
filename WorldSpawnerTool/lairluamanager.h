#ifndef LAIRLUAMANAGER_H
#define LAIRLUAMANAGER_H

#include "LuaParser.h"
#include <QMap>

class LairTemplate;

class LairLuaManager : public LuaParser {
    static QString currentFile;

    QMap<QString, LairTemplate*> lairTemplates;
public:
    LairLuaManager();

    void reload();

    void registerGlobals();

    static int includeFile(lua_State* L);
    static int addLairTemplate(lua_State* L);

    void addLair(LairTemplate* lair, const QString& name);

    QMap<QString, LairTemplate*>* getLairTemplates() {
        return &lairTemplates;
    }


};

#endif // LAIRLUAMANAGER_H
