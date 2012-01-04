#include "lootitemeditor.h"
#include "ui_lootitemeditor.h"
#include "lootitemtemplatemanager.h"
#include "lootgroupeditor.h"
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
}

LootItemEditor::~LootItemEditor()
{
    delete ui;
}

void LootItemEditor::acceptedDialog() {
    //Validate all of the information in the form.

    //Save all the form data to the LootItemTemplate.
    LootItemTemplate* item = currentItem.data();
    item->setItemName(ui->lineEdit_ItemName->text());
    item->setCustomObjectName(ui->lineEdit_CustomName->text());
    item->setDirectObjectPath(ui->lineEdit_DirectObjectPath->text());
    item->setDraftSchematic(ui->lineEdit_DraftSchematic->text());
    item->setMaxLevel(ui->spinBox_MaximumLevel->value());
    item->setMinLevel(ui->spinBox_MinimumLevel->value());
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
