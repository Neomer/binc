#ifndef IOBSERVABLEDATASTREAM_H
#define IOBSERVABLEDATASTREAM_H

#include <core/IDataStream.h>
#include <core/ISubject.h>

///
/// \brief The IObservableDataStream поток данных, реализующий интерфейс ISubject для уведомления о поступлении нового блока данных
///
class IObservableDataStream : public IDataStream, public ISubject
{
public:
    IObservableDataStream();
};

#endif // IOBSERVABLEDATASTREAM_H
