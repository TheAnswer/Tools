#ifndef ADDLOOTGROUPDIALOG_H
#define ADDLOOTGROUPDIALOG_H

#include <QDialog>

namespace Ui {
class AddLootGroupDialog;
}

class AddLootGroupDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddLootGroupDialog(double maxChance = 100.f, QWidget *parent = 0);
    ~AddLootGroupDialog();

    void showEvent(QShowEvent*);

    //Getters
    QString getGroupName() const;
    double getChance();
    
private:
    Ui::AddLootGroupDialog *ui;
};

#endif // ADDLOOTGROUPDIALOG_H
