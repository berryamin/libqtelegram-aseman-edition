#ifndef LQTG_ACCOUNTPASSWORDSETTINGS
#define LQTG_ACCOUNTPASSWORDSETTINGS

#include "telegramtypeobject.h"
#include <QString>

class AccountPasswordSettings : public TelegramTypeObject
{
public:
    enum AccountPasswordSettingsType {
        typeAccountPasswordSettings = 0xb7b72ab3
    };

    AccountPasswordSettings(AccountPasswordSettingsType classType = typeAccountPasswordSettings, InboundPkt *in = 0);
    AccountPasswordSettings(InboundPkt *in);
    virtual ~AccountPasswordSettings();

    void setEmail(const QString &email);
    QString email() const;

    void setClassType(AccountPasswordSettingsType classType);
    AccountPasswordSettingsType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const AccountPasswordSettings &b);

private:
    QString m_email;
    AccountPasswordSettingsType m_classType;
};

#endif // LQTG_ACCOUNTPASSWORDSETTINGS
