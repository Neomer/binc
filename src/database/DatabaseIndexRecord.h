#ifndef DATABASEINDEXRECORD_H
#define DATABASEINDEXRECORD_H

#include <QDateTime>
#include "IDatabaseDataBlock.h"
#include <core/types/Guid.h>

///
/// \brief The DatabaseIndexRecord class Заголовок индексного файла
///
class DatabaseIndexRecord : public IDatabaseDataBlock
{
public:
    DatabaseIndexRecord();

    // IDatabaseDataBlock interface
public:
    void toDataStream(QDataStream &out) override;
    void fromDataStream(QDataStream &in) override;
    static quint64 blockSize();

    void setGuid(Guid value) { _guid = value; }
    Guid guid() { return _guid; }

    void setIsDeleted(bool value) { _is_deleted = value; }
    bool isDeleted() { return _is_deleted; }

    void setOffset(quint64 value) { _offset = value; }
    quint64 offset() { return _offset; }

    void setLength(quint64 value) { _length = value; }
    quint64 length() { return _length; }

private:
    Guid _guid;
    bool _is_deleted;
    quint64 _offset, _length;
};

#endif // DATABASEINDEXRECORD_H
