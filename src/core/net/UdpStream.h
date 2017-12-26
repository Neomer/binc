#ifndef UDPSTREAM_H
#define UDPSTREAM_H

#include <core/IDataStream.h>
#include <core/ISubject.h>
#include <QUdpSocket>
#include <QHostAddress>
#include <QThread>
#include "UdpDataBlock.h"
#include "UdpStreamException.h"

#define UDP_BUFFER_SIZE         1024

///
/// \brief The UdpStream class реализует функционал обмена информацией с помощью широковещательных запросов
///
class UdpStream : public QObject, public IDataStream, public ISubject
{
    Q_OBJECT

public:
    UdpStream();
    ~UdpStream();

    void setPort(quint16 value) { _port = value; }

    //IDataStream interface
    void close() override;
    void open() override;
    void read(IDataBlock *data) override;
    void write(IDataBlock *data) override;

private slots:
    void readDatagram();

private:
    QUdpSocket *_socket;
    quint16 _port;
    char _data_buffer[UDP_BUFFER_SIZE];
};

#endif // UDPSTREAM_H
