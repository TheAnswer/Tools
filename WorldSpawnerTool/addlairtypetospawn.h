#ifndef ADDLAIRTYPETOSPAWN_H
#define ADDLAIRTYPETOSPAWN_H

#include <QDialog>

namespace Ui {
    class AddLairTypeToSpawn;
}

class AddLairTypeToSpawn : public QDialog
{
    Q_OBJECT

public:
    explicit AddLairTypeToSpawn(QWidget *parent = 0);
    ~AddLairTypeToSpawn();

    QString getSelectedLair();

public slots:
    void openLairTool();

private:
    Ui::AddLairTypeToSpawn *ui;

    void reloadMobileList();
};

#endif // ADDLAIRTYPETOSPAWN_H
