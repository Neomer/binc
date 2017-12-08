#ifndef	_ISUBJECT_H_
#define	_ISUBJECT_H_

#include <QList>
#include <core/IObserver.h>

class ISubject
{
public:
	ISubject();
	~ISubject();
	void subscribe(IObserver *observer);
	void unsubscribe(IObserver *observer);
	
private:
	QList<IObserver *> _list;
};

#endif
