#include <core/ISubject.h>

ISubject::ISubject()
{
}

ISubject::~ISubject()
{
}

void ISubject::subscribe(IObserver *observer)
{
	_list << observer;
}