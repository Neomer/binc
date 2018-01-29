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
    /// \param limit устанавливает максимальное количество элементов. -1 для неограниченного количества.
    ///
    ICache(int limit = -1);
    ///
    /// \brief getLimit возвращает максимальное количество элементов
    /// \return
    ///
    int getLimit() { return _limit; }
    ///
    /// \brief isEmpty проверяет пустой ли кэш
    /// \return
    ///
    bool isEmpty() { return count() == 0; }
    ///
    /// \brief add добавляет элемент в кэш
    /// \param value
    ///
    virtual void add(IIdentifyed *value) = 0;
    ///
    /// \brief get получает элемент из кэша по идентификатору.
    /// \param id
    /// \returns
    ///
    virtual IIdentifyed *get(Guid id) = 0;
    ///
    /// \brief take получает элемент из кэша по идентификатору. Элемент из кэша удаляется.
    /// \param id
    /// \return
    ///
    virtual IIdentifyed *take(Guid id) = 0;
    ///
    /// \brief first возвращает первый элемент из кэша или NULL
    /// \return
    ///
    virtual IIdentifyed *first() = 0;
    ///
    /// \brief takeFirst возвращает первый элемент из кэша или NULL. Элемент из кэша удаляется.
    /// \return
    ///
    virtual IIdentifyed *takeFirst() = 0;
    ///
    /// \brief count возвращает кол-во элементов в кэше
    /// \return
    ///
    virtual int count() = 0;
    ///
    /// \brief clear очищает буфер
    ///
    virtual void clear() = 0;
    ///
    /// \brief contains проверяет существует ли в кэше объект с идентификатором id
    /// \param id идентификатор
    /// \return
    ///
    virtual bool contains(Guid id) = 0;

private:
    int _limit;
};

#endif // ICACHE_H
