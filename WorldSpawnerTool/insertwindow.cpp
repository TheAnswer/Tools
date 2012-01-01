#include "insertwindow.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QKeyEvent>

InsertWindow::InsertWindow(MainWindow* main, QWidget *parent)
    : QWidget(parent) {
    ui.setupUi(this);

    mainWindow = main;

    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(insertObject()));
    connect(this, SIGNAL(insertSingleSpawn(InsertWindow*)), mainWindow, SLOT(insertSingleSpawn(InsertWindow*)));
    //connect(ui.)
    //connect(ui.lineEdit_Mobile, SIGNAL(returnPressed()), this, SLOT(insertObject()));
    //connect(this, ui.doubleSpinBox_Heading, SIGNAL())
}

InsertWindow::~InsertWindow() {

}

void InsertWindow::insertObject() {
    if (ui.lineEdit_Mobile->text().isEmpty()) {
        QMessageBox::warning(this, tr("Error"), tr("Invalid Mobile template"), QMessageBox::Ok);

        return;
    }

    hide();

    emit insertSingleSpawn(this);
}

void InsertWindow::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
    case Qt::Key_Enter:
    case Qt::Key_Return:
        insertObject();
        event->accept();
        break;
    default:
        break;
    }


}
