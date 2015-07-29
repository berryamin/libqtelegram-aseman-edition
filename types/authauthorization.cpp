#include "authauthorization.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

AuthAuthorization::AuthAuthorization(AuthAuthorizationType classType, InboundPkt *in) :
    m_expires(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

AuthAuthorization::AuthAuthorization(InboundPkt *in) :
    m_expires(0),
    m_classType(typeAuthAuthorization)
{
    fetch(in);
}

void AuthAuthorization::setExpires(qint32 expires) {
    m_expires = expires;
}

qint32 AuthAuthorization::expires() const {
    return m_expires;
}

void AuthAuthorization::setUser(const User &user) {
    m_user = user;
}

User AuthAuthorization::user() const {
    return m_user;
}

bool AuthAuthorization::operator ==(const AuthAuthorization &b) {
    return m_expires == b.m_expires &&
           m_user == b.m_user;
}

void AuthAuthorization::setClassType(AuthAuthorization::AuthAuthorizationType classType) {
    m_classType = classType;
}

AuthAuthorization::AuthAuthorizationType AuthAuthorization::classType() const {
    return m_classType;
}

bool AuthAuthorization::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeAuthAuthorization: {
        m_expires = in->fetchInt();
        m_user.fetch(in);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool AuthAuthorization::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeAuthAuthorization: {
        out->appendInt(m_expires);
        m_user.push(out);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

