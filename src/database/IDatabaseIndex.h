#ifndef IDATABASEINDEX_H
#define IDATABASEINDEX_H

#include "DatabaseGeneral.h"
#include "IDatabaseIndexResult.h"

///
/// \brief The IDatabaseIndex class Интерфейс для работы с индексом БД
///
class IDatabaseIndex
{
public:
    ///
    /// \brief init инициализирует индекс
    ///
    virtual void init() = 0;
    ///
    /// \brief find Ищет ключ в индексе
    /// \param key Ключ
    /// \param result Записывает результат поиска
    ///
    virtual void find(dbkey key, IDatabaseIndexResult *result) = 0;
    ///
    /// \brief write записывает информацию о новом блоке в индекс
    /// \param key Ключ
    /// \param offset Смещение от начала файла
    /// \param result информация о новом объекте
    ///
    virtual void write(void *data, IDatabaseIndexResult *result) = 0;
};

#endif // IDATABASEINDEX_H
