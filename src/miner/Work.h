#ifndef WORK_H
#define WORK_H

#include <core/types/Guid.h>
#include <core/types/Hash.h>
#include <model/Block.h>

class Work
{
public:
    Work();

    void setBlock(Block &block) { _block = block; }
    Block *getBlock() { return &_block; }

    Hash getTarget() { return _hash; }
    void setTarget(Hash value) { _hash = value; }

private:
    Block _block;
    Hash _hash;
};

#endif // WORK_H
