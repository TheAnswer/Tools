#ifndef INSPECTIONDIALOG_H
#define INSPECTIONDIALOG_H

#include "idlparser.h"
#include <QDialog>
#include <QMap>
#include <QByteArray>

namespace Ui {
class InspectionDialog;
}

class InspectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InspectionDialog(QWidget *parent = 0);
    ~InspectionDialog();

    void setInformation(QMap<IDLVar, QByteArray> info);

private:
    Ui::InspectionDialog *ui;

    QMap<IDLVar, QByteArray> information;
};

#endif // INSPECTIONDIALOG_H
