/****************************************************************************
** Meta object code from reading C++ file 'lairspawneditor.h'
**
** Created: Thu Jan 5 22:43:29 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lairspawneditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lairspawneditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LairSpawnEditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      30,   16,   16,   16, 0x0a,
      53,   16,   16,   16, 0x0a,
      68,   16,   16,   16, 0x0a,
      82,   16,   16,   16, 0x0a,
      99,   16,   16,   16, 0x0a,
     122,   16,   16,   16, 0x0a,
     154,  140,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LairSpawnEditor[] = {
    "LairSpawnEditor\0\0updateData()\0"
    "clearCurrentLairData()\0editLairType()\0"
    "addLairType()\0removeLairType()\0"
    "maxSpawnLimitChanged()\0acceptedChanges()\0"
    "previous,item\0"
    "updateCurrentLair(QListWidgetItem*,QListWidgetItem*)\0"
};

void LairSpawnEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LairSpawnEditor *_t = static_cast<LairSpawnEditor *>(_o);
        switch (_id) {
        case 0: _t->updateData(); break;
        case 1: _t->clearCurrentLairData(); break;
        case 2: _t->editLairType(); break;
        case 3: _t->addLairType(); break;
        case 4: _t->removeLairType(); break;
        case 5: _t->maxSpawnLimitChanged(); break;
        case 6: _t->acceptedChanges(); break;
        case 7: _t->updateCurrentLair((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LairSpawnEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LairSpawnEditor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LairSpawnEditor,
      qt_meta_data_LairSpawnEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LairSpawnEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LairSpawnEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LairSpawnEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LairSpawnEditor))
        return static_cast<void*>(const_cast< LairSpawnEditor*>(this));
    return QDialog::qt_metacast(_clname);
}

int LairSpawnEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
