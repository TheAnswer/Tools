#ifndef INSERTBADGEFORM_H
#define INSERTBADGEFORM_H

#include <QDialog>
#include <QTableWidget>

namespace Ui {
  class InsertBadgeForm;
}

class InsertBadgeForm : public QDialog
{
  Q_OBJECT
  
public:
  explicit InsertBadgeForm(QWidget *parent = 0);
  ~InsertBadgeForm();

  void setBadgeX(float val);
  void setBadgeY(float val);

  QString getName();
  float getPositionX();
  float getPositionY();
  float getRadius();
  int getBadgeID();

public slots:
  void showBadgeMap();
  
private:
  Ui::InsertBadgeForm *ui;
  QTableWidget* badgeTable;
};

#endif // INSERTBADGEFORM_H
