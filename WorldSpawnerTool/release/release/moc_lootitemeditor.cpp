/****************************************************************************
** Meta object code from reading C++ file 'lootitemeditor.h'
**
** Created: Tue Jan 17 22:41:08 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lootitemeditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lootitemeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LootItemEditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      86,   15,   15,   15, 0x0a,
     103,   15,   15,   15, 0x0a,
     125,   15,   15,   15, 0x0a,
     147,   15,   15,   15, 0x0a,
     168,   15,   15,   15, 0x0a,
     192,   15,   15,   15, 0x0a,
     214,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LootItemEditor[] = {
    "LootItemEditor\0\0"
    "broadcastItemModified(QExplicitlySharedDataPointer<LootItemTemplate>)\0"
    "acceptedDialog()\0validateMinLevel(int)\0"
    "validateMaxLevel(int)\0addExperimentalRow()\0"
    "removeExperimentalRow()\0addCustomizationRow()\0"
    "removeCustomizationRow()\0"
};

void LootItemEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LootItemEditor *_t = static_cast<LootItemEditor *>(_o);
        switch (_id) {
        case 0: _t->broadcastItemModified((*reinterpret_cast< QExplicitlySharedDataPointer<LootItemTemplate>(*)>(_a[1]))); break;
        case 1: _t->acceptedDialog(); break;
        case 2: _t->validateMinLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->validateMaxLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->addExperimentalRow(); break;
        case 5: _t->removeExperimentalRow(); break;
        case 6: _t->addCustomizationRow(); break;
        case 7: _t->removeCustomizationRow(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LootItemEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LootItemEditor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LootItemEditor,
      qt_meta_data_LootItemEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LootItemEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LootItemEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LootItemEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LootItemEditor))
        return static_cast<void*>(const_cast< LootItemEditor*>(this));
    return QDialog::qt_metacast(_clname);
}

int LootItemEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void LootItemEditor::broadcastItemModified(QExplicitlySharedDataPointer<LootItemTemplate> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
