#include "inputcontact.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

InputContact::InputContact(InputContactType classType, InboundPkt *in) :
    m_clientId(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

InputContact::InputContact(InboundPkt *in) :
    m_clientId(0),
    m_classType(typeInputPhoneContact)
{
    fetch(in);
}

void InputContact::setClientId(qint64 clientId) {
    m_clientId = clientId;
}

qint64 InputContact::clientId() const {
    return m_clientId;
}

void InputContact::setFirstName(const QString &firstName) {
    m_firstName = firstName;
}

QString InputContact::firstName() const {
    return m_firstName;
}

void InputContact::setLastName(const QString &lastName) {
    m_lastName = lastName;
}

QString InputContact::lastName() const {
    return m_lastName;
}

void InputContact::setPhone(const QString &phone) {
    m_phone = phone;
}

QString InputContact::phone() const {
    return m_phone;
}

bool InputContact::operator ==(const InputContact &b) {
    return m_clientId == b.m_clientId &&
           m_firstName == b.m_firstName &&
           m_lastName == b.m_lastName &&
           m_phone == b.m_phone;
}

void InputContact::setClassType(InputContact::InputContactType classType) {
    m_classType = classType;
}

InputContact::InputContactType InputContact::classType() const {
    return m_classType;
}

bool InputContact::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeInputPhoneContact: {
        m_clientId = in->fetchLong();
        m_phone = in->fetchQString();
        m_firstName = in->fetchQString();
        m_lastName = in->fetchQString();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool InputContact::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeInputPhoneContact: {
        out->appendLong(m_clientId);
        out->appendQString(m_phone);
        out->appendQString(m_firstName);
        out->appendQString(m_lastName);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

