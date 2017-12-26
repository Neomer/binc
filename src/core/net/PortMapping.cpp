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

struct PMPRequest
{
    unsigned char Version;
    unsigned char OP;
    quint16 Reserved;
    quint16 InternalPort;
    quint16 MappedPort;
    quint32 TTL;
};

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
    if (!s.bind(QHostAddress::Any, 15648))
    {
        throw NetDataStreamException(NetDataStreamException::enNDSE_PortIsBusy, "Port is busy!");
    }

    PMPRequest req;
    req.Version = 0;
    req.OP = 2;
    req.Reserved = 0;
    req.InternalPort = internalPort;
    req.MappedPort = internalPort;
    req.TTL = 120;

    QByteArray data;
    data.resize(sizeof(PMPRequest));
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out << req.Version; // Version
    out << req.OP; // OP-code
    out << req.Reserved; // Reserved
    out << req.InternalPort; // Internal Port
    out << req.MappedPort; // Suggested External Port
    out << req.TTL; // Requested Port Mapping Lifetime in Secondss

    s.writeDatagram(data, QHostAddress("192.168.18.1"), PMPPORT);
    qint64 len = 0;
    while (len < sizeof(PMPResponse))
    {
        if (!s.waitForReadyRead(1000))
        {
            throw NetDataStreamException(NetDataStreamException::enNDSE_Timeout, "Response timeout!");
        }
    }
    len = s.pendingDatagramSize();
    data.resize(sizeof(PMPResponse));
    data.clear();
    qint64 read = s.readDatagram(data.data(), data.size());
    if (!read)
    {
        throw NetDataStreamException(NetDataStreamException::enNDSE_Timeout, "Responce timeout!");
    }

    QDataStream in(&data, QIODevice::ReadOnly);
    PMPResponse response;
    in >> response.Version;
    in >> response.OP;
    in >> response.ResultCode;
    in >> response.SecondsSinceEpoch;
    in >> response.InternalPort;
    in >> response.MappedPort;
    in >> response.TTL;

    printf("Version: %d\n", response.Version);
    printf("OP: %d\n", response.OP);
    printf("Result code: %d\n", response.ResultCode);
    printf("SecondsSinceEpoch: %d\n", response.SecondsSinceEpoch);
    printf("InternalPort: %d\n", response.InternalPort);
    printf("MappedPort: %d\n", response.MappedPort);
    printf("TTL: %d\n", response.TTL);


    *mappedPort = response.MappedPort;

    return true;
}

//template<typename T>
//QByteArray PortMapping::mapType(PortMapping::T data)
//{

//}
