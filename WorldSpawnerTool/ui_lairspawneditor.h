/********************************************************************************
** Form generated from reading UI file 'lairspawneditor.ui'
**
** Created: Mon 12. Dec 06:27:05 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAIRSPAWNEDITOR_H
#define UI_LAIRSPAWNEDITOR_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_LairSpawnEditor
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox_maxSpawnLimit;
    QGridLayout *gridLayout;
    QLabel *label;
    QListWidget *listWidget_lairs;
    QPushButton *pushButton_add;
    QPushButton *pushButton_remove;
    QPushButton *pushButton_edit;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QSpinBox *spinBox_spawnLimit;
    QLabel *label_7;
    QSpinBox *spinBox_weighting;
    QLabel *label_4;
    QSpinBox *spinBox_minDifficulty;
    QLabel *label_8;
    QSpinBox *spinBox_size;
    QSpinBox *spinBox_maxDifficulty;
    QLabel *label_6;
    QSpinBox *spinBox_numberToSpawn;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *buttonBox;
    QLabel *label_lairTypeSelected;
    QLabel *label_5;

    void setupUi(QDialog *LairSpawnEditor)
    {
        if (LairSpawnEditor->objectName().isEmpty())
            LairSpawnEditor->setObjectName(QString::fromUtf8("LairSpawnEditor"));
        LairSpawnEditor->resize(380, 448);
        gridLayout_2 = new QGridLayout(LairSpawnEditor);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(LairSpawnEditor);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        spinBox_maxSpawnLimit = new QSpinBox(LairSpawnEditor);
        spinBox_maxSpawnLimit->setObjectName(QString::fromUtf8("spinBox_maxSpawnLimit"));
        spinBox_maxSpawnLimit->setMaximum(500);

        gridLayout_2->addWidget(spinBox_maxSpawnLimit, 0, 1, 1, 2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(LairSpawnEditor);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        listWidget_lairs = new QListWidget(LairSpawnEditor);
        listWidget_lairs->setObjectName(QString::fromUtf8("listWidget_lairs"));

        gridLayout->addWidget(listWidget_lairs, 1, 0, 1, 3);

        pushButton_add = new QPushButton(LairSpawnEditor);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));

        gridLayout->addWidget(pushButton_add, 2, 0, 1, 1);

        pushButton_remove = new QPushButton(LairSpawnEditor);
        pushButton_remove->setObjectName(QString::fromUtf8("pushButton_remove"));

        gridLayout->addWidget(pushButton_remove, 2, 1, 1, 1);

        pushButton_edit = new QPushButton(LairSpawnEditor);
        pushButton_edit->setObjectName(QString::fromUtf8("pushButton_edit"));

        gridLayout->addWidget(pushButton_edit, 2, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 6);

        horizontalSpacer = new QSpacerItem(302, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 0, 1, 6);

        label_3 = new QLabel(LairSpawnEditor);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 4, 0, 1, 1);

        spinBox_spawnLimit = new QSpinBox(LairSpawnEditor);
        spinBox_spawnLimit->setObjectName(QString::fromUtf8("spinBox_spawnLimit"));
        spinBox_spawnLimit->setMinimum(-1);
        spinBox_spawnLimit->setValue(-1);

        gridLayout_2->addWidget(spinBox_spawnLimit, 4, 1, 1, 1);

        label_7 = new QLabel(LairSpawnEditor);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_7, 4, 3, 1, 2);

        spinBox_weighting = new QSpinBox(LairSpawnEditor);
        spinBox_weighting->setObjectName(QString::fromUtf8("spinBox_weighting"));

        gridLayout_2->addWidget(spinBox_weighting, 4, 5, 1, 1);

        label_4 = new QLabel(LairSpawnEditor);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 5, 0, 1, 1);

        spinBox_minDifficulty = new QSpinBox(LairSpawnEditor);
        spinBox_minDifficulty->setObjectName(QString::fromUtf8("spinBox_minDifficulty"));

        gridLayout_2->addWidget(spinBox_minDifficulty, 5, 1, 1, 1);

        label_8 = new QLabel(LairSpawnEditor);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_8, 5, 3, 1, 2);

        spinBox_size = new QSpinBox(LairSpawnEditor);
        spinBox_size->setObjectName(QString::fromUtf8("spinBox_size"));

        gridLayout_2->addWidget(spinBox_size, 5, 5, 1, 1);

        spinBox_maxDifficulty = new QSpinBox(LairSpawnEditor);
        spinBox_maxDifficulty->setObjectName(QString::fromUtf8("spinBox_maxDifficulty"));
        spinBox_maxDifficulty->setMaximum(500);

        gridLayout_2->addWidget(spinBox_maxDifficulty, 6, 1, 1, 1);

        label_6 = new QLabel(LairSpawnEditor);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6, 6, 2, 1, 3);

        spinBox_numberToSpawn = new QSpinBox(LairSpawnEditor);
        spinBox_numberToSpawn->setObjectName(QString::fromUtf8("spinBox_numberToSpawn"));

        gridLayout_2->addWidget(spinBox_numberToSpawn, 6, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(302, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 7, 0, 1, 6);

        buttonBox = new QDialogButtonBox(LairSpawnEditor);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 8, 0, 1, 6);

        label_lairTypeSelected = new QLabel(LairSpawnEditor);
        label_lairTypeSelected->setObjectName(QString::fromUtf8("label_lairTypeSelected"));

        gridLayout_2->addWidget(label_lairTypeSelected, 3, 0, 1, 1);

        label_5 = new QLabel(LairSpawnEditor);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_5, 6, 0, 1, 1);


        retranslateUi(LairSpawnEditor);
        QObject::connect(buttonBox, SIGNAL(accepted()), LairSpawnEditor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LairSpawnEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(LairSpawnEditor);
    } // setupUi

    void retranslateUi(QDialog *LairSpawnEditor)
    {
        LairSpawnEditor->setWindowTitle(QApplication::translate("LairSpawnEditor", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LairSpawnEditor", "Max Spawn Limit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LairSpawnEditor", "Lair Types", 0, QApplication::UnicodeUTF8));
        pushButton_add->setText(QApplication::translate("LairSpawnEditor", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_remove->setText(QApplication::translate("LairSpawnEditor", "Remove", 0, QApplication::UnicodeUTF8));
        pushButton_edit->setText(QApplication::translate("LairSpawnEditor", "Edit", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LairSpawnEditor", "Spawn Limit", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("LairSpawnEditor", "Weighting", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("LairSpawnEditor", "Min Difficulty", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("LairSpawnEditor", "Size", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("LairSpawnEditor", "Number To Spawn", 0, QApplication::UnicodeUTF8));
        label_lairTypeSelected->setText(QApplication::translate("LairSpawnEditor", "Lair Type Selected", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("LairSpawnEditor", "Max Difficulty", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LairSpawnEditor: public Ui_LairSpawnEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAIRSPAWNEDITOR_H
