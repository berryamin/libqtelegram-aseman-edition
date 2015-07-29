#ifndef LQTG_AUTHSENTCODE
#define LQTG_AUTHSENTCODE

#include "telegramtypeobject.h"
#include <QString>
#include <QtGlobal>

class AuthSentCode : public TelegramTypeObject
{
public:
    enum AuthSentCodeType {
        typeAuthSentCode = 0xefed51d9,
        typeAuthSentAppCode = 0xe325edcf
    };

    AuthSentCode(AuthSentCodeType classType = typeAuthSentCode, InboundPkt *in = 0);
    AuthSentCode(InboundPkt *in);
    virtual ~AuthSentCode();

    void setIsPassword(bool isPassword);
    bool isPassword() const;

    void setPhoneCodeHash(const QString &phoneCodeHash);
    QString phoneCodeHash() const;

    void setPhoneRegistered(bool phoneRegistered);
    bool phoneRegistered() const;

    void setSendCallTimeout(qint32 sendCallTimeout);
    qint32 sendCallTimeout() const;

    void setClassType(AuthSentCodeType classType);
    AuthSentCodeType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const AuthSentCode &b);

private:
    bool m_isPassword;
    QString m_phoneCodeHash;
    bool m_phoneRegistered;
    qint32 m_sendCallTimeout;
    AuthSentCodeType m_classType;
};

#endif // LQTG_AUTHSENTCODE
