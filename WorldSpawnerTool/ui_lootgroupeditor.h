/********************************************************************************
** Form generated from reading UI file 'lootgroupeditor.ui'
**
** Created: Mon Jan 2 09:43:39 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOOTGROUPEDITOR_H
#define UI_LOOTGROUPEDITOR_H

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
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LootGroupEditor
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_LootGroupProperties;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_MinLevel;
    QSpinBox *spinBox_MinLevel;
    QLabel *label_MaxLevel;
    QSpinBox *spinBox_MaxLevel;
    QLabel *label;
    QComboBox *comboBox_SelectGroup;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_NewGroup;
    QPushButton *pushButton_DeleteGroup;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_2;
    QLabel *label_LootItemTemplates;
    QLabel *label_LootGroupItems;
    QTableWidget *tableWidget_LootItemTemplates;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_AddItem;
    QPushButton *pushButton_RemoveItem;
    QPushButton *pushButton_EditItem;
    QSpacerItem *verticalSpacer;
    QTableWidget *tableWidget_LootGroupItems;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LootGroupEditor)
    {
        if (LootGroupEditor->objectName().isEmpty())
            LootGroupEditor->setObjectName(QString::fromUtf8("LootGroupEditor"));
        LootGroupEditor->resize(759, 362);
        verticalLayout_3 = new QVBoxLayout(LootGroupEditor);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_LootGroupProperties = new QGroupBox(LootGroupEditor);
        groupBox_LootGroupProperties->setObjectName(QString::fromUtf8("groupBox_LootGroupProperties"));
        verticalLayout = new QVBoxLayout(groupBox_LootGroupProperties);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_MinLevel = new QLabel(groupBox_LootGroupProperties);
        label_MinLevel->setObjectName(QString::fromUtf8("label_MinLevel"));

        gridLayout->addWidget(label_MinLevel, 0, 2, 1, 1);

        spinBox_MinLevel = new QSpinBox(groupBox_LootGroupProperties);
        spinBox_MinLevel->setObjectName(QString::fromUtf8("spinBox_MinLevel"));
        spinBox_MinLevel->setAlignment(Qt::AlignCenter);
        spinBox_MinLevel->setMaximum(1000);

        gridLayout->addWidget(spinBox_MinLevel, 0, 3, 1, 1);

        label_MaxLevel = new QLabel(groupBox_LootGroupProperties);
        label_MaxLevel->setObjectName(QString::fromUtf8("label_MaxLevel"));

        gridLayout->addWidget(label_MaxLevel, 0, 4, 1, 1);

        spinBox_MaxLevel = new QSpinBox(groupBox_LootGroupProperties);
        spinBox_MaxLevel->setObjectName(QString::fromUtf8("spinBox_MaxLevel"));
        spinBox_MaxLevel->setAlignment(Qt::AlignCenter);
        spinBox_MaxLevel->setMinimum(-1);
        spinBox_MaxLevel->setMaximum(1000);

        gridLayout->addWidget(spinBox_MaxLevel, 0, 5, 1, 1);

        label = new QLabel(groupBox_LootGroupProperties);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 0));
        label->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox_SelectGroup = new QComboBox(groupBox_LootGroupProperties);
        comboBox_SelectGroup->setObjectName(QString::fromUtf8("comboBox_SelectGroup"));
        comboBox_SelectGroup->setMinimumSize(QSize(275, 0));
        comboBox_SelectGroup->setEditable(false);

        gridLayout->addWidget(comboBox_SelectGroup, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_NewGroup = new QPushButton(groupBox_LootGroupProperties);
        pushButton_NewGroup->setObjectName(QString::fromUtf8("pushButton_NewGroup"));

        horizontalLayout->addWidget(pushButton_NewGroup);

        pushButton_DeleteGroup = new QPushButton(groupBox_LootGroupProperties);
        pushButton_DeleteGroup->setObjectName(QString::fromUtf8("pushButton_DeleteGroup"));

        horizontalLayout->addWidget(pushButton_DeleteGroup);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(groupBox_LootGroupProperties);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_LootItemTemplates = new QLabel(LootGroupEditor);
        label_LootItemTemplates->setObjectName(QString::fromUtf8("label_LootItemTemplates"));

        gridLayout_2->addWidget(label_LootItemTemplates, 0, 0, 1, 1);

        label_LootGroupItems = new QLabel(LootGroupEditor);
        label_LootGroupItems->setObjectName(QString::fromUtf8("label_LootGroupItems"));

        gridLayout_2->addWidget(label_LootGroupItems, 0, 2, 1, 1);

        tableWidget_LootItemTemplates = new QTableWidget(LootGroupEditor);
        if (tableWidget_LootItemTemplates->columnCount() < 1)
            tableWidget_LootItemTemplates->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_LootItemTemplates->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget_LootItemTemplates->setObjectName(QString::fromUtf8("tableWidget_LootItemTemplates"));
        tableWidget_LootItemTemplates->setMinimumSize(QSize(250, 0));
        tableWidget_LootItemTemplates->setAlternatingRowColors(true);
        tableWidget_LootItemTemplates->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_LootItemTemplates->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_LootItemTemplates->setColumnCount(1);
        tableWidget_LootItemTemplates->horizontalHeader()->setStretchLastSection(true);
        tableWidget_LootItemTemplates->verticalHeader()->setVisible(false);
        tableWidget_LootItemTemplates->verticalHeader()->setDefaultSectionSize(20);
        tableWidget_LootItemTemplates->verticalHeader()->setMinimumSectionSize(20);

        gridLayout_2->addWidget(tableWidget_LootItemTemplates, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        pushButton_AddItem = new QPushButton(LootGroupEditor);
        pushButton_AddItem->setObjectName(QString::fromUtf8("pushButton_AddItem"));
        pushButton_AddItem->setEnabled(false);

        verticalLayout_2->addWidget(pushButton_AddItem);

        pushButton_RemoveItem = new QPushButton(LootGroupEditor);
        pushButton_RemoveItem->setObjectName(QString::fromUtf8("pushButton_RemoveItem"));
        pushButton_RemoveItem->setEnabled(false);

        verticalLayout_2->addWidget(pushButton_RemoveItem);

        pushButton_EditItem = new QPushButton(LootGroupEditor);
        pushButton_EditItem->setObjectName(QString::fromUtf8("pushButton_EditItem"));
        pushButton_EditItem->setEnabled(false);

        verticalLayout_2->addWidget(pushButton_EditItem);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout_2->addLayout(verticalLayout_2, 1, 1, 1, 1);

        tableWidget_LootGroupItems = new QTableWidget(LootGroupEditor);
        if (tableWidget_LootGroupItems->columnCount() < 2)
            tableWidget_LootGroupItems->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_LootGroupItems->setHorizontalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_LootGroupItems->setHorizontalHeaderItem(1, __qtablewidgetitem2);
        tableWidget_LootGroupItems->setObjectName(QString::fromUtf8("tableWidget_LootGroupItems"));
        tableWidget_LootGroupItems->setMinimumSize(QSize(400, 0));
        tableWidget_LootGroupItems->setAlternatingRowColors(true);
        tableWidget_LootGroupItems->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_LootGroupItems->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_LootGroupItems->setColumnCount(2);
        tableWidget_LootGroupItems->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_LootGroupItems->horizontalHeader()->setStretchLastSection(true);
        tableWidget_LootGroupItems->verticalHeader()->setVisible(false);
        tableWidget_LootGroupItems->verticalHeader()->setDefaultSectionSize(20);
        tableWidget_LootGroupItems->verticalHeader()->setMinimumSectionSize(20);

        gridLayout_2->addWidget(tableWidget_LootGroupItems, 1, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        buttonBox = new QDialogButtonBox(LootGroupEditor);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(LootGroupEditor);
        QObject::connect(buttonBox, SIGNAL(accepted()), LootGroupEditor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LootGroupEditor, SLOT(reject()));
        QObject::connect(pushButton_AddItem, SIGNAL(clicked()), LootGroupEditor, SLOT(addItemClicked()));
        QObject::connect(tableWidget_LootItemTemplates, SIGNAL(itemSelectionChanged()), LootGroupEditor, SLOT(lootItemTemplatesItemSelectionChanged()));
        QObject::connect(pushButton_NewGroup, SIGNAL(clicked()), LootGroupEditor, SLOT(newGroupClicked()));

        QMetaObject::connectSlotsByName(LootGroupEditor);
    } // setupUi

    void retranslateUi(QDialog *LootGroupEditor)
    {
        LootGroupEditor->setWindowTitle(QApplication::translate("LootGroupEditor", "Manage Loot Groups", 0, QApplication::UnicodeUTF8));
        groupBox_LootGroupProperties->setTitle(QApplication::translate("LootGroupEditor", "Loot Group Properties", 0, QApplication::UnicodeUTF8));
        label_MinLevel->setText(QApplication::translate("LootGroupEditor", "Minimum Level", 0, QApplication::UnicodeUTF8));
        label_MaxLevel->setText(QApplication::translate("LootGroupEditor", "Maximum Level", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LootGroupEditor", "Select Loot Group:", 0, QApplication::UnicodeUTF8));
        pushButton_NewGroup->setText(QApplication::translate("LootGroupEditor", "New", 0, QApplication::UnicodeUTF8));
        pushButton_DeleteGroup->setText(QApplication::translate("LootGroupEditor", "Delete", 0, QApplication::UnicodeUTF8));
        label_LootItemTemplates->setText(QApplication::translate("LootGroupEditor", "Loot Item Templates", 0, QApplication::UnicodeUTF8));
        label_LootGroupItems->setText(QApplication::translate("LootGroupEditor", "Loot Group Items", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_LootItemTemplates->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("LootGroupEditor", "Item Name", 0, QApplication::UnicodeUTF8));
        pushButton_AddItem->setText(QApplication::translate("LootGroupEditor", ">>", 0, QApplication::UnicodeUTF8));
        pushButton_RemoveItem->setText(QApplication::translate("LootGroupEditor", "<<", 0, QApplication::UnicodeUTF8));
        pushButton_EditItem->setText(QApplication::translate("LootGroupEditor", "Edit Item", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_LootGroupItems->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("LootGroupEditor", "Item Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_LootGroupItems->horizontalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("LootGroupEditor", "Chance", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LootGroupEditor: public Ui_LootGroupEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOOTGROUPEDITOR_H
