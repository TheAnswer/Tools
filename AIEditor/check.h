#ifndef CHECK_H
#define CHECK_H

#include "behavior.h"

class Check : public Behavior
{
public:
    Check(Composite *parent = 0)
        : Behavior(parent) {}
    Check(const QMap<QString, QVariant> &data, Composite *parent = 0)
        : Behavior(data, parent) {}

signals:

public slots:
};

#endif // CHECK_H
