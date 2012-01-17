/********************************************************************************
** Form generated from reading UI file 'addlairtypetospawn.ui'
**
** Created: Thu Jan 5 22:43:19 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDLAIRTYPETOSPAWN_H
#define UI_ADDLAIRTYPETOSPAWN_H

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

QT_BEGIN_NAMESPACE

class Ui_AddLairTypeToSpawn
{
public:
    QGridLayout *gridLayout;
    QListWidget *listWidget_lairs;
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QPushButton *pushButton_lairTool;

    void setupUi(QDialog *AddLairTypeToSpawn)
    {
        if (AddLairTypeToSpawn->objectName().isEmpty())
            AddLairTypeToSpawn->setObjectName(QString::fromUtf8("AddLairTypeToSpawn"));
        AddLairTypeToSpawn->resize(400, 300);
        gridLayout = new QGridLayout(AddLairTypeToSpawn);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listWidget_lairs = new QListWidget(AddLairTypeToSpawn);
        listWidget_lairs->setObjectName(QString::fromUtf8("listWidget_lairs"));

        gridLayout->addWidget(listWidget_lairs, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(AddLairTypeToSpawn);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 0, 1, 1);

        label = new QLabel(AddLairTypeToSpawn);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton_lairTool = new QPushButton(AddLairTypeToSpawn);
        pushButton_lairTool->setObjectName(QString::fromUtf8("pushButton_lairTool"));

        gridLayout->addWidget(pushButton_lairTool, 3, 0, 1, 1);


        retranslateUi(AddLairTypeToSpawn);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddLairTypeToSpawn, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddLairTypeToSpawn, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddLairTypeToSpawn);
    } // setupUi

    void retranslateUi(QDialog *AddLairTypeToSpawn)
    {
        AddLairTypeToSpawn->setWindowTitle(QApplication::translate("AddLairTypeToSpawn", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddLairTypeToSpawn", "Available lair types", 0, QApplication::UnicodeUTF8));
        pushButton_lairTool->setText(QApplication::translate("AddLairTypeToSpawn", "Open lair types tool", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddLairTypeToSpawn: public Ui_AddLairTypeToSpawn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDLAIRTYPETOSPAWN_H
