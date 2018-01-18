#include "TransportTransaction.h"

TransportTransaction::TransportTransaction()
{

}

TransportTransaction::~TransportTransaction()
{
    _blocks_cache.clear();
}

void TransportTransaction::addBlock(TransportDataBlock *block)
{
    if (block->getPreviousBlockId().isEmpty())
    {

    }

    if (_blocks_cache.isEmpty())
    {

    }
}

OutgoingTransportTransaction::OutgoingTransportTransaction(IJsonSerializable *object)
{
    QByteArray data = IJsonSerializable::toByteArray(object);

    TransportDataBlock *b, *b1 = 0;
    int blocks = data.size() / MAX_BLOCK_SIZE + 1;
    for (int i = 0; i < blocks; i++)
    {
        b = new TransportDataBlock();
        if (i == blocks - 1)
        {
            b->setStatus(TransportDataBlock::enStatusLast);
        }
        else if (i == 0)
        {
            b->setStatus(TransportDataBlock::enStatusFirst);
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
        b->setTransactionId(this->getId());
        b->setData(data.constData() + i * MAX_BLOCK_SIZE, qMin(MAX_BLOCK_SIZE, data.size() - i * MAX_BLOCK_SIZE));
        b1 = b;
    }
}
