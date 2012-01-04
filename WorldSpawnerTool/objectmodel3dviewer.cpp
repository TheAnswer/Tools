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
#include "spawn.h"
#include "mainwindow.h"

ViewerWidget::ViewerWidget(QMutex* updateMutex, osgViewer::ViewerBase::ThreadingModel threadingModel) : QWidget()
{
    setThreadingModel(threadingModel);

    this->updateMutex = updateMutex;

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
    //camera->set
    return camera.release();
}

void ViewerWidget::paintEvent( QPaintEvent* event ) {
    {
        QMutexLocker locker(updateMutex);

        frame();
    }
}

ObjectModel3dViewer::ObjectModel3dViewer(QWidget *parent) :
    QDialog(parent), mutex(QMutex::Recursive),
    ui(new Ui::ObjectModel3dViewer) {
    ui->setupUi(this);

    osgViewerWidget = new ViewerWidget(&mutex);
    osgViewerWidget->setGeometry( 100, 100, 800, 600 );

    repo = NULL;

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);

    modelsLeft = 0;

    ui->lineEdit_template->setText("object/mobile/shared_krayt_dragon.iff");

    loadingModel = false;

    rootNode = new osg::MatrixTransform;

    rootNode->setMatrix(
                osg::Matrix::rotate(
                    osg::DegreesToRadians( 90.0 ),
                    1.0, 0.0, 0.0 )
                );

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(loadFile()));
    connect(ui->lineEdit_template, SIGNAL(textChanged(QString)), this, SLOT(modelTextChanged()));
    connect(this, SIGNAL(increaseUiProgress(int)), this, SLOT(increaseProgress(int)));
    //connect(ui->toolButton_list, SIGNAL(clicked()), this, SLOT(listFiles()));

    this->setWindowFlags(windowFlags() | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
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

    /*std::list<std::string>* files = archive->getArchiveContents();

   if (files == NULL)
     return;

   for( std::list<std::string>::const_iterator i = files->begin(); i != files->end(); ++i) {
       QString qstring = (*i).c_str();
       repoContents.append(qstring);
     }

   delete files;*/

    /*QCompleter* completer = new QCompleter(repoContents, this);
   //completer->setCompletionMode();
   completer->setModelSorting(QCompleter::UnsortedModel);

   ui->lineEdit_template->setCompleter(completer);*/
}

void ObjectModel3dViewer::loadFile(const QString& name) {
    ui->lineEdit_template->setText(name);

    loadFile();
}

void SingleModelLoadWork::run() {
    osg::ref_ptr<osg::Node> node = NULL;

    try {
        node = repo->loadFile(file.toStdString());
    } catch (std::exception e) {
        //QMessageBox::warning(NULL, "Warning", "Could not parse file");
    }

    emit signalWorkFinished(node.release());
}

AppendModelLoadWork::AppendModelLoadWork(ObjectModel3dViewer* viewer, Spawn* spawn) {
    this->viewer = viewer;
    this->spawn = spawn;

    setAutoDelete(true);
}

void AppendModelLoadWork::run() {
    osg::ref_ptr<osg::Node> node = NULL;

    try {
        QString sharedTemplate = spawn->getSharedTemplate();

        if (!sharedTemplate.isEmpty()) {

            node = viewer->getSWGRepository()->loadFile(sharedTemplate.toStdString());

            if (node != NULL) {
                osg::Quat nodeQuat( spawn->getDirX(), spawn->getDirY(), spawn->getDirZ(), spawn->getDirW() );
                osg::ref_ptr<osg::MatrixTransform> transform = new osg::MatrixTransform;
                osg::Matrix rotMat( osg::Matrix::rotate( nodeQuat ) );

                osg::Matrix trotMat(
                            rotMat(0,0), rotMat(1,0), -rotMat(2,0), rotMat(3,0),
                            rotMat(0,1), rotMat(1,1), -rotMat(2,1), rotMat(3,1),
                            -rotMat(0,2), -rotMat(1,2), rotMat(2,2), -rotMat(3,2),
                            rotMat(0,3), rotMat(1,3), -rotMat(2,3), rotMat(3,3)
                            );

                osg::Matrix matrix( trotMat * osg::Matrix::rotate( -osg::PI_2, 0, 1, 0 ) * osg::Matrix::translate( spawn->getWorldX(), spawn->getWorldZ(), spawn->getWorldY()));

                transform->setMatrix( matrix );
                transform->addChild( node );

                osg::ref_ptr<osg::MatrixTransform> wsnpMesh = new osg::MatrixTransform;
                wsnpMesh->setMatrix( osg::Matrix::rotate( -osg::PI, 1, 0, 0 ) );
                wsnpMesh->addChild(transform);

                node = wsnpMesh;
            }
        }
    } catch (std::exception e) {
        //QMessageBox::warning(NULL, "Warning", "Could not parse file");
    }

    if (node != NULL)
        viewer->addNodeToCurrentScene(node.release());
    else
        viewer->addNodeToCurrentScene(NULL);
}

void ObjectModel3dViewer::addSpawnsToScene(QList<Spawn*>& spawns) {
    QMutexLocker locker(&mutex);

    if (spawns.size() == 0)
        return;

    if (repo == NULL) {
        QMessageBox::warning(NULL, "Warning", "You must set a tre directory");

        loadingModel = false;
        return;
    }

    if (loadingModel) {
        QMessageBox::warning(NULL, "Warning", "Already loading model");
        return;
    }

    loadingModel = true;

    modelsLeft = spawns.size();

    repo->cleanCurrentObjects();

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(modelsLeft);
    ui->progressBar->setValue(0);

    removeSceneChildren();

    QThreadPool* threadPool = QThreadPool::globalInstance();

    for (int i = 0; i < modelsLeft; ++i) {
        AppendModelLoadWork* work = new AppendModelLoadWork(this, spawns[i]);
        threadPool->start(work);
    }

    create3DView();

    show();

    activateWindow();
}

void ObjectModel3dViewer::create3DView() {
    if (!osgViewerWidget->isRealized()) {
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
    }
}

void ObjectModel3dViewer::increaseProgress(int vals) {
    ui->progressBar->setValue(ui->progressBar->value() + vals);
}

void ObjectModel3dViewer::addNodeToCurrentScene(osg::Node* node) {
    QMutexLocker locker(&mutex);

    if (node != NULL)
        rootNode->addChild(node);

    if (--modelsLeft == 0) {
        loadingModel = false;
    }

    emit increaseUiProgress(1);
}

void ObjectModel3dViewer::loadFile() {
    QMutexLocker locker(&mutex);

    if (loadingModel) {
        QMessageBox::warning(NULL, "Warning", "Already loading model");
        return;
    }

    loadingModel = true;

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);

    QString file = ui->lineEdit_template->text();

    if (repo == NULL) {
        QMessageBox::warning(NULL, "Warning", "You must set a tre directory");

        loadingModel = false;
        return;
    }

    repo->cleanCurrentObjects();

    ui->progressBar->setValue(10);

    QThreadPool* threadPool = QThreadPool::globalInstance();

    SingleModelLoadWork* work = new SingleModelLoadWork(repo, file, this);
    threadPool->start(work);

    show();

    activateWindow();

    //this->s
}

void ObjectModel3dViewer::removeSceneChildren() {
    MainWindow::instance->outputToConsole("removing scene children");

    while (rootNode->getNumChildren() > 0)
        rootNode->removeChildren(0, 1);

    MainWindow::instance->outputToConsole("done");
}

void ObjectModel3dViewer::loadFileFinished(osg::Node* node) {
    QMutexLocker locker(&mutex);

    ui->progressBar->setValue(90);

    if (node == NULL) {
        ui->progressBar->setValue(100);
        QMessageBox::warning(NULL, "Warning", "Could not parse file");

        loadingModel = false;
        return;
    }

    removeSceneChildren();

    rootNode->addChild(node);

    ui->progressBar->setValue(100);

    loadingModel = false;

    // locker.

    create3DView();

}
