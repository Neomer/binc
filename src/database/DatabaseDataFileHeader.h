#ifndef DATABASEDATAFILEHEADER_H
#define DATABASEDATAFILEHEADER_H

#include "IDatabaseDataBlock.h"

///
/// \brief The DatabaseDataFileHeader class Заголовок файла с данными
///
class DatabaseDataFileHeader : public IDatabaseDataBlock
{
public:
    DatabaseDataFileHeader();
};

#endif // DATABASEDATAFILEHEADER_H
