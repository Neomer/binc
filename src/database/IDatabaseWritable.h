#ifndef IDATABASEWRITABLE_H
#define IDATABASEWRITABLE_H

#include <core/IIdentifyed.h>
#include <core/IBinarySerializable.h>
#include <core/IEntity.h>

class IDatabaseWritable :
        public IIdentifyed,
        public IBinarySerializable
{
public:
    IDatabaseWritable();
};

#endif // IDATABASEWRITABLE_H
