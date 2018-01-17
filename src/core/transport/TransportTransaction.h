#ifndef ITRANSPORTTRANSACTION_H
#define ITRANSPORTTRANSACTION_H

#include <QList>

#include <core/IIdentifyed.h>
#include <core/types/Guid.h>
#include <core/MemoryCache.h>
#include <core/transport/TransportDataBlock.h>

class IncomingTransportTransaction : public IIdentifyed
{
public:
    IncomingTransportTransaction();
    ~IncomingTransportTransaction();

    void postponeBlock(TransportDataBlock *block);

private:
    MemoryCache _blocks_cache;
};

class OutgoingTransportTransaction : public IIdentifyed
{
public:
    OutgoingTransportTransaction();
};

#endif // ITRANSPORTTRANSACTION_H
