#ifndef IBINARYSERIALIZABLE_H
#define IBINARYSERIALIZABLE_H

#include <QDataStream>

class IBinarySerializable
{
public:
    ///
    /// \brief serialize преобразует блок в массив байт, готовый для записи в файл
    /// \return
    ///
    virtual void toDataStream(QDataStream &out) = 0;
    ///
    /// \brief deserialize преобразует массив байт, прочитанный из файла, в класс
    /// \param data
    ///
    virtual void fromDataStream(QDataStream &in) = 0;
};

#endif // IBINARYSERIALIZABLE_H
