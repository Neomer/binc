#include "IDatabaseFile.h"
#include <QDebug>

IDatabaseFile::IDatabaseFile(IDatabaseFileHeader * header, QString filename) :
    _datafile(filename.append(".data")),
    _headerfile(filename.append(".hdr"))
{

}

IDatabaseFile::~IDatabaseFile()
{
}

bool IDatabaseFile::open()
{
    bool ret = true;

    if (!_datafile.open(QIODevice::ReadWrite))
    {
        throw DatabaseFileException(_datafile.fileName().toUtf8().constData(), "File openning failed!");
    }
    _stream.setDevice(&_datafile);

    try
    {
        readHeader();
    }
    catch (DatabaseFileException &ex)
    {
        ret = false;
        qDebug() << "Error in file (" << ex.filename() << "):" << ex.what();
    }
    return ret;
}

void IDatabaseFile::close()
{
}

void IDatabaseFile::toBegin()
{
    _datafile.seek(0);
}

void IDatabaseFile::toEnd()
{
}

void IDatabaseFile::write(IDatabaseWritable *data)
{
    data->toDataStream(_stream);
}
