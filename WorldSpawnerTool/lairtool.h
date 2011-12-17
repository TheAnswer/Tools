#ifndef LAIRTOOL_H
#define LAIRTOOL_H

#include <QDialog>
#include <QVector>
#include <QListWidget>
#include <QString>
#include "lairtemplate.h"
#include "lairname.h"
#include "newlairmobile.h"

namespace Ui {
    class LairTool;
}

class LairTool : public QDialog
{
    Q_OBJECT

public:
    explicit LairTool(QWidget *parent = 0);
    ~LairTool();

public slots:
    void setTemplate(LairTemplate* templ);
    void addBuilding();
    void addMobile();

    void removeBuilding();
    void removeMobile();

    void commitToTemplate();
    void view3d();

private:
    Ui::LairTool *ui;

    LairTemplate* currentTemplate;
    NewLairMobile* nameMobileForm;
    LairName* nameBuildingForm;

    void updateBuildings(QVector<QString>* buildings, QListWidget* list);
    QListWidget* getCurrentBuildingList();
    void commitBuildings(QListWidget* list, int type);
};

#endif // LAIRTOOL_H
