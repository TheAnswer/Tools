#include "lairtool.h"
#include "ui_lairtool.h"
#include "mainwindow.h"

LairTool::LairTool(QWidget *parent) : QDialog(parent), ui(new Ui::LairTool) {
    ui->setupUi(this);

    currentTemplate = NULL;

    nameMobileForm = new NewLairMobile(this);
    nameBuildingForm = new LairName(this);

    connect(ui->pushButton_addMobile, SIGNAL(clicked()), nameMobileForm, SLOT(show()));
    connect(ui->pushButton_AddBuilding, SIGNAL(clicked()), nameBuildingForm, SLOT(show()));
    connect(nameMobileForm, SIGNAL(accepted()), this, SLOT(addMobile()));
    connect(nameBuildingForm, SIGNAL(accepted()), this, SLOT(addBuilding()));
    connect(ui->pushButton_RemoveBuilding, SIGNAL(clicked()), this, SLOT(removeBuilding()));
    connect(ui->pushButton_removeMobile, SIGNAL(clicked()), this, SLOT(removeMobile()));
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(commitToTemplate()));
}

LairTool::~LairTool() {
    //MainWindow::instance->outputToConsole("destroying window");

    delete ui;
    delete nameMobileForm;
    delete nameBuildingForm;
}

void LairTool::commitBuildings(QListWidget* list, int type) {
    QVector<QString>* buildings = currentTemplate->getBuildings(type);
    buildings->clear();

    for (int i = 0; i < list->count(); ++i) {
        buildings->append(list->item(i)->text());
    }
}

void LairTool::commitToTemplate() {
    if (currentTemplate == NULL)
        return;

    currentTemplate->setSpawnLimit(ui->spinBox->value());

    QMap<QString, uint32>* mobiles = currentTemplate->getMobiles();
    mobiles->clear();

    for (int i = 0; i < ui->listWidget_mobiles->count(); ++i) {
        QListWidgetItem* item = ui->listWidget_mobiles->item(i);

        QString data = item->text();

        QString mobile = data.section('\t', 0, 0);
        QString level = data.section('\t', 1, 1);

        mobiles->insert(mobile, level.toInt());
    }

    commitBuildings(ui->listWidget_veryEasy, LairTemplate::VERYEASY);
    commitBuildings(ui->listWidget_easy, LairTemplate::EASY);
    commitBuildings(ui->listWidget_Medium, LairTemplate::MEDIUM);
    commitBuildings(ui->listWidget_Hard, LairTemplate::HARD);
    commitBuildings(ui->listWidget_veryHard, LairTemplate::VERYHARD);
}

QListWidget* LairTool::getCurrentBuildingList() {
    int idx = ui->tabWidget_buildings->currentIndex();

    QListWidget* list = NULL;

    switch (idx) {
    case LairTemplate::VERYEASY:
        list = ui->listWidget_veryEasy;
        break;
    case LairTemplate::EASY:
        list = ui->listWidget_easy;
        break;
    case LairTemplate::MEDIUM:
         list = ui->listWidget_Medium;
        break;
    case LairTemplate::HARD:
         list = ui->listWidget_Hard;
        break;
    case LairTemplate::VERYHARD:
         list = ui->listWidget_veryHard;
        break;
    }

    return list;
}

void LairTool::removeBuilding() {
    QListWidget* list = getCurrentBuildingList();

    if (list == NULL)
        return;

    int idx = list->currentRow();

    delete list->takeItem(idx);
}

void LairTool::removeMobile() {
    int idx = ui->listWidget_mobiles->currentRow();

    delete ui->listWidget_mobiles->takeItem(idx);
}

void LairTool::addBuilding() {
    QString text = nameBuildingForm->getName();

    if (text.isEmpty())
        return;

    QListWidget* list = getCurrentBuildingList();

    if (list == NULL)
        return;

    list->addItem(text);
}

void LairTool::addMobile() {
    QString mobile = nameMobileForm->getMobile();

    if (mobile.isEmpty())
        return;

    int lvl = nameMobileForm->getLevel();

    QString level = QString::number(lvl);
    QString item = mobile + "\t" + level;

    ui->listWidget_mobiles->addItem(item);
}

void LairTool::setTemplate(LairTemplate* templ) {
    currentTemplate = templ;

    setWindowTitle(currentTemplate->getName());

    QMap<QString, uint32>* mobiles = currentTemplate->getMobiles();

    ui->listWidget_mobiles->clear();

    QMapIterator<QString, uint32> i(*mobiles);

    while (i.hasNext()) {
        i.next();

        QString mobile = i.key();
        QString level = QString::number((int)i.value());
        QString item = mobile + "\t" + level;

        ui->listWidget_mobiles->addItem(item);
    }

    ui->spinBox->setValue(currentTemplate->getSpawnLimit());

    QVector<QString>* buildings = currentTemplate->getBuildings(LairTemplate::VERYEASY);
    updateBuildings(buildings, ui->listWidget_veryEasy);

    buildings = currentTemplate->getBuildings(LairTemplate::EASY);
    updateBuildings(buildings, ui->listWidget_easy);

    buildings = currentTemplate->getBuildings(LairTemplate::MEDIUM);
    updateBuildings(buildings, ui->listWidget_Medium);

    buildings = currentTemplate->getBuildings(LairTemplate::HARD);
    updateBuildings(buildings, ui->listWidget_Hard);

    buildings = currentTemplate->getBuildings(LairTemplate::VERYHARD);
    updateBuildings(buildings, ui->listWidget_veryHard);
}

void LairTool::updateBuildings(QVector<QString>* buildings, QListWidget* list) {
    list->clear();

    for (int i = 0; i < buildings->size(); ++i) {
        list->addItem(buildings->at(i));
    }
}
