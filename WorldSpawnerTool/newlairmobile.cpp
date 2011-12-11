#include "newlairmobile.h"
#include "ui_newlairmobile.h"
#include "mainwindow.h"
#include "creaturemanager.h"

NewLairMobile::NewLairMobile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewLairMobile) {
    ui->setupUi(this);

    connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(showExistingMobiles()));
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(mobileChanged(QListWidgetItem*)));
}


NewLairMobile::~NewLairMobile() {
    delete ui;
}

QString NewLairMobile::getMobile() {
    return ui->lineEdit_mobile->text();
}

int NewLairMobile::getLevel() {
    return ui->spinBox_level->value();
}

void NewLairMobile::mobileChanged(QListWidgetItem* item) {
    if (item == NULL)
        return;

    QString name = item->text();

    ui->lineEdit_mobile->setText(name);
}

void NewLairMobile::showExistingMobiles() {
    CreatureManager* manager = MainWindow::instance->getCreatureManager();

    QList<QString> mobiles = manager->getMobiles();

    if (mobiles.isEmpty()) {
        manager->loadCreatureObjects();
    }

    mobiles = manager->getMobiles();

    ui->listWidget->clear();

    for (int i = 0; i < mobiles.size(); ++i) {
        QString mobile = mobiles.at(i);

        ui->listWidget->addItem(mobile);
    }

    ui->listWidget->setEnabled(true);
}
