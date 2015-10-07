#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <QTextStream>

#include "node.h"

class Composite : public Node
{
public:
    Composite(Node *parent = 0) : Node(parent) {}
    Composite(const QMap<QString, QVariant> &data, Node *parent = 0)
        : Node(data, parent) {}
    virtual ~Composite() {}

    QTextStream& write(QTextStream& stream) const
    {
        stream << "\t{\"" << id().toString()
               << "\", \"" << fName().toString()
               << "\", \"" << parentID().toString();
        if (name().toString() == "Sequence")
            stream << "\", SEQUENCEBEHAVIOR},\n";
        else if (name().toString() == "Selector")
            stream << "\", SELECTORBEHAVIOR},\n";
        else if (name().toString() == "SequenceParallel")
            stream << "\", PARALLELSEQUENCEBEHAVIOR},\n";
        else if (name().toString() == "SelectorParallel")
            stream << "\", PARALLELSELECTORBEHAVIOR},\n";
        else if (name().toString() == "SequenceNonDeterministic")
            stream << "\", NONDETERMINISTICSEQUENCEBEHAVIOR},\n";
        else if (name().toString() == "SelectorNonDeterministic")
            stream << "\", NONDETERMINISTICSELECTORBEHAVIOR},\n";

        return Node::write(stream);
    }

private:
};

#endif // COMPOSITE_H
