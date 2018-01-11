#include <core/ISubject.h>
#include <QDebug>

ISubject::ISubject()
{
    _guid = Guid::randomGuid();
    _list.clear();
}

ISubject::~ISubject()
{
    _list.clear();
}

void ISubject::subscribe(IObserver *observer)
{
	_list << observer;
}

void ISubject::unsubscribe(IObserver *observer)
{
    _list.removeOne(observer);
}

void ISubject::update(void *data)
{
    foreach (IObserver *o, _list)
    {
        try
        {
            o->update(_guid, data);
        }
        catch (BaseException &ex)
        {
            qDebug() << ex.what();
        }
    }
}

