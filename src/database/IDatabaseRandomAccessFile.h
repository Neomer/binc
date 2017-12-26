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
    IDatabaseRandomAccessFile(HeaderDataBlock *header, quint64 blockSize);

    // IDatabaseFile interface
public:
    void toBegin() override;
    void toEnd() override;
    void seek(quint64 index) override;
    void write(IDatabaseDataBlock *block) override;
    void read(IDatabaseDataBlock *block) override;

private:
    quint64 _block_size;
};

#endif // IDATABASERANDOMACCESSFILE_H
