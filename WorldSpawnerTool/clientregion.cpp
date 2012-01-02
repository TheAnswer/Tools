#include "clientregion.h"
#include <QBrush>
#include <QPen>

ClientRegion::ClientRegion(const QString& name) : Region(15) {
  this->name = name;

  setToolTip(name);

  QBrush brush(Qt::FDiagPattern);
  brush.setColor(Qt::magenta);

  QPen pen;
  pen.setColor(Qt::magenta);
  pen.setWidthF(1);

  setBrush(brush);
  setPen(pen);

  //setAcceptDrops(true);
  setFlag(QGraphicsItem::ItemIsSelectable, true);
  setFlag(QGraphicsItem::ItemIsMovable, false);
  setFlag(QGraphicsItem::ItemSendsGeometryChanges, false);
}
