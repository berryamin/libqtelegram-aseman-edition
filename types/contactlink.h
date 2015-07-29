#ifndef LQTG_CONTACTLINK
#define LQTG_CONTACTLINK

#include "telegramtypeobject.h"

class ContactLink : public TelegramTypeObject
{
public:
    enum ContactLinkType {
        typeContactLinkUnknown = 0x5f4f9247,
        typeContactLinkNone = 0xfeedd3ad,
        typeContactLinkHasPhone = 0x268f3f59,
        typeContactLinkContact = 0xd502c2d0
    };

    ContactLink(ContactLinkType classType = typeContactLinkUnknown, InboundPkt *in = 0);
    ContactLink(InboundPkt *in);
    virtual ~ContactLink();

    void setClassType(ContactLinkType classType);
    ContactLinkType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const ContactLink &b);

private:
    ContactLinkType m_classType;
};

#endif // LQTG_CONTACTLINK
