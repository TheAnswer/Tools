#ifndef CHANCELINEEDIT_H
#define CHANCELINEEDIT_H

#include "QLineEdit"

class ChanceLineEdit : public QLineEdit
{
public:
    ChanceLineEdit(QWidget* parent = 0);

public slots:
    void updateChanceTotal();
};

#endif // CHANCELINEEDIT_H
