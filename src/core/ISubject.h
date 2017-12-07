#IFNDEF	_ISUBJECT_H_
#DEFINE	_ISUBJECT_H_

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
}

#ENDIF