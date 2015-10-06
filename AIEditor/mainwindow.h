#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QMainWindow>
#include <QModelIndex>
#include <QMenu>

#include "ui_mainwindow.h"
#include "actiongroups.h"

class TreeItem;

class MainWindow : public QMainWindow, private Ui::MainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

    void loadSettings();
    void saveSettings();

    void insertChildBehavior(TreeItem* behavior);
    void insertChildDecision(TreeItem* behavior);

private:
	QDir scriptsDir;
	QFileInfo currentFileInfo;
	QFile currentFile;

    ActionGroup actionGroup;
    CheckGroup checkGroup;
    CompositeGroup compositeGroup;
    NodeGroup nodeGroup;
    LeafGroup leafGroup;

signals:

public slots:
	void updateBehaviors();

private slots:
	void insertChild();
	void openFileDialog();
    void openDirDialog();
    void clear();
};

#endif // MAINWINDOW_H
