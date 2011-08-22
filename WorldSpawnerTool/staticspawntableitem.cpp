#include "staticspawntableitem.h"

StaticSpawnTableItem::StaticSpawnTableItem(StaticSpawn* sp, const QString& text) :
    QTableWidgetItem(text), spawn(sp) {

}
