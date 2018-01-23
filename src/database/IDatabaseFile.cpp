#include "IDatabaseFile.h"
#include <QDebug>

IDatabaseFile::IDatabaseFile(IDatabaseFileHeader * header, QString filename) :
    _datafile(filename.append(".data")),
    _headerfile(filename.append(".hdr"))
{
    Q_UNUSED(header);
}

IDatabaseFile::~IDatabaseFile()
{
}

bool IDatabaseFile::open()
{
    bool ret = true;

    if (!_datafile.open())
    {
        throw DatabaseFileException(_datafile.fileName().toUtf8().constData(), "File openning failed!");
    }

    try
    {
        //readHeader();
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
    _datafile.close();
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
    data->toDataStream(_datafile.stream());
}

void IDatabaseFile::read(IDatabaseWritable *data)
{
    data->fromDataStream(_datafile.stream());
}
