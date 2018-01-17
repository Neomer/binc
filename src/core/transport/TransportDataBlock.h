#ifndef ITRANSPORTDATABLOCK_H
#define ITRANSPORTDATABLOCK_H

#include <core/IIdentifyed.h>
#include <core/types/Guid.h>
#include <core/types/Hash.h>
#include <core/IBinarySerializable.h>

class TransportDataBlock : public IIdentifyed, public IBinarySerializable
{
public:
    enum TransportDataBlockStatus
    {
        enStatusFirst,
        enStatusRegular,
        enStatusLast
    };

    TransportDataBlock();

    Guid getTransactionId() { return _transaction_id; }
    Guid getPreviousBlockId() { return _prev_block_id; }
    quint16 getLength() { return _length; }
    TransportDataBlockStatus getStatus() { return _status; }
    QByteArray getData() { return  _data; }

private:
    Guid _transaction_id, _prev_block_id;
    Hash _hash;
    quint16 _length;
    QString _prefix;
    TransportDataBlockStatus _status;
    QByteArray _data;

    // IBinarySerializable interface
public:
    void serialize(QDataStream &out) override;
    void deserialize(QDataStream &in) override;
};

#endif // ITRANSPORTDATABLOCK_H
