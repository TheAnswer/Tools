#ifndef CHECK_H
#define CHECK_H

#include "leaf.h"

class Node;

class Check : public Leaf
{
public:
    Check(Node *parent = 0)
        : Leaf(parent) {}
    Check(const QMap<QString, QVariant> &data, Node *parent = 0)
        : Leaf(data, parent) {}

signals:

public slots:
};

#endif // CHECK_H
