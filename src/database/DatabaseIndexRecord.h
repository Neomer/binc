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
};

#endif // DATABASEINDEXRECORD_H
