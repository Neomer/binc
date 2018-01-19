#ifndef SERIALIZABLEENTITYFACTORY_H
#define SERIALIZABLEENTITYFACTORY_H

#include <core/IEntityFactory.h>

class SerializableEntityFactory : public IEntityFactory
{
public:
    SerializableEntityFactory();

    static bool IsBlock(IEntity *entity);

    // IEntityFactory interface
public:
    IEntity *createEntity(QString name) override;
};

#endif // SERIALIZABLEENTITYFACTORY_H
