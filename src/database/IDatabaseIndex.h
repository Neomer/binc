#ifndef IDATABASEINDEX_H
#define IDATABASEINDEX_H

#include "DatabaseGeneral.h"
#include "IDatabaseIndexResult.h"

///
/// \brief The IDatabaseIndex class интерфейс для поддержки индексов базы данных
///
class IDatabaseIndex
{
public:
    ///
    /// \brief find Ищет ключ в индексе
    /// \param key Ключ
    /// \param result Записывает результат поиска
    ///
    virtual void find(dbkey key, IDatabaseIndexResult *result) = 0;
    ///
    /// \brief write записывает информацию о новом блоке в индекс
    /// \param key Ключ
    /// \param result информация о новом объекте
    ///
    virtual void write(dbkey key, IDatabaseIndexResult *result) = 0;
};

#endif // IDATABASEINDEX_H
