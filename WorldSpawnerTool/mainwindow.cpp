#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worldmap.h"
#include "databaseconnection.h"
#include "console.h"
#include <QTextStream>
#include "insertwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include "settings.h"
#include "creaturemanager.h"
#include <QMessageBox>
#include "planetspawnregion.h"
#include "creatureluamanager.h"
#include "spawnluamanager.h"
#include "preorcreaturemanager.h"
#include "staticspawn.h"
#include <QListWidget>
#include "staticspawntableitem.h"
#include "planetselection.h"
#include <QUndoStack>
#include <QUndoView>
#include "commands.h"
#include "utils.h"
#include "lairtool.h"
#include "lairtypes.h"
#include "lairspawneditor.h"
#include "loadingdialog.h"
#include <QProgressBar>
#include <QInputDialog>

using namespace utils;

MainWindow* MainWindow::instance = NULL;
float MainWindow::VERSION = 0.02;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    instance = this;

    undoStack = new QUndoStack(this);
    undoView = new QUndoView(undoStack);
    undoStack->setUndoLimit(50);
    undoView->setWindowTitle(tr("Command List"));
    undoView->setAttribute(Qt::WA_QuitOnClose, false);

    database = new DatabaseConnection();
    console = new Console();
    insertWindow = new InsertWindow(this);
    settings = new Settings(this);
    creatureManager = new CreatureManager(this);
    luaManager = new CreatureLuaManager();
    preORManager = new PreORCreatureManager();
    spawnLuaManager = new SpawnLuaManager();
    lairLuaManager = new LairLuaManager();
    lairTypes = new LairTypes(lairLuaManager);

    setWindowTitle(getApplicationFullName());

    currentAction = 0;

    currentMap = "naboo";

    initializeWorldMaps();

    planetSelection = new PlanetSelection(this);

    createActions();

    connect(ui->actionConnect_to_database, SIGNAL(triggered()), database, SLOT(show()));
    connect(ui->actionConsole, SIGNAL(triggered()), console, SLOT(show()));
    connect(this, SIGNAL(printToConsole(QString)), console, SLOT(printLine(QString)));
    connect(database, SIGNAL(connectedToDatabase()), this, SLOT(loadDataFromDatabase()));
    connect(ui->pushButton_InsertStaticSpawn, SIGNAL(clicked()), insertWindow, SLOT(show()));
    connect(ui->actionGeneral_settings, SIGNAL(triggered()), settings, SLOT(show()));
    connect(ui->actionLoad, SIGNAL(triggered()), creatureManager, SLOT(show()));
    connect(ui->load, SIGNAL(clicked()), this, SLOT(promptToReloadPlanet()));
    connect(ui->regions, SIGNAL(currentIndexChanged(QString)), this, SLOT(updateCurrentSpawnRegionSelection(QString)));
    connect(ui->actionPreOR_Creatures, SIGNAL(triggered()), preORManager, SLOT(show()));
    connect(ui->comboBox_StaticSpawns, SIGNAL(currentIndexChanged(QString)), this, SLOT(updateStaticSpawnsTable()));
    connect(ui->lineEdit_StaticSpawnSearch, SIGNAL(textChanged(QString)), this, SLOT(searchStaticMobileSpawn(QString)));
    connect(ui->pushButton_RemoveStaticSpawn, SIGNAL(clicked()), this, SLOT(promptToDeleteStaticSpawn()));
    connect(ui->pushButton_SavePlanet, SIGNAL(clicked()), this, SLOT(saveMap()));
    connect(ui->pushButton_ChangePlanet, SIGNAL(clicked()), this, SLOT(promptToChangePlanet()));
    connect(ui->actionChange_Planet, SIGNAL(triggered()), planetSelection, SLOT(show()));
    connect(ui->tableWidget_StaticSpawns, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(staticSpawnChanged(QTableWidgetItem*)));
    connect(ui->regionRadius, SIGNAL(valueChanged(double)), this, SLOT(spawnRegionRadiusChanged()));
    connect(ui->regionX, SIGNAL(valueChanged(double)), this, SLOT(spawnRegionXChanged()));
    connect(ui->regionY, SIGNAL(valueChanged(double)), this, SLOT(spawnRegionYChanged()));
    connect(ui->tier, SIGNAL(valueChanged(int)), this, SLOT(spawnRegionTierChanged()));
    connect(ui->constant, SIGNAL(valueChanged(int)), this, SLOT(spawnRegionTierChanged()));
    connect(ui->actionLair_Tool, SIGNAL(triggered()), lairTypes, SLOT(show()));
    connect(ui->pushButton_editSpawn, SIGNAL(clicked()), this, SLOT(editSpawn()));
    connect(ui->pushButton_addSpawn, SIGNAL(clicked()), this, SLOT(addSpawn()));
    connect(ui->pushButton_removeSpawn, SIGNAL(clicked()), this, SLOT(removeSpawn()));

    ui->graphicsView->setMouseTracking(true);

    if (settings->getServerDirectory().isEmpty())
        settings->show();
    else
        planetSelection->show();

    emit printToConsole("WorldSpawnerTool started");
}

QString MainWindow::getApplicationFullName() {
    return QString("SWGEmu Creature Spawner Tool v" + QString::number(VERSION));
}

MainWindow::~MainWindow() {
    delete ui;

    QMapIterator<QString, WorldMap*> i(mapVector);

    while (i.hasNext()) {
        i.next();

        delete i.value();
    }

    mapVector.clear();

    delete database;
    delete console;
    delete insertWindow;
    delete settings;
    delete creatureManager;
    delete luaManager;
    delete preORManager;
    delete spawnLuaManager;
    delete planetSelection;
    delete lairTypes;
    delete lairLuaManager;
}

void MainWindow::createActions() {
    QAction* action = new QAction(tr("&Insert"), this);
    action->setShortcuts(QKeySequence::New);
    actions["insertAction"] = action;
    connect(action, SIGNAL(triggered()), insertWindow, SLOT(show()));
    ui->menuEdit->addAction(action);

    action = new QAction(tr("&Save"), this);
    action->setShortcuts(QKeySequence::Save);
    actions["saveAction"] = action;
    connect(action, SIGNAL(triggered()), this, SLOT(saveMap()));
    ui->menuEdit->addAction(action);

    action = new QAction(tr("&Show Command List"), this);
    connect(action, SIGNAL(triggered()), undoView, SLOT(show()));
    actions["showCommandList"] = action;
    ui->menuEdit->addAction(action);

    action = undoStack->createUndoAction(this, tr("&Undo"));
    action->setShortcuts(QKeySequence::Undo);
    actions["undoAction"] = action;
    ui->menuEdit->addAction(action);

    action = undoStack->createRedoAction(this, tr("&Redo"));
    action->setShortcuts(QKeySequence::Redo);
    actions["redoAction"] = action;
    ui->menuEdit->addAction(action);
}

void MainWindow::showInsertWindow(float x, float y) {
    insertWindow->setPositionX(x);
    insertWindow->setPositionY(y);

    insertWindow->show();
}

void MainWindow::pushUndoCommand(QUndoCommand* command) {
    undoStack->push(command);
}

void MainWindow::promptToChangePlanet() {
    if (QMessageBox::question (this, "Change planet", "Are you sure?\nAll your current changes will be lost", QMessageBox::Ok, QMessageBox::Abort) == QMessageBox::Ok) {
        planetSelection->show();
    }
}

void MainWindow::promptToReloadPlanet() {
    if (QMessageBox::question (this, "Reload planet", "Are you sure?\nAll your current changes will be lost", QMessageBox::Ok, QMessageBox::Abort) == QMessageBox::Ok) {
        reloadPlanet();
    }
}

void MainWindow::promptToDeleteStaticSpawn() {
    if (QMessageBox::question (this, "Delete", "Are you sure?", QMessageBox::Ok, QMessageBox::Abort) == QMessageBox::Ok) {
        removeCurrentStaticSpawnSelection();
    }
}

void MainWindow::saveMap() {
    if (QMessageBox::question (this, "Saving planet", "Are you sure?", QMessageBox::Save, QMessageBox::Abort) == QMessageBox::Save) {
        outputToConsole("saving planet...");

        if (settings->getServerDirectory().isEmpty()) {
            warning("No Core3 server directory specified");
            return;
        }

        QMap<QString, PlanetSpawnRegion*>* planetSpawnRegions = mapVector[currentMap]->getSpawnRegions();
        QMap<QString, QVector<StaticSpawn* >* >* staticSpawns = mapVector[currentMap]->getStaticSpawns();

        QString spawnRegionData = spawnLuaManager->serializePlanetRegions(planetSpawnRegions->values(), currentMap);
        QString staticSpawnsData = spawnLuaManager->serializeStaticSpawns(staticSpawns->values(), currentMap);

       /* emit printToConsole(spawnRegionData);
        emit printToConsole(staticSpawnsData);*/

        QString data;
        QTextStream streamData(&data);

        streamData << "-- Generated by " << getApplicationFullName() << endl;
        streamData << "-- {\"regionName\", xCenter, yCenter, radius, tier, spawnConstant, \"spawnGroup1\", [...]}" << endl;
        streamData << "-- tier: 0 = no spawn, 1 = static spawn area, 2 = dynamic spawn area, 3 = lair spawn area" << endl << endl;

        streamData << spawnRegionData << endl << endl;
        streamData << staticSpawnsData << endl;

        QString fileName = settings->getServerDirectory() + "/bin/scripts/managers/spawn_manager/" + currentMap + ".lua";

        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            emit printToConsole(data);

            QTextStream outFile(&file);
            outFile << data;

            file.close();
        } else {
            warning("could not open file " + fileName);
        }

        lairTypes->saveLairs(true);

        //save lairgroups

        spawnLuaManager->saveLairGroups();

    }
}

void MainWindow::spawnRegionXChanged() {
    WorldMap* world = mapVector[currentMap];
    PlanetSpawnRegion* region = world->getSpawnRegion(ui->regions->currentText());

    if (region == NULL)
        return;

    float x = ui->regionX->value();

    if (x != region->getWorldX())
        pushUndoCommand(new SpawnMoveCommand(region, x, region->getWorldY(), region->getWorldZ()));
}

void MainWindow::spawnRegionYChanged() {
    WorldMap* world = mapVector[currentMap];
    PlanetSpawnRegion* region = world->getSpawnRegion(ui->regions->currentText());

    if (region == NULL)
        return;

    float y = ui->regionY->value();

    if (y != region->getWorldY())
        pushUndoCommand(new SpawnMoveCommand(region, region->getWorldX(), y, region->getWorldZ()));
}

void MainWindow::spawnRegionTierChanged() {
    WorldMap* world = mapVector[currentMap];
    PlanetSpawnRegion* region = world->getSpawnRegion(ui->regions->currentText());

    if (region == NULL)
        return;

    int tier = ui->tier->value();

    if (tier != region->getTier())
        pushUndoCommand(new PlanetSpawnRegionChangeCommand(region, tier, region->getConstant(), region->getRadius()));
}

void MainWindow::spawnRegionRadiusChanged() {
    WorldMap* world = mapVector[currentMap];
    PlanetSpawnRegion* region = world->getSpawnRegion(ui->regions->currentText());

    if (region == NULL)
        return;

    float rad = ui->regionRadius->value();

    if (rad != region->getRadius())
        pushUndoCommand(new PlanetSpawnRegionChangeCommand(region, region->getTier(), region->getConstant(), rad));
}

void MainWindow::spawnRegionConstantChanged() {
    WorldMap* world = mapVector[currentMap];
    PlanetSpawnRegion* region = world->getSpawnRegion(ui->regions->currentText());

    if (region == NULL)
        return;

    int constant = ui->constant->value();

    if (constant != region->getConstant())
        pushUndoCommand(new PlanetSpawnRegionChangeCommand(region, region->getTier(), constant, region->getRadius()));
}

void MainWindow::outputToConsole(const QString& str) {
    emit printToConsole(str);
}

void MainWindow::warning(const QString& str) {
    QMessageBox::warning(NULL, "Warning", str);

    emit printToConsole(str);
}

void MainWindow::initializeWorldMaps() {
    mapVector.insert("tatooine", new WorldMap("tatoiine"));
    mapVector.insert("corellia", new WorldMap("corellia"));
    mapVector.insert("dantooine", new WorldMap("dantooine"));
    mapVector.insert("dathomir", new WorldMap("dathomir"));
    mapVector.insert("endor", new WorldMap("endor"));
    mapVector.insert("lok", new WorldMap("lok"));
    mapVector.insert("naboo", new WorldMap("naboo"));
    mapVector.insert("rori", new WorldMap("rori"));
    mapVector.insert("talus", new WorldMap("talus"));
    mapVector.insert("yavin4", new WorldMap("yavin4"));
}

void MainWindow::editSpawn() {
    if (ui->tier->value() != 3) {
        warning("Only regions with tier 3 are editable. Please change it");
        return;
    }

    QListWidgetItem* item = ui->spawnsList->currentItem();

    if (item == NULL)
        return;

    QString name = item->text();

    LairGroup* group = spawnLuaManager->getLairGroup(name);

    if (group == NULL) {
        warning("Only tier 3/lair group spawns available for edit");
        return;
    }

    LairSpawnEditor editor(group, this);
    editor.exec();
}

void MainWindow::removeSpawn() {
    if (ui->tier->value() != 3) {
        warning("Only regions with tier 3 are editable. Please change it");
        return;
    }

    QListWidgetItem* item = ui->spawnsList->currentItem();

    if (item == NULL)
        return;

    QString name = item->text();

    LairGroup* group = spawnLuaManager->getLairGroup(name);

    if (group == NULL) {
        warning("Only tier 3/lair group spawns available for edit/remove");
        return;
    }

    QString currentRegion = ui->regions->currentText();
    PlanetSpawnRegion* region = getCurrentWorldMap()->getSpawnRegion(currentRegion);

    if (region == NULL)
        return;

    delete ui->spawnsList->takeItem(ui->spawnsList->currentRow());
    region->removeSpawn(name);
}

void MainWindow::addSpawn() {
    if (ui->tier->value() != 3) {
        warning("Only regions with tier 3 are editable. Please change it");
        return;
    }

    bool ok;
    QString text = QInputDialog::getText(this, tr("Spawn"), tr("New Spawn"), QLineEdit::Normal, "", &ok);

    if (!ok) {
        return;
    }

    if (text.isEmpty()) {
        warning("Invalid spawn name");
        return;
    }

    if (ui->spawnsList->findItems(text, Qt::MatchFixedString).size() > 0) {
        warning("Lair spawn already exists");
        return;
    }

    QString currentRegion = ui->regions->currentText();
    PlanetSpawnRegion* region = getCurrentWorldMap()->getSpawnRegion(currentRegion);

    if (region == NULL)
        return;

    LairGroup* group = spawnLuaManager->getLairGroup(text);

    if (group == NULL) {
        group = new LairGroup(text);
        spawnLuaManager->insertLairGroup(text, group);
    }

    ui->spawnsList->addItem(text);

    region->addSpawn(group->getName());
}

void MainWindow::changeWorldMap() {
    currentMap = planetSelection->getCurrentPlanetSelection();

    reloadPlanet();
}

void MainWindow::loadDataFromDatabase() {
    QMapIterator<QString, WorldMap*> i(mapVector);

    while (i.hasNext()) {
        i.next();

        WorldMap* map = i.value();
        map->loadCityRegions();
        map->loadNoBuildZones();
    }
}

void MainWindow::reloadPlanet() {
    LoadingDialog dialog(this);
    dialog.setText("world map");
    dialog.show();

    currentMap = planetSelection->getCurrentPlanetSelection();

    ui->tableWidget_StaticSpawns->clearContents();
    ui->tableWidget_StaticSpawns->setColumnCount(6);
    ui->tableWidget_StaticSpawns->setRowCount(0);

    ui->regions->clear();
    ui->comboBox_StaticSpawns->clear();

    WorldMap* oldMap = mapVector[currentMap];
    mapVector[currentMap] = new WorldMap(currentMap);

    ui->graphicsView->setScene(mapVector[currentMap]);

    delete oldMap;

    dialog.setProgress(10);
    dialog.setText("spawn lua manager");

    QString serverDir = settings->getServerDirectory();

    undoStack->clear();

    delete spawnLuaManager;
    spawnLuaManager = new SpawnLuaManager();

    dialog.setProgress(15);
    dialog.setText("spawn planet regions");

    QVector<PlanetSpawnRegion*> regions = spawnLuaManager->loadPlanetRegions(currentMap, serverDir);

    for (int i = 0; i < regions.size(); ++i) {
        mapVector[currentMap]->addSpawnRegion(regions.at(i)->getRegionName(), regions.at(i));

        ui->regions->addItem(regions.at(i)->getRegionName());
    }

    dialog.setProgress(20);
    dialog.setText("static spawns");

    QVector<StaticSpawn* > staticSpawns = spawnLuaManager->loadStaticSpawns(currentMap, serverDir);

    mapVector[currentMap]->addStaticSpawns(staticSpawns);

    ui->comboBox_StaticSpawns->setDuplicatesEnabled(false);

    for (int i = 0; i < staticSpawns.size(); ++i) {
        if (ui->comboBox_StaticSpawns->findText(staticSpawns.at(i)->getMobile()) == -1)
            ui->comboBox_StaticSpawns->addItem(staticSpawns.at(i)->getMobile());
    }

    dialog.setProgress(30);
    dialog.setText("spawn groups");
    spawnLuaManager->loadSpawnGroups(serverDir);

    dialog.setText("creature manager");
    dialog.setProgress(40);
    creatureManager->loadCreatureObjects();

    dialog.setProgress(80);
    dialog.setText("lair types");
    lairTypes->loadCurrentLairTypes(true);

    dialog.setProgress(100);
    dialog.setText("done");
}

void MainWindow::updateStaticSpawnTableItem(StaticSpawn* spawn) {
    StaticSpawnTableItem* tableItem = getStaticSpawnTableItem(spawn);
    if (tableItem == NULL)
        return;

    int row = tableItem->row();

    tableItem = getStaticSpawnTableData(row, StaticSpawnTableItem::POSITIONX);

    float posX = tableItem->text().toFloat();

    if (posX != spawn->getWorldX()) {
        tableItem->setText(tr("%1").arg(spawn->getWorldX()));
    }

    tableItem = getStaticSpawnTableData(row, StaticSpawnTableItem::POSITIONY);
    float posY = tableItem->text().toFloat();

    if (posY != spawn->getWorldY()) {
        tableItem->setText(tr("%1").arg(spawn->getWorldY()));
    }

    tableItem = getStaticSpawnTableData(row, StaticSpawnTableItem::POSITIONZ);
    float posZ = tableItem->text().toFloat();

    if (posZ != spawn->getWorldZ()) {
        tableItem->setText(tr("%1").arg(spawn->getWorldZ()));
    }

    tableItem = getStaticSpawnTableData(row, StaticSpawnTableItem::HEADING);
    float heading = tableItem->text().toFloat();

    if (heading != spawn->getHeading()) {
        tableItem->setText(tr("%1").arg(spawn->getHeading()));
    }

    tableItem = getStaticSpawnTableData(row, StaticSpawnTableItem::RESPAWN);
    uint32 respawn = tableItem->text().toUInt();

    if (respawn != spawn->getRespawnTimer()) {
        tableItem->setText(tr("%1").arg(spawn->getRespawnTimer()));
    }

    tableItem = getStaticSpawnTableData(row, StaticSpawnTableItem::PARENTID);
    uint64 parentID = tableItem->text().toULongLong();

    if (parentID != spawn->getParentID()) {
        tableItem->setText(tr("%1").arg(spawn->getParentID()));
    }
}

void MainWindow::updateStaticSpawnsTable() {
    ui->tableWidget_StaticSpawns->clearContents();
    ui->tableWidget_StaticSpawns->setColumnCount(6);
    ui->tableWidget_StaticSpawns->setRowCount(0);

    QString currentMobile = ui->comboBox_StaticSpawns->currentText();

    QVector<StaticSpawn* >* spawns = mapVector[currentMap]->getMobileStaticSpawns(currentMobile);

    if (spawns != NULL) {
        for (int i = 0; i < spawns->size(); ++i) {
            StaticSpawn* spawn = spawns->at(i);

            insertStaticSpawnToTable(spawn);
        }
    }
}

void MainWindow::staticSpawnChanged(QTableWidgetItem* item) {
    StaticSpawnTableItem* tableItem = dynamic_cast<StaticSpawnTableItem*>(item);

    if (item == NULL)
        return;

    StaticSpawn* spawn = tableItem->getSpawn();

    switch (tableItem->column()) {
    case StaticSpawnTableItem::POSITIONX:
        if (spawn->getWorldX() != tableItem->text().toFloat()) {
            pushUndoCommand(new SpawnMoveCommand(spawn, tableItem->text().toFloat(), spawn->getWorldY(), spawn->getWorldZ()));
            updateCurrentItemPosition(tableItem->text().toFloat(), spawn->getWorldY());
        }

        break;
    case StaticSpawnTableItem::POSITIONY:
        if (spawn->getWorldY() != tableItem->text().toFloat()) {
            pushUndoCommand(new SpawnMoveCommand(spawn, spawn->getWorldX(), tableItem->text().toFloat(), spawn->getWorldZ()));
            updateCurrentItemPosition(spawn->getWorldX(), tableItem->text().toFloat());
        }

        break;
    case StaticSpawnTableItem::POSITIONZ:
        if (spawn->getWorldZ() != tableItem->text().toFloat()) {
            pushUndoCommand(new SpawnMoveCommand(spawn, spawn->getWorldX(), spawn->getWorldY(), tableItem->text().toFloat()));
        }

        break;
    case StaticSpawnTableItem::PARENTID:
        if (spawn->getParentID() != tableItem->text().toULongLong())
            pushUndoCommand(new StaticSpawnChangeCommand(spawn, spawn->getRespawnTimer(), spawn->getHeading(), tableItem->text().toULongLong()));

        break;
    case StaticSpawnTableItem::HEADING:
        if (spawn->getHeading() != tableItem->text().toFloat())
            pushUndoCommand(new StaticSpawnChangeCommand(spawn, spawn->getRespawnTimer(), tableItem->text().toFloat(), spawn->getParentID()));

        break;
    case StaticSpawnTableItem::RESPAWN:
        if (spawn->getRespawnTimer() != tableItem->text().toUInt())
            pushUndoCommand(new StaticSpawnChangeCommand(spawn, tableItem->text().toUInt(), spawn->getHeading(), spawn->getParentID()));

        break;
    default:
        emit outputToConsole("unkown column in MainWindow::staticSpawnChanged " + QString::number(tableItem->column()));
        break;
    }

}

void MainWindow::removeStaticSpawn(StaticSpawn* spawn) {
    mapVector[currentMap]->removeStaticSpawn(spawn);
    StaticSpawnTableItem* tableItem = getStaticSpawnTableItem(spawn);

    if (tableItem != NULL)
        ui->tableWidget_StaticSpawns->removeRow(tableItem->row());
}

void MainWindow::removeCurrentStaticSpawnSelection() {
    QList<QTableWidgetItem*> selected = ui->tableWidget_StaticSpawns->selectedItems();

    QMap<int, StaticSpawn*> singleRows;

    for (int i = 0; i < selected.size(); ++i) {
        QTableWidgetItem* tableItem = selected.at(i);
        StaticSpawnTableItem* spawnTableItem(dynamic_cast<StaticSpawnTableItem*>(tableItem));

        if (spawnTableItem == NULL)
            continue;

        int row = tableItem->row();

        if (!singleRows.contains(row)) {
            StaticSpawn* spawn(spawnTableItem->getSpawn());

            singleRows.insert(row, spawn);
        }
    }

    QMapIterator<int, StaticSpawn* > rowIterator(singleRows);

    while (rowIterator.hasNext()) {
        rowIterator.next();

        pushUndoCommand(new RemoveStaticSpawnCommand(rowIterator.value()));
    }
}

void MainWindow::insertStaticSpawnToTable(StaticSpawn* spawn) {
    int row = ui->tableWidget_StaticSpawns->rowCount();
    ui->tableWidget_StaticSpawns->insertRow(row);

    QTableWidgetItem* newItem = new StaticSpawnTableItem(spawn, tr("%1").arg(spawn->getWorldX()));
    ui->tableWidget_StaticSpawns->setItem(row, StaticSpawnTableItem::POSITIONX, newItem);

    newItem = new StaticSpawnTableItem(spawn, tr("%1").arg(spawn->getWorldZ()));
    ui->tableWidget_StaticSpawns->setItem(row, StaticSpawnTableItem::POSITIONZ, newItem);

    newItem = new StaticSpawnTableItem(spawn, tr("%1").arg(spawn->getWorldY()));
    ui->tableWidget_StaticSpawns->setItem(row, StaticSpawnTableItem::POSITIONY, newItem);

    newItem = new StaticSpawnTableItem(spawn, tr("%1").arg(spawn->getHeading()));
    ui->tableWidget_StaticSpawns->setItem(row, StaticSpawnTableItem::HEADING, newItem);

    newItem = new StaticSpawnTableItem(spawn, tr("%1").arg(spawn->getRespawnTimer()));
    ui->tableWidget_StaticSpawns->setItem(row, StaticSpawnTableItem::RESPAWN, newItem);

    newItem = new StaticSpawnTableItem(spawn, tr("%1").arg(spawn->getParentID()));
    ui->tableWidget_StaticSpawns->setItem(row, StaticSpawnTableItem::PARENTID, newItem);
}

void MainWindow::insertStaticSpawn(StaticSpawn* spawn) {
    mapVector[currentMap]->addStaticSpawn(spawn);

    ui->comboBox_StaticSpawns->setDuplicatesEnabled(false);

    if (ui->comboBox_StaticSpawns->findText(spawn->getMobile()) == -1)
        ui->comboBox_StaticSpawns->addItem(spawn->getMobile());
    else
        updateStaticSpawnsTable();

    updateCurrentStaticSpawnSelection(spawn);
}

void MainWindow::insertSingleSpawn(InsertWindow* window) {
    float posX = window->getPositionX();
    float posY = window->getPositionY();
    float posZ = window->getPositionZ();

    QString templateFile = window->getMobile();
    float heading = window->getHeading();
    unsigned long long parentid = window->getParentID();

    StaticSpawn* spawn = new StaticSpawn();
    spawn->setWorldX(posX);
    spawn->setWorldY(posY);
    spawn->setWorldZ(posZ);
    spawn->setMobile(templateFile);
    spawn->setHeading(heading);
    spawn->setParentID(parentid);

    undoStack->push(new InsertStaticSpawnCommand(spawn));
}

void MainWindow::updateCurrentItemPosition(float x, float y) {
    QString str;
    QTextStream stream(&str);
    stream << "x:" << x << " y:" << y;

    ui->textBrowser->setText(str);
}

void MainWindow::searchStaticMobileSpawn(const QString& str) {
    int idx = ui->comboBox_StaticSpawns->findText(str, Qt::MatchContains);

    if (idx != -1)
        ui->comboBox_StaticSpawns->setCurrentIndex(idx);
}

StaticSpawnTableItem* MainWindow::getStaticSpawnTableItem(StaticSpawn* spawn) {
    for (int i = 0; i < ui->tableWidget_StaticSpawns->rowCount(); ++i) {
        StaticSpawnTableItem* tableItem = dynamic_cast<StaticSpawnTableItem*>(ui->tableWidget_StaticSpawns->item(i, 0));

        if (tableItem == NULL)
            continue;

        if (tableItem->getSpawn() == spawn) {
            return tableItem;
        }
    }

    return NULL;
}

void MainWindow::updateCurrentStaticSpawnSelection(StaticSpawn* spawn) {
    searchStaticMobileSpawn(spawn->getMobile());

    ui->tableWidget_StaticSpawns->setCurrentItem(getStaticSpawnTableItem(spawn));
}

void MainWindow::updateCurrentSpawnRegionSelection(const QString& name) {
    int idx = ui->regions->findText(name);

    if (idx != -1)
        ui->regions->setCurrentIndex(idx);

    WorldMap* worldMap = mapVector[currentMap];

    PlanetSpawnRegion* region = worldMap->getSpawnRegion(name);

    if (region != NULL) {
        if (ui->regionRadius->value() != region->getRadius())
            ui->regionRadius->setValue(region->getRadius());

        if (ui->regionX->value() != region->getWorldX())
            ui->regionX->setValue(region->getWorldX());

        if (ui->regionY->value() != region->getWorldY())
            ui->regionY->setValue(region->getWorldY());

        if (ui->tier->value() != region->getTier())
            ui->tier->setValue(region->getTier());

        if (ui->constant->value() != region->getConstant())
            ui->constant->setValue(region->getConstant());

        ui->spawnsList->clear();

        QVector<QString>* spawns = region->getSpawns();

        for (int i = 0; i < spawns->size(); ++i)
            ui->spawnsList->addItem(spawns->at(i));

        //region->setSelected(true);

        worldMap->selectPlanetSpawnRegion(name);
    }

}

void MainWindow::changeEvent(QEvent *e) {
    QMainWindow::changeEvent(e);
    /*switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }*/
}

StaticSpawnTableItem* MainWindow::getStaticSpawnTableData(int row, int column) {
    return dynamic_cast<StaticSpawnTableItem*>(ui->tableWidget_StaticSpawns->item(row, column));
}
