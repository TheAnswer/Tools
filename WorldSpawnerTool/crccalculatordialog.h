#ifndef CRCCALCULATORDIALOG_H
#define CRCCALCULATORDIALOG_H

#include <QDialog>

namespace Ui {
class CRCCalculatorDialog;
}

class CRCCalculatorDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit CRCCalculatorDialog(QWidget *parent = 0);
    ~CRCCalculatorDialog();
    
private slots:
    void on_lineEdit_CRC_textChanged(const QString &arg1);

private:
    Ui::CRCCalculatorDialog *ui;
};

#endif // CRCCALCULATORDIALOG_H
