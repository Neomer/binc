#ifndef TCPSTREAM_H
#define TCPSTREAM_H

#include <QTcpSocket>

#include <core/IDataStream.h>
#include <core/ISubject.h>
#include <core/SerializableEntityFactory.h>
#include <core/transport/TransportTransaction.h>
#include <core/MemoryCache.h>

class TcpStream :
        public QObject,
        public IDataStream,
        public ISubject
{
    Q_OBJECT

public:
    TcpStream();
    ~TcpStream();

    // IDataStream interface
public:
    void open() override;
    void close() override;
    void read(IJsonSerializable *data) override;
    void write(IJsonSerializable *data) override;

private slots:
    void readData();

private:
    QTcpSocket *_socket;
    QByteArray _buffer;
    QDataStream _stream;
    SerializableEntityFactory _entity_factory;
    MemoryCache _transaction_cache;
};

#endif // TCPSTREAM_H
