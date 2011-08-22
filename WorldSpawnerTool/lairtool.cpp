#include "lairtool.h"
#include "ui_lairtool.h"

LairTool::LairTool(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LairTool) {
    ui->setupUi(this);
}

LairTool::~LairTool() {
    delete ui;
}
