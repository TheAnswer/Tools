#include <iostream>

#include <QtGui>
#include <QFileDialog>

#include "mainwindow.h"
#include "treemodel.h"
#include "composite.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	setupUi(this);

	QStringList headers;
	headers << tr("Name") << tr("Type") << tr("Parameters");

	scriptsDir = QDir(tr("/home/swgemu/MMOCoreORB/bin/scripts/ai"), tr("Lua (*.lua)"));
	if (!scriptsDir.exists())
		scriptsDir = QDir::currentPath();

	currentFileInfo.setFile(scriptsDir.absolutePath() + tr("/templates/example.lua"));

	TreeModel *model = new TreeModel();
    btTreeView->setModel(model);

	// File Menu
	connect(actionOpen, SIGNAL(triggered()), this, SLOT(openFileDialog()));
	connect(actionSelect_Scripts, SIGNAL(triggered()), this, SLOT(openDirDialog()));
	connect(actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));

	// Actions Menu
    connect(menuActions, SIGNAL(aboutToShow()), this, SLOT(updateBehaviors()));
    connect(actionSelector, SIGNAL(triggered()), this, SLOT(insertChildBehavior()));
    connect(actionSequence, SIGNAL(triggered()), this, SLOT(insertChildBehavior()));
    compositeGroup.addAction(actionSelector);
    compositeGroup.addAction(actionSequence);
	// TODO: actions will need to be forced to have no children and composites will allow children
	// probably rewrite TreeItem to be Action (with no children) and have Composite inherit that to add children

    updateBehaviors();
}

MainWindow::~MainWindow()
{}

void MainWindow::updateBehaviors()
{
	// Process the actions file for actions. Don't worry about overhead since the file is
	// never going to get too big. This way we don't have to think when we update the file
	// since it will always reprocess when opening the menu.
	QList<QAction*> actions = menuInsert_Action->actions();
	for (QList<QAction*>::iterator it = actions.begin(); it != actions.end(); ++it)
	{
		menuInsert_Action->removeAction(*it);
	}

	QFile actionsFile(scriptsDir.absoluteFilePath("actions/actions.lua"));

	if (!actionsFile.open(QIODevice::ReadOnly | QIODevice::Text))
		return;

	QTextStream in(&actionsFile);
	while (!in.atEnd())
	{
		QStringList line = in.readLine().split('"');
		if (line.length() < 2)
			continue;

		QFile actionFile(scriptsDir.absoluteFilePath(line.at(1)));
		QRegExp classDefs("(.*) = createClass.*");

		if (!actionFile.open(QIODevice::ReadOnly | QIODevice::Text))
			return;

		QTextStream fullIn(&actionFile);
		while (!fullIn.atEnd())
		{
			QString contents = fullIn.readLine();

			if (classDefs.exactMatch(contents)) {
                QString actionText = classDefs.capturedTexts().at(1);
                QAction *newAction = new QAction(actionText, this);
				menuInsert_Action->addAction(newAction);

                if (QStringRef(&actionText, 0, 2) == "is")
                    checkGroup.addAction(newAction);
                else //if (QStringRef(&actionText, 0, 2) == "do")
                    actionGroup.addAction(newAction);

                connect(newAction, SIGNAL(triggered()), this, SLOT(insertChildBehavior()));
			}
		}
	}
}

void MainWindow::openFileDialog()
{
	QString fileSelection = QFileDialog::getOpenFileName(this, tr("Open Template File"), currentFileInfo.absolutePath(), tr("Lua (*.lua)"));
	if (fileSelection.isEmpty())
		return;

	currentFileInfo = fileSelection;

	// TODO: Need to determine if we have a template or an action (possibly use the directory structure or the file structure)
	// TODO: process the file
}

void MainWindow::openDirDialog()
{
	QString dirSelection = QFileDialog::getExistingDirectory(this, tr("Set Script Directory"), scriptsDir.absolutePath());
	if (dirSelection.isEmpty())
		return;

	scriptsDir = dirSelection;

	// TODO: process the directory to populate the action menu
	//	possibly a popout tool selector like dia
	//	or a scrollbox in the first column (is that even doable?)
	//	or a menu subitem to insert action and insert composite
}

void MainWindow::insertChildBehavior()
{
	QAction *senderAction = dynamic_cast<QAction*>(sender());

	if (senderAction != NULL)
		std::cout << senderAction->text().toStdString() << std::endl;

    TreeModel* model = dynamic_cast<TreeModel*>(btTreeView->model());

	if (model == NULL) return;

    QModelIndex index = btTreeView->selectionModel()->currentIndex();

    BehaviorGroup *senderGroup = dynamic_cast<BehaviorGroup *>(senderAction->actionGroup());
    if (!model->addItem(senderGroup, index))
        return;

    model->setData(model->index(0, 0, index), senderAction->text(), Qt::DisplayRole);

    QString childType("[No Data]");
    if (senderGroup->isAction())
        childType = "Action";
    else if (senderGroup->isCheck())
        childType = "Check";
    else if (senderGroup->isComposite())
        childType = "Composite";

    model->setData(model->index(0, 1, index), childType, Qt::EditRole);

    // TODO: add flags?
    model->setData(model->index(0, 2, index), QString("[No Data]"), Qt::EditRole);

    btTreeView->selectionModel()->setCurrentIndex(model->index(0, 0, index), QItemSelectionModel::ClearAndSelect);

    btTreeView->resizeColumnToContents(0);
    btTreeView->resizeColumnToContents(1);
    btTreeView->resizeColumnToContents(2);

    updateBehaviors();
}
