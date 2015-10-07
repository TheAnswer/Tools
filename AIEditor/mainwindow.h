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
class QFile;

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
    
    // <finalName, <BTname, DTname> >
    QMap<QString, QPair<QString, QString> > compositeClasses;
    
    void readDefs(QFile& actionsFile);

signals:

public slots:
	void updateBehaviors();
	void updateDecisions();

private slots:
    void btSelectionCallback(const QItemSelection& selected, const QItemSelection& deselected);
    void dtSelectionCallback(const QItemSelection& selected, const QItemSelection& deselected);
    void idChangedCallback(const QModelIndex& topLeft, const QModelIndex& botRght);
    void removeBehavior();
    void removeDecision();
	void insertChild();
	void openFileDialog();
    void openDirDialog();
    void openSaveDialog();
    void clear();
};

#endif // MAINWINDOW_H
