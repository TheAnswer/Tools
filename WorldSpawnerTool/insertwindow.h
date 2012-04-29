#ifndef INSERTWINDOW_H
#define INSERTWINDOW_H

#include <QtGui/QDialog>
#include "ui_insertwindow.h"

class MainWindow;

class InsertWindow : public QDialog {
    Q_OBJECT

public:
    InsertWindow(MainWindow* main);
    ~InsertWindow();

    inline void setPositionX(float x) {
        ui.doubleSpinBox_PositionX->setValue(x);
    }

    inline void setPositionY(float y) {
        ui.doubleSpinBox_PositionY->setValue(y);
    }

    QString getMobile() {
        return ui.lineEdit_Mobile->text();
    }

    float getPositionX() {
        return ui.doubleSpinBox_PositionX->value();
    }

    float getPositionZ() {
        return ui.doubleSpinBox_PositionZ->value();
    }

    float getPositionY() {
        return ui.doubleSpinBox_PositionY->value();
    }

    float getHeading() {
        return ui.doubleSpinBox_Heading->value();
    }

    int getParentID() {
        return ui.lineEdit_ParentID->text().toInt();
    }

    int getRespawn() {
        return ui.spinBox_Respawn->value();
    }

public slots:
    void insertObject();

signals:
    void insertSingleSpawn(InsertWindow* window);

protected:
    void keyPressEvent(QKeyEvent* event);

private:
    Ui::InsertWindowClass ui;
    MainWindow* mainWindow;
};

#endif // INSERTWINDOW_H
