#include "IDatabaseFile.h"

IDatabaseFile::IDatabaseFile(IDatabaseDataBlock *header) :
    _stream(this)
{
    _header = header;
}

bool IDatabaseFile::open(QIODevice::OpenMode flags)
{
    return QFile::open(flags);
}

void IDatabaseFile::close()
{
    QFile::flush();
    QFile::close();
}
