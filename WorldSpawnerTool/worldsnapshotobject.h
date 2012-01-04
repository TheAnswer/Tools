#ifndef WORLDSNAPSHOTOBJECT_H
#define WORLDSNAPSHOTOBJECT_H

#include <QGraphicsRectItem>
#include "spawn.h"

class WorldSnapshotObject : public QObject, public QGraphicsRectItem, public Spawn {
    Q_OBJECT

    unsigned int wsID;

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

public:
    WorldSnapshotObject(int snapshotID, const QString& sharedTemplate);

    unsigned int getSnapshotID() {
        return wsID;
    }

public slots:
    void show3dModel();
};

#endif // WORLDSNAPSHOTOBJECT_H
