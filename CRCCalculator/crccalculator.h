#ifndef CRCCALCULATOR_H
#define CRCCALCULATOR_H

#include <QtGui/QWidget>
#include "ui_crccalculator.h"

class CRCCalculator : public QWidget {
    Q_OBJECT

public:
    CRCCalculator(QWidget *parent = 0);
    ~CRCCalculator();

   unsigned int hashCode(const char* str, int len);

public slots:
    void calculateCRC();

private:
    Ui::CRCCalculatorClass ui;
};

#endif // CRCCALCULATOR_H
