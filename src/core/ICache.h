#ifndef ICACHE_H
#define ICACHE_H

#include <QList>

#include <core/IIdentifyed.h>
#include <core/BaseException.h>

///
/// \brief The ICache интерфейс для реализации кэша
///
class ICache
{
public:
    ///
    /// \brief ICache
    /// \param limit устанавливает максимальное количество элементов
    ///
    ICache(int limit = -1);
    ///
    /// \brief add добавляет элемент в кэш
    /// \param value
    ///
    virtual void add(IIdentifyed *value) = 0;
    ///
    /// \brief get получает элемент из кэша по идентификатору
    /// \param id
    /// \returns
    ///
    virtual IIdentifyed * get(Guid id) = 0;
    ///
    /// \brief first возвращает первый элемент из кэша или NULL
    /// \return
    ///
    virtual IIdentifyed * first() = 0;
    ///
    /// \brief getLimit возвращает максимальное количество элементов
    /// \return
    ///
    int getLimit() { return _limit; }

private:
    int _limit;
};

#endif // ICACHE_H
