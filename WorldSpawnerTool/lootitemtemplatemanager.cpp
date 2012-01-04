#include "lootitemtemplatemanager.h"
#include "ui_lootitemtemplatemanager.h"
#include "mainwindow.h"
#include "lootluamanager.h"
#include "lootitemeditor.h"
#include "lootitemtemplatetablewidgetitem.h"
#include "QMessageBox"

LootItemTemplateManager::LootItemTemplateManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LootItemTemplateManager)
{
    ui->setupUi(this);

    connect(ui->pushButton_Remove, SIGNAL(clicked()), this, SLOT(pressedRemoveButton()));
    connect(ui->pushButton_Modify, SIGNAL(clicked()), this, SLOT(pressedModifyButton()));
    connect(ui->pushButton_Create, SIGNAL(clicked()), this, SLOT(pressedCreateButton()));
    connect(ui->tableWidget, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(doubleClickedCell(int, int)));

    QHeaderView* header = ui->tableWidget->horizontalHeader();
    header->resizeSection(1, 50); //Resize the min and max level columns
    header->resizeSection(2, 50);

    lootManager = MainWindow::instance->getLootLuaManager();

    QMap<QString, QExplicitlySharedDataPointer<LootItemTemplate> > lootItems = lootManager->getLootItems();
    QMapIterator<QString, QExplicitlySharedDataPointer<LootItemTemplate> > i(lootItems);

    while (i.hasNext()) {
        i.next();
        insertLootItemTemplate(i.value());
    }
}

LootItemTemplateManager::~LootItemTemplateManager()
{
    delete ui;
}

void LootItemTemplateManager::insertLootItemTemplate(QExplicitlySharedDataPointer<LootItemTemplate> item) {
    int n = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(n);

    LootItemTemplateTableWidgetItem* widgetItem = new LootItemTemplateTableWidgetItem(item);
    QTableWidgetItem* minLvl = new QTableWidgetItem(QString::number(item.data()->getMinLevel()));
    minLvl->setTextAlignment(Qt::AlignHCenter);
    QTableWidgetItem* maxLvl = new QTableWidgetItem(QString::number(item.data()->getMaxLevel()));
    maxLvl->setTextAlignment(Qt::AlignHCenter);
    QTableWidgetItem* coName = new QTableWidgetItem(item.data()->getCustomObjectName());

    ui->tableWidget->setItem(n, 0, widgetItem);
    ui->tableWidget->setItem(n, 1, minLvl);
    ui->tableWidget->setItem(n, 2, maxLvl);
    ui->tableWidget->setItem(n, 3, coName);
}

void LootItemTemplateManager::notifyItemModified(QExplicitlySharedDataPointer<LootItemTemplate>) {
    //We need to update the ui with the changed details at this point.
}

void LootItemTemplateManager::pressedRemoveButton() {
    LootItemTemplateTableWidgetItem* widgetItem = dynamic_cast<LootItemTemplateTableWidgetItem*>(ui->tableWidget->item(ui->tableWidget->currentRow(), 0));

    if (widgetItem == NULL)
        return;

    QMessageBox confirm(QMessageBox::Warning,
                        "Confirm Deletion",
                        "WARNING: This action cannot be undone.\n\nAre you sure you want to permanently delete this loot item template?",
                        QMessageBox::Yes | QMessageBox::No);

    if (confirm.exec() == QMessageBox::Yes) {
        QExplicitlySharedDataPointer<LootItemTemplate> item = widgetItem->getLootItemTemplate();

        ui->tableWidget->removeRow(ui->tableWidget->currentRow());

        lootManager->deleteLootItemTemplate(item);

        emit broadcastItemDeleted(item);
    }
}

void LootItemTemplateManager::pressedModifyButton() {
    LootItemTemplateTableWidgetItem* widgetItem = dynamic_cast<LootItemTemplateTableWidgetItem*>(ui->tableWidget->item(ui->tableWidget->currentRow(), 0));

    if (widgetItem != NULL) {
        //Show the editor with this item.
        LootItemEditor editor(widgetItem->getLootItemTemplate(), this);
        editor.exec();
    }
}

void LootItemTemplateManager::pressedCreateButton() {
    QExplicitlySharedDataPointer<LootItemTemplate> itemTemplate = lootManager->createLootItemTemplate();

    insertLootItemTemplate(itemTemplate);

    emit broadcastItemCreated(itemTemplate);

    LootItemEditor editor(itemTemplate, this);
    editor.exec();
}

void LootItemTemplateManager::doubleClickedCell(int row, int col) {
    LootItemTemplateTableWidgetItem* widgetItem = dynamic_cast<LootItemTemplateTableWidgetItem*>(ui->tableWidget->item(row, 0));

    if (widgetItem != NULL) {
        LootItemEditor editor(widgetItem->getLootItemTemplate(), this);
        editor.exec();
    }
}
