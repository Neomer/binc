#ifndef IENTITYFACTORY_H
#define IENTITYFACTORY_H

#include <core/IEntity.h>

///
/// \brief The IEntityFactory интерфейс для создания фабрики сущностей
///
class IEntityFactory
{
public:
    ///
    /// \brief createEntity функция создает сущность по наименованию
    /// \param name Наименование сущности
    /// \return
    ///
    virtual IEntity *createEntity(QString name) = 0;
};

#endif // IENTITYFACTORY_H
