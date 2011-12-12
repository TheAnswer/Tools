#ifndef LOADINGDIALOG_H
#define LOADINGDIALOG_H

#include <QDialog>

namespace Ui {
    class LoadingDialog;
}

class LoadingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoadingDialog(QWidget *parent = 0);
    ~LoadingDialog();

    void setProgress(int val);
    void setText(const QString& val);

private:
    Ui::LoadingDialog *ui;
};

#endif // LOADINGDIALOG_H
