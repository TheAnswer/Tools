/****************************************************************************
** Meta object code from reading C++ file 'newlairmobile.h'
**
** Created: Thu Jan 5 22:43:29 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../newlairmobile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newlairmobile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewLairMobile[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      42,   37,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NewLairMobile[] = {
    "NewLairMobile\0\0showExistingMobiles()\0"
    "item\0mobileChanged(QListWidgetItem*)\0"
};

void NewLairMobile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NewLairMobile *_t = static_cast<NewLairMobile *>(_o);
        switch (_id) {
        case 0: _t->showExistingMobiles(); break;
        case 1: _t->mobileChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NewLairMobile::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NewLairMobile::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewLairMobile,
      qt_meta_data_NewLairMobile, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NewLairMobile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NewLairMobile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NewLairMobile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewLairMobile))
        return static_cast<void*>(const_cast< NewLairMobile*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewLairMobile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
