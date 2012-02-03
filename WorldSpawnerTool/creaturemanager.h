#ifndef CREATUREMANAGER_H
#define CREATUREMANAGER_H

#include <QDialog>
#include <QMap>
#include <QByteArray>

class MainWindow;
class CreatureObject;



namespace Ui {
    class CreatureManager;
}

class CreatureManager : public QDialog
{
    Q_OBJECT

public:
    explicit CreatureManager(MainWindow* mainWindow, QWidget *parent = 0);
    ~CreatureManager();

    QList<QString> getMobiles() {
        return creatureMap.keys();
    }

    CreatureObject* getMobile(const QString& name) {
        return creatureMap.value(name, NULL);
    }

    double getTotalGroupLootChance();

public slots:
    void loadCreatureObjects();

    /*
    CreatureObject* parseCreatureObject(const QString& fileName);

    void parseVariables(QByteArray& buffer, CreatureObject* creatureObject, int& currentPosition);
    void parseVariableData(QByteArray& buffer, CreatureObject* creatureObject, int& currentPosition, QString& name, QString& variableData);
    */
    void findCreatureFile(const QString& str);
    void currentCreatureChanged(const QString& text);
    void reloadCreature();
    void saveCurrentCreature();
    void promptToSave();
    void optionBitSelectionChanged();
    void optionBitValueChanged();
    void addNewCreature();

    void addWeapon();
    void removeWeapon();

    void promptAddLootGroupCollection();

    void addTemplate();
    void removeTemplate();
    void view3d();
    void addAttack();
    void removeAttack();

    void openSTFWithName();

    //void loadFiles(QByteArray& includeFile);

    void addCreatureObject(const QString& key, CreatureObject* value);

private:
    Ui::CreatureManager *ui;
    MainWindow* mainWindow;
    QVector<QString> creatureFiles;
    QMap<QString, CreatureObject*> creatureMap;
    CreatureObject* currentCreatureObject;
    bool creatureChanged;

    QString parseName(QByteArray& buffer, int& currentPosition);


};

#endif // CREATUREMANAGER_H
