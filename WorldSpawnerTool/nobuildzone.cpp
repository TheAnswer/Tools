/*
 * nobuildzone.cpp
 *
 *  Created on: 02/07/2010
 *      Author: TheAnswer
 */

#include <QBrush>
#include <QPen>
#include "nobuildzone.h"

NoBuildZone::NoBuildZone(qreal radius) : Region(radius) {
    QBrush brush;
    brush.setColor(Qt::red);

    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidthF(1);

    setBrush(brush);
    setPen(pen);
}
