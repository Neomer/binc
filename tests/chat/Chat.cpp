#include "Chat.h"
#include <QDebug>
#include "NetMessage.h"

Chat::Chat()
{
    Context::Instance().consoleInput()->subscribe(this);
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
        Context::Instance().network()->write(&msg);
    }

}
