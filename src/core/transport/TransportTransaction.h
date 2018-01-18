#ifndef ITRANSPORTTRANSACTION_H
#define ITRANSPORTTRANSACTION_H

#include <QList>

#include <core/IIdentifyed.h>
#include <core/types/Guid.h>
#include <core/MemoryCache.h>
#include <core/IJsonSerializable.h>
#include <core/transport/TransportDataBlock.h>

class TransportTransaction : public IIdentifyed
{
public:
    TransportTransaction();
    ~TransportTransaction();

    ///
    /// \brief cache Возвращает кэш блоков
    /// \return
    ///
    const MemoryCache &cache() { return _blocks_cache; }
    void addBlock(TransportDataBlock *block);

private:
    MemoryCache _blocks_cache;
};

class OutgoingTransportTransaction : public IIdentifyed
{
public:
    OutgoingTransportTransaction(IJsonSerializable *object);

private:
    QList<TransportDataBlock *> _blocks;
};

#endif // ITRANSPORTTRANSACTION_H
