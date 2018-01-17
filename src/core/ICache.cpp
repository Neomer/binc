#include "ICache.h"

ICache::ICache(int limit)
{
    _limit = limit;
}

void ICache::append(IIdentifyed *value)
{
    _list << value;
}

void ICache::get(Guid id)
{
    id
}
