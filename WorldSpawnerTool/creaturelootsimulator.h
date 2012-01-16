#ifndef CREATURELOOTSIMULATOR_H
#define CREATURELOOTSIMULATOR_H

#include <QDialog>

namespace Ui {
class CreatureLootSimulator;
}

class CreatureLootSimulator : public QDialog
{
    Q_OBJECT
    
public:
    explicit CreatureLootSimulator(QWidget *parent = 0);
    ~CreatureLootSimulator();
    
private:
    Ui::CreatureLootSimulator *ui;
};

#endif // CREATURELOOTSIMULATOR_H
