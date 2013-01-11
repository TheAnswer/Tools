#include "region.h"
#include "mainwindow.h"
#include <QBrush>
#include <QPen>
#include <QTextStream>

Region::Region(qreal radius) : QGraphicsEllipseItem(-radius/2, -radius/2, radius, radius) {
    regionShape = Circle;
    this->radius = radius;
    this->height = 0;
    this->width = 0;
    setFlag(QGraphicsItem::ItemIsSelectable, true);

    QBrush brush(Qt::Dense7Pattern);
    brush.setColor(Qt::yellow);

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::yellow);
    pen.setWidthF(1);

    setBrush(brush);
    setPen(pen);
}

Region::Region(qreal height, qreal width) : QGraphicsRectItem(-width/2, -height/2, width, height) {
    regionShape = Rectangle;
    this->radius = 0;
    this->height = height;
    this->width = width;
    setFlag(QGraphicsItem::ItemIsSelectable, true);

    QBrush brush(Qt::Dense7Pattern);
    brush.setColor(Qt::yellow);

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::yellow);
    pen.setWidthF(1);

    setBrush(brush);
    setPen(pen);
}

void Region::setBrush(const QBrush &brush) {
    QGraphicsRectItem::setBrush(brush);
    QGraphicsEllipseItem::setBrush(brush);
}

void Region::setPen(const QPen &pen) {
    QGraphicsRectItem::setPen(pen);
    QGraphicsEllipseItem::setPen(pen);
}

void Region::setFlag(GraphicsItemFlag flag, bool enabled) {
    QGraphicsRectItem::setFlag(flag, enabled);
    QGraphicsEllipseItem::setFlag(flag, enabled);
}

void Region::setToolTip(const QString &toolTip) {
    QGraphicsRectItem::setToolTip(toolTip);
    QGraphicsEllipseItem::setToolTip(toolTip);
}

QGraphicsScene *Region::scene() const {
    if (regionShape == Rectangle) {
        return QGraphicsRectItem::scene();
    } else {
        return QGraphicsEllipseItem::scene();
    }
}

bool Region::isSelected() const {
    if (regionShape == Rectangle) {
        return QGraphicsRectItem::isSelected();
    } else {
        return QGraphicsEllipseItem::isSelected();
    }
}

QGraphicsItem *Region::getQGraphicsItem() {
    if (regionShape == Rectangle) {
        return (QGraphicsItem*)((QGraphicsRectItem*)this);
    } else {
        return (QGraphicsItem*)((QGraphicsEllipseItem*)this);
    }
}

void Region::setSelected(bool selected) {
    if (regionShape == Rectangle) {
        QGraphicsRectItem::setSelected(selected);
    } else {
        QGraphicsEllipseItem::setSelected(selected);
    }
}

void Region::setPos(qreal ax, qreal ay) {
    if (regionShape == Rectangle) {
        QGraphicsRectItem::setPos(ax, ay);
    } else {
        QGraphicsEllipseItem::setPos(ax, ay);
    }
}

void Region::setRect(qreal ax, qreal ay, qreal w, qreal h) {
    if (regionShape == Rectangle) {
        QGraphicsRectItem::setRect(ax, ay, w, h);
    } else {
        QGraphicsEllipseItem::setRect(ax, ay, w, h);
    }
}

void Region::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    if (regionShape == Rectangle) {
        QGraphicsRectItem::paint(painter, option, widget);
    } else {
        QGraphicsEllipseItem::paint(painter, option, widget);
    }
}

inline void Region::update(qreal x, qreal y, qreal width, qreal height) {
    if (regionShape == Rectangle) {
        QGraphicsRectItem::update(x, y, width, height);
    } else {
        QGraphicsEllipseItem::update(x, y, width, height);
    }
}
