#ifndef ITRANSPORTDATABLOCK_H
#define ITRANSPORTDATABLOCK_H

#include <core/IIdentifyed.h>
#include <core/types/Guid.h>
#include <core/types/Hash.h>
#include <core/IBinarySerializable.h>

#define MAX_BLOCK_SIZE          1024

///
/// \brief The TransportDataBlock class блок данных, передаваемый через каналы связи
///
class TransportDataBlock : public IIdentifyed, public IBinarySerializable
{
public:
    enum TransportDataBlockStatus
    {
        enStatusFirst,
        enStatusRegular,
        enStatusLast,
        enStatusPing
    };

    TransportDataBlock();

    ///
    /// \brief getTransactionId
    /// \return
    ///
    Guid getTransactionId() { return _transaction_id; }
    ///
    /// \brief setTransactionId
    /// \param value
    ///
    void setTransactionId(Guid value) { _transaction_id = value; }
    ///
    /// \brief getPreviousBlockId
    /// \return
    ///
    Guid getPreviousBlockId() { return _prev_block_id; }
    ///
    /// \brief setPreviousBlockId
    /// \param value
    ///
    void setPreviousBlockId(Guid value) { _prev_block_id = value; }
    ///
    /// \brief getLength
    /// \return
    ///
    quint16 getLength() { return _length; }
    ///
    /// \brief getStatus возвращает статус блока данных
    /// \return
    ///
    TransportDataBlockStatus getStatus() { return _status; }
    ///
    /// \brief setStatus устанавливает статус блока данных
    /// \param value
    ///
    void setStatus(TransportDataBlockStatus value) { _status = value; }
    ///
    /// \brief getData вовзращает сообщение блока данных
    /// \return
    ///
    QByteArray getData() { return  _data; }
    ///
    /// \brief setData устанавливает сообщение блока данных
    /// \param value
    ///
    void setData(QByteArray value);
    ///
    /// \brief setData устанавливает сообщение блока данных
    /// \param value
    ///
    void setData(const char *value, int length);
    ///
    /// \brief isReady проверяет удалось ли десериализовать блок
    /// \return
    ///
    bool isReady() { return _ready; }
    ///
    /// \brief isValid проверяет блок на валидность. Проверяется префикс и хэш-сумма.
    /// \return
    ///
    bool isValid();

private:
    Guid _transaction_id, _prev_block_id;
    Hash _hash;
    quint16 _length;
    QString _prefix;
    TransportDataBlockStatus _status;
    QByteArray _data;
    bool _ready;

    // IBinarySerializable interface
public:
    void toDataStream(QDataStream &out) override;
    void fromDataStream(QDataStream &in) override;
};

#endif // ITRANSPORTDATABLOCK_H
