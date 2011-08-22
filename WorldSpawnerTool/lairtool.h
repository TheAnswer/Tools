#ifndef LAIRTOOL_H
#define LAIRTOOL_H

#include <QDialog>

namespace Ui {
    class LairTool;
}

class LairTool : public QDialog
{
    Q_OBJECT

public:
    explicit LairTool(QWidget *parent = 0);
    ~LairTool();

private:
    Ui::LairTool *ui;
};

#endif // LAIRTOOL_H
