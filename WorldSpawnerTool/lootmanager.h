#ifndef LOOTMANAGER_H
#define LOOTMANAGER_H

#include <QWidget>

namespace Ui {
class LootManager;
}

class LootLuaManager;
class LootItemTemplate;
class LootGroup;

class LootManager : public QWidget
{
    Q_OBJECT
    
public:
    explicit LootManager(QWidget *parent = 0);
    ~LootManager();

    void insertTemplateToTable(QExplicitlySharedDataPointer<LootItemTemplate>);
    void insertEntryToGroupTable(const QString&, double);
    int insertGroupToComboBox(QExplicitlySharedDataPointer<LootGroup>);

public slots:
    void loadTemplates();
    void loadGroups();
    void filterTemplates();
    void changeGroup(int);
    void saveCurrentLootGroup();
    void deleteCurrentLootGroup();
    void createLootTemplate();
    void editLootTemplate();
    void deleteLootTemplate();
    void addTemplateToCurrentGroup();
    void removeTemplateFromCurrentGroup();
    void updateChanceTotal();
    void writeScripts();
    void normalizeChance();

private slots:
    void promptGroupName();
    void changeMinimumValue(int);
    void changeMaximumValue(int);

signals:

protected:
    void paintEvent(QPaintEvent*);
    
private:
    Ui::LootManager *ui;
    LootLuaManager* luaManager;
    QExplicitlySharedDataPointer<LootGroup> currentLootGroup;
};

#endif // LOOTMANAGER_H
