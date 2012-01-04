#ifndef OBJECTMODEL3DVIEWER_H
#define OBJECTMODEL3DVIEWER_H

#include <QDialog>

#include <QtCore/QTimer>
#include <QtGui/QApplication>
#include <QtGui/QGridLayout>

#include <osgViewer/CompositeViewer>
#include <osgViewer/ViewerEventHandlers>

#include <osgGA/TrackballManipulator>

#include <osgDB/ReadFile>

#include <osgQt/GraphicsWindowQt>

#include <iostream>

#include <swgRepository.hpp>
#include <QRunnable>
#include <QList>
#include <QMutex>

class Spawn;

class Model3dViewer : public osgGA::TrackballManipulator {

public:

};

class ViewerWidget : public QWidget, public osgViewer::CompositeViewer
{
public:
    ViewerWidget(QMutex* updateMutex, osgViewer::ViewerBase::ThreadingModel threadingModel = osgViewer::CompositeViewer::SingleThreaded);

    QWidget* addViewWidget( osg::Camera* camera, osg::Node* scene );

    osg::Camera* createCamera( int x, int y, int w, int h, const std::string& name="", bool windowDecoration=false );

    virtual void paintEvent( QPaintEvent* event );

protected:
    QTimer _timer;
    QMutex* updateMutex;

};

namespace Ui {
  class ObjectModel3dViewer;
}

class ObjectModel3dViewer : public QDialog {
  Q_OBJECT
  
public:
  explicit ObjectModel3dViewer(QWidget *parent = 0);
  ~ObjectModel3dViewer();

  void setTreDirectory(const QString& dir);



public slots:
  void loadFile();
  void loadFile(const QString& name);
  void loadFileFinished(osg::Node* node);
  void modelTextChanged();
  void listFiles();
  void increaseProgress(int vals);
  void addSpawnsToScene(QList<Spawn *> &spawns);
  //void addFileToScene(c)

  void addNodeToCurrentScene(osg::Node* node);

protected:
  void create3DView();
  void removeSceneChildren();

public:
  swgRepository* getSWGRepository() {
    return repo;
  }

  treArchive* getTreArchive() {
    if (repo == NULL)
      return NULL;
    else
      return repo->getTreArchive();
  }

signals:
  void increaseUiProgress(int);
  
private:
  Ui::ObjectModel3dViewer *ui;
  swgRepository* repo;
  ViewerWidget* osgViewerWidget;
  bool loadingModel;
  QStringList repoContents;

  QMutex mutex;

  osg::ref_ptr<osg::MatrixTransform> rootNode;

  int modelsLeft;
};

class AppendModelLoadWork : public QRunnable {
    ObjectModel3dViewer* viewer;
    Spawn* spawn;
public:
    AppendModelLoadWork(ObjectModel3dViewer* viewer, Spawn* spawn);

    void run();
};

class SingleModelLoadWork : public QObject, public QRunnable {
  Q_OBJECT

  swgRepository* repo;
  QString file;
public:
  SingleModelLoadWork(swgRepository* repository, const QString& file, const ObjectModel3dViewer* par) {
    setAutoDelete(true);
    repo = repository;
    this->file = file;

    connect(this, SIGNAL(signalWorkFinished(osg::Node*)), par, SLOT(loadFileFinished(osg::Node*)));
  }

  void run();

signals:
  void signalWorkFinished(osg::Node*);
};


#endif // OBJECTMODEL3DVIEWER_H
