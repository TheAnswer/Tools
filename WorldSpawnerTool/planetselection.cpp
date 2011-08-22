#include "planetselection.h"
#include "ui_planetselection.h"
#include "mainwindow.h"

PlanetSelection::PlanetSelection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlanetSelection) {
    ui->setupUi(this);

    MainWindow* main = dynamic_cast<MainWindow*>(parent);

    QList<QString> maps = main->getMapList();

    for (int i = 0; i < maps.size(); ++i) {
        ui->comboBox->addItem(maps.at(i));
    }

    connect(ui->pushButton, SIGNAL(clicked()), parent, SLOT(show()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(hide()));
    connect(ui->pushButton, SIGNAL(clicked()), parent, SLOT(changeWorldMap()));
}

PlanetSelection::~PlanetSelection() {
    delete ui;
}

QString PlanetSelection::getCurrentPlanetSelection() {
    return ui->comboBox->currentText();
}
