/****************************************************************************
** Meta object code from reading C++ file 'lootitemtemplatemanager.h'
**
** Created: Tue Jan 17 22:41:08 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lootitemtemplatemanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lootitemtemplatemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LootItemTemplateManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x05,
      94,   24,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
     163,   24,   24,   24, 0x0a,
     230,   24,   24,   24, 0x0a,
     252,   24,   24,   24, 0x0a,
     274,   24,   24,   24, 0x0a,
     298,  296,   24,   24, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LootItemTemplateManager[] = {
    "LootItemTemplateManager\0\0"
    "broadcastItemDeleted(QExplicitlySharedDataPointer<LootItemTemplate>)\0"
    "broadcastItemCreated(QExplicitlySharedDataPointer<LootItemTemplate>)\0"
    "notifyItemModified(QExplicitlySharedDataPointer<LootItemTemplate>)\0"
    "pressedRemoveButton()\0pressedModifyButton()\0"
    "pressedCreateButton()\0,\0"
    "doubleClickedCell(int,int)\0"
};

void LootItemTemplateManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LootItemTemplateManager *_t = static_cast<LootItemTemplateManager *>(_o);
        switch (_id) {
        case 0: _t->broadcastItemDeleted((*reinterpret_cast< QExplicitlySharedDataPointer<LootItemTemplate>(*)>(_a[1]))); break;
        case 1: _t->broadcastItemCreated((*reinterpret_cast< QExplicitlySharedDataPointer<LootItemTemplate>(*)>(_a[1]))); break;
        case 2: _t->notifyItemModified((*reinterpret_cast< QExplicitlySharedDataPointer<LootItemTemplate>(*)>(_a[1]))); break;
        case 3: _t->pressedRemoveButton(); break;
        case 4: _t->pressedModifyButton(); break;
        case 5: _t->pressedCreateButton(); break;
        case 6: _t->doubleClickedCell((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LootItemTemplateManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LootItemTemplateManager::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LootItemTemplateManager,
      qt_meta_data_LootItemTemplateManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LootItemTemplateManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LootItemTemplateManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LootItemTemplateManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LootItemTemplateManager))
        return static_cast<void*>(const_cast< LootItemTemplateManager*>(this));
    return QDialog::qt_metacast(_clname);
}

int LootItemTemplateManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void LootItemTemplateManager::broadcastItemDeleted(QExplicitlySharedDataPointer<LootItemTemplate> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LootItemTemplateManager::broadcastItemCreated(QExplicitlySharedDataPointer<LootItemTemplate> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
