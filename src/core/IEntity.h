#ifndef IENTITY_H
#define IENTITY_H

#include <QString>

///
/// \brief IEntity Необходимо наследовать этот инерфейс для того, чтобы возможно было создавать экземпляры своего класса через фабрики.
///
class IEntity
{
public:
    virtual QString getEntityName() = 0;
};

#endif // IENTITY_H
