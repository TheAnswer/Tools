#ifndef PREORCREATUREMANAGER_H
#define PREORCREATUREMANAGER_H

#include <QDialog>

#include "LuaParser.h"
#include <QVector>
#include <QMap>

namespace Ui {
    class PreORCreatureManager;
}

class PreORCreatureManager : public QDialog, public LuaParser
{
    Q_OBJECT

public:
    explicit PreORCreatureManager(QWidget *parent = 0);
    ~PreORCreatureManager();

    static PreORCreatureManager* instance;
    static QString fileOpen;

public slots:
    void openDirectory();
    void registerFunctions();

    static int runCreatureFile(lua_State* L);
    static int runObjectFile(lua_State* L);

    static int registerCreature(lua_State *L);
    static int addCreature(lua_State *L);
    static int addLair(lua_State * L);

    static int addBlueFrog(lua_State *L);
    static int addJunkDealer(lua_State* L);


private:
    Ui::PreORCreatureManager *ui;
    int planetID;

    void registerGlobals();

    //QVector<QString> names;
    QMap<QString, QString> names;

    QMap<unsigned int, QString> crcs;

};

#endif // PREORCREATUREMANAGER_H
