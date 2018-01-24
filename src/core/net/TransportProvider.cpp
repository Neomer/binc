#include "TransportProvider.h"
#include <core/net/UdpStream.h>
#include <core/JsonSerializableEntity.h>
#include <core/Context.h>
#include <model/Block.h>

TransportProvider::TransportProvider() :
    ISubject()
{

}

void TransportProvider::add(IObservableDataStream *stream)
{
    stream->subscribe(this);
    try
    {
        stream->open();
    }
    catch (UdpStreamException &ex)
    {
        stream->unsubscribe(this);
        return;
    }
    _streams << stream;
}

void TransportProvider::write(IJsonSerializable *data)
{
    foreach (auto stream, _streams)
    {
        stream->write(data);
    }
}

void TransportProvider::update(const Guid &subject, void *data)
{
    Q_UNUSED(subject);

    if (!data) return;
    JsonSerializableEntity *entity = static_cast<JsonSerializableEntity *>(data);
    if (SerializableEntityFactory::IsBlock(entity))
    {
        Block *b = static_cast<Block *>(entity);
        ISubject::update(b);
    }
    else // Unknown format
    {
        return;
    }
}
