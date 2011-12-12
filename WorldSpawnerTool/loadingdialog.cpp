#include "loadingdialog.h"
#include "ui_loadingdialog.h"

LoadingDialog::LoadingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadingDialog) {
    ui->setupUi(this);

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
}

LoadingDialog::~LoadingDialog() {
    delete ui;
}

void LoadingDialog::setProgress(int val) {
    ui->progressBar->setValue(val);
}

void LoadingDialog::setText(const QString& val) {
    ui->label_loading->setText("Loading " + val + " ...");
}
