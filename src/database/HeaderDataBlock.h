#ifndef HEADERDATABLOCK_H
#define HEADERDATABLOCK_H

#include "IDatabaseDataBlock.h"


class HeaderDataBlock : public IDatabaseDataBlock
{
public:
    HeaderDataBlock();

    void setBytesUsed(quint64 value) { _bytesUsed = value; }
    void addBytesUsed(quint64 value) { _bytesUsed += value; }
    ///
    /// \brief bytesUsed Количество занятых байт
    /// \return
    ///
    qint64 bytesUsed() { return _bytesUsed; }

    void setRecords(quint64 value) { _records = value; }
    void addRecords(quint64 value) { _records += value; }
    ///
    /// \brief records количество блоков данных в файле
    /// \return
    ///
    qint64 records() { return _records; }

private:
    quint64 _bytesUsed;
    quint64 _records;

    // IDatabaseDataBlock interface
public:
    void toDataStream(QDataStream &out) override;
    void fromDataStream(QDataStream &in) override;
    static quint64 blockSize();
};

#endif // HEADERDATABLOCK_H
