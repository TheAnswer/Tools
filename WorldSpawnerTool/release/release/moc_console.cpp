/****************************************************************************
** Meta object code from reading C++ file 'console.h'
**
** Created: Mon Jan 16 20:31:17 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../console.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'console.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Console[] = {

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
      13,    9,    8,    8, 0x0a,
      36,   32,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Console[] = {
    "Console\0\0str\0printLine(QString)\0err\0"
    "printError(QString)\0"
};

void Console::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Console *_t = static_cast<Console *>(_o);
        switch (_id) {
        case 0: _t->printLine((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->printError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Console::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Console::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Console,
      qt_meta_data_Console, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Console::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Console::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Console::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Console))
        return static_cast<void*>(const_cast< Console*>(this));
    return QWidget::qt_metacast(_clname);
}

int Console::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
