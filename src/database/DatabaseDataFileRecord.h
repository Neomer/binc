#ifndef DATABASEDATAFILERECORD_H
#define DATABASEDATAFILERECORD_H

#include "IDatabaseDataBlock.h"
#include <QDateTime>
#include <core/types/Guid.h>

///
/// \brief The DatabaseDataFileRecord class Блок данных файла с данными
///
class DatabaseDataFileRecord : public IDatabaseDataBlock
{
public:
    DatabaseDataFileRecord();

// IDatabaseDataBlock interface
public:
    void toDataStream(QDataStream &out) override;
    void fromDataStream(QDataStream &in) override;
    quint64 blockSize();

    void setGuid(Guid value) { _guid = value; }
    Guid guid() { return _guid; }

    void setBlockNumber(quint64 value) { _number = value; }
    quint64 blockNumber() { return _number; }

    void setData(QString value) { _data = value; }
    QString data() { return _data; }

private:
    Guid _guid;
    quint64 _number;
    QString _data;
    QDateTime _creationDate;
};

#endif // DATABASEDATAFILERECORD_H
