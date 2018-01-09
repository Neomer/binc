#ifndef RPCCOMMUNICATIONTHREAD_H
#define RPCCOMMUNICATIONTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include "RPCRequest.h"


///
/// \brief The RPCCommunicationThread class
///
class RPCCommunicationThread : public QThread
{
    Q_OBJECT

public:
    RPCCommunicationThread(QTcpSocket *socket, QObject *parent = 0);

signals:
    void finish(RPCCommunicationThread *);

    // QThread interface
protected:
    void run() override;

// Функции доступные для RPC вызовов
private slots:
    ///
    /// \brief nodes функция возвращает список известных нодов
    ///
    void nodes(RPCRequest *request);

private:
    QTcpSocket *_socket;
};

#endif // RPCCOMMUNICATIONTHREAD_H
