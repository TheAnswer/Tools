#include <iostream>

#include <QtGui>
#include <QFileDialog>
#include <QSettings>
#include <QList>
#include <QMap>

#include "mainwindow.h"
#include "treemodel.h"
#include "node.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);

    loadSettings();

    currentFileInfo.setFile(scriptsDir.absolutePath() + tr("/templates/example.lua"));

    TreeModel *btModel = new TreeModel();
    TreeModel *dtModel = new TreeModel();
    btTreeView->setModel(btModel);
    dtTreeView->setModel(dtModel);
    btTreeView->setSelectionMode(QAbstractItemView::SingleSelection);
    dtTreeView->setSelectionMode(QAbstractItemView::SingleSelection);
    
    connect(btTreeView->selectionModel(),
            SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)),
            this,
            SLOT(btSelectionCallback(const QItemSelection&, const QItemSelection&)));
    connect(dtTreeView->selectionModel(),
            SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)),
            this,
            SLOT(dtSelectionCallback(const QItemSelection&, const QItemSelection&)));

    // File Menu
    connect(actionOpen, SIGNAL(triggered()), this, SLOT(openFileDialog()));
    connect(actionSelect_Scripts, SIGNAL(triggered()), this, SLOT(openDirDialog()));
    connect(actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));

    // Actions Menu
    connect(menuActions, SIGNAL(aboutToShow()), this, SLOT(updateBehaviors()));
    connect(actionSelector, SIGNAL(triggered()), this, SLOT(insertChild()));
    connect(actionSequence, SIGNAL(triggered()), this, SLOT(insertChild()));
    compositeGroup.addAction(actionSelector);
    compositeGroup.addAction(actionSequence);

    updateBehaviors();
}

MainWindow::~MainWindow()
{
    saveSettings();
}

void MainWindow::btSelectionCallback(const QItemSelection& selected, const QItemSelection& deselected)
{
    QModelIndex selIdx = selected.indexes().at(0);
    if (selIdx.isValid())
    {
        QString name = static_cast<TreeItem*>(selIdx.internalPointer())->name().toString();
        QString dtName = dynamic_cast<TreeModel*>(btTreeView->model())->getDT(name);
        std::cout << "Selected: " << name.toStdString() << ":" << dtName.toStdString() << std::endl;
    }
    
    QModelIndex desIdx = deselected.indexes().at(0);
    if (desIdx.isValid())
    {
        QString name = static_cast<TreeItem*>(desIdx.internalPointer())->name().toString();
        QString dtName = dynamic_cast<TreeModel*>(btTreeView->model())->getDT(name);
        std::cout << "Deselected: " << name.toStdString() << ":" << dtName.toStdString() << std::endl;
    }
}

void MainWindow::dtSelectionCallback(const QItemSelection& /*selected*/, const QItemSelection& /*deselected*/)
{
    
}

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
        QRegExp classDefs("(.*) = createClass\\((.*),\\s*(.*)\\)");

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
                else //if (QStringRef(&actionText, 0, 2) == "anything else")
                    actionGroup.addAction(newAction);
                
                TreeModel *model = dynamic_cast<TreeModel*>(btTreeView->model());
                if (model) model->mapDTtoBT(classDefs.capturedTexts().at(3),
                                            classDefs.capturedTexts().at(2));

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
    if (!currentFileInfo.isFile()) return;

    currentFile.close();
    currentFile.setFileName(currentFileInfo.absoluteFilePath());

    if (!currentFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QMap<QString, QStringList> actions;

    QTextStream tempIn(&currentFile);
    while (!tempIn.atEnd())
    {
        QStringList line = tempIn.readLine().split(',');
        if (line.length() < 4) continue;

        for (QStringList::iterator it = line.begin(); it != line.end(); ++it)
            it->remove('{').remove('}').remove('"');

        actions[line.at(0)] = line;
    }
    
    // This ensures that we don't have NULL models, so no need to check
    clear();

    TreeModel *btModel = dynamic_cast<TreeModel*>(btTreeView->model());
    //TreeModel *dtModel = dynamic_cast<TreeModel*>(dtTreeView->model());
    
    // for now assume we opened a template and parse it
    // each action has 4 entries (after trimming). The first is the id, and
    // is what the map is keyed to. The second is the name of the action lua
    // class. The third is the parent id. The fourth is the type of action
    // (selector, sequence, or behavior)
    
    // To ensure that we always have the id's to associate with parent id's,
    // build a list of everything first and then go back and assign the parents
    // and set up the display
    QMap<QString, QList<QMap<QString, QVariant> > > parents;
    for (QMap<QString, QStringList>::iterator it = actions.begin(); it != actions.end(); ++it)
    {
        QMap<QString, QVariant> data;
        
        if (it->at(3) == "SELECTORBEHAVIOR")
            data["Name"] = "Selector";
        else if (it->at(3) == "SEQUENCEBEHAVIOR")
            data["Name"] = "Sequence";
        else
            data["Name"] = it->at(1);
        
        data["ID"] = it->at(0);
        data["parentID"] = it->at(2);
        
        parents[data["parentID"].toString()].append(data);
    }
    
    // start with the parentID of "none" since this is necessarily the root
    // of the tree
    // parentID, parentItem
    QMap<QString, TreeItem*> idsToParse;
    {
        QList<QMap<QString, QVariant> > rootItems = parents.take("none");
        // just take the first entry, it should only have one entry so we don't
        // have any way to deal with the others anyway.
        QMap<QString, QVariant> rootData = rootItems.takeFirst();
        // no parent
        TreeItem *result = btModel->createItem(rootData);
        btModel->addItem(result);
        idsToParse[rootData["ID"].toString()] = result;
    }
    
    // Now loop through the rest and add them where they need to be
    while (!idsToParse.isEmpty())
    {
        QString currentID = idsToParse.keys().at(0);
        Node *currentParent = dynamic_cast<Node*>(idsToParse[currentID]);
        idsToParse.remove(currentID);
        if (!currentParent) continue;
        
        QList<QMap<QString, QVariant> > currentItems = parents.take(currentID);
        
        for (QList<QMap<QString, QVariant> >::iterator it = currentItems.begin(); it != currentItems.end(); ++it)
        {
            TreeItem *result = btModel->createItem(*it, currentParent);
            btModel->addItem(result);
            idsToParse[(*it)["ID"].toString()] = result;
        }
    }

    // now we have a map of all items keyed by ID with parents assigned properly
    // TODO: Feature add: edit lua actions in the editor
}

void MainWindow::openDirDialog()
{
    QString dirSelection = QFileDialog::getExistingDirectory(this, tr("Set Script Directory"), scriptsDir.absolutePath());
    if (dirSelection.isEmpty())
        return;

    scriptsDir = dirSelection;

    // TODO: process the directory to populate the action menu
    //  possibly a popout tool selector like dia
    //  or a scrollbox in the first column (is that even doable?)
    //  or a menu subitem to insert action and insert composite
}

void MainWindow::clear()
{
    TreeModel* model = dynamic_cast<TreeModel*>(btTreeView->model());
    if (model == NULL) btTreeView->setModel(new TreeModel());
    else model->clear();

    model = dynamic_cast<TreeModel*>(dtTreeView->model());
    if (model == NULL) dtTreeView->setModel(new TreeModel());
    else model->clear();
}

void MainWindow::loadSettings()
{
    QSettings settings("config.ini", QSettings::IniFormat);
    
    QString pathName = settings.value("general/scriptsDir", tr("/home/swgemu/MMOCoreORB/bin/scripts/ai")).toString();
    scriptsDir = QDir(pathName, tr("Lua (*.lua)"));
    if (!scriptsDir.exists())
    {
        scriptsDir = QDir::currentPath();
        scriptsDir.setNameFilters(QStringList("Lua (*.lua)"));
    }

}

void MainWindow::saveSettings()
{
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.setValue("general/scriptsDir", scriptsDir.path());
}

void MainWindow::insertChild()
{
    QAction *senderAction = dynamic_cast<QAction*>(sender());
    if (senderAction == NULL) return;
	
    TypeGroup *senderGroup = dynamic_cast<TypeGroup *>(senderAction->actionGroup());
    if (!senderGroup) return;

    TreeModel* model = NULL;
    if (senderGroup->isBehavior())
        model = dynamic_cast<TreeModel*>(btTreeView->model());
    else if (senderGroup->isDecision())
        model = dynamic_cast<TreeModel*>(dtTreeView->model());
    if (model == NULL) return;

    QModelIndex index = btTreeView->selectionModel()->currentIndex();

    if (!model->addItem(senderAction, index)) return;

    btTreeView->selectionModel()->setCurrentIndex(model->index(0, 0, index), QItemSelectionModel::ClearAndSelect);
    btTreeView->resizeColumnToContents(0);
    btTreeView->resizeColumnToContents(1);
}

void MainWindow::insertChildBehavior(TreeItem* behavior)
{
    TreeModel *btModel = dynamic_cast<TreeModel*>(btTreeView->model());
    if (!btModel) return;
    
    if (!btModel->addItem(behavior)) return;
    
    btTreeView->resizeColumnToContents(0);
    btTreeView->resizeColumnToContents(1);
}

void MainWindow::insertChildDecision(TreeItem* decision)
{
    TreeModel *dtModel = dynamic_cast<TreeModel*>(dtTreeView->model());
    if (!dtModel) return;
    
    if (!dtModel->addItem(decision)) return;
    
    dtTreeView->resizeColumnToContents(0);
    dtTreeView->resizeColumnToContents(1);
}
