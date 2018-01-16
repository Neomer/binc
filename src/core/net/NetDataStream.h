#ifndef NETDATASTREAM_H
#define NETDATASTREAM_H

#include <QObject>
#include <QTcpSocket>
#include <core/types/ConnectionPoint.h>
#include "../IDataStream.h"

class NetDataStream : public QObject, public IDataStream
{
    Q_OBJECT

public:
    NetDataStream(ConnectionPoint point, QObject *parent = 0);
    NetDataStream(QTcpSocket *socket);
    ~NetDataStream();

    void setPort(quint16 value) { _point.setPort(value); }

    void open() override;
    void close() override;
    void read(IDataBlock *data) override;
    void write(IDataBlock *data) override;

private:
    QTcpSocket *_socket;
    ConnectionPoint _point;

};

#endif // NETDATASTREAM_H
