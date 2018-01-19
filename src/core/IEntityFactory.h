#ifndef IENTITYFACTORY_H
#define IENTITYFACTORY_H

#include <core/IEntity.h>

class IEntityFactory
{
public:
    virtual IEntity *createEntity(QString name) = 0;
};

#endif // IENTITYFACTORY_H
