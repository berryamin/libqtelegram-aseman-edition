#ifndef LQTG_CONTACTSLINK
#define LQTG_CONTACTSLINK

#include "telegramtypeobject.h"
#include "contactlink.h"
#include "user.h"

class ContactsLink : public TelegramTypeObject
{
public:
    enum ContactsLinkType {
        typeContactsLink = 0x3ace484c
    };

    ContactsLink(ContactsLinkType classType = typeContactsLink, InboundPkt *in = 0);
    ContactsLink(InboundPkt *in);
    virtual ~ContactsLink();

    void setForeignLink(const ContactLink &foreignLink);
    ContactLink foreignLink() const;

    void setMyLink(const ContactLink &myLink);
    ContactLink myLink() const;

    void setUser(const User &user);
    User user() const;

    void setClassType(ContactsLinkType classType);
    ContactsLinkType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const ContactsLink &b);

private:
    ContactLink m_foreignLink;
    ContactLink m_myLink;
    User m_user;
    ContactsLinkType m_classType;
};

#endif // LQTG_CONTACTSLINK
