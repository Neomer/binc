#include "DatabaseFile.h"
#include <core/StreamedBuffer.h>
#include <model/DatabaseDataHeader.h>

DatabaseFile::DatabaseFile(QString filename) :
    _data_file(filename.append(".bin")),
    _hdr_file(filename.append(".hdr"))
{

}

void DatabaseFile::write(QByteArray data)
{
    if (!_hdr_file.open(QIODevice::ReadWrite))
    {
        throw BaseException("Database file access error!");
    }
    StreamedBuffer hdr_buffer(_hdr_file.readAll());
    DatabaseDataHeader header;
    header.fromDataStream(hdr_buffer.stream());

    if (!_data_file.open(QIODevice::Append))
    {
        throw BaseException("Database file access error!");
    }
    if (_data_file.write(data) != data.count())
    {
        throw BaseException("Not all data was written!");
    }
    _data_file.close();
}
