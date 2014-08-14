#include "mainwindow.h"
#include "inspectiondialog.h"
#include "ui_mainwindow.h"
#include "databasemodel.h"
#include "databaselistmodel.h"
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

    ui->listView->setModel(DatabaseListModel::instance());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    InspectionDialog id(this);
    QByteArray ba = DatabaseModel::instance()->getData(index.row());
    QMap<IDLVar, QByteArray> variableList = DatabaseModel::instance()->getVariableList(ba);
    id.setInformation(variableList);
    id.exec();
}

void MainWindow::on_idlButton_clicked()
{
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

        } catch ( DatabaseException & e ) {
            QMessageBox::critical(this, "Error Opening File", e.getMsg());
            return;
        }
    }
}

void MainWindow::on_databaseButton_clicked()
{
    QString dirName = QFileDialog::getExistingDirectory(this, "Select database directory", QDir::homePath() + "/MMOCoreORB/bin/databases");
    if (!dirName.isEmpty()) {
        try {
            QDir dir(dirName);
            DatabaseListModel::instance()->populateList(dir);
        } catch ( DatabaseException & e ) {
            QMessageBox::critical(this, "Error Opening File", e.getMsg());
            return;
        }
    }
}

void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    DatabaseListEntry entry = DatabaseListModel::instance()->getDbList()->values().at(index.row());
    QString fileName = DatabaseListModel::instance()->getDbPath() + "/" + entry.name + ".db";
    if (!fileName.isEmpty()) {
        try {
            DatabaseModel::instance()->setCompressed(entry.compressed);
            DatabaseModel::instance()->setObjectDB(entry.objectDB);
            DatabaseModel::instance()->open(fileName);
        } catch ( DatabaseException & e ) {
            QMessageBox::critical(this, "Error Opening File", e.getMsg());
            return;
        }

        ui->tableView->resizeColumnsToContents();

        //QMessageBox::information(this, "Opened File", "Opened file " + fileName + " as database.");
    }
}
