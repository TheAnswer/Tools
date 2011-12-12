#ifndef LAIRTYPES_H
#define LAIRTYPES_H

#include <QDialog>
#include <QMap>
#include <QSharedPointer>
#include <QVector>

#include "lairtemplate.h"
#include "lairname.h"

class LairTool;
class LairLuaManager;

namespace Ui {
    class LairTypes;
}

class LairTypes : public QDialog
{
    Q_OBJECT

public:
    explicit LairTypes(LairLuaManager* manager, QWidget *parent = 0);
    ~LairTypes();

    QList<QString> getLairTypes();

public slots:
    void createLair();
    void saveLairs(bool forceUpdate = false);
    void removeLair();
    void editLair();
    void loadCurrentLairTypes(bool skipDialog = false);

private:
    Ui::LairTypes *ui;

    QMap<QString, LairTemplate*>* lairTemplates;

    LairName* lairName;
    LairLuaManager* lairLuaManager;



};

#endif // LAIRTYPES_H
