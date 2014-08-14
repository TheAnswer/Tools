#include "inspectiondialog.h"
#include "ui_inspectiondialog.h"
#include "databasemodel.h"
#include <QTimer>

InspectionDialog::InspectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InspectionDialog)
{
    ui->setupUi(this);
}

InspectionDialog::~InspectionDialog()
{
    delete ui;
}

void InspectionDialog::setInformation(QMap<IDLVar, QByteArray> info) {
    information = info;

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(information.size());

    QStringList tableHeader;
    tableHeader << "type" << "name" << "value";
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    QMap<IDLVar, QByteArray>::iterator iter;
    int i = 0;

    for (iter = information.begin(); iter != information.end(); ++iter) {
        QString name = iter.key().varName;
        if (name.isEmpty() || name.isNull())
            name = "0x" + QString::number(iter.key().hashCode, 16).toUpper();

        QByteArray ba(iter.value());

        QVariant val = DatabaseModel::instance()->getDataByType(&ba, iter.key().varType);

        //ui->listWidget->addItem(name + " : " + val.toString());
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(iter.key().varType));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(name));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(val.toString()));

        ui->tableWidget->resizeColumnsToContents();

        ++i;
    }
}
