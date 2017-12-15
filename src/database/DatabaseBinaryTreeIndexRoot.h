#ifndef DATABASEBINARYTREEINDEXROOT_H
#define DATABASEBINARYTREEINDEXROOT_H

#include <QFile>
#include "DatabaseGeneral.h"

#define ALLOCATION_SIZE         10240
#define MAX_FILESIZE            1048576


class DatabaseBinaryTreeIndexRoot
{
public:
    DatabaseBinaryTreeIndexRoot(QFile *file);

    quint16 count();
    void setCount(quint16 value);

    QString getFile(dbkey key, qint64 *size = 0);

private:
    struct BTreeIndexRootHeader
    {
        quint16 Filecount;
    };
    struct BTreeIndexRootRecord
    {
        char Filename[FILENAME_MAX];
        qint64 DataSize;
        qint64 AllocSize;
        dbkey StartKey;
        dbkey EndKey;
    };
    QFile *_file;
};

#endif // DATABASEBINARYTREEINDEXROOT_H
