#ifndef SPAWN_H
#define SPAWN_H

#include <QString>

class Spawn {
protected:
    float worldX, worldY, worldZ;
    float oW, oX, oY, oZ;

    QString sharedTemplate;
public:
    Spawn();

    virtual void setWorldX(float v) {
        worldX = v;
    }

    virtual void setWorldY(float v) {
        worldY = v;
    }

    virtual void setWorldZ(float z) {
        worldZ = z;
    }

    void setSharedTemplate(const QString& file) {
        sharedTemplate = file;
    }

    void setDirW(float v) {
        oW = v;
    }

    void setDirX(float v) {
        oX = v;
    }

    void setDirY(float v) {
        oY = v;
    }

    void setDirZ(float v) {
        oZ = v;
    }

    virtual QString getSharedTemplate() {
        return sharedTemplate;
    }

    inline float getWorldX() {
        return worldX;
    }

    inline float getWorldY() {
        return worldY;
    }

    inline float getWorldZ() {
        return worldZ;
    }

    inline float getDirX() {
        return oX;
    }

    inline float getDirW() {
        return oW;
    }

    inline float getDirZ() {
        return oZ;
    }

    inline float getDirY() {
        return oY;
    }
};

#endif // SPAWN_H
