#include "Chat.h"
#include <QDebug>
#include <model/Block.h>
#include <core/SerializableEntityFactory.h>

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
        Block d;
        d.setId(Guid::randomGuid());
        d.setPreviousBlock(Guid::randomGuid());
        d.setVersion(Version(1, 0));
        d.setNonce(QString((const char *)data).toInt());

    }

}
