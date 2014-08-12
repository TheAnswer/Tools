#include "mainwindow.h"
#include "inspectiondialog.h"
#include "ui_mainwindow.h"
#include "databasemodel.h"
#include <QTableView>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableView->setModel(DatabaseModel::instance());
    ui->tableView->verticalHeader()->setVisible(false);

    QString dirName = QFileDialog::getExistingDirectory(this, "Select base directory for .idl files", QDir::homePath() + "/Core3", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!dirName.isEmpty()) {
        try {
            QDir dir(dirName);
            DatabaseModel::instance()->getHashTable()->clear();
            IDLVar _className;
            _className.className = "";
            _className.hashCode = 0x76457CCA;
            _className.varName = "_className";
            _className.varType = "string";
            DatabaseModel::instance()->getHashTable()->insert(0x76457CCA, _className);
            IDLParser::parseIDLs(dir, DatabaseModel::instance()->getHashTable());

            // begin debug
            /*QStringList inf;
            QHash<unsigned int, IDLVar>::iterator i;
            for (i = DatabaseModel::instance()->getHashTable()->begin(); i != DatabaseModel::instance()->getHashTable()->end(); ++i) {
                if (!inf.contains(i.value().varType)) {
                    inf.append(i.value().varType);
                    std::cout << i.value().varType.toStdString() << std::endl;
                }
            }*/
            // end debug

        } catch ( DatabaseException & e ) {
            QMessageBox::critical(this, "Error Opening File", e.getMsg());
            return;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select database to open", QDir::homePath() + "/MMOCoreORB/bin/databases");
    if (!fileName.isEmpty()) {
        try {
            DatabaseModel::instance()->open(fileName);
        } catch ( DatabaseException & e ) {
            QMessageBox::critical(this, "Error Opening File", e.getMsg());
            return;
        }

        ui->tableView->resizeColumnsToContents();

        //QMessageBox::information(this, "Opened File", "Opened file " + fileName + " as database.");
    }
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QVariant display = DatabaseModel::instance()->data(index);

    //QMessageBox::information(this, "Selected", "Double clicked " + display.toString() + ".");
    InspectionDialog id(this);
    QByteArray ba = DatabaseModel::instance()->getData(index.row());
    QMap<IDLVar, QByteArray> variableList = DatabaseModel::instance()->getVariableList(ba);
    id.setInformation(variableList);
    id.exec();
}
