#include "IDataBlock.h"

IDataBlock::IDataBlock()
{
    clear();
}

IDataBlock::IDataBlock(QByteArray data)
{
    parse(data);
}

void IDataBlock::clear()
{
    memset(&_header, 0, sizeof(_header));
}

void IDataBlock::setData(QByteArray data)
{
    _buffer = data;
}

QByteArray IDataBlock::compiled()
{
    _header.Length = _buffer.size();
    memcpy(_header.Prefix, "BINC", 4);
    QByteArray ret((const char *)&_header, sizeof(_header));
    ret.append(_buffer);
    return ret;
}

void IDataBlock::parse(QByteArray data)
{
    clear();
    memcpy(&_header, data.constData(), sizeof(_header));
    if (memcmp(_header.Prefix, "BINC", 4))
    {
        throw DataStreamException("Package corrupted! Prefix not found!");
    }
    if (_header.Length > data.length())
    {
        throw DataStreamException("Package corrupted!");
    }
    _buffer = data.mid(sizeof(_header), _header.Length);
}

void IDataBlock::parse()
{
    parse(_buffer);
}
