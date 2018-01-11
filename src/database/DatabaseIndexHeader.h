#ifndef DATABASEINDEXHEADER_H
#define DATABASEINDEXHEADER_H

#include "IDatabaseDataBlock.h"
#include "HeaderDataBlock.h"

///
/// \brief The DatabaseIndexHeader class Заголовок индексного файла
///
class DatabaseIndexHeader : public HeaderDataBlock
{
public:
    DatabaseIndexHeader();

};

#endif // DATABASEINDEXHEADER_H
