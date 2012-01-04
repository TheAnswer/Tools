/********************************************************************************
** Form generated from reading UI file 'lootmanager.ui'
**
** Created: Wed Jan 4 23:45:38 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOOTMANAGER_H
#define UI_LOOTMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LootManager
{
public:
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Filter;
    QLineEdit *lineEdit_Filter;
    QComboBox *comboBox_Filter;
    QPushButton *pushButton_Filter;
    QTableWidget *tableWidget_LootTemplates;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_NewTemplate;
    QPushButton *pushButton_EditTemplate;
    QPushButton *pushButton_DeleteTemplate;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_Add;
    QPushButton *pushButton_Remove;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_ReloadScripts;
    QPushButton *pushButton_DeleteAllItems;
    QPushButton *pushButton_DeleteAllGroups;
    QPushButton *pushButton_WriteScripts;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_Group;
    QLabel *label_MinLevel;
    QLabel *label_MaxLevel;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox_Group;
    QPushButton *pushButton_NewGroup;
    QPushButton *pushButton_DeleteGroup;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *spinBox_MinLevel;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *spinBox_MaxLevel;
    QLabel *label;
    QPlainTextEdit *plainTextEdit_Description;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_Normalize;
    QLabel *label_TotalChance;
    QLineEdit *lineEdit_TotalChance;
    QTableWidget *tableWidget_LootGroups;

    void setupUi(QWidget *LootManager)
    {
        if (LootManager->objectName().isEmpty())
            LootManager->setObjectName(QString::fromUtf8("LootManager"));
        LootManager->setWindowModality(Qt::NonModal);
        LootManager->resize(1009, 534);
        horizontalLayout_7 = new QHBoxLayout(LootManager);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        groupBox = new QGroupBox(LootManager);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_Filter = new QLabel(groupBox);
        label_Filter->setObjectName(QString::fromUtf8("label_Filter"));
        label_Filter->setMargin(5);
        label_Filter->setIndent(0);

        horizontalLayout_2->addWidget(label_Filter);

        lineEdit_Filter = new QLineEdit(groupBox);
        lineEdit_Filter->setObjectName(QString::fromUtf8("lineEdit_Filter"));

        horizontalLayout_2->addWidget(lineEdit_Filter);

        comboBox_Filter = new QComboBox(groupBox);
        comboBox_Filter->setObjectName(QString::fromUtf8("comboBox_Filter"));

        horizontalLayout_2->addWidget(comboBox_Filter);

        pushButton_Filter = new QPushButton(groupBox);
        pushButton_Filter->setObjectName(QString::fromUtf8("pushButton_Filter"));
        pushButton_Filter->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(pushButton_Filter);


        verticalLayout->addLayout(horizontalLayout_2);

        tableWidget_LootTemplates = new QTableWidget(groupBox);
        if (tableWidget_LootTemplates->columnCount() < 3)
            tableWidget_LootTemplates->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_LootTemplates->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_LootTemplates->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_LootTemplates->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_LootTemplates->setObjectName(QString::fromUtf8("tableWidget_LootTemplates"));
        tableWidget_LootTemplates->setContextMenuPolicy(Qt::NoContextMenu);
        tableWidget_LootTemplates->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_LootTemplates->setAlternatingRowColors(true);
        tableWidget_LootTemplates->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_LootTemplates->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_LootTemplates->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget_LootTemplates->horizontalHeader()->setMinimumSectionSize(30);
        tableWidget_LootTemplates->horizontalHeader()->setStretchLastSection(true);
        tableWidget_LootTemplates->verticalHeader()->setVisible(false);
        tableWidget_LootTemplates->verticalHeader()->setDefaultSectionSize(20);
        tableWidget_LootTemplates->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout->addWidget(tableWidget_LootTemplates);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_NewTemplate = new QPushButton(groupBox);
        pushButton_NewTemplate->setObjectName(QString::fromUtf8("pushButton_NewTemplate"));
        pushButton_NewTemplate->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(pushButton_NewTemplate);

        pushButton_EditTemplate = new QPushButton(groupBox);
        pushButton_EditTemplate->setObjectName(QString::fromUtf8("pushButton_EditTemplate"));
        pushButton_EditTemplate->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(pushButton_EditTemplate);

        pushButton_DeleteTemplate = new QPushButton(groupBox);
        pushButton_DeleteTemplate->setObjectName(QString::fromUtf8("pushButton_DeleteTemplate"));
        pushButton_DeleteTemplate->setMaximumSize(QSize(50, 16777215));
        pushButton_DeleteTemplate->setFlat(false);

        horizontalLayout->addWidget(pushButton_DeleteTemplate);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        label_Filter->raise();
        lineEdit_Filter->raise();
        pushButton_DeleteTemplate->raise();
        comboBox_Filter->raise();
        pushButton_NewTemplate->raise();
        pushButton_Filter->raise();
        tableWidget_LootTemplates->raise();
        pushButton_EditTemplate->raise();
        lineEdit_Filter->raise();
        label_Filter->raise();
        pushButton_DeleteTemplate->raise();
        pushButton_NewTemplate->raise();
        comboBox_Filter->raise();
        pushButton_Filter->raise();
        tableWidget_LootTemplates->raise();
        pushButton_EditTemplate->raise();

        horizontalLayout_7->addWidget(groupBox);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        pushButton_Add = new QPushButton(LootManager);
        pushButton_Add->setObjectName(QString::fromUtf8("pushButton_Add"));

        verticalLayout_5->addWidget(pushButton_Add);

        pushButton_Remove = new QPushButton(LootManager);
        pushButton_Remove->setObjectName(QString::fromUtf8("pushButton_Remove"));

        verticalLayout_5->addWidget(pushButton_Remove);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);


        horizontalLayout_7->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox_3 = new QGroupBox(LootManager);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_ReloadScripts = new QPushButton(groupBox_3);
        pushButton_ReloadScripts->setObjectName(QString::fromUtf8("pushButton_ReloadScripts"));

        gridLayout_2->addWidget(pushButton_ReloadScripts, 0, 1, 1, 1);

        pushButton_DeleteAllItems = new QPushButton(groupBox_3);
        pushButton_DeleteAllItems->setObjectName(QString::fromUtf8("pushButton_DeleteAllItems"));

        gridLayout_2->addWidget(pushButton_DeleteAllItems, 0, 2, 1, 1);

        pushButton_DeleteAllGroups = new QPushButton(groupBox_3);
        pushButton_DeleteAllGroups->setObjectName(QString::fromUtf8("pushButton_DeleteAllGroups"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_DeleteAllGroups->sizePolicy().hasHeightForWidth());
        pushButton_DeleteAllGroups->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(pushButton_DeleteAllGroups, 0, 3, 1, 1);

        pushButton_WriteScripts = new QPushButton(groupBox_3);
        pushButton_WriteScripts->setObjectName(QString::fromUtf8("pushButton_WriteScripts"));

        gridLayout_2->addWidget(pushButton_WriteScripts, 0, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);


        verticalLayout_6->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(LootManager);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_Group = new QLabel(groupBox_2);
        label_Group->setObjectName(QString::fromUtf8("label_Group"));
        label_Group->setIndent(5);

        gridLayout->addWidget(label_Group, 0, 0, 1, 1);

        label_MinLevel = new QLabel(groupBox_2);
        label_MinLevel->setObjectName(QString::fromUtf8("label_MinLevel"));
        label_MinLevel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_MinLevel, 0, 1, 1, 1);

        label_MaxLevel = new QLabel(groupBox_2);
        label_MaxLevel->setObjectName(QString::fromUtf8("label_MaxLevel"));
        label_MaxLevel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_MaxLevel, 0, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        comboBox_Group = new QComboBox(groupBox_2);
        comboBox_Group->setObjectName(QString::fromUtf8("comboBox_Group"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_Group->sizePolicy().hasHeightForWidth());
        comboBox_Group->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(comboBox_Group);

        pushButton_NewGroup = new QPushButton(groupBox_2);
        pushButton_NewGroup->setObjectName(QString::fromUtf8("pushButton_NewGroup"));
        pushButton_NewGroup->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(pushButton_NewGroup);

        pushButton_DeleteGroup = new QPushButton(groupBox_2);
        pushButton_DeleteGroup->setObjectName(QString::fromUtf8("pushButton_DeleteGroup"));
        pushButton_DeleteGroup->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(pushButton_DeleteGroup);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        spinBox_MinLevel = new QSpinBox(groupBox_2);
        spinBox_MinLevel->setObjectName(QString::fromUtf8("spinBox_MinLevel"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinBox_MinLevel->sizePolicy().hasHeightForWidth());
        spinBox_MinLevel->setSizePolicy(sizePolicy2);
        spinBox_MinLevel->setAlignment(Qt::AlignCenter);
        spinBox_MinLevel->setMaximum(1000);

        horizontalLayout_4->addWidget(spinBox_MinLevel);


        gridLayout->addLayout(horizontalLayout_4, 1, 1, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        spinBox_MaxLevel = new QSpinBox(groupBox_2);
        spinBox_MaxLevel->setObjectName(QString::fromUtf8("spinBox_MaxLevel"));
        sizePolicy2.setHeightForWidth(spinBox_MaxLevel->sizePolicy().hasHeightForWidth());
        spinBox_MaxLevel->setSizePolicy(sizePolicy2);
        spinBox_MaxLevel->setAlignment(Qt::AlignCenter);
        spinBox_MaxLevel->setMinimum(-1);
        spinBox_MaxLevel->setMaximum(1000);

        horizontalLayout_5->addWidget(spinBox_MaxLevel);


        gridLayout->addLayout(horizontalLayout_5, 1, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setIndent(5);

        verticalLayout_3->addWidget(label);

        plainTextEdit_Description = new QPlainTextEdit(groupBox_2);
        plainTextEdit_Description->setObjectName(QString::fromUtf8("plainTextEdit_Description"));
        sizePolicy1.setHeightForWidth(plainTextEdit_Description->sizePolicy().hasHeightForWidth());
        plainTextEdit_Description->setSizePolicy(sizePolicy1);
        plainTextEdit_Description->setMaximumSize(QSize(16777215, 50));
        plainTextEdit_Description->setBackgroundVisible(false);

        verticalLayout_3->addWidget(plainTextEdit_Description);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_Normalize = new QPushButton(groupBox_2);
        pushButton_Normalize->setObjectName(QString::fromUtf8("pushButton_Normalize"));
        sizePolicy2.setHeightForWidth(pushButton_Normalize->sizePolicy().hasHeightForWidth());
        pushButton_Normalize->setSizePolicy(sizePolicy2);
        pushButton_Normalize->setMinimumSize(QSize(120, 0));

        horizontalLayout_6->addWidget(pushButton_Normalize);

        label_TotalChance = new QLabel(groupBox_2);
        label_TotalChance->setObjectName(QString::fromUtf8("label_TotalChance"));
        label_TotalChance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_TotalChance->setMargin(0);
        label_TotalChance->setIndent(5);

        horizontalLayout_6->addWidget(label_TotalChance);

        lineEdit_TotalChance = new QLineEdit(groupBox_2);
        lineEdit_TotalChance->setObjectName(QString::fromUtf8("lineEdit_TotalChance"));
        sizePolicy2.setHeightForWidth(lineEdit_TotalChance->sizePolicy().hasHeightForWidth());
        lineEdit_TotalChance->setSizePolicy(sizePolicy2);
        lineEdit_TotalChance->setMaximumSize(QSize(75, 16777215));
        lineEdit_TotalChance->setAlignment(Qt::AlignCenter);
        lineEdit_TotalChance->setReadOnly(true);

        horizontalLayout_6->addWidget(lineEdit_TotalChance);


        verticalLayout_3->addLayout(horizontalLayout_6);

        tableWidget_LootGroups = new QTableWidget(groupBox_2);
        if (tableWidget_LootGroups->columnCount() < 2)
            tableWidget_LootGroups->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_LootGroups->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_LootGroups->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        tableWidget_LootGroups->setObjectName(QString::fromUtf8("tableWidget_LootGroups"));
        tableWidget_LootGroups->setAlternatingRowColors(true);
        tableWidget_LootGroups->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_LootGroups->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_LootGroups->horizontalHeader()->setStretchLastSection(true);
        tableWidget_LootGroups->verticalHeader()->setVisible(false);
        tableWidget_LootGroups->verticalHeader()->setDefaultSectionSize(20);
        tableWidget_LootGroups->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_3->addWidget(tableWidget_LootGroups);


        verticalLayout_6->addWidget(groupBox_2);


        horizontalLayout_7->addLayout(verticalLayout_6);


        retranslateUi(LootManager);

        QMetaObject::connectSlotsByName(LootManager);
    } // setupUi

    void retranslateUi(QWidget *LootManager)
    {
        LootManager->setWindowTitle(QApplication::translate("LootManager", "Loot Manager", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("LootManager", "Loot Item Templates", 0, QApplication::UnicodeUTF8));
        label_Filter->setText(QApplication::translate("LootManager", "Filter:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_Filter->setToolTip(QApplication::translate("LootManager", "As you type in this box, the results displayed below will be filtered according to the category selected to the right. * acts as a wildcard.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        comboBox_Filter->clear();
        comboBox_Filter->insertItems(0, QStringList()
         << QApplication::translate("LootManager", "Template Name", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootManager", "Min Lvl", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootManager", "Max Lvl", 0, QApplication::UnicodeUTF8)
        );
        pushButton_Filter->setText(QApplication::translate("LootManager", "Filter", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_LootTemplates->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("LootManager", "Template Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_LootTemplates->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("LootManager", "Min. Lvl", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_LootTemplates->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("LootManager", "Max. Lvl", 0, QApplication::UnicodeUTF8));
        pushButton_NewTemplate->setText(QApplication::translate("LootManager", "New", 0, QApplication::UnicodeUTF8));
        pushButton_EditTemplate->setText(QApplication::translate("LootManager", "Edit", 0, QApplication::UnicodeUTF8));
        pushButton_DeleteTemplate->setText(QApplication::translate("LootManager", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton_Add->setText(QApplication::translate("LootManager", ">>", 0, QApplication::UnicodeUTF8));
        pushButton_Remove->setText(QApplication::translate("LootManager", "<<", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("LootManager", "Lua Actions", 0, QApplication::UnicodeUTF8));
        pushButton_ReloadScripts->setText(QApplication::translate("LootManager", "Reload Scripts", 0, QApplication::UnicodeUTF8));
        pushButton_DeleteAllItems->setText(QApplication::translate("LootManager", "Delete All Items", 0, QApplication::UnicodeUTF8));
        pushButton_DeleteAllGroups->setText(QApplication::translate("LootManager", "Delete All Groups", 0, QApplication::UnicodeUTF8));
        pushButton_WriteScripts->setText(QApplication::translate("LootManager", "Write Scripts", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("LootManager", "Loot Groups", 0, QApplication::UnicodeUTF8));
        label_Group->setText(QApplication::translate("LootManager", "Select Group:", 0, QApplication::UnicodeUTF8));
        label_MinLevel->setText(QApplication::translate("LootManager", "Min. Lvl", 0, QApplication::UnicodeUTF8));
        label_MaxLevel->setText(QApplication::translate("LootManager", "Max. Lvl", 0, QApplication::UnicodeUTF8));
        pushButton_NewGroup->setText(QApplication::translate("LootManager", "New", 0, QApplication::UnicodeUTF8));
        pushButton_DeleteGroup->setText(QApplication::translate("LootManager", "Delete", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LootManager", "Description:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_Normalize->setToolTip(QApplication::translate("LootManager", "Automatically adjusts chances to equal 100% based in relation to their current values.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton_Normalize->setText(QApplication::translate("LootManager", "Normalize Chance", 0, QApplication::UnicodeUTF8));
        label_TotalChance->setText(QApplication::translate("LootManager", "Total Chance:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_TotalChance->setToolTip(QApplication::translate("LootManager", "It is recommended that Total Chance equal 100.00. Although a value less than 100.00 is acceptable, it may lead to unexpected results.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_LootGroups->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("LootManager", "Item", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_LootGroups->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("LootManager", "Chance", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LootManager: public Ui_LootManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOOTMANAGER_H
