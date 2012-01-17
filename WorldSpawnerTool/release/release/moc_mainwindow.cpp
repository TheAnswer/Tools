/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Jan 5 22:43:28 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   12,   11,   11, 0x0a,
      65,   12,   11,   11, 0x0a,
      82,   11,   11,   11, 0x0a,
     109,  105,   11,   11, 0x0a,
     155,  148,   11,   11, 0x0a,
     188,   11,   11,   11, 0x0a,
     212,   11,   11,   11, 0x0a,
     232,  227,   11,   11, 0x0a,
     281,  275,   11,   11, 0x0a,
     329,  227,   11,   11, 0x0a,
     366,   11,   11,   11, 0x0a,
     392,  227,   11,   11, 0x0a,
     425,   11,   11,   11, 0x0a,
     461,  275,   11,   11, 0x0a,
     498,  493,   11,   11, 0x0a,
     536,   11,   11,   11, 0x0a,
     552,   11,   11,   11, 0x0a,
     568,   11,   11,   11, 0x0a,
     589,   11,   11,   11, 0x0a,
     606,   11,   11,   11, 0x0a,
     629,   11,   11,   11, 0x0a,
     652,   11,   11,   11, 0x0a,
     680,   11,   11,   11, 0x0a,
     702,   11,   11,   11, 0x0a,
     724,   11,   11,   11, 0x0a,
     749,   11,   11,   11, 0x0a,
     776,   11,   11,   11, 0x0a,
     805,   11,   11,   11, 0x0a,
     817,   11,   11,   11, 0x0a,
     828,   11,   11,   11, 0x0a,
     842,   11,   11,   11, 0x0a,
     857,   11,   11,   11, 0x0a,
     878,   12,   11,   11, 0x0a,
     899,   11,   11,   11, 0x0a,
     916,   11,   11,   11, 0x0a,
     926,   11,   11,   11, 0x0a,
     947,   11,   11,   11, 0x0a,
     977,   11,   11,   11, 0x0a,
    1010, 1001,   11,   11, 0x0a,
    1035,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0str\0printToConsole(QString)\0"
    "outputToConsole(QString)\0warning(QString)\0"
    "loadDataFromDatabase()\0x,y\0"
    "updateCurrentItemPosition(float,float)\0"
    "window\0insertSingleSpawn(InsertWindow*)\0"
    "insertBadgeFromWindow()\0reloadPlanet()\0"
    "name\0updateCurrentSpawnRegionSelection(QString)\0"
    "spawn\0updateCurrentStaticSpawnSelection(StaticSpawn*)\0"
    "updateCurrentBadgeSelection(QString)\0"
    "updateStaticSpawnsTable()\0"
    "searchStaticMobileSpawn(QString)\0"
    "removeCurrentStaticSpawnSelection()\0"
    "removeStaticSpawn(StaticSpawn*)\0item\0"
    "staticSpawnChanged(QTableWidgetItem*)\0"
    "badgeXChanged()\0badgeYChanged()\0"
    "badgeRadiusChanged()\0badgeIDChanged()\0"
    "promptToChangePlanet()\0promptToReloadPlanet()\0"
    "promptToDeleteStaticSpawn()\0"
    "spawnRegionXChanged()\0spawnRegionYChanged()\0"
    "spawnRegionTierChanged()\0"
    "spawnRegionRadiusChanged()\0"
    "spawnRegionConstantChanged()\0editSpawn()\0"
    "addSpawn()\0removeSpawn()\0open3dViewer()\0"
    "displayLootManager()\0searchBadge(QString)\0"
    "changeWorldMap()\0saveMap()\0"
    "removeCurrentBadge()\0showInsertStaticSpawnWindow()\0"
    "showInsertBadgeWindow()\0stringID\0"
    "loadInSTFViewer(QString)\0viewSelectionsIn3d()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->printToConsole((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->outputToConsole((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->warning((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->loadDataFromDatabase(); break;
        case 4: _t->updateCurrentItemPosition((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 5: _t->insertSingleSpawn((*reinterpret_cast< InsertWindow*(*)>(_a[1]))); break;
        case 6: _t->insertBadgeFromWindow(); break;
        case 7: _t->reloadPlanet(); break;
        case 8: _t->updateCurrentSpawnRegionSelection((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->updateCurrentStaticSpawnSelection((*reinterpret_cast< StaticSpawn*(*)>(_a[1]))); break;
        case 10: _t->updateCurrentBadgeSelection((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->updateStaticSpawnsTable(); break;
        case 12: _t->searchStaticMobileSpawn((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->removeCurrentStaticSpawnSelection(); break;
        case 14: _t->removeStaticSpawn((*reinterpret_cast< StaticSpawn*(*)>(_a[1]))); break;
        case 15: _t->staticSpawnChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 16: _t->badgeXChanged(); break;
        case 17: _t->badgeYChanged(); break;
        case 18: _t->badgeRadiusChanged(); break;
        case 19: _t->badgeIDChanged(); break;
        case 20: _t->promptToChangePlanet(); break;
        case 21: _t->promptToReloadPlanet(); break;
        case 22: _t->promptToDeleteStaticSpawn(); break;
        case 23: _t->spawnRegionXChanged(); break;
        case 24: _t->spawnRegionYChanged(); break;
        case 25: _t->spawnRegionTierChanged(); break;
        case 26: _t->spawnRegionRadiusChanged(); break;
        case 27: _t->spawnRegionConstantChanged(); break;
        case 28: _t->editSpawn(); break;
        case 29: _t->addSpawn(); break;
        case 30: _t->removeSpawn(); break;
        case 31: _t->open3dViewer(); break;
        case 32: _t->displayLootManager(); break;
        case 33: _t->searchBadge((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 34: _t->changeWorldMap(); break;
        case 35: _t->saveMap(); break;
        case 36: _t->removeCurrentBadge(); break;
        case 37: _t->showInsertStaticSpawnWindow(); break;
        case 38: _t->showInsertBadgeWindow(); break;
        case 39: _t->loadInSTFViewer((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 40: _t->viewSelectionsIn3d(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::printToConsole(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
