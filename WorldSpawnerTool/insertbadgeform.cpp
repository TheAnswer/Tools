#include "insertbadgeform.h"
#include "ui_insertbadgeform.h"
#include "mainwindow.h"
#include <meshLib/dtii.hpp>

InsertBadgeForm::InsertBadgeForm(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::InsertBadgeForm) {
  ui->setupUi(this);

  ui->doubleSpinBox_radius->setValue(30);

  connect(ui->buttonBox, SIGNAL(accepted()), MainWindow::instance, SLOT(insertBadgeFromWindow()));
  //connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(showBadgeMap()));

  setWindowTitle("Insert new badge");
}

InsertBadgeForm::~InsertBadgeForm() {
  delete ui;
}

void InsertBadgeForm::showBadgeMap() {
  if (badgeTable != NULL)
    return;
/*
  badgeTable = new QTableWidget();
  badgeTable->setRowCount(2);
  badgeTable->setColumnCount(2);

  ui->gridLayout_4->addWidget(badgeTable, 0, 1);*/

  //table->exec();

}

void InsertBadgeForm::setBadgeX(float val) {
  ui->doubleSpinBox_x->setValue(val);
}

void InsertBadgeForm::setBadgeY(float val) {
  ui->doubleSpinBox_y->setValue(val);
}


QString InsertBadgeForm::getName(){
  return ui->lineEdit->text();
}

float InsertBadgeForm::getPositionX() {
  return ui->doubleSpinBox_x->value();
}

float InsertBadgeForm::getPositionY() {
  return ui->doubleSpinBox_y->value();
}

float InsertBadgeForm::getRadius() {
  return ui->doubleSpinBox_radius->value();
}

int InsertBadgeForm::getBadgeID() {
  return ui->spinBox_badgeID->value();
}
