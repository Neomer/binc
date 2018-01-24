#ifndef DATABASEDATAHEADER_H
#define DATABASEDATAHEADER_H

#include <database/IDatabaseWritable.h>

///
/// \brief DatabaseDataHeader  модель данных представляющая заголовочный файл файла данных базы
///
class DatabaseDataHeader : public IDatabaseWritable
{
private:
    quint64 _bytesUsed;

public:
    DatabaseDataHeader();
    ///
    /// \brief getBytesUsed количество использованных байт в файле
    /// \return
    ///
    quint64 getBytesUsed() { return _bytesUsed; }
    ///
    /// \brief setBytesUsed количество использованных байт в файле
    /// \param value
    ///
    void setBytesUsed(quint64 value) { _bytesUsed = value; }

    // IBinarySerializable interface
public:
    void toDataStream(QDataStream &out) override;
    void fromDataStream(QDataStream &in) override;
};

#endif // DATABASEDATAHEADER_H
