#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <QObject>
#include <QException>

class BaseException : public QException
{
    // QException interface
public:
    BaseException(const char *message);

    void raise() const override { throw *this; }
    QException *clone() const override  { return new BaseException(*this); }
    const char *what() const throw() { return _msg; }

private:
     const char * _msg;
};

#endif // BASEEXCEPTION_H
