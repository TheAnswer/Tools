/****************************************************************************
** Meta object code from reading C++ file 'stfviewer.h'
**
** Created: Thu Jan 5 22:43:29 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../stfviewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stfviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_STFViewer[] = {

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
      11,   10,   10,   10, 0x0a,
      29,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_STFViewer[] = {
    "STFViewer\0\0loadCurrentFile()\0"
    "loadCurretStringID()\0"
};

void STFViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        STFViewer *_t = static_cast<STFViewer *>(_o);
        switch (_id) {
        case 0: _t->loadCurrentFile(); break;
        case 1: _t->loadCurretStringID(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData STFViewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject STFViewer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_STFViewer,
      qt_meta_data_STFViewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &STFViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *STFViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *STFViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_STFViewer))
        return static_cast<void*>(const_cast< STFViewer*>(this));
    return QDialog::qt_metacast(_clname);
}

int STFViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
