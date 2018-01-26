#ifndef TCPSTREAMPROVIDER_H
#define TCPSTREAMPROVIDER_H

#include <QThread>

#include <core/ISubject.h>
#include <core/net/NetDataStreamException.h>

///
/// \brief TcpStreamProvider класс в отдельном потоке осуществляет попытки подключения к известным узлам сети. При удачном подключении создается экзмеляр TcpStream для этого подключения.
///
class TcpStreamProvider : public QThread, public ISubject
{
    Q_OBJECT

public:
    TcpStreamProvider();
    ///
    /// \brief start запускает процедуру поиска подключений
    ///
    void start();
    ///
    /// \brief terminate останавливает поиск новых подключений
    ///
    void terminate();

    // QThread interface
protected:
    void run() override;

private:
    volatile bool _run;
};

#endif // TCPSTREAMPROVIDER_H
