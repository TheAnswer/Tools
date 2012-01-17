#include "lootitemeditor.h"
#include "ui_lootitemeditor.h"
#include "lootitemtemplatemanager.h"
#include "QMessageBox"
#include "QAbstractButton"
#include "mainwindow.h"

LootItemEditor::LootItemEditor(QExplicitlySharedDataPointer<LootItemTemplate> item, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LootItemEditor)
{
    ui->setupUi(this);

    connect(ui->spinBox_MinimumLevel, SIGNAL(valueChanged(int)), this, SLOT(validateMinLevel(int)));
    connect(ui->spinBox_MaximumLevel, SIGNAL(valueChanged(int)), this, SLOT(validateMaxLevel(int)));
    connect(this, SIGNAL(accepted()), this, SLOT(acceptedDialog()));
    connect(ui->pushButton_AddExperimental, SIGNAL(clicked()), this, SLOT(addExperimentalRow()));
    connect(ui->pushButton_RemoveExperimental, SIGNAL(clicked()), this, SLOT(removeExperimentalRow()));

    currentItem = item;

    setWindowTitle("Loot Item Template Editor: " + currentItem->getItemName());

    QHeaderView* expHeader = ui->tableWidget_ExperimentalProperties->horizontalHeader();
    expHeader->resizeSection(1, 75); //Resize the min and max level columns
    expHeader->resizeSection(2, 75);

    QHeaderView* cstHeader = ui->tableWidget_CustomizationVariables->horizontalHeader();
    cstHeader->resizeSection(1, 75); //Resize the min and max level columns
    cstHeader->resizeSection(2, 75);

    QRegExp rx("[a-z]{1}[0-9a-z_-]+"); //Only allow letters, underscores, and hyphens in the names.
    QRegExpValidator* nameValidator = new QRegExpValidator(rx, this);
    ui->lineEdit_ItemName->setValidator(nameValidator);

    ui->lineEdit_ItemName->setText(currentItem->getItemName());
    ui->lineEdit_CustomName->setText(currentItem->getCustomObjectName());
    ui->lineEdit_DirectObjectPath->setText(currentItem->getDirectObjectPath());
    ui->lineEdit_DraftSchematic->setText(currentItem->getDraftSchematic());
    ui->spinBox_MaximumLevel->setValue(currentItem->getMaxLevel());
    ui->spinBox_MinimumLevel->setValue(currentItem->getMinLevel());
    ui->comboBox_MinimumQuality->setCurrentIndex(currentItem->getQualityRangeMin());
    ui->comboBox_MaximumQuality->setCurrentIndex(currentItem->getQualityRangeMax());

    for (int i = 0; i < currentItem->getTotalCustomizationVars(); ++i) {
        ui->tableWidget_CustomizationVariables->insertRow(i);
        ui->tableWidget_CustomizationVariables->setItem(i, 0, new QTableWidgetItem(currentItem->getCustomizationVarAt(i)));
        ui->tableWidget_CustomizationVariables->setItem(i, 1, new QTableWidgetItem(QString::number(currentItem->getCustomizationMinAt(i))));
        ui->tableWidget_CustomizationVariables->setItem(i, 2, new QTableWidgetItem(QString::number(currentItem->getCustomizationMaxAt(i))));
    }

    for (int i = 0; i < currentItem->getTotalExperimentalProps(); ++i) {
        ui->tableWidget_ExperimentalProperties->insertRow(i);
        ui->tableWidget_ExperimentalProperties->setItem(i, 0, new QTableWidgetItem(currentItem->getExperimentalPropertyAt(i)));
        ui->tableWidget_ExperimentalProperties->setItem(i, 1, new QTableWidgetItem(QString::number(currentItem->getExperimentalMinAt(i))));
        ui->tableWidget_ExperimentalProperties->setItem(i, 2, new QTableWidgetItem(QString::number(currentItem->getExperimentalMaxAt(i))));
    }
}

LootItemEditor::~LootItemEditor()
{
    delete ui;
}

void LootItemEditor::acceptedDialog() {
    //Validate all of the information in the form.

    //Save all the form data to the LootItemTemplate.
    currentItem->setItemName(ui->lineEdit_ItemName->text());
    currentItem->setCustomObjectName(ui->lineEdit_CustomName->text());
    currentItem->setDirectObjectPath(ui->lineEdit_DirectObjectPath->text());
    currentItem->setDraftSchematic(ui->lineEdit_DraftSchematic->text());
    currentItem->setMaxLevel(ui->spinBox_MaximumLevel->value());
    currentItem->setMinLevel(ui->spinBox_MinimumLevel->value());

    //Clear them all and reenter them with whats in the editor.
    currentItem->clearAllCustomizationVariables();
    currentItem->clearAllExperimentalProperties();

    for (int i = 0; i < ui->tableWidget_ExperimentalProperties->rowCount(); ++i) {
        QString property = ui->tableWidget_ExperimentalProperties->item(i, 0)->text();
        float min = ui->tableWidget_ExperimentalProperties->item(i, 1)->text().toFloat();
        float max = ui->tableWidget_ExperimentalProperties->item(i, 2)->text().toFloat();

        currentItem->addExperimentalProperty(property, min, max);
    }

    for (int i = 0; i < ui->tableWidget_CustomizationVariables->rowCount(); ++i) {
        QString variable = ui->tableWidget_CustomizationVariables->item(i, 0)->text();
        quint8 min = ui->tableWidget_CustomizationVariables->item(i, 1)->text().toInt();
        quint8 max = ui->tableWidget_CustomizationVariables->item(i, 2)->text().toInt();

        currentItem->addCustomizationVariable(variable, min, max);
    }
}

void LootItemEditor::validateMinLevel(int val) {
    int max = ui->spinBox_MaximumLevel->value();

    //Don't allow the minimum to be higher than the maximum.
    if (val > max && max != -1) {
        ui->spinBox_MaximumLevel->setValue(val);
    }
}

void LootItemEditor::validateMaxLevel(int val) {
    int min = ui->spinBox_MinimumLevel->value();

    if (val < min && val != -1) {
        ui->spinBox_MinimumLevel->setValue(val);
    }
}

void LootItemEditor::showEvent(QShowEvent* e) {
    QDialog::showEvent(e);

    ui->lineEdit_ItemName->selectAll();
}

void LootItemEditor::addExperimentalRow() {
    int rows = ui->tableWidget_ExperimentalProperties->rowCount();
    ui->tableWidget_ExperimentalProperties->insertRow(rows);

    ui->tableWidget_ExperimentalProperties->setItem(rows, 0, new QTableWidgetItem(""));
    ui->tableWidget_ExperimentalProperties->setItem(rows, 1, new QTableWidgetItem(""));
    ui->tableWidget_ExperimentalProperties->setItem(rows, 2, new QTableWidgetItem(""));
}

void LootItemEditor::removeExperimentalRow() {
    ui->tableWidget_ExperimentalProperties->removeRow(ui->tableWidget_ExperimentalProperties->currentRow());
}

void LootItemEditor::addCustomizationRow() {
    int rows = ui->tableWidget_CustomizationVariables->rowCount();
    ui->tableWidget_CustomizationVariables->insertRow(rows);

    ui->tableWidget_CustomizationVariables->setItem(rows, 0, new QTableWidgetItem(""));
    ui->tableWidget_CustomizationVariables->setItem(rows, 1, new QTableWidgetItem(""));
    ui->tableWidget_CustomizationVariables->setItem(rows, 2, new QTableWidgetItem(""));
}

void LootItemEditor::removeCustomizationRow() {
    ui->tableWidget_CustomizationVariables->removeRow(ui->tableWidget_CustomizationVariables->currentRow());
}
