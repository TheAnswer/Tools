#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui/QGraphicsScene>
#include <QVector>
#include <QByteArray>
#include <QTableWidgetItem>

namespace Ui {
    class MainWindow;
}

class DatabaseConnection;
class Console;
class WorldMap;
class InsertWindow;
class Settings;
class CreatureManager;
class CreatureLuaManager;
class PreORCreatureManager;
class SpawnLuaManager;
class StaticSpawn;
class PlanetSelection;
class StaticSpawnTableItem;
class QUndoStack;
class QUndoView;
class QUndoCommand;
class LairTypes;
class LairLuaManager;

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    Ui::MainWindow *ui;

    QMap<QString, WorldMap*> mapVector;

    DatabaseConnection* database;
    Console* console;
    InsertWindow* insertWindow;
    Settings* settings;
    CreatureManager* creatureManager;
    CreatureLuaManager* luaManager;
    PreORCreatureManager* preORManager;
    SpawnLuaManager* spawnLuaManager;
    PlanetSelection* planetSelection;
    LairTypes* lairTypes;
    LairLuaManager* lairLuaManager;

    QMap<QString, QAction*> actions;

    QUndoStack* undoStack;
    QUndoView* undoView;


    QString currentMap;

    int currentAction;

public:
    static MainWindow* instance;
    static float VERSION;

    const static int INSERT = 1;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    StaticSpawnTableItem* getStaticSpawnTableItem(StaticSpawn* spawn);
    void insertStaticSpawn(StaticSpawn* spawn);
    void pushUndoCommand(QUndoCommand* command);
    StaticSpawnTableItem* getStaticSpawnTableData(int row, int column);
    void updateStaticSpawnTableItem(StaticSpawn* spawn);
    QString getApplicationFullName();

public slots:
    void outputToConsole(const QString& str);
    void warning(const QString& str);
    void loadDataFromDatabase();
    void updateCurrentItemPosition(float x, float y);
    void insertSingleSpawn(InsertWindow* window);
    void reloadPlanet();
    void updateCurrentSpawnRegionSelection(const QString& name);
    void updateCurrentStaticSpawnSelection(StaticSpawn* spawn);
    void updateStaticSpawnsTable();
    void searchStaticMobileSpawn(const QString& name);
    void removeCurrentStaticSpawnSelection();
    void removeStaticSpawn(StaticSpawn* spawn);
    void staticSpawnChanged(QTableWidgetItem* item);
    void promptToChangePlanet();
    void promptToReloadPlanet();
    void promptToDeleteStaticSpawn();
    void spawnRegionXChanged();
    void spawnRegionYChanged();
    void spawnRegionTierChanged();
    void spawnRegionRadiusChanged();
    void spawnRegionConstantChanged();
    void editSpawn();
    void addSpawn();
    void removeSpawn();

    void changeWorldMap();
    void saveMap();

    void showInsertWindow(float x, float y);

protected:
    void changeEvent(QEvent *e);
    void initializeWorldMaps();
    void createActions();
  //  void loadRegionData(QByteArray& buffer, int& currentPosition, bool open = false);

    void insertStaticSpawnToTable(StaticSpawn* spawn);

public:
    inline QList<QString> getMapList() {
        return mapVector.keys();
    }

    inline WorldMap* getWorldMap(const QString& name) {
        return mapVector.value(name, NULL);
    }

    inline DatabaseConnection* getDatabase() {
        return database;
    }

    inline Settings* getSettings() {
        return settings;
    }

    inline CreatureLuaManager* getLuaManager() {
        return luaManager;
    }

    inline LairLuaManager* getLairLuaManager() {
        return lairLuaManager;
    }

    inline CreatureManager* getCreatureManager() {
        return creatureManager;
    }

    inline WorldMap* getCurrentWorldMap() {
        return mapVector.value(currentMap, NULL);
    }

    inline LairTypes* getLairTypes() {
        return lairTypes;
    }


signals:
    void printToConsole(const QString& str);


};

#endif // MAINWINDOW_H
