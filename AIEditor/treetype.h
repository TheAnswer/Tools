#ifndef TREETYPE_H
#define TREETYPE_H


class TreeType
{
public:
    TreeType();

    virtual bool isDecision() const { return false; }
    virtual bool isBehavior() const { return false; }

};

#endif // TREETYPE_H
