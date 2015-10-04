#ifndef ACTION_H
#define ACTION_H

#include "behavior.h"

class Action : public Behavior
{
public:
    Action(Composite *parent = 0)
        : Behavior(parent) {}
    Action(const QMap<QString, QVariant> &data, Composite *parent = 0)
        : Behavior(data, parent) {}

signals:

public slots:
};

#endif // ACTION_H
