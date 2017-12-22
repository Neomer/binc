#ifndef GUID_H
#define GUID_H

#include <QString>

///
/// \brief The Guid class класс для работы с уникальными идентификаторами
///
class Guid
{
public:
    Guid();
    Guid(const Guid& other);

    QString toString();

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

// Operators
    bool operator ==(const Guid &other);
    Guid &operator =(const Guid &other);

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
};

#endif // GUID_H
