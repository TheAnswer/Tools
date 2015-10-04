#ifndef ACTIONGROUPS_H
#define ACTIONGROUPS_H

#include <QActionGroup>

class BehaviorGroup : public QActionGroup
{
public:
    BehaviorGroup(QObject *parent = 0) : QActionGroup(parent) {}

    virtual bool isAction() const { return false; }
    virtual bool isCheck() const { return false; }
    virtual bool isComposite() const { return false; }
};

class ActionGroup : public BehaviorGroup
{
public:
    ActionGroup(QObject *parent = 0) : BehaviorGroup(parent) {}
    bool isAction() const { return true; }
};

class CheckGroup : public BehaviorGroup
{
public:
    CheckGroup(QObject *parent = 0) : BehaviorGroup(parent) {}
    bool isCheck() const { return true; }
};

class CompositeGroup : public BehaviorGroup
{
public:
    CompositeGroup(QObject *parent = 0) : BehaviorGroup(parent) {}
    bool isComposite() const { return true; }
};

#endif // ACTIONGROUPS_H

