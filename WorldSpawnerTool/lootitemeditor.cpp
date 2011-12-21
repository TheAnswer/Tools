#include "lootitemeditor.h"
#include "ui_lootitemeditor.h"

LootItemEditor::LootItemEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LootItemEditor)
{
    ui->setupUi(this);
}

LootItemEditor::~LootItemEditor()
{
    delete ui;
}
