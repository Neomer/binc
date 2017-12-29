#include "IDatabaseFile.h"

IDatabaseFile::IDatabaseFile(IDatabaseDataBlock *header) :
    _stream(this)
{
    _header = header;
}

IDatabaseFile::~IDatabaseFile()
{
    delete _header;
}

bool IDatabaseFile::open(QIODevice::OpenMode flags)
{
    bool ex = QFile::exists();
    if (ex) flags |= QIODevice::ReadOnly;
    bool ret = QFile::open(flags);
    if (ret && ex) readHeader();
    return ret;
}

void IDatabaseFile::close()
{
    QFile::flush();
    QFile::close();
}
