#include "Chat.h"
#include <QDebug>
#include <model/Block.h>

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

        UdpDataBlock block;
        block.setData(IJsonSerializable::toString(&d).toUtf8());
        _stream->write(&block);
    }
    else if (Guid::isEqual(subject, _stream->guid()))
    {
        UdpDataBlock *block = static_cast<UdpDataBlock *>(data);
        qDebug() << "From" << block->remoteAddress().toString() << ":" << QString::fromUtf8(block->data());
        Block d;
        IJsonSerializable::fromString(&d, block->data());
    }

}
