#ifndef IDATABLOCK_H
#define IDATABLOCK_H

#include <QByteArray>
#include "DataStreamException.h"

///
/// \brief The IDataBlock class класс для работы с блоком данных (сетевой пакет и т.п.)
///
class IDataBlock
{
public:
    IDataBlock();
    IDataBlock(QByteArray data);

    ///
    /// \brief clear очищает блок данных
    ///
    void clear();
    ///
    /// \brief setData записывает данные в блок
    /// \param data
    ///
    void setData(QByteArray data);
    ///
    /// \brief append дописывает данные в конец блока
    /// \param data
    ///
    void append(QByteArray data) { _buffer.append(data); }
    ///
    /// \brief size длина в байтах данных в блоке
    /// \return
    ///
    int size() { return _buffer.size(); }
    ///
    /// \brief data данные из блока
    /// \return
    ///
    QByteArray data() { return _buffer; }
    ///
    /// \brief length длина данных, полученная из заголовка пакета
    /// \return
    ///
    quint16 length() { return _header.Length; }
    ///
    /// \brief compiled возвращает готовый для отправки массив байт
    /// \return
    ///
    QByteArray compiled();
    ///
    /// \brief parse разбирает данные
    /// \param data
    ///
    void parse(QByteArray data);
    ///
    /// \brief parse разбирает данные ранее записанные в буффер
    /// \param data
    ///
    void parse();

protected:
    QByteArray _buffer;
    struct DataBlockHeader
    {
        char Prefix[4];
        quint16 Length;
    };
    DataBlockHeader _header;
};

#endif // IDATABLOCK_H
