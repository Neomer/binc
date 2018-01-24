#ifndef DATABASEINDEXRECORD_H
#define DATABASEINDEXRECORD_H

#include <database/IDatabaseWritable.h>


///
/// \brief DatabaseIndexRecord модель данных представляющая одну запись файла индекса базы данных
///
class DatabaseIndexRecord : public IDatabaseWritable
{
private:
    quint64 _offset;
    quint32 _length;

public:
    DatabaseIndexRecord();
    DatabaseIndexRecord(quint64 offset, quint32 length);

    quint64 getOffset() { return _offset; }
    void setOffset(quint64 value) { _offset = value; }

    quint32 getLength() { return _length; }
    void setLength(quint32 value) { _length = value; }

    // IBinarySerializable interface
public:
    void toDataStream(QDataStream &out) override;
    void fromDataStream(QDataStream &in) override;
};

#endif // DATABASEINDEXRECORD_H
