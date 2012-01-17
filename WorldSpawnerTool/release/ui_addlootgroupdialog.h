/********************************************************************************
** Form generated from reading UI file 'addlootgroupdialog.ui'
**
** Created: Mon Jan 16 20:31:05 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDLOOTGROUPDIALOG_H
#define UI_ADDLOOTGROUPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddLootGroupDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_LootGroups;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddLootGroupDialog)
    {
        if (AddLootGroupDialog->objectName().isEmpty())
            AddLootGroupDialog->setObjectName(QString::fromUtf8("AddLootGroupDialog"));
        AddLootGroupDialog->resize(393, 69);
        verticalLayout = new QVBoxLayout(AddLootGroupDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(AddLootGroupDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        comboBox_LootGroups = new QComboBox(AddLootGroupDialog);
        comboBox_LootGroups->setObjectName(QString::fromUtf8("comboBox_LootGroups"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_LootGroups->sizePolicy().hasHeightForWidth());
        comboBox_LootGroups->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(comboBox_LootGroups);

        label_2 = new QLabel(AddLootGroupDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_2);

        doubleSpinBox = new QDoubleSpinBox(AddLootGroupDialog);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setDecimals(5);
        doubleSpinBox->setMaximum(100);

        horizontalLayout->addWidget(doubleSpinBox);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(AddLootGroupDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AddLootGroupDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddLootGroupDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddLootGroupDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddLootGroupDialog);
    } // setupUi

    void retranslateUi(QDialog *AddLootGroupDialog)
    {
        AddLootGroupDialog->setWindowTitle(QApplication::translate("AddLootGroupDialog", "Add Loot Group", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddLootGroupDialog", "Loot Group", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddLootGroupDialog", "Chance", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddLootGroupDialog: public Ui_AddLootGroupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDLOOTGROUPDIALOG_H
