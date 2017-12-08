/*
 * Класс реализует протокол NAT-PMP.
 * По широковещательному каналу отправляется запрос на регистрацию пробороса порта до локальной машины
 * RFC 6886
 *
 * From RFC:
 * Port-mapping request
    0                   1                   2                   3
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   | Vers = 0      | OP = x        | Reserved                      |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   | Internal Port                 | Suggested External Port       |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   | Requested Port Mapping Lifetime in Seconds                    |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

  * Port-mapping response
    0                   1                   2                   3
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   | Vers = 0      | OP = 128 + x  | Result Code                   |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   | Seconds Since Start of Epoch                                  |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   | Internal Port                 | Mapped External Port          |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   | Port Mapping Lifetime in Seconds                              |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

*/

#include "PortMapping.h"
#include <QUdpSocket>
#include <QHostAddress>
#include <QDataStream>
#include "NetDataStreamException.h"

#define PMPPORT         5351

struct PMPResponse
{
    unsigned char Version;
    unsigned char OP;
    quint16 ResultCode;
    quint32 SecondsSinceEpoch;
    quint16 InternalPort;
    quint16 MappedPort;
    quint32 TTL;
};

PortMapping::PortMapping()
{

}

bool PortMapping::tryMapPort(quint16 internalPort, quint16 *mappedPort)
{
    QUdpSocket s;
    s.bind(PMPPORT);

    quint16 p = 65545;

    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);

    out << (char) 0; // Version
    out << (char) 1; // OP-code
    out << (quint16) 0; // Reserved
    out << (quint16) internalPort; // Internal Port
    out << (quint16) 0; // Suggested External Port
    out << (quint16) 86400; // Requested Port Mapping Lifetime in Secondss

    s.writeDatagram(data, QHostAddress::Broadcast, PMPPORT);
    qint64 len = 0;
    while (len < sizeof(PMPResponse))
    {
        if (!s.waitForReadyRead(1000))
        {
            throw NetDataStreamException(NetDataStreamException::enNDSE_Timeout, "Превышено время ожидания ответа!");
        }
        len += s.pendingDatagramSize();
    }
    data.resize(sizeof(PMPResponse));
    s.readDatagram(data.data(), data.size());

    QDataStream in(&data, QIODevice::ReadOnly);
    PMPResponse response;
    in >> response.Version;
    in >> response.OP;
    in >> response.ResultCode;
    in >> response.SecondsSinceEpoch;
    in >> response.InternalPort;
    in >> response.MappedPort;
    in >> response.TTL;

    *mappedPort = response.MappedPort;

    return true;
}
