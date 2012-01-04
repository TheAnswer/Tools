/********************************************************************************
** Form generated from reading UI file 'connect.ui'
**
** Created: Fri Dec 30 10:32:40 2011
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECT_H
#define UI_CONNECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConnectClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton;

    void setupUi(QDialog *ConnectClass)
    {
        if (ConnectClass->objectName().isEmpty())
            ConnectClass->setObjectName(QString::fromUtf8("ConnectClass"));
        ConnectClass->resize(193, 177);
        gridLayout = new QGridLayout(ConnectClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(ConnectClass);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(ConnectClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(ConnectClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(ConnectClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(ConnectClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(ConnectClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(ConnectClass);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(ConnectClass);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(ConnectClass);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(ConnectClass);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        verticalLayout->addWidget(lineEdit_5);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        pushButton = new QPushButton(ConnectClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_3->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(ConnectClass);

        QMetaObject::connectSlotsByName(ConnectClass);
    } // setupUi

    void retranslateUi(QDialog *ConnectClass)
    {
        ConnectClass->setWindowTitle(QApplication::translate("ConnectClass", "Connect", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConnectClass", "address", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ConnectClass", "port", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ConnectClass", "user", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ConnectClass", "password", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ConnectClass", "table", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("ConnectClass", "localhost", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("ConnectClass", "3306", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setText(QApplication::translate("ConnectClass", "root", 0, QApplication::UnicodeUTF8));
        lineEdit_4->setText(QApplication::translate("ConnectClass", "swgemu", 0, QApplication::UnicodeUTF8));
        lineEdit_5->setText(QApplication::translate("ConnectClass", "swgemu", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ConnectClass", "Connect", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConnectClass: public Ui_ConnectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECT_H
