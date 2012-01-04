#include "worldsnapshotobject.h"
#include <QPen>
#include <QColor>
#include "mainwindow.h"
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>

WorldSnapshotObject::WorldSnapshotObject(int snapshotID, const QString& sharedTemplate) {
    //QGraphicsRectItem* rec = new QGraphicsRectItem(sceneX, sceneY, 0.5, 0.5);
    //set
    QPen pen = this->pen();

    wsID = snapshotID;
    this->sharedTemplate = sharedTemplate;

    QColor color(0xE0, 0xFF, 0xFF, 50);
    //color.setGreen();
    pen.setColor(color);
    pen.setWidthF(0.5);

    setToolTip(sharedTemplate);

    setPen(pen);

    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void WorldSnapshotObject::contextMenuEvent(QGraphicsSceneContextMenuEvent *event) {
    event->accept();

    QMenu menu;
    menu.addAction("View 3d model", this, SLOT(show3dModel()));
    menu.exec(event->screenPos());
}

void WorldSnapshotObject::show3dModel() {
    MainWindow::instance->startSwgOSG(sharedTemplate);
}
