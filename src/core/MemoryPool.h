#ifndef MEMORYPOOL_H
#define MEMORYPOOL_H

#include <model/Deal.h>

///
/// \brief The MemoryPool
///
class MemoryPool
{
public:
    MemoryPool();

    ///
    /// \brief addDeal проверяет сделку на соответствие, и помещает ее в мемпул в случае валидности
    /// \param deal
    ///
    void addDeal(Deal &deal);

private:
    QList<Deal> _pool;
};

#endif // MEMORYPOOL_H
