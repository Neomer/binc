#ifndef NODECONNECTION_H
#define NODECONNECTION_H

#include <QObject>
#include <QTimer>
#include <QDateTime>
#include "NetDataStream.h"

class NodeConnection : public QObject, public NetDataStream
{
    Q_OBJECT

public:
    NodeConnection(QObject *parent = 0);

private slots:
    void ping()

private:
    QTimer *_ping_timer;
};

#endif // NODECONNECTION_H
