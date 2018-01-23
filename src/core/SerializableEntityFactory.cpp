#include "SerializableEntityFactory.h"
#include <model/Block.h>

SerializableEntityFactory::SerializableEntityFactory()
{

}

bool SerializableEntityFactory::IsBlock(IEntity *entity)
{
    return entity->getEntityName() == "Block";
}

IEntity *SerializableEntityFactory::createEntity(QString name)
{
    if (name == "Block")
        return new Block();
    else
        return 0;
}
