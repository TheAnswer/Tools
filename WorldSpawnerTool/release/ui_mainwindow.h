/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Jan 16 20:31:05 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect_to_database;
    QAction *actionConsole;
    QAction *actionDynamic_Spawn_Area;
    QAction *actionSingle_Spawn_Creature;
    QAction *actionGeneral_settings;
    QAction *actionLoad;
    QAction *actionPreOR_Creatures;
    QAction *actionChange_Planet;
    QAction *actionLair_Tool;
    QAction *action_3dviewer;
    QAction *actionSTF_Viewer;
    QAction *actionLootManager;
    QWidget *centralWidget;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayout_7;
    QTextBrowser *textBrowser;
    QGraphicsView *graphicsView;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QMenu *menuTest;
    QMenu *menuCreature_Manager;
    QMenu *menuEdit;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_3;
    QGridLayout *gridLayout_12;
    QTabWidget *tabWidget_main;
    QWidget *tab;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QComboBox *regions;
    QLabel *label;
    QDoubleSpinBox *regionX;
    QLabel *label_2;
    QDoubleSpinBox *regionY;
    QLabel *label_3;
    QDoubleSpinBox *regionRadius;
    QLabel *label_4;
    QSpinBox *tier;
    QLabel *label_5;
    QSpinBox *constant;
    QLabel *label_8;
    QListWidget *spawnsList;
    QPushButton *pushButton_addSpawn;
    QPushButton *pushButton_removeSpawn;
    QPushButton *pushButton_editSpawn;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QLabel *label_StaticSpawns;
    QComboBox *comboBox_StaticSpawns;
    QLineEdit *lineEdit_StaticSpawnSearch;
    QTableWidget *tableWidget_StaticSpawns;
    QGridLayout *gridLayout_9;
    QPushButton *pushButton_RemoveStaticSpawn;
    QPushButton *pushButton_InsertStaticSpawn;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_badgeX;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_badge_Y;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_badgeRadius;
    QLabel *label_13;
    QSpinBox *spinBox_badgeID;
    QListWidget *listWidget_badges;
    QPushButton *pushButton_addBadge;
    QPushButton *pushButton_removeBadge;
    QWidget *tab_4;
    QGridLayout *gridLayout_10;
    QTableWidget *tableWidget_worldSpashot;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(940, 593);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        actionConnect_to_database = new QAction(MainWindow);
        actionConnect_to_database->setObjectName(QString::fromUtf8("actionConnect_to_database"));
        actionConsole = new QAction(MainWindow);
        actionConsole->setObjectName(QString::fromUtf8("actionConsole"));
        actionDynamic_Spawn_Area = new QAction(MainWindow);
        actionDynamic_Spawn_Area->setObjectName(QString::fromUtf8("actionDynamic_Spawn_Area"));
        actionDynamic_Spawn_Area->setEnabled(false);
        actionSingle_Spawn_Creature = new QAction(MainWindow);
        actionSingle_Spawn_Creature->setObjectName(QString::fromUtf8("actionSingle_Spawn_Creature"));
        actionGeneral_settings = new QAction(MainWindow);
        actionGeneral_settings->setObjectName(QString::fromUtf8("actionGeneral_settings"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionPreOR_Creatures = new QAction(MainWindow);
        actionPreOR_Creatures->setObjectName(QString::fromUtf8("actionPreOR_Creatures"));
        actionChange_Planet = new QAction(MainWindow);
        actionChange_Planet->setObjectName(QString::fromUtf8("actionChange_Planet"));
        actionLair_Tool = new QAction(MainWindow);
        actionLair_Tool->setObjectName(QString::fromUtf8("actionLair_Tool"));
        action_3dviewer = new QAction(MainWindow);
        action_3dviewer->setObjectName(QString::fromUtf8("action_3dviewer"));
        actionSTF_Viewer = new QAction(MainWindow);
        actionSTF_Viewer->setObjectName(QString::fromUtf8("actionSTF_Viewer"));
        actionLootManager = new QAction(MainWindow);
        actionLootManager->setObjectName(QString::fromUtf8("actionLootManager"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_13 = new QGridLayout(centralWidget);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setSizeConstraint(QLayout::SetNoConstraint);
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMaximumSize(QSize(200, 25));

        gridLayout_7->addWidget(textBrowser, 1, 0, 1, 1);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(0, 0));
        graphicsView->setMaximumSize(QSize(16777215, 16777215));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        gridLayout_7->addWidget(graphicsView, 2, 0, 1, 1);


        gridLayout_13->addLayout(gridLayout_7, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 940, 21));
        menuTest = new QMenu(menuBar);
        menuTest->setObjectName(QString::fromUtf8("menuTest"));
        menuCreature_Manager = new QMenu(menuBar);
        menuCreature_Manager->setObjectName(QString::fromUtf8("menuCreature_Manager"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dockWidget_2->sizePolicy().hasHeightForWidth());
        dockWidget_2->setSizePolicy(sizePolicy);
        dockWidget_2->setMinimumSize(QSize(338, 366));
        dockWidget_2->setMaximumSize(QSize(524287, 524287));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        gridLayout_12 = new QGridLayout(dockWidgetContents_3);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        tabWidget_main = new QTabWidget(dockWidgetContents_3);
        tabWidget_main->setObjectName(QString::fromUtf8("tabWidget_main"));
        tabWidget_main->setMinimumSize(QSize(300, 0));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_11 = new QGridLayout(tab);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        regions = new QComboBox(tab);
        regions->setObjectName(QString::fromUtf8("regions"));

        gridLayout->addWidget(regions, 1, 1, 1, 2);

        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 2, 0, 1, 2);

        regionX = new QDoubleSpinBox(tab);
        regionX->setObjectName(QString::fromUtf8("regionX"));
        regionX->setMinimum(-7680);
        regionX->setMaximum(7680);

        gridLayout->addWidget(regionX, 2, 2, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 3, 0, 1, 2);

        regionY = new QDoubleSpinBox(tab);
        regionY->setObjectName(QString::fromUtf8("regionY"));
        regionY->setMinimum(-7680);
        regionY->setMaximum(7680);

        gridLayout->addWidget(regionY, 3, 2, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 4, 1, 1, 1);

        regionRadius = new QDoubleSpinBox(tab);
        regionRadius->setObjectName(QString::fromUtf8("regionRadius"));
        regionRadius->setMinimum(-1);
        regionRadius->setMaximum(1e+09);

        gridLayout->addWidget(regionRadius, 4, 2, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 5, 1, 1, 1);

        tier = new QSpinBox(tab);
        tier->setObjectName(QString::fromUtf8("tier"));

        gridLayout->addWidget(tier, 5, 2, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 6, 1, 1, 1);

        constant = new QSpinBox(tab);
        constant->setObjectName(QString::fromUtf8("constant"));

        gridLayout->addWidget(constant, 6, 2, 1, 1);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 1, 1, 2);

        spawnsList = new QListWidget(tab);
        spawnsList->setObjectName(QString::fromUtf8("spawnsList"));

        gridLayout_3->addWidget(spawnsList, 1, 0, 1, 3);

        pushButton_addSpawn = new QPushButton(tab);
        pushButton_addSpawn->setObjectName(QString::fromUtf8("pushButton_addSpawn"));

        gridLayout_3->addWidget(pushButton_addSpawn, 2, 0, 1, 1);

        pushButton_removeSpawn = new QPushButton(tab);
        pushButton_removeSpawn->setObjectName(QString::fromUtf8("pushButton_removeSpawn"));

        gridLayout_3->addWidget(pushButton_removeSpawn, 2, 1, 1, 1);

        pushButton_editSpawn = new QPushButton(tab);
        pushButton_editSpawn->setObjectName(QString::fromUtf8("pushButton_editSpawn"));

        gridLayout_3->addWidget(pushButton_editSpawn, 2, 2, 1, 1);


        gridLayout_11->addLayout(gridLayout_3, 0, 0, 1, 1);

        tabWidget_main->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 0, 2, 1, 1);

        label_StaticSpawns = new QLabel(tab_2);
        label_StaticSpawns->setObjectName(QString::fromUtf8("label_StaticSpawns"));

        gridLayout_2->addWidget(label_StaticSpawns, 1, 0, 1, 1);

        comboBox_StaticSpawns = new QComboBox(tab_2);
        comboBox_StaticSpawns->setObjectName(QString::fromUtf8("comboBox_StaticSpawns"));

        gridLayout_2->addWidget(comboBox_StaticSpawns, 1, 1, 1, 1);

        lineEdit_StaticSpawnSearch = new QLineEdit(tab_2);
        lineEdit_StaticSpawnSearch->setObjectName(QString::fromUtf8("lineEdit_StaticSpawnSearch"));
        lineEdit_StaticSpawnSearch->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(lineEdit_StaticSpawnSearch, 1, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        tableWidget_StaticSpawns = new QTableWidget(tab_2);
        if (tableWidget_StaticSpawns->columnCount() < 6)
            tableWidget_StaticSpawns->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_StaticSpawns->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_StaticSpawns->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_StaticSpawns->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_StaticSpawns->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_StaticSpawns->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_StaticSpawns->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget_StaticSpawns->setObjectName(QString::fromUtf8("tableWidget_StaticSpawns"));
        tableWidget_StaticSpawns->setMinimumSize(QSize(0, 100));

        gridLayout_4->addWidget(tableWidget_StaticSpawns, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        pushButton_RemoveStaticSpawn = new QPushButton(tab_2);
        pushButton_RemoveStaticSpawn->setObjectName(QString::fromUtf8("pushButton_RemoveStaticSpawn"));

        gridLayout_9->addWidget(pushButton_RemoveStaticSpawn, 0, 0, 1, 1);

        pushButton_InsertStaticSpawn = new QPushButton(tab_2);
        pushButton_InsertStaticSpawn->setObjectName(QString::fromUtf8("pushButton_InsertStaticSpawn"));

        gridLayout_9->addWidget(pushButton_InsertStaticSpawn, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_9);

        tabWidget_main->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_2 = new QVBoxLayout(tab_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_10, 0, 0, 1, 1);

        doubleSpinBox_badgeX = new QDoubleSpinBox(tab_3);
        doubleSpinBox_badgeX->setObjectName(QString::fromUtf8("doubleSpinBox_badgeX"));
        doubleSpinBox_badgeX->setMinimum(-1e+09);
        doubleSpinBox_badgeX->setMaximum(1e+09);

        gridLayout_5->addWidget(doubleSpinBox_badgeX, 0, 1, 1, 1);

        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_11, 1, 0, 1, 1);

        doubleSpinBox_badge_Y = new QDoubleSpinBox(tab_3);
        doubleSpinBox_badge_Y->setObjectName(QString::fromUtf8("doubleSpinBox_badge_Y"));
        doubleSpinBox_badge_Y->setMinimum(-1e+07);
        doubleSpinBox_badge_Y->setMaximum(1e+09);
        doubleSpinBox_badge_Y->setValue(0);

        gridLayout_5->addWidget(doubleSpinBox_badge_Y, 1, 1, 1, 1);

        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_12, 2, 0, 1, 1);

        doubleSpinBox_badgeRadius = new QDoubleSpinBox(tab_3);
        doubleSpinBox_badgeRadius->setObjectName(QString::fromUtf8("doubleSpinBox_badgeRadius"));
        doubleSpinBox_badgeRadius->setMaximum(1e+07);

        gridLayout_5->addWidget(doubleSpinBox_badgeRadius, 2, 1, 1, 1);

        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_13, 3, 0, 1, 1);

        spinBox_badgeID = new QSpinBox(tab_3);
        spinBox_badgeID->setObjectName(QString::fromUtf8("spinBox_badgeID"));

        gridLayout_5->addWidget(spinBox_badgeID, 3, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 2);

        listWidget_badges = new QListWidget(tab_3);
        listWidget_badges->setObjectName(QString::fromUtf8("listWidget_badges"));

        gridLayout_6->addWidget(listWidget_badges, 1, 0, 1, 2);

        pushButton_addBadge = new QPushButton(tab_3);
        pushButton_addBadge->setObjectName(QString::fromUtf8("pushButton_addBadge"));

        gridLayout_6->addWidget(pushButton_addBadge, 2, 0, 1, 1);

        pushButton_removeBadge = new QPushButton(tab_3);
        pushButton_removeBadge->setObjectName(QString::fromUtf8("pushButton_removeBadge"));

        gridLayout_6->addWidget(pushButton_removeBadge, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_6);

        tabWidget_main->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_10 = new QGridLayout(tab_4);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        tableWidget_worldSpashot = new QTableWidget(tab_4);
        if (tableWidget_worldSpashot->columnCount() < 11)
            tableWidget_worldSpashot->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_worldSpashot->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_worldSpashot->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_worldSpashot->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_worldSpashot->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_worldSpashot->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_worldSpashot->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_worldSpashot->setHorizontalHeaderItem(6, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_worldSpashot->setHorizontalHeaderItem(7, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_worldSpashot->setHorizontalHeaderItem(8, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_worldSpashot->setHorizontalHeaderItem(9, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_worldSpashot->setHorizontalHeaderItem(10, __qtablewidgetitem16);
        tableWidget_worldSpashot->setObjectName(QString::fromUtf8("tableWidget_worldSpashot"));

        gridLayout_10->addWidget(tableWidget_worldSpashot, 0, 0, 1, 1);

        tabWidget_main->addTab(tab_4, QString());

        gridLayout_12->addWidget(tabWidget_main, 0, 0, 1, 1);

        dockWidget_2->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_2);

        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTest->menuAction());
        menuBar->addAction(menuCreature_Manager->menuAction());
        menuTest->addAction(actionGeneral_settings);
        menuTest->addAction(actionConnect_to_database);
        menuTest->addAction(actionConsole);
        menuCreature_Manager->addAction(actionLoad);
        menuCreature_Manager->addAction(actionLair_Tool);
        menuCreature_Manager->addSeparator();
        menuCreature_Manager->addAction(actionPreOR_Creatures);
        menuCreature_Manager->addAction(action_3dviewer);
        menuCreature_Manager->addAction(actionSTF_Viewer);
        menuCreature_Manager->addAction(actionLootManager);

        retranslateUi(MainWindow);

        tabWidget_main->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionConnect_to_database->setText(QApplication::translate("MainWindow", "Connect to database", 0, QApplication::UnicodeUTF8));
        actionConsole->setText(QApplication::translate("MainWindow", "Console", 0, QApplication::UnicodeUTF8));
        actionDynamic_Spawn_Area->setText(QApplication::translate("MainWindow", "Dynamic Spawn Area", 0, QApplication::UnicodeUTF8));
        actionSingle_Spawn_Creature->setText(QApplication::translate("MainWindow", "Single Spawn Creature", 0, QApplication::UnicodeUTF8));
        actionGeneral_settings->setText(QApplication::translate("MainWindow", "General settings", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("MainWindow", "Creatures", 0, QApplication::UnicodeUTF8));
        actionPreOR_Creatures->setText(QApplication::translate("MainWindow", "PreOR Creatures", 0, QApplication::UnicodeUTF8));
        actionChange_Planet->setText(QApplication::translate("MainWindow", "Change Planet", 0, QApplication::UnicodeUTF8));
        actionLair_Tool->setText(QApplication::translate("MainWindow", "Lair Template Tool", 0, QApplication::UnicodeUTF8));
        action_3dviewer->setText(QApplication::translate("MainWindow", "3d model viewer", 0, QApplication::UnicodeUTF8));
        actionSTF_Viewer->setText(QApplication::translate("MainWindow", "STF Viewer", 0, QApplication::UnicodeUTF8));
        actionLootManager->setText(QApplication::translate("MainWindow", "Loot Manager", 0, QApplication::UnicodeUTF8));
        menuTest->setTitle(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        menuCreature_Manager->setTitle(QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        dockWidget_2->setWindowTitle(QApplication::translate("MainWindow", "Spawns", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "x", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "y", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Radius", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Tier", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Constant", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Spawn Regions", 0, QApplication::UnicodeUTF8));
        pushButton_addSpawn->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_removeSpawn->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        pushButton_editSpawn->setText(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        tabWidget_main->setTabText(tabWidget_main->indexOf(tab), QApplication::translate("MainWindow", "Spawn Regions", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Search", 0, QApplication::UnicodeUTF8));
        label_StaticSpawns->setText(QApplication::translate("MainWindow", "Static Spawns", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_StaticSpawns->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_StaticSpawns->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_StaticSpawns->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_StaticSpawns->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Heading", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_StaticSpawns->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Respawn", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_StaticSpawns->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "ParentID", 0, QApplication::UnicodeUTF8));
        pushButton_RemoveStaticSpawn->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        pushButton_InsertStaticSpawn->setText(QApplication::translate("MainWindow", "Insert", 0, QApplication::UnicodeUTF8));
        tabWidget_main->setTabText(tabWidget_main->indexOf(tab_2), QApplication::translate("MainWindow", "Static Spawns", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "x", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "y", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Radius", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Badge id", 0, QApplication::UnicodeUTF8));
        pushButton_addBadge->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_removeBadge->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        tabWidget_main->setTabText(tabWidget_main->indexOf(tab_3), QApplication::translate("MainWindow", "Badge Spawns", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_worldSpashot->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Object id", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_worldSpashot->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Parent id", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_worldSpashot->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Template", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_worldSpashot->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Cell id", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_worldSpashot->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_worldSpashot->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_worldSpashot->horizontalHeaderItem(6);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_worldSpashot->horizontalHeaderItem(7);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "oW", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_worldSpashot->horizontalHeaderItem(8);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "oX", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_worldSpashot->horizontalHeaderItem(9);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "oY", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_worldSpashot->horizontalHeaderItem(10);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "oZ", 0, QApplication::UnicodeUTF8));
        tabWidget_main->setTabText(tabWidget_main->indexOf(tab_4), QApplication::translate("MainWindow", "World Snapshot Objects", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
