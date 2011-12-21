#include "objectmodel3dviewer.h"
#include "ui_objectmodel3dviewer.h"
#include <QMessageBox>
#include <QThreadPool>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgGA/FlightManipulator>
#include <osgGA/DriveManipulator>
#include <osgGA/TerrainManipulator>
#include <QCompleter>
#include <QInputDialog>

ViewerWidget::ViewerWidget(osgViewer::ViewerBase::ThreadingModel threadingModel) : QWidget()
{
  setThreadingModel(threadingModel);

  connect( &_timer, SIGNAL(timeout()), this, SLOT(update()) );
  _timer.start( 10 );
}

QWidget* ViewerWidget::addViewWidget( osg::Camera* camera, osg::Node* scene )
{
  osgViewer::View* view = new osgViewer::View;
  view->setCamera( camera );
  addView( view );

  view->setSceneData( scene );
  view->addEventHandler( new osgViewer::StatsHandler );
  //view->setCameraManipulator( new Model3dViewer );
  view->addEventHandler(new osgViewer::ScreenCaptureHandler);
  view->addEventHandler(new osgViewer::LODScaleHandler);

  osg::ref_ptr<osgGA::KeySwitchMatrixManipulator> keyswitchManipulator
      = new osgGA::KeySwitchMatrixManipulator;

  osg::ref_ptr<Model3dViewer>
      tb = new Model3dViewer();

  keyswitchManipulator->addMatrixManipulator('1',
                                             "Trackball",
                                             tb.get()
                                             );
  keyswitchManipulator->addMatrixManipulator( '2',
                                              "Flight",
                                              new osgGA::FlightManipulator()
                                              );
  keyswitchManipulator->addMatrixManipulator( '3',
                                              "Drive",
                                              new osgGA::DriveManipulator()
                                              );
  keyswitchManipulator->addMatrixManipulator( '4',
                                              "Terrain",
                                              new osgGA::TerrainManipulator()
                                              );

  view->setCameraManipulator( keyswitchManipulator.get() );

  osgQt::GraphicsWindowQt* gw = dynamic_cast<osgQt::GraphicsWindowQt*>( camera->getGraphicsContext() );
  return gw ? gw->getGLWidget() : NULL;
}

osg::Camera* ViewerWidget::createCamera( int x, int y, int w, int h, const std::string& name, bool windowDecoration)
{
  osg::DisplaySettings* ds = osg::DisplaySettings::instance().get();
  osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
  traits->windowName = name;
  traits->windowDecoration = windowDecoration;
  traits->x = x;
  traits->y = y;
  traits->width = w;
  traits->height = h;
  traits->doubleBuffer = true;
  traits->alpha = ds->getMinimumNumAlphaBits();
  traits->stencil = ds->getMinimumNumStencilBits();
  traits->sampleBuffers = ds->getMultiSamples();
  traits->samples = ds->getNumMultiSamples();

  osg::ref_ptr<osg::Camera> camera = new osg::Camera;
  camera->setGraphicsContext( new osgQt::GraphicsWindowQt(traits.get()) );

  camera->setClearColor( osg::Vec4(0.2, 0.2, 0.6, 1.0) );
  camera->setViewport( new osg::Viewport(0, 0, traits->width, traits->height) );
  camera->setProjectionMatrixAsPerspective(
        30.0f, static_cast<double>(traits->width)/static_cast<double>(traits->height), 1.0f, 10000.0f );
  return camera.release();
}

void ViewerWidget::paintEvent( QPaintEvent* event ) {
  { frame(); }
}

ObjectModel3dViewer::ObjectModel3dViewer(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ObjectModel3dViewer) {
  ui->setupUi(this);

  osgViewerWidget = new ViewerWidget();
  osgViewerWidget->setGeometry( 100, 100, 800, 600 );

  repo = NULL;

  ui->progressBar->setMinimum(0);
  ui->progressBar->setMaximum(100);
  ui->progressBar->setValue(0);

  ui->lineEdit_template->setText("object/mobile/shared_krayt_dragon.iff");

  loadingModel = false;

  connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(loadFile()));
  connect(ui->lineEdit_template, SIGNAL(textChanged(QString)), this, SLOT(modelTextChanged()));
  //connect(ui->toolButton_list, SIGNAL(clicked()), this, SLOT(listFiles()));
}

ObjectModel3dViewer::~ObjectModel3dViewer() {
  delete ui;
  delete osgViewerWidget;
  delete repo;
}

void ObjectModel3dViewer::modelTextChanged() {
  if (repo == NULL)
    return;
}

void ObjectModel3dViewer::listFiles() {
 /* bool ok;
  QString text = QInputDialog::getItem(this, "File", "Select file", repoContents, 0, false, &ok);

  if (ok) {
      ui->lineEdit_template->setText(text);
    }*/
}

void ObjectModel3dViewer::setTreDirectory(const QString& dir) {
  std::string treDirectory( dir.toStdString() );

  for( unsigned int i = 0; i < treDirectory.size(); ++i ) {
      if( treDirectory[i] == '\\' ) {
          treDirectory[i] = '/';
        }
    }

  if( *(treDirectory.rbegin()) != '/' ) {
      treDirectory.push_back( '/' );
    }

  if (repo != NULL)
    delete repo;

  repoContents.clear();

  repo = new swgRepository(treDirectory);

   treArchive* archive = repo->getTreArchive();

   if (archive == NULL)
     return;

   std::list<std::string>* files = archive->getArchiveContents();

   if (files == NULL)
     return;

   for( std::list<std::string>::const_iterator i = files->begin(); i != files->end(); ++i) {
       QString qstring = (*i).c_str();
       repoContents.append(qstring);
     }

   delete files;

   /*QCompleter* completer = new QCompleter(repoContents, this);
   //completer->setCompletionMode();
   completer->setModelSorting(QCompleter::UnsortedModel);

   ui->lineEdit_template->setCompleter(completer);*/
}

void ObjectModel3dViewer::loadFile(const QString& name) {
  ui->lineEdit_template->setText(name);

  loadFile();
}

void ModelLoadWork::run() {
  osg::ref_ptr<osg::Node> node = NULL;

  try {
    node = repo->loadFile(file.toStdString());
  } catch (std::exception e) {
    //QMessageBox::warning(NULL, "Warning", "Could not parse file");
  }


  emit signalWorkFinished(node.release());
}

void ObjectModel3dViewer::loadFinished(osg::Node* node) {
  ui->progressBar->setValue(90);

  if (node == NULL) {
      ui->progressBar->setValue(100);
      QMessageBox::warning(NULL, "Warning", "Could not parse file");

      loadingModel = false;
      return;
    }

  //rootNode->
  rootNode->addChild(node);

  if (osgViewerWidget->isRealized()) {
      osg::ref_ptr<osgViewer::View> view = osgViewerWidget->getView(0);
      osgViewerWidget->removeView(view);
    }

  QWidget* widget1 = osgViewerWidget->addViewWidget( osgViewerWidget->createCamera(0,0,256,256), rootNode );

  if (osgViewerWidget->layout() != NULL) {
      QGridLayout* oldGrid = dynamic_cast<QGridLayout*>(osgViewerWidget->layout());

      delete oldGrid->takeAt(0);

      oldGrid->addWidget(widget1, 0, 0);
    } else {
      QGridLayout* grid = new QGridLayout;
      grid->addWidget( widget1, 0, 0 );
      osgViewerWidget->setLayout(grid);
    }

  QLayout* lay = ui->widget_container->layout();

  if (lay == NULL) {
      QGridLayout* grid2 = new QGridLayout;
      grid2->addWidget(osgViewerWidget);

      ui->widget_container->setLayout(grid2);
    }

  ui->progressBar->setValue(100);

  loadingModel = false;
}


void ObjectModel3dViewer::loadFile() {
  if (loadingModel) {
      QMessageBox::warning(NULL, "Warning", "Already loading model");
      return;
    }

  loadingModel = true;

  ui->progressBar->setValue(0);

  QString file = ui->lineEdit_template->text();

  if (repo == NULL) {
      QMessageBox::warning(NULL, "Warning", "You must set a tre directory");

      loadingModel = false;
      return;
    }

  repo->cleanCurrentObjects();

  ui->progressBar->setValue(10);

  rootNode = new osg::MatrixTransform;

  rootNode->setMatrix(
        osg::Matrix::rotate(
          osg::DegreesToRadians( 90.0 ),
          1.0, 0.0, 0.0 )
        );

  QThreadPool* threadPool = QThreadPool::globalInstance();

  ModelLoadWork* work = new ModelLoadWork(repo, file, this);
  threadPool->start(work);

  show();

  activateWindow();

  //this->s
}
