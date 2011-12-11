#include "lairname.h"
#include "ui_lairname.h"

LairName::LairName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LairName)
{
    ui->setupUi(this);

    setWindowTitle("Specify");
}

LairName::~LairName()
{
    delete ui;
}


QString LairName::getName() {
    return ui->lineEdit_name->text();
}
