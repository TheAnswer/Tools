#include "databaseconnection.h"
#include "mainwindow.h"
#include <QTextStream>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQuery>

DatabaseConnection::DatabaseConnection(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	connect(this, SIGNAL(printToConsole(QString)), MainWindow::instance, SLOT(outputToConsole(QString)));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(connectDatabase()));
}

DatabaseConnection::~DatabaseConnection() {
}

void DatabaseConnection::connectDatabase() {
    sqlDatabase = QSqlDatabase::addDatabase("QMYSQL");

    sqlDatabase.setHostName(ui.lineEdit->text());
    sqlDatabase.setPort(ui.lineEdit_2->text().toInt());
    sqlDatabase.setDatabaseName(ui.lineEdit_5->text());
    sqlDatabase.setUserName(ui.lineEdit_3->text());
    sqlDatabase.setPassword(ui.lineEdit_4->text());

    bool ok = sqlDatabase.open();

    if (ok) {
        emit printToConsole("connected to database");
        QMessageBox::information(NULL, "Database", "Connected to database");

        hide();

        emit connectedToDatabase();
    } else {
    	QSqlError sqlError = sqlDatabase.lastError();

    	emit printToConsole(sqlError.text());
        emit printToConsole("could not connect to database");

        QMessageBox::information(NULL, "Database", sqlError.text());
    }


    /*QSqlQuery query("SELECT * FROM world_server_static_spawns2 WHERE mood_animation != ''");

    while (query.next()) {
        int id = query.value(0).toInt();
        QString anim = query.value(12).toString();

        QString q;
        QTextStream stream(&q);

        stream << "UPDATE world_server_static_spawns SET mood_animation = '" << anim << "' WHERE id = "
                << id - 9649 << ";";
        QSqlQuery query2(q);
    }*/
}
