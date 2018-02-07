#include "TransportProvider.h"
#include <core/net/UdpStream.h>
#include <core/JsonSerializableEntity.h>
#include <core/Context.h>
#include <model/Block.h>

TransportProvider::TransportProvider() :
    QObject(),
    ISubject()
{

}

void TransportProvider::add(IObservableDataStream *stream)
{
    stream->subscribe(this);
    try
    {
        stream->open();
        connect(stream, SIGNAL(onConnectionClosed(IObservableDataStream*)), this, SLOT(onConnectionClosed(IObservableDataStream*)));
    }
    catch (UdpStreamException &ex)
    {
        stream->unsubscribe(this);
        return;
    }
    connect(stream, SIGNAL(onEntityReady(JsonSerializableIdentifyedEntity*)), this, SLOT(entityReady(JsonSerializableIdentifyedEntity*)));

    _streams << stream;
    emit streamCountChanged(_streams.count());
}

void TransportProvider::write(JsonSerializableIdentifyedEntity *data)
{
    foreach (auto stream, _streams)
    {
        try
        {
            stream->write(data);
        }
        catch (NetDataStreamException &ex)
        {
            qDebug() << ex.what();
            _streams.removeOne(stream);
        }
        catch (BaseException &ex)
        {
            qDebug() << ex.what();
        }
    }
}

void TransportProvider::update(const Guid &subject, void *data)
{
}

void TransportProvider::onConnectionClosed(IObservableDataStream *stream)
{
    _streams.removeOne(stream);
}

void TransportProvider::entityReady(JsonSerializableIdentifyedEntity *entity)
{
    // Проверяем на эхо-ответ
    if (_blocks.contains(entity->getId())) return;

    _blocks.add(entity);
    write(entity);
    emit onEntityReady(entity);
}
