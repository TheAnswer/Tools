#ifndef BADGE_H
#define BADGE_H

#include "region.h"
#include "spawn.h"
#include <QVariant>
//#include <Gra

class Badge : public Region {
  int badgeID;
  QString name;

protected:
  QVariant itemChange(GraphicsItemChange change, const QVariant& value);

public:
  Badge(const QString& name);

  ~Badge() {

  }

  void setRadius(float val);
  void setBadgeID(int id);
  void setWorldX(float v);
  void setWorldY(float v);

  QString toLua();

  int getBadgeID() {
    return badgeID;
  }

  QString getName() {
    return name;
  }

};

#endif // BADGE_H
