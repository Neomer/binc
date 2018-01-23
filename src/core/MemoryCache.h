#ifndef MEMORYCACHE_H
#define MEMORYCACHE_H

#include <core/ICache.h>
#include <QList>

class MemoryCache : public ICache
{
public:
    MemoryCache(int limit = -1);

    // ICache interface
public:
    void add(IIdentifyed *value);
    IIdentifyed *get(Guid id);
    IIdentifyed *first();
    int count();
    IIdentifyed *take(Guid id);
    IIdentifyed *takeFirst();
    void clear();

    MemoryCache &operator <<(IIdentifyed *value);

private:
    QList<IIdentifyed *> _list;
};

#endif // MEMORYCACHE_H
