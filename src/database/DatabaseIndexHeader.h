#ifndef DATABASEINDEXHEADER_H
#define DATABASEINDEXHEADER_H

#include "IDatabaseDataBlock.h"

///
/// \brief The DatabaseIndexHeader class Заголовок индексного файла
///
class DatabaseIndexHeader : public IDatabaseDataBlock
{
public:
    DatabaseIndexHeader();
};

#endif // DATABASEINDEXHEADER_H
