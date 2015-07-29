#include "messagesdhconfig.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

MessagesDhConfig::MessagesDhConfig(MessagesDhConfigType classType, InboundPkt *in) :
    m_g(0),
    m_version(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

MessagesDhConfig::MessagesDhConfig(InboundPkt *in) :
    m_g(0),
    m_version(0),
    m_classType(typeMessagesDhConfigNotModified)
{
    fetch(in);
}

void MessagesDhConfig::setG(qint32 g) {
    m_g = g;
}

qint32 MessagesDhConfig::g() const {
    return m_g;
}

void MessagesDhConfig::setP(const QByteArray &p) {
    m_p = p;
}

QByteArray MessagesDhConfig::p() const {
    return m_p;
}

void MessagesDhConfig::setRandom(const QByteArray &random) {
    m_random = random;
}

QByteArray MessagesDhConfig::random() const {
    return m_random;
}

void MessagesDhConfig::setVersion(qint32 version) {
    m_version = version;
}

qint32 MessagesDhConfig::version() const {
    return m_version;
}

bool MessagesDhConfig::operator ==(const MessagesDhConfig &b) {
    return m_g == b.m_g &&
           m_p == b.m_p &&
           m_random == b.m_random &&
           m_version == b.m_version;
}

void MessagesDhConfig::setClassType(MessagesDhConfig::MessagesDhConfigType classType) {
    m_classType = classType;
}

MessagesDhConfig::MessagesDhConfigType MessagesDhConfig::classType() const {
    return m_classType;
}

bool MessagesDhConfig::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeMessagesDhConfigNotModified: {
        m_random = in->fetchBytes();
        return true;
    }
        break;
    
    case typeMessagesDhConfig: {
        m_g = in->fetchInt();
        m_p = in->fetchBytes();
        m_version = in->fetchInt();
        m_random = in->fetchBytes();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool MessagesDhConfig::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessagesDhConfigNotModified: {
        out->appendBytes(m_random);
        return true;
    }
        break;
    
    case typeMessagesDhConfig: {
        out->appendInt(m_g);
        out->appendBytes(m_p);
        out->appendInt(m_version);
        out->appendBytes(m_random);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

