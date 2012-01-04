#include "lootitemtemplatetablewidgetitem.h"
#include "lootitemtemplate.h"

LootItemTemplateTableWidgetItem::LootItemTemplateTableWidgetItem(QExplicitlySharedDataPointer<LootItemTemplate> lootItem) :
    QTableWidgetItem(lootItem.data()->getItemName()), itemTemplate(lootItem) {

}
