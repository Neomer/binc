#include "SerializableEntityFactory.h"
#include <model/Block.h>
#include "../../tests/chat/NetMessage.h"

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
    if (name == "NetMessage")
        return new NetMessage();
    else
        return 0;
}
