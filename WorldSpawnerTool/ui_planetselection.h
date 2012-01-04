/********************************************************************************
** Form generated from reading UI file 'planetselection.ui'
**
** Created: Fri Dec 30 10:32:40 2011
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANETSELECTION_H
#define UI_PLANETSELECTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PlanetSelection
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *PlanetSelection)
    {
        if (PlanetSelection->objectName().isEmpty())
            PlanetSelection->setObjectName(QString::fromUtf8("PlanetSelection"));
        PlanetSelection->resize(139, 113);
        PlanetSelection->setMaximumSize(QSize(16777207, 16777215));
        gridLayout_2 = new QGridLayout(PlanetSelection);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBox = new QComboBox(PlanetSelection);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 2, 0, 1, 1);

        pushButton = new QPushButton(PlanetSelection);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 0, 1, 1);

        label = new QLabel(PlanetSelection);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(PlanetSelection);

        QMetaObject::connectSlotsByName(PlanetSelection);
    } // setupUi

    void retranslateUi(QDialog *PlanetSelection)
    {
        PlanetSelection->setWindowTitle(QApplication::translate("PlanetSelection", "Planet", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("PlanetSelection", "Ok", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PlanetSelection", "Select planet", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PlanetSelection: public Ui_PlanetSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANETSELECTION_H
