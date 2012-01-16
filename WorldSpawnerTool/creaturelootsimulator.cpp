#include "creaturelootsimulator.h"
#include "ui_creaturelootsimulator.h"

CreatureLootSimulator::CreatureLootSimulator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatureLootSimulator)
{
    ui->setupUi(this);
}

CreatureLootSimulator::~CreatureLootSimulator()
{
    delete ui;
}
