/********************************************************************************
** Form generated from reading UI file 'newlairmobile.ui'
**
** Created: Thu Jan 5 22:43:19 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWLAIRMOBILE_H
#define UI_NEWLAIRMOBILE_H

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
#include <QtGui/QListWidget>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_NewLairMobile
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_mobile;
    QLabel *label_2;
    QSpinBox *spinBox_level;
    QDialogButtonBox *buttonBox;
    QToolButton *toolButton;
    QListWidget *listWidget;

    void setupUi(QDialog *NewLairMobile)
    {
        if (NewLairMobile->objectName().isEmpty())
            NewLairMobile->setObjectName(QString::fromUtf8("NewLairMobile"));
        NewLairMobile->resize(381, 172);
        gridLayout = new QGridLayout(NewLairMobile);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(NewLairMobile);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_mobile = new QLineEdit(NewLairMobile);
        lineEdit_mobile->setObjectName(QString::fromUtf8("lineEdit_mobile"));

        gridLayout->addWidget(lineEdit_mobile, 0, 1, 1, 1);

        label_2 = new QLabel(NewLairMobile);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        spinBox_level = new QSpinBox(NewLairMobile);
        spinBox_level->setObjectName(QString::fromUtf8("spinBox_level"));
        spinBox_level->setMaximum(50000);

        gridLayout->addWidget(spinBox_level, 2, 1, 1, 1);

        buttonBox = new QDialogButtonBox(NewLairMobile);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 2);

        toolButton = new QToolButton(NewLairMobile);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        gridLayout->addWidget(toolButton, 0, 2, 1, 1);

        listWidget = new QListWidget(NewLairMobile);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setEnabled(false);

        gridLayout->addWidget(listWidget, 1, 1, 1, 1);


        retranslateUi(NewLairMobile);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewLairMobile, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewLairMobile, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewLairMobile);
    } // setupUi

    void retranslateUi(QDialog *NewLairMobile)
    {
        NewLairMobile->setWindowTitle(QApplication::translate("NewLairMobile", "New Mobile", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewLairMobile", "Mobile", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NewLairMobile", "Level", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("NewLairMobile", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewLairMobile: public Ui_NewLairMobile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWLAIRMOBILE_H
