#ifndef IDATASTREAM_H
#define IDATASTREAM_H

#include <QObject>
#include <QIODevice>
#include <core/IDataBlock.h>
#include <core/transport/TransportTransaction.h>
#include <core/IJsonSerializable.h>

class IDataStream
{
public:
    IDataStream();

    virtual void open() = 0;
    virtual void close() = 0;
    virtual void read(IJsonSerializable *data) = 0;
    virtual void write(IJsonSerializable *data) = 0;
};

#endif // IDATASTREAM_H
