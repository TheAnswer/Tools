/********************************************************************************
** Form generated from reading UI file 'lairname.ui'
**
** Created: Fri Dec 30 10:32:40 2011
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAIRNAME_H
#define UI_LAIRNAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_LairName
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LairName)
    {
        if (LairName->objectName().isEmpty())
            LairName->setObjectName(QString::fromUtf8("LairName"));
        LairName->resize(229, 86);
        gridLayout = new QGridLayout(LairName);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(LairName);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_name = new QLineEdit(LairName);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        gridLayout->addWidget(lineEdit_name, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(LairName);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(LairName);
        QObject::connect(buttonBox, SIGNAL(accepted()), LairName, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LairName, SLOT(reject()));

        QMetaObject::connectSlotsByName(LairName);
    } // setupUi

    void retranslateUi(QDialog *LairName)
    {
        LairName->setWindowTitle(QApplication::translate("LairName", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LairName", "Please insert name:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LairName: public Ui_LairName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAIRNAME_H
