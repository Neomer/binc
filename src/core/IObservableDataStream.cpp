#include "IObservableDataStream.h"

IObservableDataStream::IObservableDataStream(QObject *parent) :
    QObject(parent),
    ISubject()
{

}
