#ifndef NETDATABLOCK_H
#define NETDATABLOCK_H

#include <core/IHashedDataBlock.h>
#include <core/types/ConnectionPoint.h>

class NetDataBlock : public IHashedDataBlock
{
public:
    NetDataBlock();
    NetDataBlock(QByteArray data);

    void setPoint(ConnectionPoint value) { _point = value; }
    ConnectionPoint getPoint() { return _point; }

private:
    ConnectionPoint _point;
};

#endif // NETDATABLOCK_H
