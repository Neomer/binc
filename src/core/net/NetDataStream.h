#ifndef NETDATASTREAM_H
#define NETDATASTREAM_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include "../IDataStream.h"

class NetDataStream : public IDataStream
{
    Q_OBJECT

public:
    NetDataStream(QHostAddress address);
    NetDataStream(QTcpSocket *socket);
    ~NetDataStream();

    void open(quint16 port = 0);
    void close();

protected:
    qint64 readData(char *data, qint64 maxlen);
    qint64 writeData(const char *data, qint64 len);

private:
    QTcpSocket *_socket;
    QHostAddress _remoteHost;
    quint16 _port;
};

#endif // NETDATASTREAM_H
