#ifndef NEWLAIRMOBILE_H
#define NEWLAIRMOBILE_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
    class NewLairMobile;
}

class NewLairMobile : public QDialog
{
    Q_OBJECT

public:
    explicit NewLairMobile(QWidget *parent = 0);
    ~NewLairMobile();

    QString getMobile();
    int getLevel();

public slots:
    void showExistingMobiles();
    void mobileChanged(QListWidgetItem* item);

private:
    Ui::NewLairMobile *ui;
};

#endif // NEWLAIRMOBILE_H
