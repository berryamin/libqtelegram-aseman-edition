#ifndef LQTG_HELPSUPPORT
#define LQTG_HELPSUPPORT

#include "telegramtypeobject.h"
#include <QString>
#include "user.h"

class HelpSupport : public TelegramTypeObject
{
public:
    enum HelpSupportType {
        typeHelpSupport = 0x17c6b5f6
    };

    HelpSupport(HelpSupportType classType = typeHelpSupport, InboundPkt *in = 0);
    HelpSupport(InboundPkt *in);
    virtual ~HelpSupport();

    void setPhoneNumber(const QString &phoneNumber);
    QString phoneNumber() const;

    void setUser(const User &user);
    User user() const;

    void setClassType(HelpSupportType classType);
    HelpSupportType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const HelpSupport &b);

private:
    QString m_phoneNumber;
    User m_user;
    HelpSupportType m_classType;
};

#endif // LQTG_HELPSUPPORT
