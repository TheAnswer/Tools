/********************************************************************************
** Form generated from reading UI file 'lootitemtemplatemanager.ui'
**
** Created: Sun Jan 1 14:52:38 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOOTITEMTEMPLATEMANAGER_H
#define UI_LOOTITEMTEMPLATEMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LootItemTemplateManager
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_Filter;
    QComboBox *comboBox_FilterType;
    QPushButton *pushButton_Filter;
    QLineEdit *lineEdit_Filter;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Create;
    QPushButton *pushButton_Modify;
    QPushButton *pushButton_Remove;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LootItemTemplateManager)
    {
        if (LootItemTemplateManager->objectName().isEmpty())
            LootItemTemplateManager->setObjectName(QString::fromUtf8("LootItemTemplateManager"));
        LootItemTemplateManager->resize(727, 409);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LootItemTemplateManager->sizePolicy().hasHeightForWidth());
        LootItemTemplateManager->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(LootItemTemplateManager);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_Filter = new QLabel(LootItemTemplateManager);
        label_Filter->setObjectName(QString::fromUtf8("label_Filter"));

        gridLayout->addWidget(label_Filter, 0, 0, 1, 1);

        comboBox_FilterType = new QComboBox(LootItemTemplateManager);
        comboBox_FilterType->setObjectName(QString::fromUtf8("comboBox_FilterType"));
        comboBox_FilterType->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(comboBox_FilterType, 0, 2, 1, 1);

        pushButton_Filter = new QPushButton(LootItemTemplateManager);
        pushButton_Filter->setObjectName(QString::fromUtf8("pushButton_Filter"));

        gridLayout->addWidget(pushButton_Filter, 0, 3, 1, 1);

        lineEdit_Filter = new QLineEdit(LootItemTemplateManager);
        lineEdit_Filter->setObjectName(QString::fromUtf8("lineEdit_Filter"));

        gridLayout->addWidget(lineEdit_Filter, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableWidget = new QTableWidget(LootItemTemplateManager);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QPalette palette;
        QBrush brush(QColor(246, 246, 246, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        tableWidget->setPalette(palette);
        QFont font;
        font.setPointSize(9);
        tableWidget->setFont(font);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setTextElideMode(Qt::ElideRight);
        tableWidget->setWordWrap(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        tableWidget->horizontalHeader()->setMinimumSectionSize(35);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(20);
        tableWidget->verticalHeader()->setMinimumSectionSize(20);

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        pushButton_Create = new QPushButton(LootItemTemplateManager);
        pushButton_Create->setObjectName(QString::fromUtf8("pushButton_Create"));

        gridLayout_2->addWidget(pushButton_Create, 1, 1, 1, 1);

        pushButton_Modify = new QPushButton(LootItemTemplateManager);
        pushButton_Modify->setObjectName(QString::fromUtf8("pushButton_Modify"));

        gridLayout_2->addWidget(pushButton_Modify, 1, 2, 1, 1);

        pushButton_Remove = new QPushButton(LootItemTemplateManager);
        pushButton_Remove->setObjectName(QString::fromUtf8("pushButton_Remove"));

        gridLayout_2->addWidget(pushButton_Remove, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        buttonBox = new QDialogButtonBox(LootItemTemplateManager);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(LootItemTemplateManager);
        QObject::connect(buttonBox, SIGNAL(accepted()), LootItemTemplateManager, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LootItemTemplateManager, SLOT(reject()));

        QMetaObject::connectSlotsByName(LootItemTemplateManager);
    } // setupUi

    void retranslateUi(QDialog *LootItemTemplateManager)
    {
        LootItemTemplateManager->setWindowTitle(QApplication::translate("LootItemTemplateManager", "Manage Loot Item Tempaltes", 0, QApplication::UnicodeUTF8));
        label_Filter->setText(QApplication::translate("LootItemTemplateManager", "Filter:", 0, QApplication::UnicodeUTF8));
        comboBox_FilterType->clear();
        comboBox_FilterType->insertItems(0, QStringList()
         << QApplication::translate("LootItemTemplateManager", "Item Template", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemTemplateManager", "Min Lvl", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemTemplateManager", "Max Lvl", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LootItemTemplateManager", "Custom Name", 0, QApplication::UnicodeUTF8)
        );
        pushButton_Filter->setText(QApplication::translate("LootItemTemplateManager", "Filter", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("LootItemTemplateManager", "Item Template", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("LootItemTemplateManager", "Min Lvl", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("LootItemTemplateManager", "Max Lvl", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("LootItemTemplateManager", "Custom Name", 0, QApplication::UnicodeUTF8));
        pushButton_Create->setText(QApplication::translate("LootItemTemplateManager", "Create Item", 0, QApplication::UnicodeUTF8));
        pushButton_Modify->setText(QApplication::translate("LootItemTemplateManager", "Modify Item", 0, QApplication::UnicodeUTF8));
        pushButton_Remove->setText(QApplication::translate("LootItemTemplateManager", "Remove Item", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LootItemTemplateManager: public Ui_LootItemTemplateManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOOTITEMTEMPLATEMANAGER_H
