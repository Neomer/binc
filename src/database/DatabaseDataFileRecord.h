#ifndef DATABASEDATAFILERECORD_H
#define DATABASEDATAFILERECORD_H

#include "IDatabaseDataBlock.h"
#include <QDateTime>

///
/// \brief The DatabaseDataFileRecord class Блок данных файла с данными
///
class DatabaseDataFileRecord : public IDatabaseDataBlock
{
public:
    DatabaseDataFileRecord();

// IDatabaseDataBlock interface
public:
    void serialize(QDataStream &out) override;
    void deserialize(QDataStream &in) override;
    quint64 blockSize() override;

    void setCreationDate(QDateTime value) { _creationDate = value; }
    void setBody(QString value) { _body = value; }
    void setNumber(quint64 value) { _number = value; }

private:
    QDateTime _creationDate;
    QString _body;
    quint64 _number;
};

#endif // DATABASEDATAFILERECORD_H
