#include "composite.h"

Composite::Composite(Composite *parent)
    : Behavior(parent) {}

Composite::Composite(const QMap<QString, QVariant> &data, Composite *parent)
    : Behavior(data, parent) {}

Composite::~Composite()
{
    qDeleteAll(this->children);
}

