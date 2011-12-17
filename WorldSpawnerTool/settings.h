#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

#include "ApplicationSettings.h"

namespace Ui {
    class Settings;
}


class MainWindow;

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(MainWindow* mainWindow, QWidget *parent = 0);
    ~Settings();

    QString getServerDirectory() {
        return settings->getServerDirectory();
    }

    QString getTreDirectory() {
        return settings->getTreDirectory();
    }

public slots:
    void setServerDirectory();
    void setTreDirectory();

private:
    Ui::Settings *ui;
    ApplicationSettings* settings;

};

#endif // SETTINGS_H
