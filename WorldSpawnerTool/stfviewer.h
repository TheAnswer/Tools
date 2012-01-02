#ifndef STFVIEWER_H
#define STFVIEWER_H

#include <QDialog>

namespace Ui {
  class STFViewer;
}

class STFViewer : public QDialog
{
  Q_OBJECT
  
public:
  explicit STFViewer(QWidget *parent = 0);
  ~STFViewer();

  void loadFile(const QString& name);
  void loadStringID(const QString& id);

public slots:
  void loadCurrentFile();
  void loadCurretStringID();
  
private:
  Ui::STFViewer *ui;
};

#endif // STFVIEWER_H
