#ifndef IDATASTREAM_H
#define IDATASTREAM_H

#include <QObject>
#include <QIODevice>
#include "IDataBlock.h"

class IDataStream
{
public:
    IDataStream();

    virtual void open() = 0;
    virtual void close() = 0;
    virtual void read(IDataBlock *data) = 0;
    virtual void write(IDataBlock *data) = 0;
};

#endif // IDATASTREAM_H
