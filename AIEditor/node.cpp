#include "node.h"

Node::Node(Node *parent)
    : TreeItem(parent) {}

Node::Node(const QMap<QString, QVariant> &data, Node *parent)
    : TreeItem(data, parent) {}

Node::~Node()
{
    qDeleteAll(this->children);
}

