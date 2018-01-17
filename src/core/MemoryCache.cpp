#include "MemoryCache.h"

MemoryCache::MemoryCache(int limit) :
    ICache(limit)
{

}

void MemoryCache::add(IIdentifyed *value)
{
    _list << value;
}

IIdentifyed *MemoryCache::take(Guid id)
{
    for (int i = 0; i < count(); i++)
    {
        if (Guid::isEqual(_list.at(i)->getId(), id))
        {
            return _list.takeAt(i);
        }
    }
    return 0;
}

IIdentifyed *MemoryCache::first()
{
    if (isEmpty()) return 0;
    return _list.first();
}

int MemoryCache::count()
{
    return _list.count();
}

IIdentifyed *MemoryCache::get(Guid id)
{
    foreach (IIdentifyed *i, _list)
    {
        if (Guid::isEqual(i->getId(), id))
        {
            return i;
        }
    }
    return 0;
}

IIdentifyed *MemoryCache::takeFirst()
{
    if (isEmpty()) return 0;
    return _list.takeFirst();
}
