#include "Chat.h"
#include <QDebug>

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
    _stream->open();
}

void Chat::update(const Guid &subject, void *data)
{
    if (Guid::isEqual(subject, Context::Instance().consoleInput()->guid()))
    {
        UdpDataBlock block;
        block.setData(QByteArray((const char *)data));
        _stream->write(&block);
    }
    else if (Guid::isEqual(subject, _stream->guid()))
    {
        UdpDataBlock *block = static_cast<UdpDataBlock *>(data);
        qDebug() << "From" << block->remoteAddress().toString() << ":" << QString::fromLatin1(block->data());
    }

}
