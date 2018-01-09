#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <QString>

///
/// \brief The StringUtils class Абстрактный класс для статических функций работы со строками
///
class StringUtils
{
public:
    ///
    /// \brief IsNullOrEmpty Возвращает TRUE, если строка пустая или NULL
    /// \param value проверяемая строка
    /// \return
    ///
    static bool IsNullOrEmpty(QString value);
    ///
    /// \brief TrimEx Удаляет из начала и конца строки символы [\s,\r,\t,\n]
    /// \param value
    /// \return
    ///
    static QString TrimEx(QString value);

private:
    StringUtils();
};

#endif // STRINGUTILS_H
