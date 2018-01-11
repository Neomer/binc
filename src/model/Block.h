#ifndef BLOCK_H
#define BLOCK_H

#include <core/IJsonSerializable.h>
#include <core/types/Guid.h>
#include <core/types/Version.h>
#include <QList>
#include <model/Deal.h>

class Block : public IJsonSerializable
{
public:
    Block();

    void addDeal(Deal *value) { _deals << value; }

    Guid getBlockId() { return _block_id; }
    void setBlockId(Guid value) { _block_id = value; }

    Version getVersion() { return _version; }
    void setVersion(Version value) { _version = value; }

    Guid getPreviousBlock() { return _previous_block; }
    void setPreviousBlock(Guid value) { _previous_block = value; }

    // IJsonSerializable interface
public:
    void serialize(QJsonObject &out) override;
    void deserialize(QJsonObject &in) override;

private:
    Guid _block_id;
    Version _version;
    Guid _previous_block;
    QList<Deal *> _deals;
};

#endif // BLOCK_H
