#include "contactslink.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

ContactsLink::ContactsLink(ContactsLinkType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

ContactsLink::ContactsLink(InboundPkt *in) :
    m_classType(typeContactsLink)
{
    fetch(in);
}

void ContactsLink::setForeignLink(const ContactLink &foreignLink) {
    m_foreignLink = foreignLink;
}

ContactLink ContactsLink::foreignLink() const {
    return m_foreignLink;
}

void ContactsLink::setMyLink(const ContactLink &myLink) {
    m_myLink = myLink;
}

ContactLink ContactsLink::myLink() const {
    return m_myLink;
}

void ContactsLink::setUser(const User &user) {
    m_user = user;
}

User ContactsLink::user() const {
    return m_user;
}

bool ContactsLink::operator ==(const ContactsLink &b) {
    return m_foreignLink == b.m_foreignLink &&
           m_myLink == b.m_myLink &&
           m_user == b.m_user;
}

void ContactsLink::setClassType(ContactsLink::ContactsLinkType classType) {
    m_classType = classType;
}

ContactsLink::ContactsLinkType ContactsLink::classType() const {
    return m_classType;
}

bool ContactsLink::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeContactsLink: {
        m_myLink.fetch(in);
        m_foreignLink.fetch(in);
        m_user.fetch(in);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool ContactsLink::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeContactsLink: {
        m_myLink.push(out);
        m_foreignLink.push(out);
        m_user.push(out);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

