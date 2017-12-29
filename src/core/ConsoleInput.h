#ifndef CONSOLEINPUT_H
#define CONSOLEINPUT_H

#include <QThread>
#include "ConsoleInputException.h"
#include "ISubject.h"

///
/// \brief The ConsoleInput class класс в фоновом потоке считывающий введенную с клавиатуры информацию.
/// При нажатии Enter введенный текст отправляется всем, кто подписался. Отправляется (char *).
///
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
