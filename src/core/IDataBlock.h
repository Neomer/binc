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

    int size() { return _buffer.size(); }

protected:
    QByteArray _buffer;
};

#endif // IDATABLOCK_H
