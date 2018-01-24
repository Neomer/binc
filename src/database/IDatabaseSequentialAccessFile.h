#ifndef IDATABASESEQUENTIALACCESSFILE_H
#define IDATABASESEQUENTIALACCESSFILE_H

#include "HeaderDataBlock.h"
#include "IDatabaseFile.h"

///
/// \brief The IDatabaseSequentialAccessFile class Файл базы данных с последовательным доступом
///
class IDatabaseSequentialAccessFile
{
public:
    IDatabaseSequentialAccessFile(HeaderDataBlock *header);

// IDatabaseFile interface
public:
    quint64 write(IDatabaseDataBlock *block);
    void read(IDatabaseDataBlock *block);
    ///
    /// \brief seek указывается смещение в байтах
    /// фигня какая-то...
    /// \param index
    ///
    void seek(quint64 index);
};

#endif // IDATABASESEQUENTIALACCESSFILE_H
