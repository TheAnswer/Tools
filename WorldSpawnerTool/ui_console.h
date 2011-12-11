/********************************************************************************
** Form generated from reading UI file 'console.ui'
**
** Created: Sat 3. Dec 01:37:23 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLE_H
#define UI_CONSOLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConsoleClass
{
public:
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *ConsoleClass)
    {
        if (ConsoleClass->objectName().isEmpty())
            ConsoleClass->setObjectName(QString::fromUtf8("ConsoleClass"));
        ConsoleClass->resize(603, 301);
        horizontalLayout = new QHBoxLayout(ConsoleClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textBrowser = new QTextBrowser(ConsoleClass);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        horizontalLayout->addWidget(textBrowser);


        retranslateUi(ConsoleClass);

        QMetaObject::connectSlotsByName(ConsoleClass);
    } // setupUi

    void retranslateUi(QWidget *ConsoleClass)
    {
        ConsoleClass->setWindowTitle(QApplication::translate("ConsoleClass", "Console", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConsoleClass: public Ui_ConsoleClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLE_H
