#ifndef IOBSERVABLEDATASTREAM_H
#define IOBSERVABLEDATASTREAM_H

#include <core/IDataStream.h>
#include <core/ISubject.h>
#include <core/JsonSerializableEntity.h>

///
/// \brief The IObservableDataStream поток данных, реализующий интерфейс ISubject для уведомления о поступлении нового блока данных
///
class IObservableDataStream :
        public QObject,
        public IDataStream,
        public ISubject
{
    Q_OBJECT

public:
    IObservableDataStream(QObject * parent = 0);

signals:
    void onConnectionClosed(IObservableDataStream *);
    void onEntityReady(JsonSerializableEntity *);
};

#endif // IOBSERVABLEDATASTREAM_H
