#ifndef IDATABASEDATABLOCK_H
#define IDATABASEDATABLOCK_H

#include <QByteArray>
#include <QIODevice>
#include <QDataStream>

///
/// \brief The IDatabaseDataBlock class Блок данных для записи в файл. Поддержка сериализации.
///
class IDatabaseDataBlock
{
public:
    ///
    /// \brief serialize преобразует блок в массив байт, готовый для записи в файл
    /// \return
    ///
    virtual void serialize(QDataStream &out) = 0;
    ///
    /// \brief deserialize преобразует массив байт, прочитанный из файла, в класс
    /// \param data
    ///
    virtual void deserialize(QDataStream &in) = 0;
    ///
    /// \brief blockSize размер блока с данными
    /// \return
    ///
    virtual quint64 blockSize() = 0;
};

#endif // IDATABASEDATABLOCK_H
