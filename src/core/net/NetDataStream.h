#ifndef NETDATASTREAM_H
#define NETDATASTREAM_H

#include <QObject>
#include <QTcpSocket>
#include <core/types/ConnectionPoint.h>
#include <core/ISubject.h>
#include <core/IDataStream.h>
#include <core/transport/TransportTransaction.h>
#include <core/MemoryCache.h>
#include "NetDataBlock.h"

#define NET_BUFFER_SIZE         10240

class NetDataStream : public QObject, public IDataStream, public ISubject
{
    Q_OBJECT

public:
    NetDataStream(ConnectionPoint point, QObject *parent = 0);
    NetDataStream(QTcpSocket *socket);
    ~NetDataStream();

    void setPort(quint16 value) { _point.setPort(value); }

    void open() override;
    void close() override;
    void read(IJsonSerializable *data) override;
    void write(IJsonSerializable *data) override;

private slots:
    void readData();

private:
    QTcpSocket *_socket;
    ConnectionPoint _point;
    char _data_buffer[NET_BUFFER_SIZE];
};

#endif // NETDATASTREAM_H
