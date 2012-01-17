/********************************************************************************
** Form generated from reading UI file 'objectmodel3dviewer.ui'
**
** Created: Thu Jan 5 22:43:19 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJECTMODEL3DVIEWER_H
#define UI_OBJECTMODEL3DVIEWER_H

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
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ObjectModel3dViewer
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_template;
    QProgressBar *progressBar;
    QLabel *label_2;
    QPushButton *pushButton;
    QWidget *widget_container;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ObjectModel3dViewer)
    {
        if (ObjectModel3dViewer->objectName().isEmpty())
            ObjectModel3dViewer->setObjectName(QString::fromUtf8("ObjectModel3dViewer"));
        ObjectModel3dViewer->resize(994, 726);
        gridLayout_2 = new QGridLayout(ObjectModel3dViewer);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ObjectModel3dViewer);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_template = new QLineEdit(ObjectModel3dViewer);
        lineEdit_template->setObjectName(QString::fromUtf8("lineEdit_template"));

        gridLayout->addWidget(lineEdit_template, 0, 1, 1, 1);

        progressBar = new QProgressBar(ObjectModel3dViewer);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 1, 1, 1, 1);

        label_2 = new QLabel(ObjectModel3dViewer);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        pushButton = new QPushButton(ObjectModel3dViewer);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 0, 1, 1, 1);

        widget_container = new QWidget(ObjectModel3dViewer);
        widget_container->setObjectName(QString::fromUtf8("widget_container"));

        gridLayout_2->addWidget(widget_container, 1, 0, 1, 2);

        buttonBox = new QDialogButtonBox(ObjectModel3dViewer);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(ObjectModel3dViewer);
        QObject::connect(buttonBox, SIGNAL(accepted()), ObjectModel3dViewer, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ObjectModel3dViewer, SLOT(reject()));

        QMetaObject::connectSlotsByName(ObjectModel3dViewer);
    } // setupUi

    void retranslateUi(QDialog *ObjectModel3dViewer)
    {
        ObjectModel3dViewer->setWindowTitle(QApplication::translate("ObjectModel3dViewer", "Model viewer", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ObjectModel3dViewer", "Client file", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ObjectModel3dViewer", "Press space to find inserted objects", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ObjectModel3dViewer", "Open", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ObjectModel3dViewer: public Ui_ObjectModel3dViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECTMODEL3DVIEWER_H
