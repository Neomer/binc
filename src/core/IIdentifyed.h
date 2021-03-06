#ifndef IIDENTIFYED_H
#define IIDENTIFYED_H

#include <core/types/Guid.h>

///
/// \brief IIdentifyed интерейс для реализации любой сущности имеющей идентификатор
///
class IIdentifyed
{
public:
    ///
    /// \brief IIdentifyed инициализирует сущность со случайно сгенерированным идентификатором
    ///
    IIdentifyed() : _id(Guid::randomGuid()) {}
    ///
    /// \brief IIdentifyed инициализирует сущность с установленным идентификатором id
    /// \param id значение идентификатора
    ///
    IIdentifyed(Guid id) : _id(id) {}

    ///
    /// \brief getId получить идентификатор
    /// \return
    ///
    Guid getId() { return _id; }
    ///
    /// \brief setId установить идентификатор
    /// \param value
    ///
    void setId(Guid value) { _id = value; }
    ///
    /// \brief isTheSame проверяет на соответствие идентификаторов
    /// \param other
    /// \return
    ///
    bool isTheSame(IIdentifyed &other) { return _id == other.getId(); }

private:
    Guid _id;
};

#endif // IIDENTIFYED_H
