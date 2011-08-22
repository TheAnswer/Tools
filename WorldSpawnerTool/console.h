#ifndef CONSOLE_H
#define CONSOLE_H

#include <QtGui/QWidget>
#include "ui_console.h"

class Console : public QWidget
{
    Q_OBJECT

public:
    Console(QWidget *parent = 0);
    ~Console();


public slots:
    void printLine(const QString& str);
    void printError(const QString& err);


private:
    Ui::ConsoleClass ui;
};

#endif // CONSOLE_H
