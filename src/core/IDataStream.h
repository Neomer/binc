#ifndef IDATASTREAM_H
#define IDATASTREAM_H

#include <QObject>
#include <QIODevice>
#include <core/IDataBlock.h>
#include <core/transport/TransportTransaction.h>
#include <core/JsonSerializableIdentifyedEntity.h>

///
/// \brief IDataStream интерфейс должны реализовывать классы, которые работают с потоками данных (UDP, TCP сокеты и пр.)
///
class IDataStream
{
public:
    ///
    /// \brief open Открывает поток данных
    ///
    virtual void open() = 0;
    ///
    /// \brief close Закрывает поток данных
    ///
    virtual void close() = 0;
    ///
    /// \brief write Записывает сериализуемый объект в поток
    /// \param data
    ///
    virtual void write(JsonSerializableIdentifyedEntity *data) = 0;
};

#endif // IDATASTREAM_H
