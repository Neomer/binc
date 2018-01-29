#ifndef TRANSPORTPROVIDER_H
#define TRANSPORTPROVIDER_H

#include <QObject>
#include <core/IObservableDataStream.h>
#include <core/IObserver.h>
#include <core/ISubject.h>
#include <core/JsonSerializableIdentifyedEntity.h>
#include <core/MemoryCache.h>

///
/// \brief The TransportProvider класс работающий с группой контекстов обмена данными (UdpStream, NetDataStream, TcpStream и пр)
///
class TransportProvider : public QObject, public IObserver, public ISubject
{
    Q_OBJECT

public:
    TransportProvider();

    ///
    /// \brief add добавляет поток в список отслеживаемых
    /// \param stream
    ///
    void add(IObservableDataStream *stream);

    void write(JsonSerializableIdentifyedEntity *data);

    // IObserver interface
public:
    void update(const Guid &subject, void *data) override;

private slots:
    void onConnectionClosed(IObservableDataStream *stream);

signals:
    void onEntityReady(JsonSerializableIdentifyedEntity *);
    void streamCountChanged(int);

private:
    QList<IObservableDataStream *> _streams;
    // Переданные транспортные блоки
    MemoryCache _blocks;
};

#endif // TRANSPORTPROVIDER_H
