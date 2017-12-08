#ifndef IDATASTREAM_H
#define IDATASTREAM_H

#include <QObject>
#include <QIODevice>

class IDataStream : public QIODevice
{
    Q_OBJECT

public:
    IDataStream();


};

#endif // IDATASTREAM_H
