#ifndef DATABASEINDEXRECORD_H
#define DATABASEINDEXRECORD_H

#include "IDatabaseDataBlock.h"

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

private:

};

#endif // DATABASEINDEXRECORD_H
