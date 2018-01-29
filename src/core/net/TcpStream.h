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
#include <core/JsonSerializableEntity.h>

class TcpStream :
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
    void write(JsonSerializableIdentifyedEntity *data) override;

private slots:
    void readData();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError error);

signals:
    void Disconnected(TcpStream *);
    void PackageReceived(JsonSerializableEntity *);

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
