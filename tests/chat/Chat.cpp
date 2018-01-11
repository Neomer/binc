#include "Chat.h"
#include <QDebug>
#include <model/Deal.h>

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
        bool ok = true;

        Deal d;
        d.setRecipient(Guid::randomGuid());
        d.setSender(Guid::randomGuid());
        d.setAmount(QString((const char *)data).toDouble(&ok));
        if (!ok)
        {
            throw BaseException("Wrong amount format!");
        }
        d.setReward(d.getAmount() * 0.01);

        UdpDataBlock block;
        block.setData(IJsonSerializable::toString(&d).toUtf8());
        _stream->write(&block);
    }
    else if (Guid::isEqual(subject, _stream->guid()))
    {
        UdpDataBlock *block = static_cast<UdpDataBlock *>(data);
        qDebug() << "From" << block->remoteAddress().toString() << ":" << QString::fromLatin1(block->data());
    }

}
