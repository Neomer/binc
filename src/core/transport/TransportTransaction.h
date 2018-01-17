#ifndef ITRANSPORTTRANSACTION_H
#define ITRANSPORTTRANSACTION_H

#include <QList>

#include <core/IIdentifyed.h>
#include <core/types/Guid.h>
#include <core/MemoryCache.h>
#include <core/transport/TransportDataBlock.h>

class TransportTransaction : public IIdentifyed
{
public:
    TransportTransaction();

    void postponeBlock(TransportDataBlock *block);

private:
    MemoryCache _blocks_cache;
};

#endif // ITRANSPORTTRANSACTION_H
