#ifndef LOOTITEMTEMPLATEMANAGER_H
#define LOOTITEMTEMPLATEMANAGER_H

#include <QDialog>
#include "lootitemtemplate.h"

class LootLuaManager;

namespace Ui {
class LootItemTemplateManager;
}

class LootItemTemplateManager : public QDialog {
    Q_OBJECT
    
public:
    explicit LootItemTemplateManager(QWidget *parent = 0);
    ~LootItemTemplateManager();

    void insertLootItemTemplate(QExplicitlySharedDataPointer<LootItemTemplate> item);

public slots:
    void notifyItemModified(QExplicitlySharedDataPointer<LootItemTemplate>);
    void pressedRemoveButton();
    void pressedModifyButton();
    void pressedCreateButton();
    void doubleClickedCell(int, int);

signals:
    void broadcastItemDeleted(QExplicitlySharedDataPointer<LootItemTemplate>);
    void broadcastItemCreated(QExplicitlySharedDataPointer<LootItemTemplate>);
    
private:
    Ui::LootItemTemplateManager *ui;
    LootLuaManager* lootManager;
};

#endif // LOOTITEMTEMPLATEMANAGER_H
