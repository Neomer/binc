#ifndef IMODELWITHID_H
#define IMODELWITHID_H

#include <core/IJsonSerializable.h>
#include <core/types/Guid.h>

class IModelWithId : public IJsonSerializable
{
public:
    IModelWithId();
    IModelWithId(Guid id);

    Guid getId() { return _id; }
    void setId(Guid value) { _id = value; }

private:
    Guid _id;
};

#endif // IMODELWITHID_H
