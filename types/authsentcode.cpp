#include "authsentcode.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

AuthSentCode::AuthSentCode(AuthSentCodeType classType, InboundPkt *in) :
    m_isPassword(false),
    m_phoneRegistered(false),
    m_sendCallTimeout(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

AuthSentCode::AuthSentCode(InboundPkt *in) :
    m_isPassword(false),
    m_phoneRegistered(false),
    m_sendCallTimeout(0),
    m_classType(typeAuthSentCode)
{
    fetch(in);
}

void AuthSentCode::setIsPassword(bool isPassword) {
    m_isPassword = isPassword;
}

bool AuthSentCode::isPassword() const {
    return m_isPassword;
}

void AuthSentCode::setPhoneCodeHash(const QString &phoneCodeHash) {
    m_phoneCodeHash = phoneCodeHash;
}

QString AuthSentCode::phoneCodeHash() const {
    return m_phoneCodeHash;
}

void AuthSentCode::setPhoneRegistered(bool phoneRegistered) {
    m_phoneRegistered = phoneRegistered;
}

bool AuthSentCode::phoneRegistered() const {
    return m_phoneRegistered;
}

void AuthSentCode::setSendCallTimeout(qint32 sendCallTimeout) {
    m_sendCallTimeout = sendCallTimeout;
}

qint32 AuthSentCode::sendCallTimeout() const {
    return m_sendCallTimeout;
}

bool AuthSentCode::operator ==(const AuthSentCode &b) {
    return m_isPassword == b.m_isPassword &&
           m_phoneCodeHash == b.m_phoneCodeHash &&
           m_phoneRegistered == b.m_phoneRegistered &&
           m_sendCallTimeout == b.m_sendCallTimeout;
}

void AuthSentCode::setClassType(AuthSentCode::AuthSentCodeType classType) {
    m_classType = classType;
}

AuthSentCode::AuthSentCodeType AuthSentCode::classType() const {
    return m_classType;
}

bool AuthSentCode::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeAuthSentCode: {
        m_phoneRegistered = in->fetchBool();
        m_phoneCodeHash = in->fetchQString();
        m_sendCallTimeout = in->fetchInt();
        m_isPassword = in->fetchBool();
        return true;
    }
        break;
    
    case typeAuthSentAppCode: {
        m_phoneRegistered = in->fetchBool();
        m_phoneCodeHash = in->fetchQString();
        m_sendCallTimeout = in->fetchInt();
        m_isPassword = in->fetchBool();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool AuthSentCode::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeAuthSentCode: {
        out->appendBool(m_phoneRegistered);
        out->appendQString(m_phoneCodeHash);
        out->appendInt(m_sendCallTimeout);
        out->appendBool(m_isPassword);
        return true;
    }
        break;
    
    case typeAuthSentAppCode: {
        out->appendBool(m_phoneRegistered);
        out->appendQString(m_phoneCodeHash);
        out->appendInt(m_sendCallTimeout);
        out->appendBool(m_isPassword);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

