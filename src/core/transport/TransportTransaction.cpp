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

OutgoingTransportTransaction::OutgoingTransportTransaction()
{

}
