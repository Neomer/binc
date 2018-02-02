#ifndef NODEMODEL_H
#define NODEMODEL_H

#include <QDateTime>
#include <core/IJsonSerializable.h>
#include <core/types/ConnectionPoint.h>

///
/// \brief NodeModel модель данных представляющая узел P2P-сети.
///
class NodeModel :
        public ConnectionPoint,
        public IJsonSerializable
{
    QDateTime _last_activity;
    int _fails;

public:
    ///
    /// \brief NodeModel инициализирует модель данных
    ///
    NodeModel();
    ///
    /// \brief NodeModel инициализирует модель данных
    /// \param address адрес узла
    /// \param port порт подключения к узлу
    ///
    NodeModel(QHostAddress address, quint16 port);
    ///
    /// \brief getLastActivity дата/время последней активности узла
    /// \return
    ///
    QDateTime getLastActivity() { return _last_activity; }
    ///
    /// \brief setLastActivity дата/время последней активности узла
    /// \param value
    ///
    void setLastActivity(QDateTime value) { _last_activity = value; }
    ///
    /// \brief getFailCount количество ошибок связи
    /// \return
    ///
    int getFailCount() { return _fails; }
    ///
    /// \brief setFailCount количество ошибок связи
    /// \param value
    ///
    void setFailCount(int value) { _fails = value; }

    // IJsonSerializable interface
public:
    void toJsonObject(QJsonObject &out) override;
    void fromJsonObject(QJsonObject &in) override;

};

#endif // NODEMODEL_H
