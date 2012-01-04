/********************************************************************************
** Form generated from reading UI file 'preorcreaturemanager.ui'
**
** Created: Fri Dec 30 10:32:40 2011
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREORCREATUREMANAGER_H
#define UI_PREORCREATUREMANAGER_H

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
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PreORCreatureManager
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QWidget *widget1;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QListWidget *listWidget;

    void setupUi(QDialog *PreORCreatureManager)
    {
        if (PreORCreatureManager->objectName().isEmpty())
            PreORCreatureManager->setObjectName(QString::fromUtf8("PreORCreatureManager"));
        PreORCreatureManager->resize(683, 441);
        buttonBox = new QDialogButtonBox(PreORCreatureManager);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(310, 390, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(PreORCreatureManager);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 311, 61));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        widget1 = new QWidget(PreORCreatureManager);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(20, 110, 258, 218));
        gridLayout_2 = new QGridLayout(widget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        listWidget = new QListWidget(widget1);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout_2->addWidget(listWidget, 1, 0, 1, 1);


        retranslateUi(PreORCreatureManager);
        QObject::connect(buttonBox, SIGNAL(accepted()), PreORCreatureManager, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PreORCreatureManager, SLOT(reject()));

        QMetaObject::connectSlotsByName(PreORCreatureManager);
    } // setupUi

    void retranslateUi(QDialog *PreORCreatureManager)
    {
        PreORCreatureManager->setWindowTitle(QApplication::translate("PreORCreatureManager", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PreORCreatureManager", "PreOR server directory", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("PreORCreatureManager", "Open", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PreORCreatureManager", "Creatures", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PreORCreatureManager: public Ui_PreORCreatureManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREORCREATUREMANAGER_H
