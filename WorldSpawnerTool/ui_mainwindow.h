/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Jan 3 14:26:19 2012
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
#include <QtGui/QTableWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
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
    QAction *actionManage_Loot_Item_Templates;
    QAction *actionManage_Loot_Groups;
    QAction *actionLoot_Manager;
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QGraphicsView *graphicsView;
    QTextBrowser *textBrowser;
    QPushButton *load;
    QPushButton *pushButton_SavePlanet;
    QPushButton *pushButton_ChangePlanet;
    QGridLayout *gridLayout;
    QLabel *label_8;
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
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QListWidget *spawnsList;
    QPushButton *pushButton_addSpawn;
    QPushButton *pushButton_removeSpawn;
    QPushButton *pushButton_editSpawn;
    QGridLayout *gridLayout_4;
    QLabel *label_StaticSpawns;
    QLabel *label_7;
    QComboBox *comboBox_StaticSpawns;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget_StaticSpawns;
    QPushButton *pushButton_InsertStaticSpawn;
    QPushButton *pushButton_RemoveStaticSpawn;
    QLineEdit *lineEdit_StaticSpawnSearch;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QMenu *menuTest;
    QMenu *menuCreature_Manager;
    QMenu *menuEdit;
    QMenu *menuLoot;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(817, 772);
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
        actionManage_Loot_Item_Templates = new QAction(MainWindow);
        actionManage_Loot_Item_Templates->setObjectName(QString::fromUtf8("actionManage_Loot_Item_Templates"));
        actionManage_Loot_Groups = new QAction(MainWindow);
        actionManage_Loot_Groups->setObjectName(QString::fromUtf8("actionManage_Loot_Groups"));
        actionLoot_Manager = new QAction(MainWindow);
        actionLoot_Manager->setObjectName(QString::fromUtf8("actionLoot_Manager"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(0, 0));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        gridLayout_5->addWidget(graphicsView, 0, 0, 4, 1);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMaximumSize(QSize(100, 25));

        gridLayout_5->addWidget(textBrowser, 0, 1, 1, 1);

        load = new QPushButton(centralWidget);
        load->setObjectName(QString::fromUtf8("load"));

        gridLayout_5->addWidget(load, 0, 2, 1, 1);

        pushButton_SavePlanet = new QPushButton(centralWidget);
        pushButton_SavePlanet->setObjectName(QString::fromUtf8("pushButton_SavePlanet"));

        gridLayout_5->addWidget(pushButton_SavePlanet, 0, 3, 1, 1);

        pushButton_ChangePlanet = new QPushButton(centralWidget);
        pushButton_ChangePlanet->setObjectName(QString::fromUtf8("pushButton_ChangePlanet"));

        gridLayout_5->addWidget(pushButton_ChangePlanet, 0, 4, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 0, 2, 1, 1);

        regions = new QComboBox(centralWidget);
        regions->setObjectName(QString::fromUtf8("regions"));

        gridLayout->addWidget(regions, 1, 1, 1, 2);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 2, 0, 1, 2);

        regionX = new QDoubleSpinBox(centralWidget);
        regionX->setObjectName(QString::fromUtf8("regionX"));
        regionX->setMinimum(-7680);
        regionX->setMaximum(7680);

        gridLayout->addWidget(regionX, 2, 2, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 3, 0, 1, 2);

        regionY = new QDoubleSpinBox(centralWidget);
        regionY->setObjectName(QString::fromUtf8("regionY"));
        regionY->setMinimum(-7680);
        regionY->setMaximum(7680);

        gridLayout->addWidget(regionY, 3, 2, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 4, 1, 1, 1);

        regionRadius = new QDoubleSpinBox(centralWidget);
        regionRadius->setObjectName(QString::fromUtf8("regionRadius"));
        regionRadius->setMinimum(-1);
        regionRadius->setMaximum(512);

        gridLayout->addWidget(regionRadius, 4, 2, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 5, 1, 1, 1);

        tier = new QSpinBox(centralWidget);
        tier->setObjectName(QString::fromUtf8("tier"));

        gridLayout->addWidget(tier, 5, 2, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 6, 1, 1, 1);

        constant = new QSpinBox(centralWidget);
        constant->setObjectName(QString::fromUtf8("constant"));

        gridLayout->addWidget(constant, 6, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout, 2, 1, 1, 4);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        spawnsList = new QListWidget(centralWidget);
        spawnsList->setObjectName(QString::fromUtf8("spawnsList"));

        gridLayout_3->addWidget(spawnsList, 2, 0, 1, 3);

        pushButton_addSpawn = new QPushButton(centralWidget);
        pushButton_addSpawn->setObjectName(QString::fromUtf8("pushButton_addSpawn"));

        gridLayout_3->addWidget(pushButton_addSpawn, 3, 0, 1, 1);

        pushButton_removeSpawn = new QPushButton(centralWidget);
        pushButton_removeSpawn->setObjectName(QString::fromUtf8("pushButton_removeSpawn"));

        gridLayout_3->addWidget(pushButton_removeSpawn, 3, 1, 1, 1);

        pushButton_editSpawn = new QPushButton(centralWidget);
        pushButton_editSpawn->setObjectName(QString::fromUtf8("pushButton_editSpawn"));

        gridLayout_3->addWidget(pushButton_editSpawn, 3, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 3, 1, 1, 4);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_StaticSpawns = new QLabel(centralWidget);
        label_StaticSpawns->setObjectName(QString::fromUtf8("label_StaticSpawns"));

        gridLayout_4->addWidget(label_StaticSpawns, 0, 0, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 0, 1, 1, 1);

        comboBox_StaticSpawns = new QComboBox(centralWidget);
        comboBox_StaticSpawns->setObjectName(QString::fromUtf8("comboBox_StaticSpawns"));

        gridLayout_4->addWidget(comboBox_StaticSpawns, 2, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableWidget_StaticSpawns = new QTableWidget(centralWidget);
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

        gridLayout_2->addWidget(tableWidget_StaticSpawns, 0, 0, 3, 1);

        pushButton_InsertStaticSpawn = new QPushButton(centralWidget);
        pushButton_InsertStaticSpawn->setObjectName(QString::fromUtf8("pushButton_InsertStaticSpawn"));

        gridLayout_2->addWidget(pushButton_InsertStaticSpawn, 0, 1, 1, 1);

        pushButton_RemoveStaticSpawn = new QPushButton(centralWidget);
        pushButton_RemoveStaticSpawn->setObjectName(QString::fromUtf8("pushButton_RemoveStaticSpawn"));

        gridLayout_2->addWidget(pushButton_RemoveStaticSpawn, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 3, 0, 1, 1);

        lineEdit_StaticSpawnSearch = new QLineEdit(centralWidget);
        lineEdit_StaticSpawnSearch->setObjectName(QString::fromUtf8("lineEdit_StaticSpawnSearch"));
        lineEdit_StaticSpawnSearch->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(lineEdit_StaticSpawnSearch, 2, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 4, 0, 1, 5);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 817, 21));
        menuTest = new QMenu(menuBar);
        menuTest->setObjectName(QString::fromUtf8("menuTest"));
        menuCreature_Manager = new QMenu(menuBar);
        menuCreature_Manager->setObjectName(QString::fromUtf8("menuCreature_Manager"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuLoot = new QMenu(menuBar);
        menuLoot->setObjectName(QString::fromUtf8("menuLoot"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTest->menuAction());
        menuBar->addAction(menuCreature_Manager->menuAction());
        menuBar->addAction(menuLoot->menuAction());
        menuTest->addAction(actionGeneral_settings);
        menuTest->addAction(actionConnect_to_database);
        menuTest->addAction(actionConsole);
        menuCreature_Manager->addAction(actionLoad);
        menuCreature_Manager->addAction(actionLair_Tool);
        menuCreature_Manager->addSeparator();
        menuCreature_Manager->addAction(actionPreOR_Creatures);
        menuCreature_Manager->addAction(action_3dviewer);
        menuLoot->addAction(actionManage_Loot_Item_Templates);
        menuLoot->addAction(actionManage_Loot_Groups);
        menuLoot->addAction(actionLoot_Manager);

        retranslateUi(MainWindow);

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
        actionManage_Loot_Item_Templates->setText(QApplication::translate("MainWindow", "Manage Loot Item Templates", 0, QApplication::UnicodeUTF8));
        actionManage_Loot_Groups->setText(QApplication::translate("MainWindow", "Manage Loot Groups", 0, QApplication::UnicodeUTF8));
        actionLoot_Manager->setText(QApplication::translate("MainWindow", "Loot Manager", 0, QApplication::UnicodeUTF8));
        load->setText(QApplication::translate("MainWindow", "Reload Planet", 0, QApplication::UnicodeUTF8));
        pushButton_SavePlanet->setText(QApplication::translate("MainWindow", "Save Planet", 0, QApplication::UnicodeUTF8));
        pushButton_ChangePlanet->setText(QApplication::translate("MainWindow", "Change Planet", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Spawn Regions", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "x", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "y", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Radius", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Tier", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Constant", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Spawns", 0, QApplication::UnicodeUTF8));
        pushButton_addSpawn->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_removeSpawn->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        pushButton_editSpawn->setText(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        label_StaticSpawns->setText(QApplication::translate("MainWindow", "Static Spawns", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Search", 0, QApplication::UnicodeUTF8));
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
        pushButton_InsertStaticSpawn->setText(QApplication::translate("MainWindow", "Insert", 0, QApplication::UnicodeUTF8));
        pushButton_RemoveStaticSpawn->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        menuTest->setTitle(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        menuCreature_Manager->setTitle(QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuLoot->setTitle(QApplication::translate("MainWindow", "Loot", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
