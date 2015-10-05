#ifndef LEAF_H
#define LEAF_H

#include "treeitem.h"

class Node;

class Leaf : public TreeItem
{
public:
    Leaf(Node *parent = 0)
        : TreeItem(parent) {}
    Leaf(const QMap<QString, QVariant> &data, Node *parent = 0)
        : TreeItem(data, parent) {}

};

#endif // LEAF_H
