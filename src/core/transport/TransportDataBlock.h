#ifndef ITRANSPORTDATABLOCK_H
#define ITRANSPORTDATABLOCK_H

#include <core/types/Guid.h>
#include <core/types/Hash.h>

class TransportDataBlock
{
public:
    enum TransportDataBlockStatus
    {
        enStatusFirst,
        enStatusRegular,
        enStatusLast
    };

    TransportDataBlock();

private:
    Guid _transaction_id, _block_id, _prev_block_id;
    Hash _hash;
    quint16 _length;
    char _prefix[4];
    TransportDataBlockStatus _status;
};

#endif // ITRANSPORTDATABLOCK_H
