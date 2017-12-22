#include "IHashedDataBlock.h"
#include <QCryptographicHash>


IHashedDataBlock::IHashedDataBlock() :
    IDataBlock()
{

}

IHashedDataBlock::IHashedDataBlock(QByteArray data) :
    IDataBlock(data)
{

}

QByteArray IHashedDataBlock::compiled()
{
    _buffer.append("HASH");
    return IDataBlock::compiled();
}

void IHashedDataBlock::parse()
{
    IDataBlock::parse();
    checkHash();
}

void IHashedDataBlock::checkHash()
{
    QByteArray hash = _buffer.right(4);
    _buffer = _buffer.left(_buffer.length() - 4);
    if (QString::fromLatin1(hash) != "HASH")
    {
        throw DataStreamException("Data block corrputed!");
    }
}
