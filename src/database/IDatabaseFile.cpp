#include "IDatabaseFile.h"

IDatabaseFile::IDatabaseFile(IDatabaseDataBlock *header) :
    _stream(this)
{
    _header = header;
}

bool IDatabaseFile::open(QIODevice::OpenMode flags)
{
    bool ret = QFile::open(flags);
    if (ret) readHeader();
    return ret;
}

void IDatabaseFile::close()
{
    QFile::flush();
    QFile::close();
}
