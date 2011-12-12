#ifndef LAIRSPAWNEDITOR_H
#define LAIRSPAWNEDITOR_H

#include <QDialog>
#include "lairgroup.h"
#include <QListWidgetItem>

namespace Ui {
    class LairSpawnEditor;
}

class LairSpawnEditor : public QDialog
{
    Q_OBJECT

public:
    explicit LairSpawnEditor(LairGroup* group, QWidget *parent = 0);
    ~LairSpawnEditor();

public slots:
    void updateData();
    void clearCurrentLairData();
    void editLairType();
    void addLairType();
    void removeLairType();

    void maxSpawnLimitChanged();

    void acceptedChanges();

    void updateCurrentLair(QListWidgetItem* previous, QListWidgetItem* item);

protected:
    void showEvent(QShowEvent * event);

private:
    Ui::LairSpawnEditor *ui;
    LairGroup* group;

    LairSpawnEntry* getCurrentEntry();
    void commitCurrentData(QListWidgetItem* item);
};

#endif // LAIRSPAWNEDITOR_H
