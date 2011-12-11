#ifndef LAIRNAME_H
#define LAIRNAME_H

#include <QDialog>

namespace Ui {
    class LairName;
}

class LairName : public QDialog
{
    Q_OBJECT

public:
    explicit LairName(QWidget *parent = 0);
    ~LairName();

    QString getName();
private:
    Ui::LairName *ui;
};

#endif // LAIRNAME_H
