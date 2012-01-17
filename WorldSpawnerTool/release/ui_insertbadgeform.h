/********************************************************************************
** Form generated from reading UI file 'insertbadgeform.ui'
**
** Created: Thu Jan 5 22:43:19 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTBADGEFORM_H
#define UI_INSERTBADGEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_InsertBadgeForm
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLabel *label;
    QSpinBox *spinBox_badgeID;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_x;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_y;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_radius;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *InsertBadgeForm)
    {
        if (InsertBadgeForm->objectName().isEmpty())
            InsertBadgeForm->setObjectName(QString::fromUtf8("InsertBadgeForm"));
        InsertBadgeForm->resize(274, 222);
        gridLayout_4 = new QGridLayout(InsertBadgeForm);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        frame = new QFrame(InsertBadgeForm);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        spinBox_badgeID = new QSpinBox(frame);
        spinBox_badgeID->setObjectName(QString::fromUtf8("spinBox_badgeID"));
        spinBox_badgeID->setMaximum(656156);

        gridLayout->addWidget(spinBox_badgeID, 1, 1, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        doubleSpinBox_x = new QDoubleSpinBox(frame);
        doubleSpinBox_x->setObjectName(QString::fromUtf8("doubleSpinBox_x"));
        doubleSpinBox_x->setMinimum(-999999);
        doubleSpinBox_x->setMaximum(999999);

        gridLayout->addWidget(doubleSpinBox_x, 2, 1, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        doubleSpinBox_y = new QDoubleSpinBox(frame);
        doubleSpinBox_y->setObjectName(QString::fromUtf8("doubleSpinBox_y"));
        doubleSpinBox_y->setMinimum(-99999);
        doubleSpinBox_y->setMaximum(999999);

        gridLayout->addWidget(doubleSpinBox_y, 3, 1, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        doubleSpinBox_radius = new QDoubleSpinBox(frame);
        doubleSpinBox_radius->setObjectName(QString::fromUtf8("doubleSpinBox_radius"));
        doubleSpinBox_radius->setMaximum(100000);

        gridLayout->addWidget(doubleSpinBox_radius, 4, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(frame, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(InsertBadgeForm);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);


        retranslateUi(InsertBadgeForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), InsertBadgeForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InsertBadgeForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(InsertBadgeForm);
    } // setupUi

    void retranslateUi(QDialog *InsertBadgeForm)
    {
        InsertBadgeForm->setWindowTitle(QApplication::translate("InsertBadgeForm", "Dialog", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("InsertBadgeForm", "Object name", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("InsertBadgeForm", "Badge id", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("InsertBadgeForm", "x", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("InsertBadgeForm", "y", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("InsertBadgeForm", "Radius", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InsertBadgeForm: public Ui_InsertBadgeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTBADGEFORM_H
