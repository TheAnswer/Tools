#include "lairspawneditor.h"
#include "ui_lairspawneditor.h"
#include "lairtool.h"
#include "mainwindow.h"
#include "lairluamanager.h"
#include "addlairtypetospawn.h"

LairSpawnEditor::LairSpawnEditor(LairGroup* group, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LairSpawnEditor) {
    ui->setupUi(this);

    this->group = group;

    setWindowTitle(group->getName());

    updateData();

    connect(ui->pushButton_edit, SIGNAL(clicked()), this, SLOT(editLairType()));
    connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(addLairType()));
    connect(ui->pushButton_remove, SIGNAL(clicked()), this, SLOT(removeLairType()));
    connect(ui->spinBox_maxSpawnLimit, SIGNAL(valueChanged(int)), this, SLOT(maxSpawnLimitChanged()));
    connect(ui->listWidget_lairs, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), this, SLOT(updateCurrentLair(QListWidgetItem*,QListWidgetItem*)));
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(acceptedChanges()));
    //connect()
}

LairSpawnEditor::~LairSpawnEditor() {
    delete ui;
}

void LairSpawnEditor::showEvent(QShowEvent * event) {
    QDialog::showEvent(event);

    clearCurrentLairData();
}

void LairSpawnEditor::acceptedChanges() {
    QListWidgetItem* item = ui->listWidget_lairs->currentItem();

    if (item == NULL)
        return;

    commitCurrentData(item);
}

void LairSpawnEditor::removeLairType() {
    QListWidgetItem* item = ui->listWidget_lairs->currentItem();

    if (item == NULL)
        return;

    group->removeSpawnEntry(item->text());

    delete ui->listWidget_lairs->takeItem(ui->listWidget_lairs->currentRow());
}

void LairSpawnEditor::maxSpawnLimitChanged() {
   group->setMaxSpawnLimit(ui->spinBox_maxSpawnLimit->value());
}

void LairSpawnEditor::addLairType() {
    AddLairTypeToSpawn tool(this);
    tool.exec();

    QString selectedLair = tool.getSelectedLair();

    if (selectedLair.isEmpty())
        return;

    if (group->getSpawnEntry(selectedLair) != NULL) {
        MainWindow::instance->warning("Lair already in the list");
        return;
    }

    LairSpawnEntry* entry = new LairSpawnEntry(selectedLair);
    group->addSpawnEntry(entry);

    QListWidgetItem* newItem = new QListWidgetItem(selectedLair, ui->listWidget_lairs);

    ui->listWidget_lairs->addItem(newItem);
}

void LairSpawnEditor::updateData() {
    ui->spinBox_maxSpawnLimit->setValue(group->getMaxSpawnLimit());

    QVector<LairSpawnEntry*>* entries = group->getSpawnEntries();

    ui->listWidget_lairs->clear();

    for (int i = 0; i < entries->size(); ++i) {
        LairSpawnEntry* entry = entries->at(i);

        ui->listWidget_lairs->addItem(entry->getLairTemplateName());
    }

    if (entries->size() > 0) {
        updateCurrentLair(ui->listWidget_lairs->item(0), NULL);
    }
}

void LairSpawnEditor::commitCurrentData(QListWidgetItem* item) {
    LairSpawnEntry* entry = group->getSpawnEntry(item->text());

    if (entry == NULL)
        return;

    entry->setSpawnLimit(ui->spinBox_spawnLimit->value());
    entry->setMinDifficulty(ui->spinBox_minDifficulty->value());
    entry->setMaxDifficulty(ui->spinBox_maxDifficulty->value());
    entry->setNumberToSpawn(ui->spinBox_numberToSpawn->value());
    entry->setWeighting(ui->spinBox_weighting->value());
    entry->setSize(ui->spinBox_size->value());
}

void LairSpawnEditor::updateCurrentLair(QListWidgetItem* item, QListWidgetItem* previous) {
    if (item == previous)
        return;

    if (previous != NULL)
        commitCurrentData(previous);

    if (item == NULL) {
        clearCurrentLairData();
        return;
    }

    LairSpawnEntry* entry = group->getSpawnEntry(item->text());

    if (entry == NULL) {
        clearCurrentLairData();
    } else {
        ui->label_lairTypeSelected->setText(entry->getLairTemplateName());
        ui->spinBox_maxDifficulty->setValue(entry->getMaxDifficulty());
        ui->spinBox_minDifficulty->setValue(entry->getMinDifficulty());
        ui->spinBox_numberToSpawn->setValue(entry->getNumberToSpawn());
        ui->spinBox_size->setValue(entry->getSize());
        ui->spinBox_weighting->setValue(entry->getWeighting());
    }
}

void LairSpawnEditor::clearCurrentLairData() {
    ui->label_lairTypeSelected->setText("No lair selected");
    ui->spinBox_maxDifficulty->setValue(0);
    ui->spinBox_minDifficulty->setValue(0);
    ui->spinBox_numberToSpawn->setValue(0);
    ui->spinBox_size->setValue(0);
    ui->spinBox_weighting->setValue(0);
}

LairSpawnEntry* LairSpawnEditor::getCurrentEntry() {
    QListWidgetItem* item = ui->listWidget_lairs->currentItem();

    if (item == NULL)
        return NULL;

    return group->getSpawnEntry(item->text());
}

void LairSpawnEditor::editLairType() {
    QListWidgetItem* item = ui->listWidget_lairs->currentItem();

    if (item == NULL)
        return;

    QString name = item->text();

    LairLuaManager* luaManager = MainWindow::instance->getLairLuaManager();
    QMap<QString, LairTemplate*>* lairTemplates = luaManager->getLairTemplates();

    LairTemplate* lairTemplate = lairTemplates->value(name, NULL);

    if (lairTemplate == NULL) {
        MainWindow::instance->warning("Lair not found to edit");

        return;
    }

    LairTool tool(this);
    tool.setTemplate(lairTemplate);
    tool.exec();
}
