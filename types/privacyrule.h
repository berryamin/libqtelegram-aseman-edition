#ifndef LQTG_PRIVACYRULE
#define LQTG_PRIVACYRULE

#include "telegramtypeobject.h"
#include <QList>
#include <QtGlobal>

class PrivacyRule : public TelegramTypeObject
{
public:
    enum PrivacyRuleType {
        typePrivacyValueAllowContacts = 0xfffe1bac,
        typePrivacyValueAllowAll = 0x65427b82,
        typePrivacyValueAllowUsers = 0x4d5bbe0c,
        typePrivacyValueDisallowContacts = 0xf888fa1a,
        typePrivacyValueDisallowAll = 0x8b73e763,
        typePrivacyValueDisallowUsers = 0xc7f49b7
    };

    PrivacyRule(PrivacyRuleType classType = typePrivacyValueAllowContacts, InboundPkt *in = 0);
    PrivacyRule(InboundPkt *in);
    virtual ~PrivacyRule();

    void setUsers(const QList<qint32> &users);
    QList<qint32> users() const;

    void setClassType(PrivacyRuleType classType);
    PrivacyRuleType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const PrivacyRule &b);

private:
    QList<qint32> m_users;
    PrivacyRuleType m_classType;
};

#endif // LQTG_PRIVACYRULE
