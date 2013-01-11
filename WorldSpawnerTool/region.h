#ifndef REGION_H
#define REGION_H

#include <QGraphicsEllipseItem>
#include "spawn.h"

class Region : public QGraphicsEllipseItem, public QGraphicsRectItem, public Spawn {
protected:
  float radius;
  float height;
  float width;
public:
  enum RegionShape {
      Circle,
      Rectangle
  };
protected:
  RegionShape regionShape;

public:
  Region(qreal radius);
  Region(qreal height, qreal width);

  inline float getRadius() {
    return radius;
  }

  inline float getWidth() {
    return width;
  }

  inline float getHeight() {
    return height;
  }

  void setBrush(const QBrush &brush);
  void setPen(const QPen &pen);
  void setFlag(GraphicsItemFlag flag, bool enabled = true);
  void setToolTip(const QString &toolTip);
  QGraphicsScene *scene() const;
  bool isSelected() const;
  QGraphicsItem *getQGraphicsItem();
  void setSelected(bool selected);
  void setPos(qreal ax, qreal ay);
  void setRect(qreal ax, qreal ay, qreal w, qreal h);
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
  inline void update(qreal x, qreal y, qreal width, qreal height);
};

#endif // REGION_H
