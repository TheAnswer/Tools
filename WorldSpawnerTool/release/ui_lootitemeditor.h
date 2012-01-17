/********************************************************************************
** Form generated from reading UI file 'lootitemeditor.ui'
**
** Created: Tue Jan 17 22:20:12 2012
**      by: Qt User Interface Compiler version 4.8.0
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
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LootItemEditor
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_ItemName;
    QLineEdit *lineEdit_ItemName;
    QLabel *label_CustomName;
    QLineEdit *lineEdit_CustomName;
    QGridLayout *gridLayout_3;
    QLabel *label_MinimumLevel;
    QSpinBox *spinBox_MinimumLevel;
    QLabel *label_MaximumLevel;
    QSpinBox *spinBox_MaximumLevel;
    QLabel *label_DirectObjectPath;
    QLineEdit *lineEdit_DirectObjectPath;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label_DraftSchematic;
    QLineEdit *lineEdit_DraftSchematic;
    QTableWidget *tableWidget_ExperimentalProperties;
    QLabel *label_MinimumQuality;
    QComboBox *comboBox_MinimumQuality;
    QLabel *label_MaximumQuality;
    QComboBox *comboBox_MaximumQuality;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_AddExperimental;
    QPushButton *pushButton_RemoveExperimental;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget_CustomizationVariables;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_AddCustomization;
    QPushButton *pushButton_RemoveCustomization;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LootItemEditor)
    {
        if (LootItemEditor->objectName().isEmpty())
            LootItemEditor->setObjectName(QString::fromUtf8("LootItemEditor"));
        LootItemEditor->resize(603, 534);
        verticalLayout_2 = new QVBoxLayout(LootItemEditor);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_ItemName = new QLabel(LootItemEditor);
        label_ItemName->setObjectName(QString::fromUtf8("label_ItemName"));
        label_ItemName->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_ItemName, 0, 0, 1, 1);

        lineEdit_ItemName = new QLineEdit(LootItemEditor);
        lineEdit_ItemName->setObjectName(QString::fromUtf8("lineEdit_ItemName"));

        gridLayout_2->addWidget(lineEdit_ItemName, 0, 1, 1, 1);

        label_CustomName = new QLabel(LootItemEditor);
        label_CustomName->setObjectName(QString::fromUtf8("label_CustomName"));
        label_CustomName->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_CustomName, 0, 2, 1, 1);

        lineEdit_CustomName = new QLineEdit(LootItemEditor);
        lineEdit_CustomName->setObjectName(QString::fromUtf8("lineEdit_CustomName"));

        gridLayout_2->addWidget(lineEdit_CustomName, 0, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_MinimumLevel = new QLabel(LootItemEditor);
        label_MinimumLevel->setObjectName(QString::fromUtf8("label_MinimumLevel"));

        gridLayout_3->addWidget(label_MinimumLevel, 0, 0, 1, 1);

        spinBox_MinimumLevel = new QSpinBox(LootItemEditor);
        spinBox_MinimumLevel->setObjectName(QString::fromUtf8("spinBox_MinimumLevel"));
        spinBox_MinimumLevel->setAlignment(Qt::AlignCenter);
        spinBox_MinimumLevel->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_MinimumLevel->setMinimum(0);
        spinBox_MinimumLevel->setMaximum(1000);

        gridLayout_3->addWidget(spinBox_MinimumLevel, 0, 1, 1, 1);

        label_MaximumLevel = new QLabel(LootItemEditor);
        label_MaximumLevel->setObjectName(QString::fromUtf8("label_MaximumLevel"));

        gridLayout_3->addWidget(label_MaximumLevel, 0, 2, 1, 1);

        spinBox_MaximumLevel = new QSpinBox(LootItemEditor);
        spinBox_MaximumLevel->setObjectName(QString::fromUtf8("spinBox_MaximumLevel"));
        spinBox_MaximumLevel->setAlignment(Qt::AlignCenter);
        spinBox_MaximumLevel->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_MaximumLevel->setMinimum(-1);
        spinBox_MaximumLevel->setMaximum(1000);
        spinBox_MaximumLevel->setValue(-1);

        gridLayout_3->addWidget(spinBox_MaximumLevel, 0, 3, 1, 1);

        label_DirectObjectPath = new QLabel(LootItemEditor);
        label_DirectObjectPath->setObjectName(QString::fromUtf8("label_DirectObjectPath"));

        gridLayout_3->addWidget(label_DirectObjectPath, 0, 4, 1, 1);

        lineEdit_DirectObjectPath = new QLineEdit(LootItemEditor);
        lineEdit_DirectObjectPath->setObjectName(QString::fromUtf8("lineEdit_DirectObjectPath"));

        gridLayout_3->addWidget(lineEdit_DirectObjectPath, 0, 5, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        groupBox = new QGroupBox(LootItemEditor);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_DraftSchematic = new QLabel(groupBox);
        label_DraftSchematic->setObjectName(QString::fromUtf8("label_DraftSchematic"));
        label_DraftSchematic->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_DraftSchematic, 0, 0, 1, 1);

        lineEdit_DraftSchematic = new QLineEdit(groupBox);
        lineEdit_DraftSchematic->setObjectName(QString::fromUtf8("lineEdit_DraftSchematic"));

        gridLayout->addWidget(lineEdit_DraftSchematic, 0, 1, 1, 3);

        tableWidget_ExperimentalProperties = new QTableWidget(groupBox);
        if (tableWidget_ExperimentalProperties->columnCount() < 3)
            tableWidget_ExperimentalProperties->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_ExperimentalProperties->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_ExperimentalProperties->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_ExperimentalProperties->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_ExperimentalProperties->setObjectName(QString::fromUtf8("tableWidget_ExperimentalProperties"));
        tableWidget_ExperimentalProperties->setAlternatingRowColors(true);
        tableWidget_ExperimentalProperties->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_ExperimentalProperties->setSelectionBehavior(QAbstractItemView::SelectItems);
        tableWidget_ExperimentalProperties->verticalHeader()->setVisible(false);
        tableWidget_ExperimentalProperties->verticalHeader()->setDefaultSectionSize(20);
        tableWidget_ExperimentalProperties->verticalHeader()->setMinimumSectionSize(20);

        gridLayout->addWidget(tableWidget_ExperimentalProperties, 2, 0, 1, 4);

        label_MinimumQuality = new QLabel(groupBox);
        label_MinimumQuality->setObjectName(QString::fromUtf8("label_MinimumQuality"));
        label_MinimumQuality->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_MinimumQuality, 1, 0, 1, 1);

        comboBox_MinimumQuality = new QComboBox(groupBox);
        comboBox_MinimumQuality->setObjectName(QString::fromUtf8("comboBox_MinimumQuality"));

        gridLayout->addWidget(comboBox_MinimumQuality, 1, 1, 1, 1);

        label_MaximumQuality = new QLabel(groupBox);
        label_MaximumQuality->setObjectName(QString::fromUtf8("label_MaximumQuality"));
        label_MaximumQuality->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_MaximumQuality, 1, 2, 1, 1);

        comboBox_MaximumQuality = new QComboBox(groupBox);
        comboBox_MaximumQuality->setObjectName(QString::fromUtf8("comboBox_MaximumQuality"));

        gridLayout->addWidget(comboBox_MaximumQuality, 1, 3, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_AddExperimental = new QPushButton(groupBox);
        pushButton_AddExperimental->setObjectName(QString::fromUtf8("pushButton_AddExperimental"));

        horizontalLayout_2->addWidget(pushButton_AddExperimental);

        pushButton_RemoveExperimental = new QPushButton(groupBox);
        pushButton_RemoveExperimental->setObjectName(QString::fromUtf8("pushButton_RemoveExperimental"));

        horizontalLayout_2->addWidget(pushButton_RemoveExperimental);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 4);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(LootItemEditor);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget_CustomizationVariables = new QTableWidget(groupBox_2);
        if (tableWidget_CustomizationVariables->columnCount() < 3)
            tableWidget_CustomizationVariables->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_CustomizationVariables->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_CustomizationVariables->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_CustomizationVariables->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        tableWidget_CustomizationVariables->setObjectName(QString::fromUtf8("tableWidget_CustomizationVariables"));
        tableWidget_CustomizationVariables->setAlternatingRowColors(true);
        tableWidget_CustomizationVariables->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_CustomizationVariables->setSelectionBehavior(QAbstractItemView::SelectItems);
        tableWidget_CustomizationVariables->verticalHeader()->setVisible(false);
        tableWidget_CustomizationVariables->verticalHeader()->setDefaultSectionSize(20);
        tableWidget_CustomizationVariables->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout->addWidget(tableWidget_CustomizationVariables);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_AddCustomization = new QPushButton(groupBox_2);
        pushButton_AddCustomization->setObjectName(QString::fromUtf8("pushButton_AddCustomization"));

        horizontalLayout_3->addWidget(pushButton_AddCustomization);

        pushButton_RemoveCustomization = new QPushButton(groupBox_2);
        pushButton_RemoveCustomization->setObjectName(QString::fromUtf8("pushButton_RemoveCustomization"));

        horizontalLayout_3->addWidget(pushButton_RemoveCustomization);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(LootItemEditor);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(LootItemEditor);
        QObject::connect(buttonBox, SIGNAL(accepted()), LootItemEditor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LootItemEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(LootItemEditor);
    } // setupUi

    void retranslateUi(QDialog *LootItemEditor)
    {
        LootItemEditor->setWindowTitle(QApplication::translate("LootItemEditor", "Loot Item Editor", 0, QApplication::UnicodeUTF8));
        label_ItemName->setText(QApplication::translate("LootItemEditor", "Template Name", 0, QApplication::UnicodeUTF8));
        label_CustomName->setText(QApplication::translate("LootItemEditor", "Custom Name", 0, QApplication::UnicodeUTF8));
        label_MinimumLevel->setText(QApplication::translate("LootItemEditor", "Min Lvl", 0, QApplication::UnicodeUTF8));
        label_MaximumLevel->setText(QApplication::translate("LootItemEditor", "Max Lvl", 0, QApplication::UnicodeUTF8));
        label_DirectObjectPath->setText(QApplication::translate("LootItemEditor", "Direct Object Path", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("LootItemEditor", "Experimental Properties", 0, QApplication::UnicodeUTF8));
        label_DraftSchematic->setText(QApplication::translate("LootItemEditor", "Draft Schematic", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_ExperimentalProperties->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("LootItemEditor", "Property", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_ExperimentalProperties->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("LootItemEditor", "Minimum", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_ExperimentalProperties->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("LootItemEditor", "Maximum", 0, QApplication::UnicodeUTF8));
        label_MinimumQuality->setText(QApplication::translate("LootItemEditor", "Minimum Quality", 0, QApplication::UnicodeUTF8));
        comboBox_MinimumQuality->clear();
        comboBox_MinimumQuality->insertItems(0, QStringList()
         << QApplication::translate("LootItemEditor", "Amazing Success", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemEditor", "Great Success", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemEditor", "Good Success", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemEditor", "Moderate Success", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemEditor", "Success", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemEditor", "Marginal Success", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemEditor", "Ok", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemEditor", "Barely Successful", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemEditor", "Critical Failure", 0, QApplication::UnicodeUTF8)
        );
        label_MaximumQuality->setText(QApplication::translate("LootItemEditor", "Maximum Quality", 0, QApplication::UnicodeUTF8));
        comboBox_MaximumQuality->clear();
        comboBox_MaximumQuality->insertItems(0, QStringList()
         << QApplication::translate("LootItemEditor", "Amazing Success", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemEditor", "Great Success", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemEditor", "Good Success", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemEditor", "Moderate Success", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemEditor", "Success", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemEditor", "Marginal Success", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemEditor", "Ok", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemEditor", "Barely Successful", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemEditor", "Critical Failure", 0, QApplication::UnicodeUTF8)
        );
        pushButton_AddExperimental->setText(QApplication::translate("LootItemEditor", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_RemoveExperimental->setText(QApplication::translate("LootItemEditor", "Remove", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("LootItemEditor", "Customization Variables", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_CustomizationVariables->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("LootItemEditor", "Variable Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_CustomizationVariables->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("LootItemEditor", "Minimum", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_CustomizationVariables->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("LootItemEditor", "Maximum", 0, QApplication::UnicodeUTF8));
        pushButton_AddCustomization->setText(QApplication::translate("LootItemEditor", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_RemoveCustomization->setText(QApplication::translate("LootItemEditor", "Remove", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LootItemEditor: public Ui_LootItemEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOOTITEMEDITOR_H
