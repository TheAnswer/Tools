#ifndef ACTIONGROUPS_H
#define ACTIONGROUPS_H

#include <QActionGroup>

class TypeGroup : public QActionGroup
{
public:
    TypeGroup(QObject *parent = 0) : QActionGroup(parent) {}

    virtual bool isAction() const { return false; }
    virtual bool isCheck() const { return false; }
    virtual bool isComposite() const { return false; }
    virtual bool isNode() const { return false; }
    virtual bool isLeaf() const { return false; }
};

class ActionGroup : public TypeGroup
{
public:
    ActionGroup(QObject *parent = 0) : TypeGroup(parent) {}
    bool isAction() const { return true; }
};

class CheckGroup : public TypeGroup
{
public:
    CheckGroup(QObject *parent = 0) : TypeGroup(parent) {}
    bool isCheck() const { return true; }
};

class CompositeGroup : public TypeGroup
{
public:
    CompositeGroup(QObject *parent = 0) : TypeGroup(parent) {}
    bool isComposite() const { return true; }
};

class NodeGroup : public TypeGroup
{
public:
    NodeGroup(QObject *parent = 0) : TypeGroup(parent) {}
    bool isNode() const { return true; }
};

class LeafGroup : public TypeGroup
{
public:
    LeafGroup(QObject *parent = 0) : TypeGroup(parent) {}
    bool isLeaf() { return true; }
};

#endif // ACTIONGROUPS_H

