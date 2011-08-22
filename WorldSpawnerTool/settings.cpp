#include "settings.h"
#include "ui_settings.h"

#include <QFileDialog>
#include "mainwindow.h"

Settings::Settings(MainWindow* mainWindow, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings) {

    ui->setupUi(this);
    settings = new ApplicationSettings();
    settings->loadSettings(mainWindow);

    ui->lineEdit->setText(settings->getServerDirectory());
    ui->lineEdit_2->setText(settings->getTreDirectory());

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(setServerDirectory()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(setTreDirectory()));

    connect(ui->buttonBox, SIGNAL(clicked(QAbstractButton*)), mainWindow, SLOT(show()));
    connect(ui->buttonBox, SIGNAL(clicked(QAbstractButton*)), mainWindow, SLOT(reloadPlanet()));
}

Settings::~Settings() {
    delete ui;
    delete settings;
}

void Settings::setServerDirectory() {
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);

    ui->lineEdit->setText(dir);
    settings->setServerDirectory(dir);
    settings->saveSettings();
}

void Settings::setTreDirectory() {
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);

    ui->lineEdit_2->setText(dir);
    settings->setTreDirectory(dir);
    settings->saveSettings();
}
