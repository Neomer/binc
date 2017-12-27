#ifndef IDATABASEDATA_H
#define IDATABASEDATA_H

#include "IDatabaseFileCollection.h"
#include "DatabaseDataFileRecord.h"
#include "DatabaseDataFile.h"

///
/// \brief The IDatabaseData class Интерфейс для работы с данными БД
///
class IDatabaseData : public DatabaseDataFile
{
public:
    IDatabaseData();


};

#endif // IDATABASEDATA_H
