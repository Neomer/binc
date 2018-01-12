#ifndef TRANSPORTPROVIDER_H
#define TRANSPORTPROVIDER_H

#include <core/IDataStream.h>
#include <core/IObserver.h>
#include <core/ISubject.h>

///
/// \brief The TransportProvider класс работающий с группой контекстов обмена данными (UdpStream, NetDataStream и пр)
///
class TransportProvider : public IObserver, public ISubject
{
public:
    TransportProvider();

    // IObserver interface
public:
    void update(const Guid &subject, void *data) override;

private:
    QList<IDataStream *> _streams;
};

#endif // TRANSPORTPROVIDER_H
