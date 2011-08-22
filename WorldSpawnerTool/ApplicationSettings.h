#ifndef APPLICATIONSETTINGS_H
#define APPLICATIONSETTINGS_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"

class ApplicationSettings {
    QString treDirectory;
    QString serverDirectory;


public:
    ApplicationSettings() {

    }

    void saveSettings() {
        QFile newFile("settings.ini");
        newFile.open(QIODevice::WriteOnly);
        newFile.setTextModeEnabled(true);;

        QString data;
        QTextStream stream(&data);

        stream << "treDirectory=" << treDirectory << endl;
        stream << "serverDirectory=" << serverDirectory << endl;

        newFile.write(data.toAscii());
        newFile.close();
    }

    void loadSettings(MainWindow* mainWindow) {
        QFile newFile("settings.ini");
        if (!newFile.open(QIODevice::ReadOnly)) {
            mainWindow->outputToConsole("could not open settings file");
            return;
        } else
            mainWindow->outputToConsole("opened settings.ini");

        QByteArray data = newFile.readAll();

        int i = 0;
        while (i < data.size()) {
            QString token;
            QTextStream stream(&token);
            char c;

            while ((c = data[i++]) && c != ' ' && c != '\n' && c != '\0') {
                stream << c;
            }

            //mainWindow->outputToConsole(token);

            int dataIdx = token.indexOf("=");

            if (dataIdx != -1) {
                if (token.contains("treDirectory")) {
                    treDirectory = token.mid(dataIdx + 1).simplified();
                } else if (token.contains("serverDirectory")) {
                    serverDirectory = token.mid(dataIdx + 1).simplified();
                }
            }
        }

    }

    void setTreDirectory(const QString& dir) {
        treDirectory = dir;
    }

    void setServerDirectory(const QString& dir) {
        serverDirectory = dir;
    }

    QString getTreDirectory() {
        return treDirectory;
    }

    QString getServerDirectory() {
        return serverDirectory;
    }

};

#endif // APPLICATIONSETTINGS_H
