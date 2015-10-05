#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "node.h"

class Composite : public Node
{
public:
    Composite(Node *parent = 0) : Node(parent) {}
    Composite(const QMap<QString, QVariant> &data, Node *parent = 0)
        : Node(data, parent) {}
    virtual ~Composite() {}

private:
};

#endif // COMPOSITE_H
