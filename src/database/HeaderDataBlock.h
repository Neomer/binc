#ifndef HEADERDATABLOCK_H
#define HEADERDATABLOCK_H

#include "IDatabaseDataBlock.h"


class HeaderDataBlock : public IDatabaseDataBlock
{
public:
    HeaderDataBlock();

    void setBytesUsed(quint64 value) { _bytesUsed = value; }
    void addBytesUsed(quint64 value) { _bytesUsed += value; }
    qint64 bytesUsed() { return _bytesUsed; }

private:
    quint64 _bytesUsed;

    // IDatabaseDataBlock interface
public:
    void serialize(QDataStream &out) override;
    void deserialize(QDataStream &in) override;
    quint64 blockSize() override;
};

#endif // HEADERDATABLOCK_H
