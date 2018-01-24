#include "IDatabaseFileHeader.h"

IDatabaseFileHeader::IDatabaseFileHeader()
{

}

void IDatabaseFileHeader::toDataStream(QDataStream &out)
{
    out << _bytesUsed;
    out << _version;
}

void IDatabaseFileHeader::fromDataStream(QDataStream &in)
{
    in >> _bytesUsed;
    in >> _version;
}
