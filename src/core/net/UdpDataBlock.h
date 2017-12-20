#ifndef UDPDATABLOCK_H
#define UDPDATABLOCK_H

#include <core/IDataBlock.h>
#include <QHostAddress>

class UdpDataBlock : public IDataBlock
{
public:
    UdpDataBlock();
    UdpDataBlock(QByteArray data);

    QHostAddress remoteAddress() { return _remoteAddress; }
    void setRemoteAddress(QHostAddress value) { _remoteAddress = value; }

    quint16 remotePort() { return _remotePort; }
    void setRemotePort(quint16 value) { _remotePort = value; }

private:
    QHostAddress _remoteAddress;
    quint16 _remotePort;
};

#endif // UDPDATABLOCK_H
