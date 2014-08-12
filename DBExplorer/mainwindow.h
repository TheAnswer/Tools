#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "idlparser.h"
#include <QMainWindow>
#include <QSettings>
#include <QString>
#include <QModelIndex>
#include <QHash>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
