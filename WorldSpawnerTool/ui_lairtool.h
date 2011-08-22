/********************************************************************************
** Form generated from reading UI file 'lairtool.ui'
**
** Created: Mon 22. Aug 20:29:47 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAIRTOOL_H
#define UI_LAIRTOOL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LairTool
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;

    void setupUi(QDialog *LairTool)
    {
        if (LairTool->objectName().isEmpty())
            LairTool->setObjectName(QString::fromUtf8("LairTool"));
        LairTool->resize(400, 300);
        buttonBox = new QDialogButtonBox(LairTool);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButton = new QPushButton(LairTool);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 80, 221, 31));

        retranslateUi(LairTool);
        QObject::connect(buttonBox, SIGNAL(accepted()), LairTool, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LairTool, SLOT(reject()));

        QMetaObject::connectSlotsByName(LairTool);
    } // setupUi

    void retranslateUi(QDialog *LairTool)
    {
        LairTool->setWindowTitle(QApplication::translate("LairTool", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("LairTool", "Create lair templates", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LairTool: public Ui_LairTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAIRTOOL_H
