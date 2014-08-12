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
        //DatabaseModel::instance()->getString(iter.value());

        QString name = iter.key().varName;
        if (name.isEmpty() || name.isNull())
            name = "0x" + QString::number(iter.key().hashCode, 16).toUpper();

        QVariant val;
        if (iter.key().varType == "string")
            val = DatabaseModel::instance()->getString(iter.value());
        else if (iter.key().varType == "unicode")
            val = DatabaseModel::instance()->getUnicode(iter.value());
        else if (iter.key().varType == "unsigned int")
            val = DatabaseModel::instance()->getUnsignedInt(iter.value());
        else if (iter.key().varType == "unsigned short")
            val = DatabaseModel::instance()->getUnsignedShort(iter.value());
        else if (iter.key().varType == "boolean")
            val = DatabaseModel::instance()->getBoolean(iter.value());
        else if (iter.key().varType == "byte")
            val = DatabaseModel::instance()->getByte(iter.value());
        else if (iter.key().varType == "short")
            val = DatabaseModel::instance()->getShort(iter.value());
        else if (iter.key().varType == "int")
            val = DatabaseModel::instance()->getInt(iter.value());
        else if (iter.key().varType == "float")
            val = DatabaseModel::instance()->getFloat(iter.value());
        else if (iter.key().varType == "double")
            val = DatabaseModel::instance()->getDouble(iter.value());
        else if (iter.key().varType == "unsigned long")
            val = DatabaseModel::instance()->getUnsignedLong(iter.value());
        else if (iter.key().varType == "long")
            val = DatabaseModel::instance()->getLong(iter.value());
        else
            val = "0x" + QString::number(DatabaseModel::instance()->getUnsignedLong(iter.value()), 16).toUpper();

        //ui->listWidget->addItem(name + " : " + val.toString());
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(iter.key().varType));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(name));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(val.toString()));

        ui->tableWidget->resizeColumnsToContents();

        ++i;
    }
}
