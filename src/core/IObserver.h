#IFNDEF	_IOBSERVER_H_
#DEFINE	_IOBSERVER_H_

#include <core/IData.h>

class IObserver
{
public:
	virtual void update(IData *data) = 0;
}

#ENDIF