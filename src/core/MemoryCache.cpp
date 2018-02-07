#include "MemoryCache.h"

MemoryCache::MemoryCache(int limit) :
    ICache(limit),
    _ttl(60000)
{
    _timer.setInterval(60000);
    connect(&_timer, SIGNAL(timeout()), this, SLOT(clearTick()));
}

void MemoryCache::setClearInterval(int interval)
{
    _timer.stop();
    _timer.setInterval(interval);
    _timer.start();
}

void MemoryCache::add(IIdentifyed *value)
{
    if (getLimit() >= 0 && _list.count() >= getLimit()) throw BaseException("Cache overflow!");
    MemoryCacheItem item;
    item.CreationDate = QDateTime::currentDateTime();
    item.Data = value;
    _list << item;
}

IIdentifyed *MemoryCache::take(Guid id)
{
    for (int i = 0; i < count(); i++)
    {
        if (Guid::isEqual(_list.at(i).Data->getId(), id))
        {
            return _list.takeAt(i).Data;
        }
    }
    return 0;
}

IIdentifyed *MemoryCache::first()
{
    if (isEmpty()) return 0;
    return _list.first().Data;
}

int MemoryCache::count()
{
    return _list.count();
}

IIdentifyed *MemoryCache::get(Guid id)
{
    foreach (MemoryCacheItem i, _list)
    {
        if (Guid::isEqual(i.Data->getId(), id))
        {
            return i.Data;
        }
    }
    return 0;
}

IIdentifyed *MemoryCache::takeFirst()
{
    if (isEmpty()) return 0;
    return _list.takeFirst().Data;
}

void MemoryCache::clear()
{
    _list.clear();
}

bool MemoryCache::contains(Guid id)
{
    foreach (MemoryCacheItem i, _list)
    {
        if (Guid::isEqual(i.Data->getId(), id))
        {
            return true;
        }
    }
    return false;
}

MemoryCache &MemoryCache::operator <<(IIdentifyed *value)
{
    add(value);
    return *this;
}

void MemoryCache::clearTick()
{
    for (int i = 0; i < _list.count(); i++)
    {
        if (_list.at(i).CreationDate.msecsTo(QDateTime::currentDateTime()) >= _ttl)
        {
            _list.removeAt(i--);
        }
    }
}
