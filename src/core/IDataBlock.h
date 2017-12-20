#ifndef IDATABLOCK_H
#define IDATABLOCK_H

#include <QByteArray>

///
/// \brief The IDataBlock class класс для работы с блоком данных (сетевой пакет и т.п.)
///
class IDataBlock
{
public:
    IDataBlock();
    IDataBlock(QByteArray data);

    void setData(QByteArray data) { _buffer = data; }

    int size() { return _buffer.size(); }
    QByteArray data() { return _buffer; }

protected:
    QByteArray _buffer;
};

#endif // IDATABLOCK_H
