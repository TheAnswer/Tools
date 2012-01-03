#ifndef STATICSPAWN_H
#define STATICSPAWN_H

#include <QGraphicsEllipseItem>
#include <QTextStream>
#include <QSharedData>
#include "spawn.h"

class StaticSpawn : public QObject, public QGraphicsEllipseItem, public Spawn  {
    Q_OBJECT
protected:
    QString mobile;
    unsigned int respawnTimer;
    float heading;
    unsigned long long parentID;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant& value);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

public slots:
    void show3dModel();

public:
    StaticSpawn();

    QString toLua();

    void setWorldX(float v);
    void setWorldY(float v);

    void setRespawnTimer(unsigned int timer);
    void setHeading(float head);
    void setParentID(unsigned long long id);

    inline void setMobile(const QString& mob) {
        mobile = mob;
    }

    inline QString getMobile() const {
        return mobile;
    }

    inline unsigned int getRespawnTimer() {
        return respawnTimer;
    }

    inline float getHeading() {
        return heading;
    }

    inline unsigned long long getParentID() {
        return parentID;
    }

    QString getListWidgetItem() {
        QString text;
        QTextStream stream(&text);

        stream << "x:" << worldX << " z:" << worldZ << " y:" << worldY << endl;
        stream << "respawn: " << respawnTimer << " heading: " << heading << endl;
        stream << "parentID: " << parentID;

        return text;
    }

};

#endif // STATICSPAWN_H
