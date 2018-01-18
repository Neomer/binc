#include "TransportTransaction.h"

IncomingTransportTransaction::IncomingTransportTransaction()
{

}

IncomingTransportTransaction::~IncomingTransportTransaction()
{
    _blocks_cache.clear();
}

void IncomingTransportTransaction::postponeBlock(TransportDataBlock *block)
{
    _blocks_cache.add(block);
}

OutgoingTransportTransaction::OutgoingTransportTransaction(IJsonSerializable *object)
{
    QByteArray data = IJsonSerializable::toByteArray(object);

    TransportDataBlock *b, *b1 = 0;
    int blocks = data.size() / MAX_BLOCK_SIZE;
    bool first = true;
    while (--blocks)
    {
        b = new TransportDataBlock();
        if (blocks == 0)
        {
            b->setStatus(TransportDataBlock::enStatusLast);
        }
        else if (first)
        {
            b->setStatus(TransportDataBlock::enStatusFirst);
            first = false;
        }
        else
        {
            b->setStatus(TransportDataBlock::enStatusRegular);
        }
        if (!b1)
        {
            b->setPreviousBlockId(Guid::emptyGuid());
        }
        else
        {
            b->setPreviousBlockId(b1->getId());
        }
        b1 = b;
    }
}
