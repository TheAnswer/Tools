/********************************************************************************
** Form generated from reading UI file 'loadingdialog.ui'
**
** Created: Thu Jan 5 22:43:19 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGDIALOG_H
#define UI_LOADINGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_LoadingDialog
{
public:
    QGridLayout *gridLayout;
    QProgressBar *progressBar;
    QLabel *label_loading;

    void setupUi(QDialog *LoadingDialog)
    {
        if (LoadingDialog->objectName().isEmpty())
            LoadingDialog->setObjectName(QString::fromUtf8("LoadingDialog"));
        LoadingDialog->resize(276, 58);
        gridLayout = new QGridLayout(LoadingDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        progressBar = new QProgressBar(LoadingDialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 1, 0, 1, 1);

        label_loading = new QLabel(LoadingDialog);
        label_loading->setObjectName(QString::fromUtf8("label_loading"));

        gridLayout->addWidget(label_loading, 0, 0, 1, 1);


        retranslateUi(LoadingDialog);

        QMetaObject::connectSlotsByName(LoadingDialog);
    } // setupUi

    void retranslateUi(QDialog *LoadingDialog)
    {
        LoadingDialog->setWindowTitle(QApplication::translate("LoadingDialog", "Progress", 0, QApplication::UnicodeUTF8));
        label_loading->setText(QApplication::translate("LoadingDialog", "Loading:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoadingDialog: public Ui_LoadingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGDIALOG_H
