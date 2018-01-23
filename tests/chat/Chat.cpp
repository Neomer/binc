#include "Chat.h"
#include <QDebug>
#include <model/Block.h>
#include <core/SerializableEntityFactory.h>

Chat::Chat()
{
    _stream = new UdpStream();
    _stream->subscribe(this);
    Context::Instance().consoleInput()->subscribe(this);
}

Chat::~Chat()
{
    delete _stream;
}

void Chat::run()
{
    qDebug() << "Running Chat...";
    _stream->open();
}

void Chat::update(const Guid &subject, void *data)
{
    if (Guid::isEqual(subject, Context::Instance().consoleInput()->guid()))
    {
        Block d;
        d.setPreviousBlock(Guid::randomGuid());
        d.setVersion(Version(1, 0));
        d.setNonce(QString((const char *)data).toInt());

        _stream->write(&d);
    }
    else if (Guid::isEqual(subject, _stream->guid()))
    {
        if (SerializableEntityFactory::IsBlock(static_cast<IEntity *>(data)))
        {
            Block *b = static_cast<Block *>(data);
            qDebug() << "New block!"
                     << "\nBlock ID:" << b->getId().toString()
                     << "\nPrevious Block:" <<  b->getPreviousBlock().toString()
                     << "\nCreation Time:" <<  b->getCreationTime().toString("yyyy-MM-dd hh:mm:ss")
                     << "\nNonce:" <<  b->getNonce()
                     << "\nVersion:" <<  b->getVersion().toString();
        }


    }

}
