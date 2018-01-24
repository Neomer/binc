#ifndef DATABASEFILE_H
#define DATABASEFILE_H

#include <QString>
#include <QFile>
#include <database/IDatabaseWritable.h>
#include <core/BaseException.h>

class DatabaseFile
{
public:
    DatabaseFile(QString filename);

    void write(QByteArray data);

private:
    QFile _data_file, _hdr_file;
};

#endif // DATABASEFILE_H
