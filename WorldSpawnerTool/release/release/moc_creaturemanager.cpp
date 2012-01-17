/****************************************************************************
** Meta object code from reading C++ file 'creaturemanager.h'
**
** Created: Mon Jan 16 20:31:17 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../creaturemanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'creaturemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CreatureManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      43,   39,   16,   16, 0x0a,
      74,   69,   16,   16, 0x0a,
     106,   16,   16,   16, 0x0a,
     123,   16,   16,   16, 0x0a,
     145,   16,   16,   16, 0x0a,
     160,   16,   16,   16, 0x0a,
     188,   16,   16,   16, 0x0a,
     212,   16,   16,   16, 0x0a,
     229,   16,   16,   16, 0x0a,
     241,   16,   16,   16, 0x0a,
     256,   16,   16,   16, 0x0a,
     271,   16,   16,   16, 0x0a,
     297,   16,   16,   16, 0x0a,
     321,   16,   16,   16, 0x0a,
     335,   16,   16,   16, 0x0a,
     352,   16,   16,   16, 0x0a,
     361,   16,   16,   16, 0x0a,
     373,   16,   16,   16, 0x0a,
     388,   16,   16,   16, 0x0a,
     416,  406,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CreatureManager[] = {
    "CreatureManager\0\0loadCreatureObjects()\0"
    "str\0findCreatureFile(QString)\0text\0"
    "currentCreatureChanged(QString)\0"
    "reloadCreature()\0saveCurrentCreature()\0"
    "promptToSave()\0optionBitSelectionChanged()\0"
    "optionBitValueChanged()\0addNewCreature()\0"
    "addWeapon()\0removeWeapon()\0addLootGroup()\0"
    "removeSelectedLootGroup()\0"
    "editSelectedLootGroup()\0addTemplate()\0"
    "removeTemplate()\0view3d()\0addAttack()\0"
    "removeAttack()\0openSTFWithName()\0"
    "key,value\0addCreatureObject(QString,CreatureObject*)\0"
};

void CreatureManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CreatureManager *_t = static_cast<CreatureManager *>(_o);
        switch (_id) {
        case 0: _t->loadCreatureObjects(); break;
        case 1: _t->findCreatureFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->currentCreatureChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->reloadCreature(); break;
        case 4: _t->saveCurrentCreature(); break;
        case 5: _t->promptToSave(); break;
        case 6: _t->optionBitSelectionChanged(); break;
        case 7: _t->optionBitValueChanged(); break;
        case 8: _t->addNewCreature(); break;
        case 9: _t->addWeapon(); break;
        case 10: _t->removeWeapon(); break;
        case 11: _t->addLootGroup(); break;
        case 12: _t->removeSelectedLootGroup(); break;
        case 13: _t->editSelectedLootGroup(); break;
        case 14: _t->addTemplate(); break;
        case 15: _t->removeTemplate(); break;
        case 16: _t->view3d(); break;
        case 17: _t->addAttack(); break;
        case 18: _t->removeAttack(); break;
        case 19: _t->openSTFWithName(); break;
        case 20: _t->addCreatureObject((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< CreatureObject*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CreatureManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CreatureManager::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreatureManager,
      qt_meta_data_CreatureManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CreatureManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CreatureManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CreatureManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CreatureManager))
        return static_cast<void*>(const_cast< CreatureManager*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreatureManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
