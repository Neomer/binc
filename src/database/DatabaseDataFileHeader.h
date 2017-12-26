#ifndef DATABASEDATAFILEHEADER_H
#define DATABASEDATAFILEHEADER_H

#include "HeaderDataBlock.h"

///
/// \brief The DatabaseDataFileHeader class Заголовок файла с данными
///
class DatabaseDataFileHeader : public HeaderDataBlock
{
public:
    DatabaseDataFileHeader();

// IDatabaseDataBlock interface
public:
    quint64 blockSize() override;
    void serialize(QDataStream &out) override;
    void deserialize(QDataStream &in) override;

    void setRecords(quint64 value) { _records = value; }
    void addRecords(quint64 value) { _records += value; }
    qint64 records() { return _records; }

private:
    quint64 _records;
};

#endif // DATABASEDATAFILEHEADER_H
