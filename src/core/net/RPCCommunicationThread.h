#ifndef RPCCOMMUNICATIONTHREAD_H
#define RPCCOMMUNICATIONTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>

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

private:
    QTcpSocket *_socket;
};

#endif // RPCCOMMUNICATIONTHREAD_H
