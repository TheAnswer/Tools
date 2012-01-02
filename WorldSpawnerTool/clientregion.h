#ifndef CLIENTREGION_H
#define CLIENTREGION_H

#include "region.h"

class ClientRegion : public Region {
  QString name;
public:
  ClientRegion(const QString& name);
};

#endif // CLIENTREGION_H
