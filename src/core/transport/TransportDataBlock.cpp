#include "TransportDataBlock.h"

TransportDataBlock::TransportDataBlock() :
    IIdentifyed(),
    _length(0),
    _ready(false)
{

}

void TransportDataBlock::setData(QByteArray value)
{
    _length = value.size();
    _data = value;
}

void TransportDataBlock::setData(const char *value, int length)
{
    _data = QByteArray(value, length);
    _length = length;
}

bool TransportDataBlock::isValid()
{
    //TODO: сделать
    return true;
}

void TransportDataBlock::serialize(QDataStream &out)
{
    out << QString("BINC");
    out << (quint16)_length;
    out << _transaction_id;
    out << getId();
    out << (quint8)_status;
    out << _prev_block_id;
    out << _data;
    //out << _hash;
}

void TransportDataBlock::deserialize(QDataStream &in)
{
    in.startTransaction();

    Guid tmp;
    quint8 tmp_status;

    in >> _prefix;
    in >> _length;
    in >> _transaction_id;
    in >> tmp;
    in >> tmp_status;
    in >> _prev_block_id;
    in >> _data;
    //out << _hash;


    setId(tmp);
    _status = (TransportDataBlockStatus)tmp_status;

    _ready = in.commitTransaction();
}
