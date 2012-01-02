#include "stfviewer.h"
#include "ui_stfviewer.h"
#include "mainwindow.h"
#include <meshLib/str.hpp>

STFViewer::STFViewer(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::STFViewer) {
  ui->setupUi(this);

  ui->lineEdit->setText("string/en/mob/creature_names.stf");

  setWindowTitle("STFViewer");

  connect(ui->pushButton_open, SIGNAL(clicked()), this, SLOT(loadCurrentFile()));
  connect(ui->pushButton_stringID, SIGNAL(clicked()), this, SLOT(loadCurretStringID()));

  this->setWindowFlags(windowFlags() | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
}

STFViewer::~STFViewer() {
  delete ui;
}

void STFViewer::loadCurrentFile() {
  QString file = ui->lineEdit->text();

  loadFile(file);
}

void STFViewer::loadCurretStringID() {
  loadStringID(ui->lineEdit_stringID->text());
}

void STFViewer::loadStringID(const QString& id) {
  ui->lineEdit_stringID->setText(id);

  if (id.isEmpty()) {
    MainWindow::instance->warning("Wrong string id specified");
    return;
  }

  if (id.at(0) != '@') {
    MainWindow::instance->warning("Wrong string id specified");
    return;
  }

  if (!id.contains(":")) {
    MainWindow::instance->warning("Wrong string id specified");
    return;
  }

  int idx1 = id.indexOf(":", 1);

  QString file = id.mid(1, idx1 - 1);
  QString key = id.mid(idx1 + 1);

  ui->lineEdit->setText("string/en/" + file + ".stf");

  loadCurrentFile();

  for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
    QTableWidgetItem* item = ui->tableWidget->item(i, 0);

    if (item == NULL)
      continue;

    if (item->text() == key) {
      ui->tableWidget->setCurrentItem(item);

      return;
    }
  }

  MainWindow::instance->warning("StringID key not found in current file");
}

void STFViewer::loadFile(const QString& name) {
  ui->tableWidget->clearContents();

  treArchive* archive = MainWindow::instance->getTreArchive();

  if (archive == NULL) {
    MainWindow::instance->warning("Invalid tre directory!");
    return;
  }

  std::auto_ptr< std::istream > iffFile( archive->getFileStream( name.toStdString() ) );

  if( NULL == iffFile.get()) {
    //std::cout << "Unable to find file in archive!" << std::endl;
    MainWindow::instance->warning("Unable to find file in archive!");
    return;
  }

  ml::str parsedFile;

  if (!parsedFile.isRightType(*iffFile)) {
    return;
  }

  parsedFile.readSTR(*iffFile);

  std::map<std::string, std::string>* map = parsedFile.getMap();

  std::map<std::string, std::string>::const_iterator end = map->end();

  ui->tableWidget->setRowCount(map->size());

  //MainWindow::instance->outputToConsole("map size " + QString::number(map->size()));

  int row = 0;

  for (std::map<std::string, std::string>::const_iterator it = map->begin(); it != end; ++it) {
    QTableWidgetItem* item = new QTableWidgetItem(it->first.c_str());
    QTableWidgetItem* value = new QTableWidgetItem(it->second.c_str());
    item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    value->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

    ui->tableWidget->setItem(row, 0, item);
    ui->tableWidget->setItem(row, 1, value);
    ++row;
  }

  ui->tableWidget->resizeColumnsToContents();

}
