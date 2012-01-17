/****************************************************************************
** Meta object code from reading C++ file 'lairtool.h'
**
** Created: Thu Jan 5 22:43:28 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lairtool.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lairtool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LairTool[] = {

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
      16,   10,    9,    9, 0x0a,
      43,    9,    9,    9, 0x0a,
      57,    9,    9,    9, 0x0a,
      69,    9,    9,    9, 0x0a,
      86,    9,    9,    9, 0x0a,
     101,    9,    9,    9, 0x0a,
     120,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LairTool[] = {
    "LairTool\0\0templ\0setTemplate(LairTemplate*)\0"
    "addBuilding()\0addMobile()\0removeBuilding()\0"
    "removeMobile()\0commitToTemplate()\0"
    "view3d()\0"
};

void LairTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LairTool *_t = static_cast<LairTool *>(_o);
        switch (_id) {
        case 0: _t->setTemplate((*reinterpret_cast< LairTemplate*(*)>(_a[1]))); break;
        case 1: _t->addBuilding(); break;
        case 2: _t->addMobile(); break;
        case 3: _t->removeBuilding(); break;
        case 4: _t->removeMobile(); break;
        case 5: _t->commitToTemplate(); break;
        case 6: _t->view3d(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LairTool::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LairTool::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LairTool,
      qt_meta_data_LairTool, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LairTool::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LairTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LairTool::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LairTool))
        return static_cast<void*>(const_cast< LairTool*>(this));
    return QDialog::qt_metacast(_clname);
}

int LairTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
