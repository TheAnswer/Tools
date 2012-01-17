/********************************************************************************
** Form generated from reading UI file 'creaturelootsimulator.ui'
**
** Created: Sun Jan 15 18:41:03 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATURELOOTSIMULATOR_H
#define UI_CREATURELOOTSIMULATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_CreatureLootSimulator
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *CreatureLootSimulator)
    {
        if (CreatureLootSimulator->objectName().isEmpty())
            CreatureLootSimulator->setObjectName(QString::fromUtf8("CreatureLootSimulator"));
        CreatureLootSimulator->resize(810, 328);
        buttonBox = new QDialogButtonBox(CreatureLootSimulator);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(460, 290, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(CreatureLootSimulator);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 191, 16));

        retranslateUi(CreatureLootSimulator);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreatureLootSimulator, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreatureLootSimulator, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreatureLootSimulator);
    } // setupUi

    void retranslateUi(QDialog *CreatureLootSimulator)
    {
        CreatureLootSimulator->setWindowTitle(QApplication::translate("CreatureLootSimulator", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreatureLootSimulator", "CreatureName", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreatureLootSimulator: public Ui_CreatureLootSimulator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATURELOOTSIMULATOR_H
