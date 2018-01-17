#ifndef IIDENTIFYED_H
#define IIDENTIFYED_H

#include <core/types/Guid.h>

///
/// \brief IIdentifyed интерейс для реализации любой сущности имеющей идентификатор
///
class IIdentifyed
{
public:
    Guid getId() { return _id; }
    void setId(Guid value) { _id = value; }

private:
    Guid _id;
}

#endif // IIDENTIFYED_H
