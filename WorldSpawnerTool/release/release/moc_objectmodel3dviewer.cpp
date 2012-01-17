/****************************************************************************
** Meta object code from reading C++ file 'objectmodel3dviewer.h'
**
** Created: Thu Jan 5 22:43:30 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../objectmodel3dviewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'objectmodel3dviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ObjectModel3dViewer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   20,   20,   20, 0x0a,
      61,   56,   20,   20, 0x0a,
      84,   79,   20,   20, 0x0a,
     113,   20,   20,   20, 0x0a,
     132,   20,   20,   20, 0x0a,
     149,  144,   20,   20, 0x0a,
     178,  171,   20,   20, 0x0a,
     211,   79,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ObjectModel3dViewer[] = {
    "ObjectModel3dViewer\0\0increaseUiProgress(int)\0"
    "loadFile()\0name\0loadFile(QString)\0"
    "node\0loadFileFinished(osg::Node*)\0"
    "modelTextChanged()\0listFiles()\0vals\0"
    "increaseProgress(int)\0spawns\0"
    "addSpawnsToScene(QList<Spawn*>&)\0"
    "addNodeToCurrentScene(osg::Node*)\0"
};

void ObjectModel3dViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ObjectModel3dViewer *_t = static_cast<ObjectModel3dViewer *>(_o);
        switch (_id) {
        case 0: _t->increaseUiProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->loadFile(); break;
        case 2: _t->loadFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->loadFileFinished((*reinterpret_cast< osg::Node*(*)>(_a[1]))); break;
        case 4: _t->modelTextChanged(); break;
        case 5: _t->listFiles(); break;
        case 6: _t->increaseProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->addSpawnsToScene((*reinterpret_cast< QList<Spawn*>(*)>(_a[1]))); break;
        case 8: _t->addNodeToCurrentScene((*reinterpret_cast< osg::Node*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ObjectModel3dViewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ObjectModel3dViewer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ObjectModel3dViewer,
      qt_meta_data_ObjectModel3dViewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ObjectModel3dViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ObjectModel3dViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ObjectModel3dViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ObjectModel3dViewer))
        return static_cast<void*>(const_cast< ObjectModel3dViewer*>(this));
    return QDialog::qt_metacast(_clname);
}

int ObjectModel3dViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void ObjectModel3dViewer::increaseUiProgress(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_SingleModelLoadWork[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_SingleModelLoadWork[] = {
    "SingleModelLoadWork\0\0"
    "signalWorkFinished(osg::Node*)\0"
};

void SingleModelLoadWork::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SingleModelLoadWork *_t = static_cast<SingleModelLoadWork *>(_o);
        switch (_id) {
        case 0: _t->signalWorkFinished((*reinterpret_cast< osg::Node*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SingleModelLoadWork::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SingleModelLoadWork::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SingleModelLoadWork,
      qt_meta_data_SingleModelLoadWork, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SingleModelLoadWork::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SingleModelLoadWork::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SingleModelLoadWork::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SingleModelLoadWork))
        return static_cast<void*>(const_cast< SingleModelLoadWork*>(this));
    if (!strcmp(_clname, "QRunnable"))
        return static_cast< QRunnable*>(const_cast< SingleModelLoadWork*>(this));
    return QObject::qt_metacast(_clname);
}

int SingleModelLoadWork::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void SingleModelLoadWork::signalWorkFinished(osg::Node * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
