#include "cityregion.h"

#include <QBrush>
#include <QPen>

CityRegion::CityRegion(qreal radius) : Region(radius) {
    QBrush brush(Qt::FDiagPattern);
    brush.setColor(Qt::red);

    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidthF(1);

    setBrush(brush);
    setPen(pen);
}
