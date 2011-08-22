#include "preorcreaturemanager.h"
#include "ui_preorcreaturemanager.h"
#include <QFileDialog>
#include "mainwindow.h"
#include <QTextStream>

PreORCreatureManager* PreORCreatureManager::instance = NULL;
QString PreORCreatureManager::fileOpen;

PreORCreatureManager::PreORCreatureManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreORCreatureManager) {
    ui->setupUi(this);

    planetID = 0;

    instance = this;

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(openDirectory()));

    registerGlobals();
    registerFunctions();
}

PreORCreatureManager::~PreORCreatureManager() {
    delete ui;
}

void PreORCreatureManager::registerGlobals() {
    setGlobalInt("ATTACKABLE_FLAG", 1);
    setGlobalInt("AGGRESSIVE_FLAG", 2);
    setGlobalInt("ENEMY_FLAG", 0x20);
    setGlobalInt("NPC_FLAG", 0x15);
    setGlobalInt("PLANET_ID", planetID);
    setGlobalInt("JAWA", 0);
    setGlobalInt("GUNGAN", 1);
    setGlobalInt("BARTENDER", 3);
    setGlobalInt("MEDDROID", 2);
    setGlobalInt("EWOK", 4);
    setGlobalInt("JEDI", 5);
}

void PreORCreatureManager::registerFunctions() {
    //lua generic
    lua_register(L, "RunCreatureFile", runCreatureFile);
    lua_register(L, "RunObjectFile", runObjectFile);

    lua_register(L, "RegisterCreatureWithServer", registerCreature);

    lua_register(L, "AddCreatureToServer", addCreature);
    lua_register(L, "AddLairToServer", addLair);

    lua_register(L, "AddBlueFrogToServer", addBlueFrog);
    lua_register(L, "AddJunkDealerToServer", addJunkDealer);
}

int PreORCreatureManager::registerCreature(lua_State *L) {
    QString speciesName = getStringField(L, "speciesName");
    unsigned int crc = getIntField(L, "objectCRC");
    QString objectName = getStringField(L, "objectName");

    /*if (instance->names.contains(speciesName))
        MainWindow::instance->outputToConsole("conflicting speciesName " + speciesName);
    else {
        instance->namews.append(speciesName);
    }

    if (instance->crcs.contains(crc))
        MainWindow::instance->outputToConsole("conflicting crc " + QString::number(crc));
    else {
        instance->crcs.append(crc);
    }*/

    instance->ui->listWidget->addItem(objectName);

    if (instance->names.contains(speciesName)) {
        QString text;
        QTextStream stream(&text);

        stream << "name was registered in:" << instance->names.value(speciesName) <<  " while running " << fileOpen;
        MainWindow::instance->outputToConsole(text);

    } else {
        instance->names[speciesName] = fileOpen;
    }

    if (instance->crcs.contains(crc)) {
        /* QString text;
        QTextStream stream(&text);

        stream << "names was registered in:" << instance->crcs.value(crc) <<  " while running " << fileOpen;
        MainWindow::instance->outputToConsole(text);*/

    } else {
        instance->crcs[crc] = objectName;
    }

    //lua_pop(L, 1);

    return 0;
}

int PreORCreatureManager::addCreature(lua_State *L) {
    return 0;
}

int PreORCreatureManager::addLair(lua_State *L) {
    unsigned int objectCRC = getIntField(L, "objectCRC");

    MainWindow::instance->outputToConsole(QString::number(objectCRC) + " addLair");

    return 0;
}

int PreORCreatureManager::addBlueFrog(lua_State *L) {
    return 0;
}

int PreORCreatureManager::addJunkDealer(lua_State *L) {
    return 0;
}


int PreORCreatureManager::runCreatureFile(lua_State* L) {
    QString filename = lua_tostring(L, -1);
    lua_pop(L, 1);

    QString fullDir = instance->ui->lineEdit->text() + "/bin/scripts/creatures/" + filename;

    // MainWindow::instance->outputToConsole(fullDir);

    fileOpen = fullDir;

    if (luaL_loadfile(L, fullDir.toAscii()) || lua_pcall(L, 0, 0, 0)) {
        const char* err = lua_tostring(L, -1);
        lua_pop(L,1);

        QString data;
        QTextStream msg(&data);

        msg << "file:" << filename << " ERROR " << err;

        MainWindow::instance->outputToConsole(data);
    }

    //MainWindow::instance->outputToConsole(filename);

    return 0;
}

int PreORCreatureManager::runObjectFile(lua_State* L) {

    QString filename = lua_tostring(L, -1);
    lua_pop(L, 1);

    QString fullDir = instance->ui->lineEdit->text() + "/bin/scripts/sceneobjects/" + filename;

    MainWindow::instance->outputToConsole(fullDir);

    fileOpen = fullDir;

    if (luaL_loadfile(L, fullDir.toAscii()) || lua_pcall(L, 0, 0, 0)) {
        const char* err = lua_tostring(L, -1);
        lua_pop(L,1);

        QString data;
        QTextStream msg(&data);

        msg << "file:" << filename << " ERROR " << err;

        MainWindow::instance->outputToConsole(data);
    }

    /*String filename = getStringParameter(L);

    int idx = filename.lastIndexOf('/');
    String templatename;

    if (filename.indexOf("objects/") != -1  &&
            idx != filename.indexOf('/')) {

        int idx2 = filename.indexOf('.', idx);
        if (idx2 != -1)
            templatename = filename.subString(idx + 1, idx2);
        else
            templatename = filename.subString(idx + 1, filename.length());
    }

    runFile("scripts/sceneobjects/" + filename, L);


    // only add lairs that are spawnable, don't add the zone lair files...
    if (templatename.indexOf("Lairs") == -1 && templatename.length() > 0) {
        // Load lair from lua
        LuaFunction getObject(L, "getObject", 1);
        String tempstr = templatename;
        getObject << tempstr; // push first argument
        callFunction(&getObject);

        LuaObject result(L);
        if (!result.isValidTable()) {
            System::out << "Unknown lair type " << tempstr << endl;
            return NULL;
        }

        uint32 creatureCRC = result.getLongField("creatureCRC");

        instance->localLairs.put(templatename, creatureCRC);
    }*/

    return 0;
}

void PreORCreatureManager::openDirectory() {
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);

    ui->lineEdit->setText(dir);

    //QString fullDir = dir + "/bin/scripts/creatures/main.lua";
    QString fullDir = dir + "/bin/scripts/sceneobjects/main.lua";

    MainWindow::instance->outputToConsole(fullDir);

    for (int i = 0; i < 10; ++i) {
        setGlobalInt("PLANET_ID", i);

        if (luaL_loadfile(L, fullDir.toAscii()) || lua_pcall(L, 0, 0, 0)) {
            const char* err = lua_tostring(L, -1);
            lua_pop(L,1);

            QString data;
            QTextStream msg(&data);

            msg << "file:" << fullDir << " ERROR " << err;

            MainWindow::instance->outputToConsole(data);
        }
    }

    MainWindow::instance->outputToConsole("loaded names: " + QString::number(names.size()));
    MainWindow::instance->outputToConsole("loaded crcs: " + QString::number(crcs.size()));


}
