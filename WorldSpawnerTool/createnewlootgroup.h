#ifndef CREATENEWLOOTGROUP_H
#define CREATENEWLOOTGROUP_H

#include <QDialog>

namespace Ui {
class CreateNewLootGroup;
}

class CreateNewLootGroup : public QDialog
{
    Q_OBJECT
    
public:
    explicit CreateNewLootGroup(QWidget *parent = 0);
    ~CreateNewLootGroup();

    bool validateGroupName();

    inline QString getGroupName() const {
        return groupName;
    }

public slots:
    void accept();

signals:
    
private:
    Ui::CreateNewLootGroup *ui;
    QString groupName;
};

#endif // CREATENEWLOOTGROUP_H
