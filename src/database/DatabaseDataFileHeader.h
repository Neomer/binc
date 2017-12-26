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

// IDatabaseDataBlock interface
public:
    quint64 blockSize() override;
    void serialize(QDataStream &out) override;
    void deserialize(QDataStream &in) override;

    void setBytesUsed(quint64 value) { _bytesUsed = value; }
    void addBytesUsed(quint64 value) { _bytesUsed += value; }
    qint64 bytesUsed() { return _bytesUsed; }

private:
    quint64 _bytesUsed;
};

#endif // DATABASEDATAFILEHEADER_H
