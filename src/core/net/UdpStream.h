#ifndef UDPSTREAM_H
#define UDPSTREAM_H

#include <core/transport/TransportTransaction.h>
#include <core/MemoryCache.h>
#include <core/IObservableDataStream.h>
#include <core/SerializableEntityFactory.h>
#include <QUdpSocket>
#include <QHostAddress>
#include <QThread>
#include "UdpStreamException.h"

#define UDP_BUFFER_SIZE         1024

///
/// \brief The UdpStream class реализует функционал обмена информацией с помощью широковещательных запросов
/// При получении пакета данных он отправляется всем подписчикам. Отправляется (UdpDataBlock *)
///
class UdpStream : public IObservableDataStream
{
    Q_OBJECT

public:
    UdpStream();
    ~UdpStream();

    void setPort(quint16 value) { _port = value; }

    //IDataStream interface
    void close() override;
    void open() override;
    void read(IJsonSerializable *data) override;
    void write(IJsonSerializable *data) override;

private slots:
    void readDatagram();

private:
    QUdpSocket *_socket;
    quint16 _port;
    MemoryCache _transaction_cache;
    QByteArray _buffer;
    QDataStream _stream;
    SerializableEntityFactory _entity_factory;
};

#endif // UDPSTREAM_H
