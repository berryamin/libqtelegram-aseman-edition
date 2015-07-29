#include "inputpeer.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

InputPeer::InputPeer(InputPeerType classType, InboundPkt *in) :
    m_accessHash(0),
    m_chatId(0),
    m_userId(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

InputPeer::InputPeer(InboundPkt *in) :
    m_accessHash(0),
    m_chatId(0),
    m_userId(0),
    m_classType(typeInputPeerEmpty)
{
    fetch(in);
}

void InputPeer::setAccessHash(qint64 accessHash) {
    m_accessHash = accessHash;
}

qint64 InputPeer::accessHash() const {
    return m_accessHash;
}

void InputPeer::setChatId(qint32 chatId) {
    m_chatId = chatId;
}

qint32 InputPeer::chatId() const {
    return m_chatId;
}

void InputPeer::setUserId(qint32 userId) {
    m_userId = userId;
}

qint32 InputPeer::userId() const {
    return m_userId;
}

bool InputPeer::operator ==(const InputPeer &b) {
    return m_accessHash == b.m_accessHash &&
           m_chatId == b.m_chatId &&
           m_userId == b.m_userId;
}

void InputPeer::setClassType(InputPeer::InputPeerType classType) {
    m_classType = classType;
}

InputPeer::InputPeerType InputPeer::classType() const {
    return m_classType;
}

bool InputPeer::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeInputPeerEmpty: {
        return true;
    }
        break;
    
    case typeInputPeerSelf: {
        return true;
    }
        break;
    
    case typeInputPeerContact: {
        m_userId = in->fetchInt();
        return true;
    }
        break;
    
    case typeInputPeerForeign: {
        m_userId = in->fetchInt();
        m_accessHash = in->fetchLong();
        return true;
    }
        break;
    
    case typeInputPeerChat: {
        m_chatId = in->fetchInt();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool InputPeer::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeInputPeerEmpty: {
        return true;
    }
        break;
    
    case typeInputPeerSelf: {
        return true;
    }
        break;
    
    case typeInputPeerContact: {
        out->appendInt(m_userId);
        return true;
    }
        break;
    
    case typeInputPeerForeign: {
        out->appendInt(m_userId);
        out->appendLong(m_accessHash);
        return true;
    }
        break;
    
    case typeInputPeerChat: {
        out->appendInt(m_chatId);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

