#include "contactsuggested.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

ContactSuggested::ContactSuggested(ContactSuggestedType classType, InboundPkt *in) :
    m_mutualContacts(0),
    m_userId(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

ContactSuggested::ContactSuggested(InboundPkt *in) :
    m_mutualContacts(0),
    m_userId(0),
    m_classType(typeContactSuggested)
{
    fetch(in);
}

void ContactSuggested::setMutualContacts(qint32 mutualContacts) {
    m_mutualContacts = mutualContacts;
}

qint32 ContactSuggested::mutualContacts() const {
    return m_mutualContacts;
}

void ContactSuggested::setUserId(qint32 userId) {
    m_userId = userId;
}

qint32 ContactSuggested::userId() const {
    return m_userId;
}

bool ContactSuggested::operator ==(const ContactSuggested &b) {
    return m_mutualContacts == b.m_mutualContacts &&
           m_userId == b.m_userId;
}

void ContactSuggested::setClassType(ContactSuggested::ContactSuggestedType classType) {
    m_classType = classType;
}

ContactSuggested::ContactSuggestedType ContactSuggested::classType() const {
    return m_classType;
}

bool ContactSuggested::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeContactSuggested: {
        m_userId = in->fetchInt();
        m_mutualContacts = in->fetchInt();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool ContactSuggested::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeContactSuggested: {
        out->appendInt(m_userId);
        out->appendInt(m_mutualContacts);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

