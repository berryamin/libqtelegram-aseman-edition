#include "accountpassword.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

AccountPassword::AccountPassword(AccountPasswordType classType, InboundPkt *in) :
    m_hasRecovery(false),
    m_classType(classType)
{
    if(in) fetch(in);
}

AccountPassword::AccountPassword(InboundPkt *in) :
    m_hasRecovery(false),
    m_classType(typeAccountNoPassword)
{
    fetch(in);
}

void AccountPassword::setCurrentSalt(const QByteArray &currentSalt) {
    m_currentSalt = currentSalt;
}

QByteArray AccountPassword::currentSalt() const {
    return m_currentSalt;
}

void AccountPassword::setEmailUnconfirmedPattern(const QString &emailUnconfirmedPattern) {
    m_emailUnconfirmedPattern = emailUnconfirmedPattern;
}

QString AccountPassword::emailUnconfirmedPattern() const {
    return m_emailUnconfirmedPattern;
}

void AccountPassword::setHasRecovery(bool hasRecovery) {
    m_hasRecovery = hasRecovery;
}

bool AccountPassword::hasRecovery() const {
    return m_hasRecovery;
}

void AccountPassword::setHint(const QString &hint) {
    m_hint = hint;
}

QString AccountPassword::hint() const {
    return m_hint;
}

void AccountPassword::setNewSalt(const QByteArray &newSalt) {
    m_newSalt = newSalt;
}

QByteArray AccountPassword::newSalt() const {
    return m_newSalt;
}

bool AccountPassword::operator ==(const AccountPassword &b) {
    return m_currentSalt == b.m_currentSalt &&
           m_emailUnconfirmedPattern == b.m_emailUnconfirmedPattern &&
           m_hasRecovery == b.m_hasRecovery &&
           m_hint == b.m_hint &&
           m_newSalt == b.m_newSalt;
}

void AccountPassword::setClassType(AccountPassword::AccountPasswordType classType) {
    m_classType = classType;
}

AccountPassword::AccountPasswordType AccountPassword::classType() const {
    return m_classType;
}

bool AccountPassword::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeAccountNoPassword: {
        m_newSalt = in->fetchBytes();
        m_emailUnconfirmedPattern = in->fetchQString();
        return true;
    }
        break;
    
    case typeAccountPassword: {
        m_currentSalt = in->fetchBytes();
        m_newSalt = in->fetchBytes();
        m_hint = in->fetchQString();
        m_hasRecovery = in->fetchBool();
        m_emailUnconfirmedPattern = in->fetchQString();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool AccountPassword::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeAccountNoPassword: {
        out->appendBytes(m_newSalt);
        out->appendQString(m_emailUnconfirmedPattern);
        return true;
    }
        break;
    
    case typeAccountPassword: {
        out->appendBytes(m_currentSalt);
        out->appendBytes(m_newSalt);
        out->appendQString(m_hint);
        out->appendBool(m_hasRecovery);
        out->appendQString(m_emailUnconfirmedPattern);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

