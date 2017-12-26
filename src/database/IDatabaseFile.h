#ifndef IDATABASEFILE_H
#define IDATABASEFILE_H

#include "IDatabaseDataBlock.h"

class IDatabaseFile
{
public:
    IDatabaseFile(IDatabaseDataBlock *header);

private:
    IDatabaseDataBlock *_header;
};

#endif // IDATABASEFILE_H
