#ifndef NODECONNECTION_H
#define NODECONNECTION_H

#include <QObject>
#include <QTimer>
#include <QDateTime>
#include "NetDataStream.h"

class NodeConnection : public NetDataStream
{
    Q_OBJECT

public:
    NodeConnection(ConnectionPoint point, QObject *parent = 0);
    ~NodeConnection();

private slots:
    void ping();

signals:
    void ConnectionClosed(NodeConnection *);

private:
    QTimer *_ping_timer;
    QDateTime _last_activity;
};

#endif // NODECONNECTION_H
