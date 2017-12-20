#ifndef IDATASTREAM_H
#define IDATASTREAM_H

#include <QObject>
#include <QIODevice>
#include "IDataBlock.h"

class IDataStream : public QIODevice
{
    Q_OBJECT

public:
    IDataStream();

    virtual void open() = 0;
    virtual void close() = 0;

signals:
    void blockReady(IDataBlock);

};

#endif // IDATASTREAM_H
