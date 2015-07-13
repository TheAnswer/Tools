#include <iostream>

#include <QtGui>

#include "mainwindow.h"
#include "treemodel.h"

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
	treeView->setModel(model);

	// File Menu
	connect(actionOpen, SIGNAL(triggered()), this, SLOT(openFileDialog()));
	connect(actionSelect_Scripts, SIGNAL(triggered()), this, SLOT(openDirDialog()));
	connect(actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));

	// Actions Menu
	connect(menuActions, SIGNAL(aboutToShow()), this, SLOT(updateActions()));
	connect(actionSelector, SIGNAL(triggered()), this, SLOT(insertChild()));
	connect(actionSequence, SIGNAL(triggered()), this, SLOT(insertChild()));
	// TODO: actions will need to be forced to have no children and composites will allow children
	// probably rewrite TreeItem to be Action (with no children) and have Composite inherit that to add children

	updateActions();
}

MainWindow::~MainWindow()
{}

void MainWindow::updateActions()
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
				QAction *newAction = new QAction(classDefs.capturedTexts().at(1), this);
				menuInsert_Action->addAction(newAction);

				connect(newAction, SIGNAL(triggered()), this, SLOT(insertChild()));
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

void MainWindow::insertChild()
{
	QAction *senderAction = dynamic_cast<QAction*>(sender());

	if (senderAction != NULL)
		std::cout << senderAction->text().toStdString() << std::endl;

	TreeModel* model = static_cast<TreeModel*>(treeView->model());

	if (model == NULL) return;

	QModelIndex index = treeView->selectionModel()->currentIndex();

	if (!model->insertRows(0, 1, index)) return;

	for (int column = 0; column < model->columnCount(index); column++) {
		QModelIndex child = model->index(0, column, index);
		model->setData(child, QVariant("[No Data]"), Qt::EditRole);
	}

	treeView->selectionModel()->setCurrentIndex(model->index(0, 0, index), QItemSelectionModel::ClearAndSelect);

	treeView->resizeColumnToContents(0);
	treeView->resizeColumnToContents(1);
	treeView->resizeColumnToContents(2);

	updateActions();
}
