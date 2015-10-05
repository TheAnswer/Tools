#ifndef NODE_H
#define NODE_H

#include "treeitem.h"

class Node : public TreeItem
{
public:
    Node(Node *parent = 0);
    Node(const QMap<QString, QVariant> &data, Node *parent = 0);
    virtual ~Node();

    size_t count() const
    {
        return children.count();
    }

    TreeItem* get(const size_t index) const
    {
        return children.value(index);
    }

    bool insert(TreeItem *newChild, const size_t position = 0)
    {
        children.insert(position, newChild);
        if (children.at(position) != newChild) return false;
        return true;
    }

    bool insert(const size_t position, const size_t count)
    {
        if (position > (size_t)children.size()) return false;

        for (size_t row = 0; row < count; ++row)
            children.insert(position, new TreeItem(this));

        return true;
    }

    bool remove(const size_t position = 0)
    {
        TreeItem *childItem = children.at(position);
        children.removeAt(position);

        if (children.contains(childItem)) return false;
        return true;
    }

    bool remove(const size_t position, const size_t count)
    {
        if (position + count > (size_t)children.size()) return false;

        for (size_t row = 0; row < count; ++row)
            delete children.takeAt(position);

        return true;
    }

    size_t getIndex(TreeItem *child)
    {
        return (size_t)children.indexOf(child);
    }

private:
    QList<TreeItem*> children;

};

#endif // NODE_H
