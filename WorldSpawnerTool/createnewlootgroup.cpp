#include "createnewlootgroup.h"
#include "ui_createnewlootgroup.h"
#include "QMessageBox"
#include "mainwindow.h"
#include "lootluamanager.h"

CreateNewLootGroup::CreateNewLootGroup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateNewLootGroup)
{
    ui->setupUi(this);

    QRegExp rx("[a-z]{1}[0-9a-z_-]+"); //Only allow letters, underscores, and hyphens in the names.
    QRegExpValidator* nameValidator = new QRegExpValidator(rx, this);
    ui->lineEdit_LootGroupName->setValidator(nameValidator);
}

CreateNewLootGroup::~CreateNewLootGroup()
{
    delete ui;
}


void CreateNewLootGroup::accept() {
    if (validateGroupName()) {
        QDialog::accept();
    }
}

bool CreateNewLootGroup::validateGroupName() {
    LootLuaManager* lootManager = MainWindow::instance->getLootLuaManager();

    groupName = ui->lineEdit_LootGroupName->text();

    if (lootManager->lootGroupExists(groupName)) {
        QMessageBox box(QMessageBox::Critical, "Error", "ERROR: That group name is invalid or already exists.\n\nPlease choose another name.");
        box.exec();

        return false;
    }

    return true;
}
