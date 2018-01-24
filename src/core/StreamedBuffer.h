#ifndef STREAMEDBUFFER_H
#define STREAMEDBUFFER_H

#include <QDataStream>
#include <QByteArray>

///
/// \brief StreamedBuffer класс поддерживающий потоковую запись в буффер
///
class StreamedBuffer : public QByteArray
{
public:
    ///
    /// \brief StreamedBuffer Инициализирует с пустым буффером
    ///
    StreamedBuffer() : _stream(this, QIODevice::ReadWrite) { }
    ///
    /// \brief StreamedBuffer инициализирует класс с копией готового буффера
    /// \param other
    ///
    StreamedBuffer(QByteArray other) : QByteArray(other), _stream(this, QIODevice::ReadWrite) { }

    QDataStream &stream() { return _stream; }

private:
    QDataStream _stream;
};

#endif // STREAMEDBUFFER_H
