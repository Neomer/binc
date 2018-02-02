#include "Chat.h"
#include <QDebug>
#include "NetMessage.h"
#include <core/net/Net.h>

Chat::Chat()
{
    Context::Instance().consoleInput()->subscribe(this);
    Net::Instance().subscribe(this);
}

Chat::~Chat()
{

}

void Chat::run()
{
    qDebug() << "Running Chat...";
}

void Chat::update(const Guid &subject, void *data)
{
    if (Guid::isEqual(subject, Context::Instance().consoleInput()->guid()))
    {
        NetMessage msg;
        msg.setId(Guid::randomGuid());
        msg.setMessage(QString((const char *)data));
        Net::Instance().write(&msg);
    }
    else if (Guid::isEqual(subject, Net::Instance().guid()))
    {
        NetMessage *msg = static_cast<NetMessage *>(data);
        qDebug() << "receive: " << msg->getMessage();
    }

}
