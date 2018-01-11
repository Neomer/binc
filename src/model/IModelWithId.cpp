#include "IModelWithId.h"

IModelWithId::IModelWithId() :
    _id(Guid::randomGuid())
{

}

IModelWithId::IModelWithId(Guid id) :
    _id(id)
{

}
