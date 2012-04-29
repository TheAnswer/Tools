#include "crccalculatordialog.h"
#include "ui_crccalculatordialog.h"
#include "utils.h"

CRCCalculatorDialog::CRCCalculatorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CRCCalculatorDialog)
{
    ui->setupUi(this);
}

CRCCalculatorDialog::~CRCCalculatorDialog()
{
    delete ui;
}

void CRCCalculatorDialog::on_lineEdit_CRC_textChanged(const QString &arg1)
{
    ui->lineEdit_CRC->setText(arg1.trimmed());
    ui->label_CRC->setText("CRC: 0x" + QString::number(utils::Utils::hashCode(arg1.trimmed()), 16).toUpper());
}
