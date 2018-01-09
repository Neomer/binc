#ifndef INETMESSAGEWITHHEADERS_H
#define INETMESSAGEWITHHEADERS_H

#include <QString>
#include <QMap>

///
/// \brief The INetMessageWithHeaders класс для работы с передаваемыми по интернет каналу сообщениями,
/// содержащими блок данных с заголовками. Необходим для реализации протоколов HTTP, E-MAIL и пр.
///
class INetMessageWithHeaders
{
public:
    INetMessageWithHeaders();

    ///
    /// \brief compile компилирует сообщение в готовый для отправки пакет
    /// \return
    ///
    QString compile();
    ///
    /// \brief setHeader устанавливает значение value заголовка с именем name
    /// \param name
    /// \param value
    /// \return
    ///
    void setHeader(QString name, QString value);
    ///
    /// \brief header возвращает значение заголовка с именем name, если такого нет, то пустую строку
    /// \param name
    /// \return
    ///
    QString header(QString name);
    ///
    /// \brief content Тело сообщения
    /// \return
    ///
    QString content() { return _content; }
    ///
    /// \brief content устанавливает значение тела сообщения
    /// \param value
    ///
    void setContent(QString value) { _content = value; }
    ///
    /// \brief parse разбирает данные из пакета
    /// \param data
    ///
    void parse(QString data);


protected:
    ///
    /// \brief statusRow Виртуальный метод. Наследники должны вернуть корректную статусную строку (идет первой в скомпилированном сообщении)
    /// \return
    ///
    virtual QString statusRow() = 0;
    ///
    /// \brief parseStatusRow Виртуальный метод. Наследники должны корректно распознать статусную строку (идет первой в скомпилированном сообщении)
    ///
    virtual void parseStatusRow(QString data) = 0;

private:
    ///
    /// \brief compileHeaders компилирует заголовки
    ///
    QString compileHeaders();

    QMap<QString, QString> _headers;
    QString _content;
};

#endif // INETMESSAGEWITHHEADERS_H
