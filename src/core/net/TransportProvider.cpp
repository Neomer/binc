#include "TransportProvider.h"
#include <core/net/UdpStream.h>
#include <core/SerializableEntity.h>
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

void TransportProvider::update(const Guid &subject, void *data)
{
    Q_UNUSED(subject);

    if (!data) return;
    SerializableEntity *entity = static_cast<SerializableEntity *>(data);
    if (SerializableEntityFactory::IsBlock(entity))
    {
        Block *b = static_cast<Block *>(entity);

    }
    else // Unknown format
    {
        return;
    }
}
