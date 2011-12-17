/********************************************************************************
** Form generated from reading UI file 'lairtool.ui'
**
** Created: Sat 17. Dec 22:02:11 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAIRTOOL_H
#define UI_LAIRTOOL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LairTool
{
public:
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout;
    QLabel *label;
    QListWidget *listWidget_mobiles;
    QPushButton *pushButton_addMobile;
    QPushButton *pushButton_removeMobile;
    QLabel *label_2;
    QSpinBox *spinBox;
    QGridLayout *gridLayout_7;
    QLabel *label_3;
    QTabWidget *tabWidget_buildings;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QListWidget *listWidget_veryEasy;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QListWidget *listWidget_easy;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QListWidget *listWidget_Medium;
    QWidget *tab_4;
    QGridLayout *gridLayout_5;
    QListWidget *listWidget_Hard;
    QWidget *tab_5;
    QGridLayout *gridLayout_6;
    QListWidget *listWidget_veryHard;
    QPushButton *pushButton_AddBuilding;
    QPushButton *pushButton_RemoveBuilding;
    QPushButton *pushButton_view3d;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LairTool)
    {
        if (LairTool->objectName().isEmpty())
            LairTool->setObjectName(QString::fromUtf8("LairTool"));
        LairTool->resize(324, 501);
        gridLayout_8 = new QGridLayout(LairTool);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(LairTool);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        listWidget_mobiles = new QListWidget(LairTool);
        listWidget_mobiles->setObjectName(QString::fromUtf8("listWidget_mobiles"));

        gridLayout->addWidget(listWidget_mobiles, 1, 0, 2, 1);

        pushButton_addMobile = new QPushButton(LairTool);
        pushButton_addMobile->setObjectName(QString::fromUtf8("pushButton_addMobile"));

        gridLayout->addWidget(pushButton_addMobile, 1, 1, 1, 1);

        pushButton_removeMobile = new QPushButton(LairTool);
        pushButton_removeMobile->setObjectName(QString::fromUtf8("pushButton_removeMobile"));

        gridLayout->addWidget(pushButton_removeMobile, 2, 1, 1, 1);

        label_2 = new QLabel(LairTool);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 1, 1, 1);

        spinBox = new QSpinBox(LairTool);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        gridLayout->addWidget(spinBox, 4, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_3 = new QLabel(LairTool);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_7->addWidget(label_3, 0, 0, 1, 1);

        tabWidget_buildings = new QTabWidget(LairTool);
        tabWidget_buildings->setObjectName(QString::fromUtf8("tabWidget_buildings"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        listWidget_veryEasy = new QListWidget(tab);
        listWidget_veryEasy->setObjectName(QString::fromUtf8("listWidget_veryEasy"));

        gridLayout_2->addWidget(listWidget_veryEasy, 0, 0, 1, 1);

        tabWidget_buildings->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        listWidget_easy = new QListWidget(tab_3);
        listWidget_easy->setObjectName(QString::fromUtf8("listWidget_easy"));

        gridLayout_3->addWidget(listWidget_easy, 0, 0, 1, 1);

        tabWidget_buildings->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        listWidget_Medium = new QListWidget(tab_2);
        listWidget_Medium->setObjectName(QString::fromUtf8("listWidget_Medium"));

        gridLayout_4->addWidget(listWidget_Medium, 0, 0, 1, 1);

        tabWidget_buildings->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_5 = new QGridLayout(tab_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        listWidget_Hard = new QListWidget(tab_4);
        listWidget_Hard->setObjectName(QString::fromUtf8("listWidget_Hard"));

        gridLayout_5->addWidget(listWidget_Hard, 0, 0, 1, 1);

        tabWidget_buildings->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_6 = new QGridLayout(tab_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        listWidget_veryHard = new QListWidget(tab_5);
        listWidget_veryHard->setObjectName(QString::fromUtf8("listWidget_veryHard"));

        gridLayout_6->addWidget(listWidget_veryHard, 0, 0, 1, 1);

        tabWidget_buildings->addTab(tab_5, QString());

        gridLayout_7->addWidget(tabWidget_buildings, 1, 0, 1, 2);

        pushButton_AddBuilding = new QPushButton(LairTool);
        pushButton_AddBuilding->setObjectName(QString::fromUtf8("pushButton_AddBuilding"));

        gridLayout_7->addWidget(pushButton_AddBuilding, 3, 0, 1, 1);

        pushButton_RemoveBuilding = new QPushButton(LairTool);
        pushButton_RemoveBuilding->setObjectName(QString::fromUtf8("pushButton_RemoveBuilding"));

        gridLayout_7->addWidget(pushButton_RemoveBuilding, 3, 1, 1, 1);

        pushButton_view3d = new QPushButton(LairTool);
        pushButton_view3d->setObjectName(QString::fromUtf8("pushButton_view3d"));

        gridLayout_7->addWidget(pushButton_view3d, 2, 0, 1, 2);


        gridLayout_8->addLayout(gridLayout_7, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(LairTool);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_8->addWidget(buttonBox, 3, 0, 1, 1);


        retranslateUi(LairTool);
        QObject::connect(buttonBox, SIGNAL(accepted()), LairTool, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LairTool, SLOT(reject()));

        tabWidget_buildings->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LairTool);
    } // setupUi

    void retranslateUi(QDialog *LairTool)
    {
        LairTool->setWindowTitle(QApplication::translate("LairTool", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LairTool", "Mobiles and Default level", 0, QApplication::UnicodeUTF8));
        pushButton_addMobile->setText(QApplication::translate("LairTool", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_removeMobile->setText(QApplication::translate("LairTool", "Remove", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LairTool", "Spawn Limit", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LairTool", "Buildings", 0, QApplication::UnicodeUTF8));
        tabWidget_buildings->setTabText(tabWidget_buildings->indexOf(tab), QApplication::translate("LairTool", "Very Easy", 0, QApplication::UnicodeUTF8));
        tabWidget_buildings->setTabText(tabWidget_buildings->indexOf(tab_3), QApplication::translate("LairTool", "Easy", 0, QApplication::UnicodeUTF8));
        tabWidget_buildings->setTabText(tabWidget_buildings->indexOf(tab_2), QApplication::translate("LairTool", "Medium", 0, QApplication::UnicodeUTF8));
        tabWidget_buildings->setTabText(tabWidget_buildings->indexOf(tab_4), QApplication::translate("LairTool", "Hard", 0, QApplication::UnicodeUTF8));
        tabWidget_buildings->setTabText(tabWidget_buildings->indexOf(tab_5), QApplication::translate("LairTool", "Very Hard", 0, QApplication::UnicodeUTF8));
        pushButton_AddBuilding->setText(QApplication::translate("LairTool", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_RemoveBuilding->setText(QApplication::translate("LairTool", "Remove", 0, QApplication::UnicodeUTF8));
        pushButton_view3d->setText(QApplication::translate("LairTool", "View 3d model", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LairTool: public Ui_LairTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAIRTOOL_H
