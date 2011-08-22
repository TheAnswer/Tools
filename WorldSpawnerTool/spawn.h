#ifndef SPAWN_H
#define SPAWN_H

class Spawn {
protected:
    float worldX, worldY, worldZ;
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

    inline float getWorldX() {
        return worldX;
    }

    inline float getWorldY() {
        return worldY;
    }

    inline float getWorldZ() {
        return worldZ;
    }
};

#endif // SPAWN_H
