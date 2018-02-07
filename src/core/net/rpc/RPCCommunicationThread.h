#ifndef RPCCOMMUNICATIONTHREAD_H
#define RPCCOMMUNICATIONTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include "RPCRequest.h"
#include "RPCResponse.h"
#include "controllers/IAbstractRpcController.h"

///
/// \brief The RPCCommunicationThread class
///
class RPCCommunicationThread : public QThread
{
    Q_OBJECT

public:
    RPCCommunicationThread(QTcpSocket *socket, QObject *parent = 0);

    void setControllers(QList<IAbstractRpcController *> &controller) { _controllers = controller; }

signals:
    void finish(RPCCommunicationThread *);

    // QThread interface
protected:
    void run() override;

private:
    ///
    /// \brief getController возвращает контроллер из коллекции по его имени <i>name</i>.
    /// \param name Наименование контроллера
    /// \return
    ///
    IAbstractRpcController *getController(QString name);

    QTcpSocket *_socket;
    QList<IAbstractRpcController *> _controllers;
};

#endif // RPCCOMMUNICATIONTHREAD_H
