/********************************************************************************
** Form generated from reading UI file 'crccalculator.ui'
**
** Created: Thu 28. Oct 06:06:08 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRCCALCULATOR_H
#define UI_CRCCALCULATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CRCCalculatorClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QLabel *label;

    void setupUi(QWidget *CRCCalculatorClass)
    {
        if (CRCCalculatorClass->objectName().isEmpty())
            CRCCalculatorClass->setObjectName(QString::fromUtf8("CRCCalculatorClass"));
        CRCCalculatorClass->resize(373, 111);
        verticalLayout_2 = new QVBoxLayout(CRCCalculatorClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(CRCCalculatorClass);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        label = new QLabel(CRCCalculatorClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);
        label->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(label);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(CRCCalculatorClass);

        QMetaObject::connectSlotsByName(CRCCalculatorClass);
    } // setupUi

    void retranslateUi(QWidget *CRCCalculatorClass)
    {
        CRCCalculatorClass->setWindowTitle(QApplication::translate("CRCCalculatorClass", "CRCCalculator", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CRCCalculatorClass", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CRCCalculatorClass: public Ui_CRCCalculatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRCCALCULATOR_H
