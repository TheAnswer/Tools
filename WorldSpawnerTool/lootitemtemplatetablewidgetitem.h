#ifndef LOOTITEMTEMPLATETABLEWIDGETITEM_H
#define LOOTITEMTEMPLATETABLEWIDGETITEM_H

#include <QTableWidgetItem>

class LootItemTemplate;

class LootItemTemplateTableWidgetItem : public QTableWidgetItem {
public:
    LootItemTemplateTableWidgetItem(QExplicitlySharedDataPointer<LootItemTemplate> item);

    inline QExplicitlySharedDataPointer<LootItemTemplate> getLootItemTemplate() {
        return itemTemplate;
    }
    
signals:
    
public slots:
    
private:
    QExplicitlySharedDataPointer<LootItemTemplate> itemTemplate;
};

#endif // LOOTITEMTEMPLATETABLEWIDGETITEM_H
