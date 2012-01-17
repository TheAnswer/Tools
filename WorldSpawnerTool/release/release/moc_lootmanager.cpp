/****************************************************************************
** Meta object code from reading C++ file 'lootmanager.h'
**
** Created: Thu Jan 5 22:43:29 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lootmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lootmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LootManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      29,   12,   12,   12, 0x0a,
      42,   12,   12,   12, 0x0a,
      60,   12,   12,   12, 0x0a,
      77,   12,   12,   12, 0x0a,
     100,   12,   12,   12, 0x0a,
     125,   12,   12,   12, 0x0a,
     146,   12,   12,   12, 0x0a,
     165,   12,   12,   12, 0x0a,
     186,   12,   12,   12, 0x0a,
     214,   12,   12,   12, 0x0a,
     247,   12,   12,   12, 0x0a,
     267,   12,   12,   12, 0x0a,
     282,   12,   12,   12, 0x0a,
     300,   12,   12,   12, 0x08,
     318,   12,   12,   12, 0x08,
     342,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LootManager[] = {
    "LootManager\0\0loadTemplates()\0loadGroups()\0"
    "filterTemplates()\0changeGroup(int)\0"
    "saveCurrentLootGroup()\0deleteCurrentLootGroup()\0"
    "createLootTemplate()\0editLootTemplate()\0"
    "deleteLootTemplate()\0addTemplateToCurrentGroup()\0"
    "removeTemplateFromCurrentGroup()\0"
    "updateChanceTotal()\0writeScripts()\0"
    "normalizeChance()\0promptGroupName()\0"
    "changeMinimumValue(int)\0changeMaximumValue(int)\0"
};

void LootManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LootManager *_t = static_cast<LootManager *>(_o);
        switch (_id) {
        case 0: _t->loadTemplates(); break;
        case 1: _t->loadGroups(); break;
        case 2: _t->filterTemplates(); break;
        case 3: _t->changeGroup((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->saveCurrentLootGroup(); break;
        case 5: _t->deleteCurrentLootGroup(); break;
        case 6: _t->createLootTemplate(); break;
        case 7: _t->editLootTemplate(); break;
        case 8: _t->deleteLootTemplate(); break;
        case 9: _t->addTemplateToCurrentGroup(); break;
        case 10: _t->removeTemplateFromCurrentGroup(); break;
        case 11: _t->updateChanceTotal(); break;
        case 12: _t->writeScripts(); break;
        case 13: _t->normalizeChance(); break;
        case 14: _t->promptGroupName(); break;
        case 15: _t->changeMinimumValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->changeMaximumValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LootManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LootManager::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LootManager,
      qt_meta_data_LootManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LootManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LootManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LootManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LootManager))
        return static_cast<void*>(const_cast< LootManager*>(this));
    return QWidget::qt_metacast(_clname);
}

int LootManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
