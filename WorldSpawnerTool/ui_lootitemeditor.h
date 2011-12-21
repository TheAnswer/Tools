/********************************************************************************
** Form generated from reading UI file 'lootitemeditor.ui'
**
** Created: Mon 19. Dec 23:05:47 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOOTITEMEDITOR_H
#define UI_LOOTITEMEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_LootItemEditor
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *spinBox_minLevel;
    QLabel *label_2;
    QSpinBox *spinBox_maxLevel;
    QDoubleSpinBox *doubleSpinBox_chance;
    QLabel *label_4;
    QLineEdit *lineEdit_customObjectName;
    QLabel *label_5;
    QLineEdit *lineEdit_directObjectTemplate;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_3;
    QComboBox *comboBox_qualityMin;
    QComboBox *comboBox_qualityMax;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLineEdit *lineEdit_draftSchematic;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget_customization;
    QTableWidget *tableWidget_experiment;
    QDialogButtonBox *buttonBox;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QDialog *LootItemEditor)
    {
        if (LootItemEditor->objectName().isEmpty())
            LootItemEditor->setObjectName(QString::fromUtf8("LootItemEditor"));
        LootItemEditor->resize(945, 371);
        gridLayout_4 = new QGridLayout(LootItemEditor);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(LootItemEditor);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 2);

        spinBox_minLevel = new QSpinBox(LootItemEditor);
        spinBox_minLevel->setObjectName(QString::fromUtf8("spinBox_minLevel"));

        gridLayout->addWidget(spinBox_minLevel, 1, 2, 1, 1);

        label_2 = new QLabel(LootItemEditor);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 2, 0, 1, 2);

        spinBox_maxLevel = new QSpinBox(LootItemEditor);
        spinBox_maxLevel->setObjectName(QString::fromUtf8("spinBox_maxLevel"));

        gridLayout->addWidget(spinBox_maxLevel, 2, 2, 1, 1);

        doubleSpinBox_chance = new QDoubleSpinBox(LootItemEditor);
        doubleSpinBox_chance->setObjectName(QString::fromUtf8("doubleSpinBox_chance"));

        gridLayout->addWidget(doubleSpinBox_chance, 3, 2, 1, 1);

        label_4 = new QLabel(LootItemEditor);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 4, 0, 1, 2);

        lineEdit_customObjectName = new QLineEdit(LootItemEditor);
        lineEdit_customObjectName->setObjectName(QString::fromUtf8("lineEdit_customObjectName"));

        gridLayout->addWidget(lineEdit_customObjectName, 4, 2, 1, 1);

        label_5 = new QLabel(LootItemEditor);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 5, 0, 1, 2);

        lineEdit_directObjectTemplate = new QLineEdit(LootItemEditor);
        lineEdit_directObjectTemplate->setObjectName(QString::fromUtf8("lineEdit_directObjectTemplate"));

        gridLayout->addWidget(lineEdit_directObjectTemplate, 5, 2, 1, 1);

        label_10 = new QLabel(LootItemEditor);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 6, 0, 1, 2);

        label_11 = new QLabel(LootItemEditor);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 7, 0, 1, 2);

        label_3 = new QLabel(LootItemEditor);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 3, 0, 1, 2);

        comboBox_qualityMin = new QComboBox(LootItemEditor);
        comboBox_qualityMin->setObjectName(QString::fromUtf8("comboBox_qualityMin"));

        gridLayout->addWidget(comboBox_qualityMin, 6, 2, 1, 1);

        comboBox_qualityMax = new QComboBox(LootItemEditor);
        comboBox_qualityMax->setObjectName(QString::fromUtf8("comboBox_qualityMax"));

        gridLayout->addWidget(comboBox_qualityMax, 7, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout, 1, 0, 2, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_6 = new QLabel(LootItemEditor);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_draftSchematic = new QLineEdit(LootItemEditor);
        lineEdit_draftSchematic->setObjectName(QString::fromUtf8("lineEdit_draftSchematic"));

        gridLayout_2->addWidget(lineEdit_draftSchematic, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 1, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tableWidget_customization = new QTableWidget(LootItemEditor);
        if (tableWidget_customization->columnCount() < 2)
            tableWidget_customization->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_customization->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_customization->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_customization->setObjectName(QString::fromUtf8("tableWidget_customization"));
        tableWidget_customization->horizontalHeader()->setDefaultSectionSize(100);

        gridLayout_3->addWidget(tableWidget_customization, 0, 1, 1, 1);

        tableWidget_experiment = new QTableWidget(LootItemEditor);
        if (tableWidget_experiment->columnCount() < 3)
            tableWidget_experiment->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_experiment->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_experiment->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_experiment->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        tableWidget_experiment->setObjectName(QString::fromUtf8("tableWidget_experiment"));

        gridLayout_3->addWidget(tableWidget_experiment, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 2, 1, 1, 2);

        buttonBox = new QDialogButtonBox(LootItemEditor);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_4->addWidget(buttonBox, 3, 2, 1, 1);

        label_7 = new QLabel(LootItemEditor);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 0, 0, 1, 1);

        label_8 = new QLabel(LootItemEditor);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 1, 2, 1, 1);


        retranslateUi(LootItemEditor);
        QObject::connect(buttonBox, SIGNAL(accepted()), LootItemEditor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LootItemEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(LootItemEditor);
    } // setupUi

    void retranslateUi(QDialog *LootItemEditor)
    {
        LootItemEditor->setWindowTitle(QApplication::translate("LootItemEditor", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LootItemEditor", "Minimum Level", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LootItemEditor", "Maximum Level", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("LootItemEditor", "Custom Object Name", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("LootItemEditor", "Direct Object Template", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("LootItemEditor", "Quality Range Min", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("LootItemEditor", "Quality Range Max", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LootItemEditor", "Chance", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("LootItemEditor", "Draft Schematic", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_customization->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("LootItemEditor", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_customization->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("LootItemEditor", "Values", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_experiment->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("LootItemEditor", "Experimental title", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_experiment->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("LootItemEditor", "Min value", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_experiment->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("LootItemEditor", "Max value", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("LootItemEditor", "loot item name", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("LootItemEditor", "Customization Data", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LootItemEditor: public Ui_LootItemEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOOTITEMEDITOR_H
