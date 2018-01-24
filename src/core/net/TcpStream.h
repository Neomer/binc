#ifndef TCPSTREAM_H
#define TCPSTREAM_H

#include <QTcpSocket>

#include <core/IDataStream.h>
#include <core/ISubject.h>

class TcpStream : public QObject, public IDataStream, public ISubject
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

private:
    QTcpSocket *_socket;
};

#endif // TCPSTREAM_H
