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
    void serialize(QDataStream &out) override;
    void deserialize(QDataStream &in) override;
    static quint64 blockSize();

    Guid guid() { return _guid; }
    QDateTime creationDate() { return _creationDate; }
    quint64 blockNumber(){ return _number; }
    void setBlockNumber(quint64 value) { _number = value; }

private:
    Guid _guid;
    quint64 _number;
    QDateTime _creationDate;
};

#endif // DATABASEINDEXRECORD_H
