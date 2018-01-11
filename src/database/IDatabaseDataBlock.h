#ifndef IDATABASEDATABLOCK_H
#define IDATABASEDATABLOCK_H

#include <core/IBinarySerializable.h>

///
/// \brief The IDatabaseDataBlock class Блок данных для записи в файл. Поддержка сериализации.
///
class IDatabaseDataBlock : public IBinarySerializable
{
public:
    ///
    /// \brief blockSize размер блока с данными
    /// \return
    ///
    static quint64 blockSize();
};

#endif // IDATABASEDATABLOCK_H
