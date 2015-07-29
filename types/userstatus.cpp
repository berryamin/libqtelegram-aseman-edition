#include "userstatus.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

UserStatus::UserStatus(UserStatusType classType, InboundPkt *in) :
    m_expires(0),
    m_wasOnline(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

UserStatus::UserStatus(InboundPkt *in) :
    m_expires(0),
    m_wasOnline(0),
    m_classType(typeUserStatusEmpty)
{
    fetch(in);
}

void UserStatus::setExpires(qint32 expires) {
    m_expires = expires;
}

qint32 UserStatus::expires() const {
    return m_expires;
}

void UserStatus::setWasOnline(qint32 wasOnline) {
    m_wasOnline = wasOnline;
}

qint32 UserStatus::wasOnline() const {
    return m_wasOnline;
}

bool UserStatus::operator ==(const UserStatus &b) {
    return m_expires == b.m_expires &&
           m_wasOnline == b.m_wasOnline;
}

void UserStatus::setClassType(UserStatus::UserStatusType classType) {
    m_classType = classType;
}

UserStatus::UserStatusType UserStatus::classType() const {
    return m_classType;
}

bool UserStatus::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeUserStatusEmpty: {
        return true;
    }
        break;
    
    case typeUserStatusOnline: {
        m_expires = in->fetchInt();
        return true;
    }
        break;
    
    case typeUserStatusOffline: {
        m_wasOnline = in->fetchInt();
        return true;
    }
        break;
    
    case typeUserStatusRecently: {
        return true;
    }
        break;
    
    case typeUserStatusLastWeek: {
        return true;
    }
        break;
    
    case typeUserStatusLastMonth: {
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool UserStatus::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeUserStatusEmpty: {
        return true;
    }
        break;
    
    case typeUserStatusOnline: {
        out->appendInt(m_expires);
        return true;
    }
        break;
    
    case typeUserStatusOffline: {
        out->appendInt(m_wasOnline);
        return true;
    }
        break;
    
    case typeUserStatusRecently: {
        return true;
    }
        break;
    
    case typeUserStatusLastWeek: {
        return true;
    }
        break;
    
    case typeUserStatusLastMonth: {
        return true;
    }
        break;
    
    default:
        return false;
    }
}

