#ifndef IDATABASEFILEHEADER_H
#define IDATABASEFILEHEADER_H

#include <core/IBinarySerializable.h>
#include <core/types/Version.h>

///
/// \brief Интерфейс для реализации блока данных в заголовочном файле базы данных.
///
class IDatabaseFileHeader : public IBinarySerializable
{
private:
    quint64 _bytesUsed;
    Version _version;

public:
    ///
    /// \brief IDatabaseFileHeader Инициализирует блок данных в заголовочном файле базы данных
    ///
    IDatabaseFileHeader();
    ///
    /// \brief getUsedBytes Количество используемых байт
    /// \return
    ///
    quint64 getUsedBytes() { return _bytesUsed; }
    ///
    /// \brief setBytesUsed Количество используемых байт
    /// \param value
    ///
    void setBytesUsed(quint64 value) { _bytesUsed = value; }
    ///
    /// \brief getVersion Версия протокола файла
    /// \return
    ///
    Version getVersion() { return _version; }
    ///
    /// \brief setVersion Версия протокола файла
    /// \param value
    ///
    void setVersion(Version value) { _version = value; }

    // IBinarySerializable interface
public:
    void toDataStream(QDataStream &out) override;
    void fromDataStream(QDataStream &in) override;
};

#endif // IDATABASEFILEHEADER_H
