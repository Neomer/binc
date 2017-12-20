#ifndef UDPSTREAM_H
#define UDPSTREAM_H

#include <core/IDataStream.h>
#include <QUdpSocket>
#include <QHostAddress>
#include "UdpStreamException.h"

///
/// \brief The UdpStream class реализует функционал обмена информацией с помощью широковещательных запросов
///
class UdpStream : public IDataStream
{
    Q_OBJECT

public:
    UdpStream();
    ~UdpStream();

    void setPort(quint16 value) { _port = value; }

    //IDataStream interface
    void close() override;
    void open() override;

    // QIODevice interface
protected:
    qint64 readData(char *data, qint64 maxlen) override;
    qint64 writeData(const char *data, qint64 len) override;

private slots:
    void readDatagram();

private:
    QUdpSocket *_socket;
    quint16 _port;
};

#endif // UDPSTREAM_H
