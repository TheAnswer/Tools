/********************************************************************************
** Form generated from reading UI file 'stfviewer.ui'
**
** Created: Thu Jan 5 22:43:19 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STFVIEWER_H
#define UI_STFVIEWER_H

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
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_STFViewer
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_stringID;
    QPushButton *pushButton_stringID;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_open;
    QTableWidget *tableWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *STFViewer)
    {
        if (STFViewer->objectName().isEmpty())
            STFViewer->setObjectName(QString::fromUtf8("STFViewer"));
        STFViewer->resize(509, 308);
        gridLayout_2 = new QGridLayout(STFViewer);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(STFViewer);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_stringID = new QLineEdit(STFViewer);
        lineEdit_stringID->setObjectName(QString::fromUtf8("lineEdit_stringID"));

        gridLayout->addWidget(lineEdit_stringID, 0, 1, 1, 1);

        pushButton_stringID = new QPushButton(STFViewer);
        pushButton_stringID->setObjectName(QString::fromUtf8("pushButton_stringID"));

        gridLayout->addWidget(pushButton_stringID, 0, 2, 1, 1);

        label = new QLabel(STFViewer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit = new QLineEdit(STFViewer);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        pushButton_open = new QPushButton(STFViewer);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));

        gridLayout->addWidget(pushButton_open, 1, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        tableWidget = new QTableWidget(STFViewer);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setShowGrid(true);

        gridLayout_2->addWidget(tableWidget, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(STFViewer);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(STFViewer);
        QObject::connect(buttonBox, SIGNAL(accepted()), STFViewer, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), STFViewer, SLOT(reject()));

        QMetaObject::connectSlotsByName(STFViewer);
    } // setupUi

    void retranslateUi(QDialog *STFViewer)
    {
        STFViewer->setWindowTitle(QApplication::translate("STFViewer", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("STFViewer", "String ID", 0, QApplication::UnicodeUTF8));
        pushButton_stringID->setText(QApplication::translate("STFViewer", "Open", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("STFViewer", "File", 0, QApplication::UnicodeUTF8));
        pushButton_open->setText(QApplication::translate("STFViewer", "Open", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("STFViewer", "Key", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("STFViewer", "String", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class STFViewer: public Ui_STFViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STFVIEWER_H
