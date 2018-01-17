#include "TransportDataBlock.h"

TransportDataBlock::TransportDataBlock() :
    IIdentifyed()
{

}

void TransportDataBlock::serialize(QDataStream &out)
{
    out << "BINC";
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
}
