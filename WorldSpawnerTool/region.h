#ifndef REGION_H
#define REGION_H

#include <QGraphicsEllipseItem>
#include "spawn.h"

class Region : public QGraphicsEllipseItem, public Spawn {
protected:
  float radius;
public:
  Region(qreal radius);

  virtual void setRadius(float v) {
    radius = v;
  }

  inline float getRadius() {
    return radius;
  }
};

#endif // REGION_H
