#ifndef ACTION_H
#define ACTION_H

#include "leaf.h"

class Node;

class Action : public Leaf
{
public:
    Action(Node *parent = 0)
        : Leaf(parent) {}
    Action(const QMap<QString, QVariant> &data, Node *parent = 0)
        : Leaf(data, parent) {}

signals:

public slots:
};

#endif // ACTION_H
