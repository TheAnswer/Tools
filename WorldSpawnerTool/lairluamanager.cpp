#include "lairluamanager.h"
#include "mainwindow.h"
#include "ApplicationSettings.h"
#include "settings.h"
#include "lairtemplate.h"

QString LairLuaManager::currentFile;

LairLuaManager::LairLuaManager() {
    registerGlobals();
}

void LairLuaManager::registerGlobals() {
    lua_register(L, "includeFile", includeFile);
    lua_register(L, "addLairTemplate", addLairTemplate);
}

void LairLuaManager::reload() {
    QMapIterator<QString, LairTemplate*> i(lairTemplates);

    while (i.hasNext()) {
        i.next();

        delete i.value();
    }

    lairTemplates.clear();

    QString fullDir = MainWindow::instance->getSettings()->getServerDirectory() + "/bin/scripts/mobile/lair/serverobjects.lua";

    runFile(fullDir);
}

int LairLuaManager::addLairTemplate(lua_State* L) {
    QString ascii = lua_tostring(L, -2);
    //unsigned int crc = (unsigned int) Utils::hashCode(ascii);

    MainWindow::instance->outputToConsole("inserting.." + ascii);

    LairTemplate* lair = new LairTemplate(ascii);
    lair->setFileName(currentFile);
    lair->readObject(L);

    MainWindow::instance->getLairLuaManager()->addLair(lair, ascii);

    return 0;
}

void LairLuaManager::addLair(LairTemplate* lair, const QString& name) {
    lairTemplates.insert(name, lair);
}

int LairLuaManager::includeFile(lua_State* L) {
    QString filename = lua_tostring(L, -1);
    lua_pop(L, 1);

    //MainWindow::instance->getCreatureManager()->setCurrentFileName()
    currentFile = filename;

    QString fullDir = MainWindow::instance->getSettings()->getServerDirectory() + "/bin/scripts/mobile/" + filename;

   // MainWindow::instance->outputToConsole(fullDir);

    if (luaL_loadfile(L, fullDir.toAscii()) || lua_pcall(L, 0, 0, 0)) {
        const char* err = lua_tostring(L, -1);
        lua_pop(L,1);

        QString data;
        QTextStream msg(&data);

        msg << "file:" << filename << " ERROR " << err;

        MainWindow::instance->outputToConsole(data);
    }

    return 0;
}
