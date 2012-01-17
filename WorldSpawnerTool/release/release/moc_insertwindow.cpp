/****************************************************************************
** Meta object code from reading C++ file 'insertwindow.h'
**
** Created: Mon Jan 16 20:31:17 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../insertwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'insertwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_InsertWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      54,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_InsertWindow[] = {
    "InsertWindow\0\0window\0"
    "insertSingleSpawn(InsertWindow*)\0"
    "insertObject()\0"
};

void InsertWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        InsertWindow *_t = static_cast<InsertWindow *>(_o);
        switch (_id) {
        case 0: _t->insertSingleSpawn((*reinterpret_cast< InsertWindow*(*)>(_a[1]))); break;
        case 1: _t->insertObject(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData InsertWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject InsertWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_InsertWindow,
      qt_meta_data_InsertWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &InsertWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *InsertWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *InsertWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InsertWindow))
        return static_cast<void*>(const_cast< InsertWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int InsertWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void InsertWindow::insertSingleSpawn(InsertWindow * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
