#ifndef NODECONNECTIONPOINT_H
#define NODECONNECTIONPOINT_H

#include <QTcpServer>

#include <core/ISubject.h>
#include <core/net/TcpStream.h>
#include <core/net/NetDataStreamException.h>

///
/// \brief NodeConnectionPoint класс реализующий точку подключения для P2P-сети. Подключения выполняются удаленной машиной с помощью класса TcpStream.
///
class NodeConnectionPoint : public QObject, public ISubject
{
    Q_OBJECT

public:
    ///
    /// \brief NodeConnectionPoint инициализирует сервер
    /// \param parent
    ///
    NodeConnectionPoint(QObject *parent = 0);
    ///
    /// \brief open открывает прослушивание порта.
    ///
    void open();
    ///
    /// \brief close Закрывает прослушивание порта.
    ///
    void close();

private slots:
    void onConnectionAccept();

private:
    QTcpServer _server;
};

#endif // NODECONNECTIONPOINT_H
