#ifndef CHAT_H
#define CHAT_H

#include <core/Context.h>
#include <core/net/UdpStream.h>

class Chat : public IObserver
{
public:
    Chat();
    ~Chat();

    void run();

    // IObserver interface
public:
    void update(const Guid &subject, void *data) override;

private:
    UdpStream *_stream;
};

#endif // CHAT_H
