#ifndef DECISION_H
#define DECISION_H

#include "treetype.h"

class Node;

class Decision : public TreeType
{
public:
    Decision() : TreeType() {}
    virtual ~Decision() {}

    bool isDecision() const { return true; }

};

#endif // DECISION_H
