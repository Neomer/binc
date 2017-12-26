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
    void write(IDatabaseDataBlock *block) override;
    void read(IDatabaseDataBlock *block) override;
    ///
    /// \brief seek указывается смещение в байтах
    /// фигня какая-то...
    /// \param index
    ///
    void seek(quint64 index) override;
};

#endif // IDATABASESEQUENTIALACCESSFILE_H
