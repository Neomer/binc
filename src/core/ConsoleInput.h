#ifndef CONSOLEINPUT_H
#define CONSOLEINPUT_H

#include <QThread>
#include "ConsoleInputException.h"
#include "ISubject.h"

class ConsoleInput : public QThread, public ISubject
{
    Q_OBJECT
public:
    explicit ConsoleInput(QObject *parent = nullptr);

    // QThread interface
protected:
    void run() override;

private:
};
#endif // CONSOLEINPUT_H
