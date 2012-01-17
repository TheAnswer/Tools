/****************************************************************************
** Meta object code from reading C++ file 'lairtypes.h'
**
** Created: Thu Jan 5 22:43:29 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lairtypes.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lairtypes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LairTypes[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      36,   24,   10,   10, 0x0a,
      52,   10,   10,   10, 0x2a,
      64,   10,   10,   10, 0x0a,
      77,   10,   10,   10, 0x0a,
      99,   88,   10,   10, 0x0a,
     126,   10,   10,   10, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_LairTypes[] = {
    "LairTypes\0\0createLair()\0forceUpdate\0"
    "saveLairs(bool)\0saveLairs()\0removeLair()\0"
    "editLair()\0skipDialog\0loadCurrentLairTypes(bool)\0"
    "loadCurrentLairTypes()\0"
};

void LairTypes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LairTypes *_t = static_cast<LairTypes *>(_o);
        switch (_id) {
        case 0: _t->createLair(); break;
        case 1: _t->saveLairs((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->saveLairs(); break;
        case 3: _t->removeLair(); break;
        case 4: _t->editLair(); break;
        case 5: _t->loadCurrentLairTypes((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->loadCurrentLairTypes(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LairTypes::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LairTypes::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LairTypes,
      qt_meta_data_LairTypes, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LairTypes::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LairTypes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LairTypes::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LairTypes))
        return static_cast<void*>(const_cast< LairTypes*>(this));
    return QDialog::qt_metacast(_clname);
}

int LairTypes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
