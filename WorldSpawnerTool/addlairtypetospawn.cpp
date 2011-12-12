#include "addlairtypetospawn.h"
#include "ui_addlairtypetospawn.h"
#include <QListWidgetItem>
#include "mainwindow.h"
#include "lairtypes.h"

AddLairTypeToSpawn::AddLairTypeToSpawn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLairTypeToSpawn) {
    ui->setupUi(this);

    connect(ui->pushButton_lairTool, SIGNAL(clicked()), this, SLOT(openLairTool()));

    reloadMobileList();
}

AddLairTypeToSpawn::~AddLairTypeToSpawn() {
    delete ui;
}

void AddLairTypeToSpawn::reloadMobileList() {
    ui->listWidget_lairs->clear();

    LairTypes* lairs = MainWindow::instance->getLairTypes();

    QList<QString> types = lairs->getLairTypes();

    for (int i = 0; i < types.size(); ++i)
        ui->listWidget_lairs->addItem(types.at(i));
}

QString AddLairTypeToSpawn::getSelectedLair() {
    QListWidgetItem* item = ui->listWidget_lairs->currentItem();

    if (item != NULL)
        return item->text();
    else
        return "";
}

void AddLairTypeToSpawn::openLairTool() {
    LairTypes* lairs = MainWindow::instance->getLairTypes();

    if (!lairs->exec())
        return;

    reloadMobileList();
}
