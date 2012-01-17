/****************************************************************************
** Meta object code from reading C++ file 'preorcreaturemanager.h'
**
** Created: Thu Jan 5 22:43:28 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../preorcreaturemanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'preorcreaturemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PreORCreatureManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x0a,
      38,   21,   21,   21, 0x0a,
      64,   62,   58,   21, 0x0a,
      92,   62,   58,   21, 0x0a,
     118,   62,   58,   21, 0x0a,
     147,   62,   58,   21, 0x0a,
     171,   62,   58,   21, 0x0a,
     191,   62,   58,   21, 0x0a,
     215,   62,   58,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PreORCreatureManager[] = {
    "PreORCreatureManager\0\0openDirectory()\0"
    "registerFunctions()\0int\0L\0"
    "runCreatureFile(lua_State*)\0"
    "runObjectFile(lua_State*)\0"
    "registerCreature(lua_State*)\0"
    "addCreature(lua_State*)\0addLair(lua_State*)\0"
    "addBlueFrog(lua_State*)\0"
    "addJunkDealer(lua_State*)\0"
};

void PreORCreatureManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PreORCreatureManager *_t = static_cast<PreORCreatureManager *>(_o);
        switch (_id) {
        case 0: _t->openDirectory(); break;
        case 1: _t->registerFunctions(); break;
        case 2: { int _r = _t->runCreatureFile((*reinterpret_cast< lua_State*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->runObjectFile((*reinterpret_cast< lua_State*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->registerCreature((*reinterpret_cast< lua_State*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { int _r = _t->addCreature((*reinterpret_cast< lua_State*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: { int _r = _t->addLair((*reinterpret_cast< lua_State*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: { int _r = _t->addBlueFrog((*reinterpret_cast< lua_State*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: { int _r = _t->addJunkDealer((*reinterpret_cast< lua_State*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PreORCreatureManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PreORCreatureManager::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PreORCreatureManager,
      qt_meta_data_PreORCreatureManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PreORCreatureManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PreORCreatureManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PreORCreatureManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PreORCreatureManager))
        return static_cast<void*>(const_cast< PreORCreatureManager*>(this));
    if (!strcmp(_clname, "LuaParser"))
        return static_cast< LuaParser*>(const_cast< PreORCreatureManager*>(this));
    return QDialog::qt_metacast(_clname);
}

int PreORCreatureManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
