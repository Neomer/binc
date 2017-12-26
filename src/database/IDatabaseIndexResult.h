#ifndef IDATABASEINDEXRESULT_H
#define IDATABASEINDEXRESULT_H

#include <QString>

class IDatabaseIndexResult
{
public:
    IDatabaseIndexResult();

    QString filename() { return _filename; }
    qint64 offset() { return _offset; }
    int size() { return _size; }

    void setFilename(QString value) { _filename = value; }
    void setOffset(qint64 value) { _offset = value; }
    void setSize(int value) { _size = value; }

private:
    QString _filename;
    qint64 _offset;
    int _size;
};

#endif // IDATABASEINDEXRESULT_H
