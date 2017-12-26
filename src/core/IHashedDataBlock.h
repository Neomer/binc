#ifndef IHASHEDDATABLOCK_H
#define IHASHEDDATABLOCK_H

#include "IDataBlock.h"

///
/// \brief The IHashedDataBlock class класс добавляющий проверку контроьлной суммы для блока данных
///
class IHashedDataBlock : public IDataBlock
{
public:
    IHashedDataBlock();
    IHashedDataBlock(QByteArray data);

    QByteArray compiled();
    void parse();

private:
    void checkHash();
};

#endif // IHASHEDDATABLOCK_H
