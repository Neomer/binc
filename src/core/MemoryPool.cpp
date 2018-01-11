#include "MemoryPool.h"

MemoryPool::MemoryPool()
{

}

void MemoryPool::addDeal(Deal &deal)
{
    _pool << deal;
}
