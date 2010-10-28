#include "crccalculator.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CRCCalculator w;
    w.show();

    return a.exec();
}
