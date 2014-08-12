/********************************************************************************
** Form generated from reading UI file 'inspectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSPECTIONDIALOG_H
#define UI_INSPECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_InspectionDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget;

    void setupUi(QDialog *InspectionDialog)
    {
        if (InspectionDialog->objectName().isEmpty())
            InspectionDialog->setObjectName(QString::fromUtf8("InspectionDialog"));
        InspectionDialog->resize(801, 607);
        gridLayout = new QGridLayout(InspectionDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(InspectionDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 0, 1, 1, 1);

        tableWidget = new QTableWidget(InspectionDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(296, 282));
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::NoPen);
        tableWidget->setSortingEnabled(true);
        tableWidget->setWordWrap(false);
        tableWidget->verticalHeader()->setVisible(false);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);


        retranslateUi(InspectionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), InspectionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InspectionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(InspectionDialog);
    } // setupUi

    void retranslateUi(QDialog *InspectionDialog)
    {
        InspectionDialog->setWindowTitle(QApplication::translate("InspectionDialog", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InspectionDialog: public Ui_InspectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSPECTIONDIALOG_H
