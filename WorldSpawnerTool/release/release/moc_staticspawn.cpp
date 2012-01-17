/****************************************************************************
** Meta object code from reading C++ file 'staticspawn.h'
**
** Created: Thu Jan 5 22:43:28 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../staticspawn.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'staticspawn.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StaticSpawn[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_StaticSpawn[] = {
    "StaticSpawn\0\0show3dModel()\0"
};

void StaticSpawn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StaticSpawn *_t = static_cast<StaticSpawn *>(_o);
        switch (_id) {
        case 0: _t->show3dModel(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData StaticSpawn::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StaticSpawn::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StaticSpawn,
      qt_meta_data_StaticSpawn, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StaticSpawn::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StaticSpawn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StaticSpawn::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StaticSpawn))
        return static_cast<void*>(const_cast< StaticSpawn*>(this));
    if (!strcmp(_clname, "QGraphicsEllipseItem"))
        return static_cast< QGraphicsEllipseItem*>(const_cast< StaticSpawn*>(this));
    if (!strcmp(_clname, "Spawn"))
        return static_cast< Spawn*>(const_cast< StaticSpawn*>(this));
    return QObject::qt_metacast(_clname);
}

int StaticSpawn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
