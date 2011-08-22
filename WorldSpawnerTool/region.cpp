#include "region.h"
#include <QBrush>
#include <QPen>

Region::Region(qreal radius) : QGraphicsEllipseItem(-radius/2, -radius/2, radius, radius) {
    setFlag(QGraphicsItem::ItemIsSelectable, true);

    QBrush brush(Qt::Dense7Pattern);
    brush.setColor(Qt::yellow);

    QPen pen;
    pen.setColor(Qt::yellow);
    pen.setWidthF(1.5);

    setBrush(brush);
    setPen(pen);

    //this->set
}
