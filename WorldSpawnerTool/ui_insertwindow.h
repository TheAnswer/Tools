/********************************************************************************
** Form generated from reading UI file 'insertwindow.ui'
**
** Created: Sat 3. Dec 01:37:23 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTWINDOW_H
#define UI_INSERTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InsertWindowClass
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_Mobile;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_PositionX;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_PositionZ;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_PositionY;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_Heading;
    QLabel *label_6;
    QLabel *label_10;
    QSpinBox *spinBox_ParentID;
    QSpinBox *spinBox_Respawn;
    QPushButton *pushButton;

    void setupUi(QWidget *InsertWindowClass)
    {
        if (InsertWindowClass->objectName().isEmpty())
            InsertWindowClass->setObjectName(QString::fromUtf8("InsertWindowClass"));
        InsertWindowClass->resize(265, 285);
        gridLayout_2 = new QGridLayout(InsertWindowClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(InsertWindowClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_Mobile = new QLineEdit(InsertWindowClass);
        lineEdit_Mobile->setObjectName(QString::fromUtf8("lineEdit_Mobile"));

        gridLayout->addWidget(lineEdit_Mobile, 0, 1, 1, 1);

        label_2 = new QLabel(InsertWindowClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        doubleSpinBox_PositionX = new QDoubleSpinBox(InsertWindowClass);
        doubleSpinBox_PositionX->setObjectName(QString::fromUtf8("doubleSpinBox_PositionX"));
        doubleSpinBox_PositionX->setMinimum(-1e+09);
        doubleSpinBox_PositionX->setMaximum(1e+09);

        gridLayout->addWidget(doubleSpinBox_PositionX, 1, 1, 1, 1);

        label_3 = new QLabel(InsertWindowClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        doubleSpinBox_PositionZ = new QDoubleSpinBox(InsertWindowClass);
        doubleSpinBox_PositionZ->setObjectName(QString::fromUtf8("doubleSpinBox_PositionZ"));
        doubleSpinBox_PositionZ->setMinimum(-1e+09);
        doubleSpinBox_PositionZ->setMaximum(1e+09);

        gridLayout->addWidget(doubleSpinBox_PositionZ, 2, 1, 1, 1);

        label_4 = new QLabel(InsertWindowClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        doubleSpinBox_PositionY = new QDoubleSpinBox(InsertWindowClass);
        doubleSpinBox_PositionY->setObjectName(QString::fromUtf8("doubleSpinBox_PositionY"));
        doubleSpinBox_PositionY->setMinimum(-1e+09);
        doubleSpinBox_PositionY->setMaximum(1e+09);

        gridLayout->addWidget(doubleSpinBox_PositionY, 3, 1, 1, 1);

        label_5 = new QLabel(InsertWindowClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        doubleSpinBox_Heading = new QDoubleSpinBox(InsertWindowClass);
        doubleSpinBox_Heading->setObjectName(QString::fromUtf8("doubleSpinBox_Heading"));
        doubleSpinBox_Heading->setMinimum(-1e+09);
        doubleSpinBox_Heading->setMaximum(1e+09);

        gridLayout->addWidget(doubleSpinBox_Heading, 4, 1, 1, 1);

        label_6 = new QLabel(InsertWindowClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_10 = new QLabel(InsertWindowClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 6, 0, 1, 1);

        spinBox_ParentID = new QSpinBox(InsertWindowClass);
        spinBox_ParentID->setObjectName(QString::fromUtf8("spinBox_ParentID"));
        spinBox_ParentID->setMaximum(10);

        gridLayout->addWidget(spinBox_ParentID, 6, 1, 1, 1);

        spinBox_Respawn = new QSpinBox(InsertWindowClass);
        spinBox_Respawn->setObjectName(QString::fromUtf8("spinBox_Respawn"));
        spinBox_Respawn->setMaximum(10);

        gridLayout->addWidget(spinBox_Respawn, 5, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        pushButton = new QPushButton(InsertWindowClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 1, 0, 1, 1);


        retranslateUi(InsertWindowClass);

        QMetaObject::connectSlotsByName(InsertWindowClass);
    } // setupUi

    void retranslateUi(QWidget *InsertWindowClass)
    {
        InsertWindowClass->setWindowTitle(QApplication::translate("InsertWindowClass", "Insert Static Spawn", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("InsertWindowClass", "Mobile", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("InsertWindowClass", "PositionX", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("InsertWindowClass", "PositionZ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("InsertWindowClass", "PositionY", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("InsertWindowClass", "Heading", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("InsertWindowClass", "Respawn", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("InsertWindowClass", "Parentid", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("InsertWindowClass", "Insert", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InsertWindowClass: public Ui_InsertWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTWINDOW_H
