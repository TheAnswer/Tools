#include "insertbadgeform.h"
#include "ui_insertbadgeform.h"
#include "mainwindow.h"

InsertBadgeForm::InsertBadgeForm(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::InsertBadgeForm) {
  ui->setupUi(this);

  ui->doubleSpinBox_radius->setValue(30);

  connect(ui->buttonBox, SIGNAL(accepted()), MainWindow::instance, SLOT(insertBadgeFromWindow()));

  setWindowTitle("Insert new badge");
}

InsertBadgeForm::~InsertBadgeForm() {
  delete ui;
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
