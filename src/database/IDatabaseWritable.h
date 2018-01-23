#ifndef IDATABASEWRITABLE_H
#define IDATABASEWRITABLE_H

#include <core/IIdentifyed.h>
#include <core/IBinarySerializable.h>
#include <core/IEntity.h>

///
/// \brief Блок данных для записи в базу данных.
///
class IDatabaseWritable :
        public IIdentifyed,
        public IBinarySerializable
{
public:
    ///
    /// \brief IDatabaseWritable Инициализирует блок данных для записи в базу данных.
    ///
    IDatabaseWritable() : IIdentifyed() {}
    ///
    /// \brief IDatabaseWritable Инициализирует блок данных для записи в базу данных.
    /// \param id Идентификатор блока
    ///
    IDatabaseWritable(Guid id) : IIdentifyed(id) {}
};

#endif // IDATABASEWRITABLE_H
