#ifndef LQTG_USERSTATUS
#define LQTG_USERSTATUS

#include "telegramtypeobject.h"
#include <QtGlobal>

class UserStatus : public TelegramTypeObject
{
public:
    enum UserStatusType {
        typeUserStatusEmpty = 0x9d05049,
        typeUserStatusOnline = 0xedb93949,
        typeUserStatusOffline = 0x8c703f,
        typeUserStatusRecently = 0xe26f42f1,
        typeUserStatusLastWeek = 0x7bf09fc,
        typeUserStatusLastMonth = 0x77ebc742
    };

    UserStatus(UserStatusType classType = typeUserStatusEmpty, InboundPkt *in = 0);
    UserStatus(InboundPkt *in);
    virtual ~UserStatus();

    void setExpires(qint32 expires);
    qint32 expires() const;

    void setWasOnline(qint32 wasOnline);
    qint32 wasOnline() const;

    void setClassType(UserStatusType classType);
    UserStatusType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const UserStatus &b);

private:
    qint32 m_expires;
    qint32 m_wasOnline;
    UserStatusType m_classType;
};

#endif // LQTG_USERSTATUS
