#ifndef GUID_H
#define GUID_H

#include <QString>
#include <QDataStream>
#include <core/BaseException.h>

///
/// \brief Guid Класс для работы с уникальными идентификаторами.
///
class Guid
{
public:
    ///
    /// \brief Guid Инициализирует пустой идентификатор
    ///
    Guid();
    ///
    /// \brief Guid Инициализирует идентификатор, как копию другого
    /// \param other
    ///
    Guid(const Guid& other);
    ///
    /// \brief toString Приводит Guid к печатному виду
    /// \return
    ///
    QString toString();
    ///
    /// \brief fromString возвращает экземпляр Guid из строки
    /// \param data
    /// \return
    ///
    static Guid fromString(QString data);
    ///
    /// \brief isEqual возвращает TRUE в случае равенства Guid
    /// \return
    ///
    static bool isEqual(const Guid &v1, const Guid &v2);
    ///
    /// \brief randomGuid генерирует случайный Guid
    /// \return
    ///
    static Guid randomGuid();
    ///
    /// \brief emptyGuid генерирует нулевой Guid
    /// \return
    ///
    static Guid emptyGuid();
    ///
    /// \brief isEmpty проверяет нулевой ли Guid
    /// \return
    ///
    bool isEmpty();

// Operators
    ///
    /// \brief operator == Проверяет два Guid на равенство
    /// \param other
    /// \return
    ///
    bool operator ==(const Guid &other);
    ///
    /// \brief operator = Копирует значение Guid
    /// \param other
    /// \return
    ///
    Guid &operator =(const Guid &other);
    ///
    /// \brief operator < Сравнивает два Guid
    /// \param other
    /// \return
    ///
    bool operator <(const Guid &other);
    ///
    /// \brief operator > Сравнивает два Guid
    /// \param other
    /// \return
    ///
    bool operator >(const Guid &other);
    ///
    /// \brief operator << Метод необходимый для работы с QDataStream
    /// \param stream
    /// \param object
    /// \return
    ///
    friend QDataStream &operator <<(QDataStream &stream, const Guid &object);
    ///
    /// \brief operator >>  Метод необходимый для работы с QDataStream
    /// \param stream
    /// \param object
    /// \return
    ///
    friend QDataStream &operator >>(QDataStream &stream, Guid &object);


private:
    struct GuidStructure
    {
        quint32 Data1;
        quint16 Data2;
        quint16 Data3;
        quint32 Data4;
        quint32 Data5;
    };
    GuidStructure _data;

    friend class QDataStream;
};

inline QDataStream &operator <<(QDataStream &stream, const Guid &object)
{
    stream << object._data.Data1;
    stream << object._data.Data2;
    stream << object._data.Data3;
    stream << object._data.Data4;
    stream << object._data.Data5;
    return stream;
}

inline QDataStream &operator >>(QDataStream &stream, Guid &object)
{
    stream >> object._data.Data1;
    stream >> object._data.Data2;
    stream >> object._data.Data3;
    stream >> object._data.Data4;
    stream >> object._data.Data5;
    return stream;
}


#endif // GUID_H
