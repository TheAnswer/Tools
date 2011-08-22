#ifndef PLANETSELECTION_H
#define PLANETSELECTION_H

#include <QDialog>

namespace Ui {
    class PlanetSelection;
}

class PlanetSelection : public QDialog
{
    Q_OBJECT

public:
    explicit PlanetSelection(QWidget *parent = 0);
    ~PlanetSelection();

    QString getCurrentPlanetSelection();

private:
    Ui::PlanetSelection *ui;
};

#endif // PLANETSELECTION_H
