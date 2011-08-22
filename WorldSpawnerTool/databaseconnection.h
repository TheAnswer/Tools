#ifndef CONNECT_H
#define CONNECT_H

#include <QtGui/QDialog>
#include "ui_connect.h"

#include <QSqlDatabase>

class DatabaseConnection : public QDialog {
    Q_OBJECT

public:
    DatabaseConnection(QWidget *parent = 0);
    ~DatabaseConnection();

    inline bool isOpen() {
        return sqlDatabase.isOpen();
    }

public slots:
    void connectDatabase();

signals:
    void printToConsole(const QString& a);
    void connectedToDatabase();

private:
    Ui::ConnectClass ui;

    QSqlDatabase sqlDatabase;
};

#endif // CONNECT_H
