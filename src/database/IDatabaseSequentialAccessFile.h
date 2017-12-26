#ifndef IDATABASESEQUENTIALACCESSFILE_H
#define IDATABASESEQUENTIALACCESSFILE_H

#include "HeaderDataBlock.h"
#include "IDatabaseFile.h"

///
/// \brief The IDatabaseSequentialAccessFile class Файл базы данных с последовательным доступом
///
class IDatabaseSequentialAccessFile : public IDatabaseFile
{
public:
    IDatabaseSequentialAccessFile(HeaderDataBlock *header);

// IDatabaseFile interface
public:
    void toBegin() override;
    void write(IDatabaseDataBlock *block) override;
};

#endif // IDATABASESEQUENTIALACCESSFILE_H
