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
    connect(ui->pushButton_AddExperimental, SIGNAL(clicked()), this, SLOT(addExperimentalRow()));
    connect(ui->pushButton_RemoveExperimental, SIGNAL(clicked()), this, SLOT(removeExperimentalRow()));
    connect(ui->pushButton_AddCustomization, SIGNAL(clicked()), this, SLOT(addCustomizationRow()));
    connect(ui->pushButton_RemoveCustomization, SIGNAL(clicked()), this, SLOT(removeCustomizationRow()));
    connect(ui->pushButton_AddSkillMod, SIGNAL(clicked()), this, SLOT(addSkillModRow()));
    connect(ui->pushButton_RemoveSkillMod, SIGNAL(clicked()), this, SLOT(removeSkillModRow()));
    connect(this, SIGNAL(accepted()), this, SLOT(acceptedDialog()));

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
    ui->spinBox_MaximumLevel->setValue(currentItem->getMaxLevel());
    ui->spinBox_MinimumLevel->setValue(currentItem->getMinLevel());

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
        ui->tableWidget_ExperimentalProperties->setItem(i, 3, new QTableWidgetItem(QString::number(currentItem->getExperimentalPrecision(i))));
    }

    for (int i = 0; i < currentItem->getTotalSkillMods(); ++i) {
        ui->tableWidget_SkillMods->insertRow(i);
        ui->tableWidget_SkillMods->setItem(i, 0, new QTableWidgetItem(currentItem->getSkillModNameAt(i)));
        ui->tableWidget_SkillMods->setItem(i, 1, new QTableWidgetItem(QString::number(currentItem->getSkillModValueAt(i))));
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
    currentItem->setMaxLevel(ui->spinBox_MaximumLevel->value());
    currentItem->setMinLevel(ui->spinBox_MinimumLevel->value());

    //Clear them all and reenter them with whats in the editor.
    currentItem->clearAllCustomizationVariables();
    currentItem->clearAllExperimentalProperties();
    currentItem->clearAllSkillMods();

    for (int i = 0; i < ui->tableWidget_ExperimentalProperties->rowCount(); ++i) {
        QString property = ui->tableWidget_ExperimentalProperties->item(i, 0)->text();
        float min = ui->tableWidget_ExperimentalProperties->item(i, 1)->text().toFloat();
        float max = ui->tableWidget_ExperimentalProperties->item(i, 2)->text().toFloat();
        float precision = ui->tableWidget_ExperimentalProperties->item(i, 3)->text().toFloat();

        currentItem->addExperimentalProperty(property, min, max, precision);
    }

    for (int i = 0; i < ui->tableWidget_CustomizationVariables->rowCount(); ++i) {
        QString variable = ui->tableWidget_CustomizationVariables->item(i, 0)->text();
        quint8 min = ui->tableWidget_CustomizationVariables->item(i, 1)->text().toInt();
        quint8 max = ui->tableWidget_CustomizationVariables->item(i, 2)->text().toInt();

        currentItem->addCustomizationVariable(variable, min, max);
    }

    for (int i = 0; i < ui->tableWidget_SkillMods->rowCount(); ++i) {
        QString skillMod = ui->tableWidget_SkillMods->item(i, 0)->text();
        quint8 value = ui->tableWidget_SkillMods->item(i, 1)->text().toInt();

        currentItem->addSkillMod(skillMod, value);
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
    ui->tableWidget_ExperimentalProperties->setItem(rows, 3, new QTableWidgetItem(""));
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

void LootItemEditor::addSkillModRow() {
    int rows = ui->tableWidget_SkillMods->rowCount();
    ui->tableWidget_SkillMods->insertRow(rows);

    ui->tableWidget_SkillMods->setItem(rows, 0, new QTableWidgetItem(""));
    ui->tableWidget_SkillMods->setItem(rows, 1, new QTableWidgetItem(""));
}

void LootItemEditor::removeSkillModRow() {
    ui->tableWidget_SkillMods->removeRow(ui->tableWidget_SkillMods->currentRow());
}
