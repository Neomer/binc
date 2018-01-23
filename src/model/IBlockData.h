#ifndef IBLOCKDATA_H
#define IBLOCKDATA_H

#include <core/IJsonSerializable.h>

class IBlockData : public IJsonSerializable
{
public:
    IBlockData();

    // IJsonSerializable interface
public:
    void toJsonObject(QJsonObject &out) override;
    void fromJsonObject(QJsonObject &in) override;
};

#endif // IBLOCKDATA_H
