#include "TransportTransaction.h"

TransportTransaction::TransportTransaction()
{

}

void TransportTransaction::postponeBlock(TransportDataBlock *block)
{
    _blocks_cache.add(block);
}
