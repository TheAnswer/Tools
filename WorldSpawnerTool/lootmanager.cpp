#include "lootmanager.h"
#include "ui_lootmanager.h"
#include "mainwindow.h"
#include "lootitemtemplatetablewidgetitem.h"
#include "lootluamanager.h"
#include "QMessageBox"
#include "createnewlootgroup.h"
#include "lootitemeditor.h"
#include "QColor"

LootManager::LootManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LootManager)
{
    ui->setupUi(this);

    connect(ui->comboBox_Group, SIGNAL(currentIndexChanged(int)), this, SLOT(changeGroup(int)));
    connect(ui->spinBox_MinLevel, SIGNAL(valueChanged(int)), this, SLOT(changeMinimumValue(int)));
    connect(ui->spinBox_MaxLevel, SIGNAL(valueChanged(int)), this, SLOT(changeMaximumValue(int)));
    connect(ui->pushButton_Filter, SIGNAL(clicked()), this, SLOT(filterTemplates()));
    connect(ui->pushButton_NewGroup, SIGNAL(clicked()), this, SLOT(promptGroupName()));
    connect(ui->pushButton_DeleteGroup, SIGNAL(clicked()), this, SLOT(deleteCurrentLootGroup()));
    connect(ui->pushButton_NewTemplate, SIGNAL(clicked()), this, SLOT(createLootTemplate()));
    connect(ui->pushButton_EditTemplate, SIGNAL(clicked()), this, SLOT(editLootTemplate()));
    connect(ui->pushButton_DeleteTemplate, SIGNAL(clicked()), this, SLOT(deleteLootTemplate()));
    connect(ui->pushButton_Add, SIGNAL(clicked()), this, SLOT(addTemplateToCurrentGroup()));
    connect(ui->pushButton_Remove, SIGNAL(clicked()), this, SLOT(removeTemplateFromCurrentGroup()));
    connect(ui->pushButton_WriteScripts, SIGNAL(clicked()), this, SLOT(writeScripts()));
    connect(ui->pushButton_Normalize, SIGNAL(clicked()), this, SLOT(normalizeChance()));
    connect(ui->tableWidget_LootTemplates, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(editLootTemplate()));
    connect(ui->tableWidget_LootGroups, SIGNAL(cellChanged(int, int)), this, SLOT(changeLootChance(int, int)));

    luaManager = MainWindow::instance->getLootLuaManager();

    loadTemplates();
    loadGroups();
}

LootManager::~LootManager()
{
    delete ui;
}

void LootManager::paintEvent(QPaintEvent* e) {
    QWidget::paintEvent(e);

    QHeaderView* header = ui->tableWidget_LootTemplates->horizontalHeader();
    header->resizeSection(0, header->width() - 100);
    header->resizeSection(1, 50);
    header->resizeSection(2, 50);

    header = ui->tableWidget_LootGroups->horizontalHeader();
    header->resizeSection(0, header->width() - 100);
    header->resizeSection(1, 100);
}

void LootManager::loadTemplates() {
    QMap<QString, QExplicitlySharedDataPointer<LootItemTemplate> > templates = luaManager->getLootItems();
    QMapIterator<QString, QExplicitlySharedDataPointer<LootItemTemplate> > i(templates);

    while (i.hasNext()) {
        i.next();
        insertTemplateToTable(i.value());
    }
}

void LootManager::loadGroups() {
    QMap<QString, QExplicitlySharedDataPointer<LootGroup> > groups = luaManager->getLootGroups();
    QMapIterator<QString, QExplicitlySharedDataPointer<LootGroup> > i(groups);

    while (i.hasNext()) {
        i.next();
        insertGroupToComboBox(i.value());
    }
}

void LootManager::insertTemplateToTable(QExplicitlySharedDataPointer<LootItemTemplate> itemTemplate) {
    LootItemTemplateTableWidgetItem* widgetItem = new LootItemTemplateTableWidgetItem(itemTemplate);

    QTableWidgetItem* minLvl = new QTableWidgetItem(QString::number(itemTemplate->getMinLevel()));
    minLvl->setTextAlignment(Qt::AlignHCenter);

    QTableWidgetItem* maxLvl = new QTableWidgetItem(QString::number(itemTemplate->getMaxLevel()));
    maxLvl->setTextAlignment(Qt::AlignHCenter);

    int rowCount = ui->tableWidget_LootTemplates->rowCount();
    ui->tableWidget_LootTemplates->insertRow(rowCount);

    ui->tableWidget_LootTemplates->setItem(rowCount, 0, widgetItem);
    ui->tableWidget_LootTemplates->setItem(rowCount, 1, minLvl);
    ui->tableWidget_LootTemplates->setItem(rowCount, 2, maxLvl);
}

int LootManager::insertGroupToComboBox(QExplicitlySharedDataPointer<LootGroup> group) {
    ui->comboBox_Group->addItem(group->getGroupName());

    return ui->comboBox_Group->count();
}

void LootManager::filterTemplates() {
    QString filterText = ui->lineEdit_Filter->text();

    if (filterText.isEmpty()) {
        //Show all rows if the filter is empty.
        for (int i = 0; i < ui->tableWidget_LootTemplates->rowCount(); ++i) {
            ui->tableWidget_LootTemplates->showRow(i);
        }

        return;
    }

    QList<QTableWidgetItem*> items = ui->tableWidget_LootTemplates->findItems(filterText, Qt::MatchWildcard | Qt::MatchContains);

    for (int i = 0; i < ui->tableWidget_LootTemplates->rowCount(); ++i) {
        QTableWidgetItem* item = ui->tableWidget_LootTemplates->item(i, ui->comboBox_Filter->currentIndex());

        if (item == NULL)
            continue;

        if (!items.contains(item))
            ui->tableWidget_LootTemplates->hideRow(i);
        else
            ui->tableWidget_LootTemplates->showRow(i);
    }
}

void LootManager::changeGroup(int index) {
    //Save the current loot group before switching.
    saveCurrentLootGroup();

    QString groupName = ui->comboBox_Group->itemText(index);

    currentLootGroup = luaManager->getLootGroup(groupName);

    ui->spinBox_MinLevel->setValue(currentLootGroup->getMinimumLevel());
    ui->spinBox_MaxLevel->setValue(currentLootGroup->getMaximumLevel());

    //Remove all the old entries.
    ui->tableWidget_LootGroups->clearContents();
    ui->tableWidget_LootGroups->setRowCount(0);

    updateChanceTotal();

    //Load the entries.
    QMap<QString, int> entries = currentLootGroup->getEntriesCopy();
    QMapIterator<QString, int> i(entries);

    while (i.hasNext()) {
        i.next();

        insertEntryToGroupTable(i.key(), i.value());
    }
}

void LootManager::insertEntryToGroupTable(const QString& templateName, int weight) {
    QTableWidgetItem* templateWidget = new QTableWidgetItem(templateName);
    templateWidget->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QRegExp rx("(^100([.]0{1,5})?)$|(^[0-9]{1,2}([.][0-9]{1,5})?)$");
    QRegExpValidator* validator = new QRegExpValidator(rx);

    QLineEdit* weightWidget = new QLineEdit();
    weightWidget->setAlignment(Qt::AlignRight);
    weightWidget->setFrame(false);
    weightWidget->setValidator(validator);
    weightWidget->setText(QString::number(weight / 100000, 'f', 5));
    QPalette palette;
    palette.setColor(QPalette::Base, Qt::transparent);
    weightWidget->setPalette(palette);

    connect(weightWidget, SIGNAL(editingFinished()), this, SLOT(updateChanceTotal()));

    int rows = ui->tableWidget_LootGroups->rowCount();
    ui->tableWidget_LootGroups->insertRow(rows);

    ui->tableWidget_LootGroups->setItem(rows, 0, templateWidget);
    ui->tableWidget_LootGroups->setCellWidget(rows, 1, weightWidget);
}

void LootManager::saveCurrentLootGroup() {
    if (currentLootGroup.data() == NULL)
        return;

    currentLootGroup->setMinimumLevel(ui->spinBox_MinLevel->value());
    currentLootGroup->setMaximumLevel(ui->spinBox_MaxLevel->value());
}

void LootManager::promptGroupName() {
    CreateNewLootGroup box(this);

    if (box.exec() == CreateNewLootGroup::Accepted) {
        QString groupName = box.getGroupName();

        QExplicitlySharedDataPointer<LootGroup> group = luaManager->createLootGroup(groupName);
        ui->comboBox_Group->setCurrentIndex(insertGroupToComboBox(group) - 1);
    }
}

void LootManager::changeMinimumValue(int value) {
    int max = ui->spinBox_MaxLevel->value();

    //Don't allow the minimum to be higher than the maximum.
    if (value > max && max != -1) {
        ui->spinBox_MaxLevel->setValue(value);
    }
}

void LootManager::changeMaximumValue(int value) {
    int min = ui->spinBox_MinLevel->value();

    if (value < min && value != -1) {
        ui->spinBox_MinLevel->setValue(value);
    }
}

void LootManager::deleteCurrentLootGroup() {
    QMessageBox confirm(QMessageBox::Warning, "Confirm Deletion", "Are you sure you want to delete this loot group?", QMessageBox::Yes | QMessageBox::No);

    if (confirm.exec() == QMessageBox::Yes) {
        int currentIndex = ui->comboBox_Group->currentIndex();

        QString groupName = ui->comboBox_Group->itemText(currentIndex);
        luaManager->deleteLootGroup(groupName);

        ui->comboBox_Group->removeItem(currentIndex);
        ui->comboBox_Group->setCurrentIndex(0); //TODO: What if no indices remain now?
    }
}

void LootManager::createLootTemplate() {
    QExplicitlySharedDataPointer<LootItemTemplate> item(new LootItemTemplate("untitled"));

    LootItemEditor editor(item, this);

    if (editor.exec() == LootItemEditor::Accepted) {
        luaManager->addLootItemTemplate(item);
        insertTemplateToTable(item);
    }
}

void LootManager::editLootTemplate() {
    int row = ui->tableWidget_LootTemplates->currentRow();

    LootItemTemplateTableWidgetItem* widgetItem = dynamic_cast<LootItemTemplateTableWidgetItem*>(ui->tableWidget_LootTemplates->item(row, 0));

    if (widgetItem == NULL)
        return;

    QExplicitlySharedDataPointer<LootItemTemplate> item = widgetItem->getLootItemTemplate();

    LootItemEditor editor(item, this);

    if (editor.exec() == LootItemEditor::Accepted) {
        if (item->getItemName() != widgetItem->text()) {
            widgetItem->setText(item->getItemName());
            //We have to refresh all the group entries containing this item if the name changed...
        }

        QTableWidgetItem* level = ui->tableWidget_LootTemplates->item(row, 1);
        level->setText(QString::number(item->getMinLevel()));

        level = ui->tableWidget_LootTemplates->item(row, 2);
        level->setText(QString::number(item->getMaxLevel()));
    }
}

void LootManager::deleteLootTemplate() {
    int row = ui->tableWidget_LootTemplates->currentRow();

    LootItemTemplateTableWidgetItem* widgetItem = dynamic_cast<LootItemTemplateTableWidgetItem*>(ui->tableWidget_LootTemplates->item(row, 0));

    if (widgetItem == NULL)
        return;

    QMessageBox box(QMessageBox::Warning, "Confirm Deletion", "Are you sure you want to delete this loot template?", QMessageBox::Yes | QMessageBox::No);

    if (box.exec() == QMessageBox::Yes) {
        QExplicitlySharedDataPointer<LootItemTemplate> item = widgetItem->getLootItemTemplate();

        ui->tableWidget_LootTemplates->removeRow(row);
        luaManager->deleteLootItemTemplate(item);
        changeGroup(ui->comboBox_Group->currentIndex()); //Refresh the current loot group.
    }
}

void LootManager::addTemplateToCurrentGroup() {
    if (currentLootGroup.data() == NULL)
        return;

    int row = ui->tableWidget_LootTemplates->currentRow();

    LootItemTemplateTableWidgetItem* widgetItem = dynamic_cast<LootItemTemplateTableWidgetItem*>(ui->tableWidget_LootTemplates->item(row, 0));
    QExplicitlySharedDataPointer<LootItemTemplate> item = widgetItem->getLootItemTemplate();

    QString itemName = item->getItemName();

    if (!currentLootGroup->hasLootItemTemplate(itemName)) {
        currentLootGroup->addLootItemTemplate(itemName, 0);
        insertEntryToGroupTable(itemName, 0);
    }
}

void LootManager::removeTemplateFromCurrentGroup() {
    if (currentLootGroup.data() == NULL)
        return;

    int row = ui->tableWidget_LootGroups->currentRow();

    QString itemName = ui->tableWidget_LootGroups->item(row, 0)->text();

    luaManager->removeItemFromGroup(itemName, currentLootGroup->getGroupName());

    ui->tableWidget_LootGroups->removeRow(row);

    updateChanceTotal();
}

void LootManager::updateChanceTotal() {
    double totalChance = 0.f;

    for (int i = 0; i < ui->tableWidget_LootGroups->rowCount(); ++i) {
        QLineEdit* chance = dynamic_cast<QLineEdit*>(ui->tableWidget_LootGroups->cellWidget(i, 1));
        QString itemName = ui->tableWidget_LootGroups->item(i, 0)->text();

        if (chance == NULL)
            continue;

        double dblChance = chance->text().toDouble();
        chance->setText(QString::number(dblChance, 'f', 5));

        totalChance += dblChance;

        currentLootGroup->setChance(itemName, qRound(dblChance * 100000));
    }

    QColor color;

    if (totalChance < 100.f) {
        color.setRgb(250, 240, 200);
    } else if (totalChance > 100.f) {
        color.setRgb(250, 200, 190);
    } else {
        color.setRgb(230, 250, 200);
    }

    QPalette palette;
    palette.setColor(QPalette::Base, color);

    ui->lineEdit_TotalChance->setText(QString::number(totalChance, 'f', 5));
    ui->lineEdit_TotalChance->setPalette(palette);
}

void LootManager::writeScripts() {
    double totalChance = ui->lineEdit_TotalChance->text().toDouble();

    if (totalChance > 100.f) {
        QMessageBox box(QMessageBox::Critical, "Cannot Write Scripts", "ERROR: The total chance of each loot group may not exceed 100.\n\nPlease fix any groups that violate this rule and try again.");
        box.exec();

        return;
    }

    if (totalChance < 100.f) {
        QMessageBox box(QMessageBox::Warning, "Warning", "WARNING: The total chance of the current loot group does not equal 100.\n\nHaving a total chance less than 100 can produce unexpected results and is highly discouraged.\n\nAre you sure you want to continue writing these scripts?", QMessageBox::Yes | QMessageBox::No);

        if (box.exec() == QMessageBox::No)
            return;
    }

    luaManager->writeLootItemTemplates();
    luaManager->writeLootGroups();
}

void LootManager::normalizeChance() {
    double totalChance = ui->lineEdit_TotalChance->text().toDouble();

    if (totalChance == 100.f)
        return;

    for (int i = 0; i < ui->tableWidget_LootGroups->rowCount(); ++i) {
        QString itemName = ui->tableWidget_LootGroups->item(i, 0)->text();

        double chance = currentLootGroup->getChance(itemName) / 100000;
        double newChance = chance / totalChance * 100;

        currentLootGroup->setChance(itemName, qRound(newChance * 100000));

        QLineEdit* chanceWidget = dynamic_cast<QLineEdit*>(ui->tableWidget_LootGroups->cellWidget(i, 1));
        chanceWidget->setText(QString::number(newChance, 'f', 5));
    }

    updateChanceTotal();
}
