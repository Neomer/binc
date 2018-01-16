#ifndef CONNECTIONPOINT_H
#define CONNECTIONPOINT_H

#include <QHostAddress>

///
/// \brief The ConnectionPoint класс для представления точки доступа <адрес>:<порт> по TCP
///
class ConnectionPoint
{
public:
    ///
    /// \brief ConnectionPoint создает точку доступа 0.0.0.0:0
    ///
    ConnectionPoint();
    ///
    /// \brief ConnectionPoint создает точку доступа <address>:<port>
    /// \param address
    /// \param port
    ///
    ConnectionPoint(QHostAddress address, quint16 port);
    ConnectionPoint(const ConnectionPoint &other);
    ///
    /// \brief getAddress возвращает адрес
    /// \return
    ///
    QHostAddress getAddress() { return _address; }
    ///
    /// \brief setAddress устанавливает адрес
    /// \param value
    ///
    void setAddress(QHostAddress value) { _address = value; }
    ///
    /// \brief getPort возвращает порт
    /// \return
    ///
    quint16 getPort() { return _port; }
    ///
    /// \brief setPort устанавливает порт
    /// \param value
    ///
    void setPort(quint16 value) { _port = value; }

private:
    QHostAddress _address;
    quint16 _port;
};

#endif // CONNECTIONPOINT_H
