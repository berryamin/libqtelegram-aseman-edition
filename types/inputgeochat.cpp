#include "inputgeochat.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

InputGeoChat::InputGeoChat(InputGeoChatType classType, InboundPkt *in) :
    m_accessHash(0),
    m_chatId(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

InputGeoChat::InputGeoChat(InboundPkt *in) :
    m_accessHash(0),
    m_chatId(0),
    m_classType(typeInputGeoChat)
{
    fetch(in);
}

void InputGeoChat::setAccessHash(qint64 accessHash) {
    m_accessHash = accessHash;
}

qint64 InputGeoChat::accessHash() const {
    return m_accessHash;
}

void InputGeoChat::setChatId(qint32 chatId) {
    m_chatId = chatId;
}

qint32 InputGeoChat::chatId() const {
    return m_chatId;
}

bool InputGeoChat::operator ==(const InputGeoChat &b) {
    return m_accessHash == b.m_accessHash &&
           m_chatId == b.m_chatId;
}

void InputGeoChat::setClassType(InputGeoChat::InputGeoChatType classType) {
    m_classType = classType;
}

InputGeoChat::InputGeoChatType InputGeoChat::classType() const {
    return m_classType;
}

bool InputGeoChat::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeInputGeoChat: {
        m_chatId = in->fetchInt();
        m_accessHash = in->fetchLong();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool InputGeoChat::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeInputGeoChat: {
        out->appendInt(m_chatId);
        out->appendLong(m_accessHash);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

