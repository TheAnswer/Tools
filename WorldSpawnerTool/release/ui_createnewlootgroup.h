/********************************************************************************
** Form generated from reading UI file 'createnewlootgroup.ui'
**
** Created: Thu Jan 5 22:43:19 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWLOOTGROUP_H
#define UI_CREATENEWLOOTGROUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateNewLootGroup
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit_LootGroupName;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CreateNewLootGroup)
    {
        if (CreateNewLootGroup->objectName().isEmpty())
            CreateNewLootGroup->setObjectName(QString::fromUtf8("CreateNewLootGroup"));
        CreateNewLootGroup->resize(272, 86);
        verticalLayout = new QVBoxLayout(CreateNewLootGroup);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(CreateNewLootGroup);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit_LootGroupName = new QLineEdit(CreateNewLootGroup);
        lineEdit_LootGroupName->setObjectName(QString::fromUtf8("lineEdit_LootGroupName"));

        verticalLayout->addWidget(lineEdit_LootGroupName);

        buttonBox = new QDialogButtonBox(CreateNewLootGroup);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CreateNewLootGroup);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateNewLootGroup, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateNewLootGroup, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateNewLootGroup);
    } // setupUi

    void retranslateUi(QDialog *CreateNewLootGroup)
    {
        CreateNewLootGroup->setWindowTitle(QApplication::translate("CreateNewLootGroup", "Create New Loot Group", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreateNewLootGroup", "Enter a name for the new loot group:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateNewLootGroup: public Ui_CreateNewLootGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWLOOTGROUP_H
