#ifndef TCPSTREAM_H
#define TCPSTREAM_H

#include <QTcpSocket>

#include <core/types/ConnectionPoint.h>
#include <core/IObservableDataStream.h>
#include <core/ISubject.h>
#include <core/SerializableEntityFactory.h>
#include <core/transport/TransportTransaction.h>
#include <core/MemoryCache.h>
#include <core/net/NetDataStreamException.h>

class TcpStream :
        public QObject,
        public IObservableDataStream
{
    Q_OBJECT

public:
    TcpStream(ConnectionPoint point);
    TcpStream(QTcpSocket *socket);
    ~TcpStream();

    // IDataStream interface
public:
    void open() override;
    void close() override;
    void read(IJsonSerializable *data) override;
    void write(IJsonSerializable *data) override;

private slots:
    void readData();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError error);

signals:
    void Disconnected(TcpStream *);

private:
    void writeTransportBlock(TransportDataBlock *block);
    void initConnections();

    QTcpSocket *_socket;
    QByteArray _buffer;
    QDataStream _stream;
    SerializableEntityFactory _entity_factory;
    MemoryCache _transaction_cache;
    ConnectionPoint _point;
};

#endif // TCPSTREAM_H
