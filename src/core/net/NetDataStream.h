#ifndef NETDATASTREAM_H
#define NETDATASTREAM_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include "../IDataStream.h"

class NetDataStream : public QObject, public IDataStream
{
    Q_OBJECT

public:
    NetDataStream(QHostAddress address);
    NetDataStream(QTcpSocket *socket);
    ~NetDataStream();

    void setPort(quint16 value) { _port = value; }

    void open() override;
    void close() override;
    void read(IDataBlock *data) override;
    qint64 write(const char *data, qint64 len) override;

private:
    QTcpSocket *_socket;
    QHostAddress _remoteHost;
    quint16 _port;

};

#endif // NETDATASTREAM_H
