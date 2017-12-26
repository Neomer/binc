#ifndef IDATABASERANDOMACCESSFILE_H
#define IDATABASERANDOMACCESSFILE_H

#include "IDatabaseFile.h"
#include "HeaderDataBlock.h"

///
/// \brief The IDatabaseRandomAccessFile class Файл базы данных с произвольным доступом
///
class IDatabaseRandomAccessFile : public IDatabaseFile
{
public:
    IDatabaseRandomAccessFile(HeaderDataBlock *header);

    // IDatabaseFile interface
public:
    void toBegin() override;
    void seek(quint64 index) override;
    void write(IDatabaseDataBlock *block) override;
};

#endif // IDATABASERANDOMACCESSFILE_H
