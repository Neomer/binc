#ifndef IDATABASERANDOMACCESSFILE_H
#define IDATABASERANDOMACCESSFILE_H

#include "IDatabaseFile.h"
#include "HeaderDataBlock.h"
#include "DatabaseFileException.h"

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
    void read(IDatabaseDataBlock *block) override;
    ///
    /// \brief write добавляет блок данных в файл на позицию index
    /// \param index
    /// \param block
    /// \return
    ///
    quint64 write(quint64 index, IDatabaseDataBlock *block);

private:
    quint64 write(IDatabaseDataBlock *block) override;
    quint64 _block_size;
};

#endif // IDATABASERANDOMACCESSFILE_H
