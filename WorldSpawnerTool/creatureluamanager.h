/*
 * luamanager.h
 *
 *  Created on: 15/03/2011
 *      Author: TheAnswer
 */

#ifndef LUAMANAGER_H_
#define LUAMANAGER_H_

#include "LuaParser.h"

#include <QString>

class CreatureLuaManager : public LuaParser {

    static QString currentFile;
public:
    CreatureLuaManager();

    ~CreatureLuaManager() {

    }

    void registerGlobals();

    static int includeFile(lua_State* L);
    static int addTemplate(lua_State* L);
    static int addWeapon(lua_State* L);
    static int addDynamicGroup(lua_State* L);
    static int addStaticGroup(lua_State* L);
    static int addConversationTemplate(lua_State* L);
};




#endif /* LUAMANAGER_H_ */
