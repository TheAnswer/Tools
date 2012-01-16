#include "addlootgroupdialog.h"
#include "ui_addlootgroupdialog.h"
#include "mainwindow.h"
#include "lootluamanager.h"

AddLootGroupDialog::AddLootGroupDialog(double maxChance, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLootGroupDialog)
{
    ui->setupUi(this);

    ui->doubleSpinBox->setMaximum(maxChance);
}

AddLootGroupDialog::~AddLootGroupDialog()
{
    delete ui;
}

void AddLootGroupDialog::showEvent(QShowEvent* e) {
    LootLuaManager* luaManager = MainWindow::instance->getLootLuaManager();

    QMap<QString, QExplicitlySharedDataPointer<LootGroup> > groups = luaManager->getLootGroups();
    QMapIterator<QString, QExplicitlySharedDataPointer<LootGroup> > i(groups);

    while (i.hasNext()) {
        i.next();

        ui->comboBox_LootGroups->addItem(i.key());
    }
}

QString AddLootGroupDialog::getGroupName() const {
    return ui->comboBox_LootGroups->currentText();
}

double AddLootGroupDialog::getChance() {
    return ui->doubleSpinBox->value();
}
