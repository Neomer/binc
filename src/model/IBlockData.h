#ifndef IBLOCKDATA_H
#define IBLOCKDATA_H

#include <core/IJsonSerializable.h>

class IBlockData : public IJsonSerializable
{
public:
    IBlockData();

    // IJsonSerializable interface
public:
    void serialize(QJsonObject &out) override;
    void deserialize(QJsonObject &in) override;
};

#endif // IBLOCKDATA_H
