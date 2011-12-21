#ifndef LOOTITEMEDITOR_H
#define LOOTITEMEDITOR_H

#include <QDialog>

namespace Ui {
    class LootItemEditor;
}

class LootItemEditor : public QDialog
{
    Q_OBJECT

public:
    explicit LootItemEditor(QWidget *parent = 0);
    ~LootItemEditor();

private:
    Ui::LootItemEditor *ui;
};

#endif // LOOTITEMEDITOR_H
