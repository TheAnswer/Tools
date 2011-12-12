/********************************************************************************
** Form generated from reading UI file 'lairtypes.ui'
**
** Created: Mon 12. Dec 06:27:05 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAIRTYPES_H
#define UI_LAIRTYPES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LairTypes
{
public:
    QGridLayout *gridLayout_3;
    QLabel *label;
    QGridLayout *gridLayout;
    QListWidget *listWidget_lairs;
    QPushButton *pushButton_add;
    QPushButton *pushButton_remove;
    QPushButton *pushButton_edit;
    QFrame *line;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton_save;
    QPushButton *pushButton_load;

    void setupUi(QDialog *LairTypes)
    {
        if (LairTypes->objectName().isEmpty())
            LairTypes->setObjectName(QString::fromUtf8("LairTypes"));
        LairTypes->resize(419, 454);
        gridLayout_3 = new QGridLayout(LairTypes);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(LairTypes);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listWidget_lairs = new QListWidget(LairTypes);
        listWidget_lairs->setObjectName(QString::fromUtf8("listWidget_lairs"));

        gridLayout->addWidget(listWidget_lairs, 0, 0, 1, 3);

        pushButton_add = new QPushButton(LairTypes);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));

        gridLayout->addWidget(pushButton_add, 1, 0, 1, 1);

        pushButton_remove = new QPushButton(LairTypes);
        pushButton_remove->setObjectName(QString::fromUtf8("pushButton_remove"));

        gridLayout->addWidget(pushButton_remove, 1, 1, 1, 1);

        pushButton_edit = new QPushButton(LairTypes);
        pushButton_edit->setObjectName(QString::fromUtf8("pushButton_edit"));

        gridLayout->addWidget(pushButton_edit, 1, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 1);

        line = new QFrame(LairTypes);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 5, 0, 1, 1);

        buttonBox = new QDialogButtonBox(LairTypes);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 6, 0, 1, 1);

        pushButton_save = new QPushButton(LairTypes);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));

        gridLayout_3->addWidget(pushButton_save, 3, 0, 1, 1);

        pushButton_load = new QPushButton(LairTypes);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));

        gridLayout_3->addWidget(pushButton_load, 2, 0, 1, 1);


        retranslateUi(LairTypes);
        QObject::connect(buttonBox, SIGNAL(accepted()), LairTypes, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LairTypes, SLOT(reject()));

        QMetaObject::connectSlotsByName(LairTypes);
    } // setupUi

    void retranslateUi(QDialog *LairTypes)
    {
        LairTypes->setWindowTitle(QApplication::translate("LairTypes", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LairTypes", "Lair Types", 0, QApplication::UnicodeUTF8));
        pushButton_add->setText(QApplication::translate("LairTypes", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_remove->setText(QApplication::translate("LairTypes", "Remove", 0, QApplication::UnicodeUTF8));
        pushButton_edit->setText(QApplication::translate("LairTypes", "Edit", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("LairTypes", "Save", 0, QApplication::UnicodeUTF8));
        pushButton_load->setText(QApplication::translate("LairTypes", "Reload", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LairTypes: public Ui_LairTypes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAIRTYPES_H
