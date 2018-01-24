#ifndef STREAMEDFILE_H
#define STREAMEDFILE_H

#include <QFile>
#include <QDataStream>

///
/// \brief StreamedFile класс предоставляющий доступ к данным файла через поток
///
class StreamedFile : public QFile
{
public:
    StreamedFile(QString filename) : QFile(filename), _stream(this) { }

    QDataStream &stream() { return _stream; }

private:
    QDataStream _stream;
};

#endif // STREAMEDFILE_H
