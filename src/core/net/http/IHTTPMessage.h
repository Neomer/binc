#ifndef IHTTPMESSAGE_H
#define IHTTPMESSAGE_H

#include <core/net/INetMessageWithHeaders.h>
#include <core/types/Version.h>

///
/// \brief The IHTTPMessage класс, расширяющий INetMessageWithHeaders для поддержки версии HTTP-протокола.
/// По умолчанию HTTPv1.1
///
class IHTTPMessage : public INetMessageWithHeaders
{
public:
    IHTTPMessage();

    ///
    /// \brief version Версия протокола HTTP
    /// \return
    ///
    Version getVersion() { return _version; }
    ///
    /// \brief setVersion устанавливает версию протокола HTTP
    /// \param value
    ///
    void setVersion(Version value) { _version = value; }

private:
    Version _version;
};

#endif // IHTTPMESSAGE_H
