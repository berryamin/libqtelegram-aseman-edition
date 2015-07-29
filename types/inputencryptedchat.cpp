#include "inputencryptedchat.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

InputEncryptedChat::InputEncryptedChat(InputEncryptedChatType classType, InboundPkt *in) :
    m_accessHash(0),
    m_chatId(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

InputEncryptedChat::InputEncryptedChat(InboundPkt *in) :
    m_accessHash(0),
    m_chatId(0),
    m_classType(typeInputEncryptedChat)
{
    fetch(in);
}

void InputEncryptedChat::setAccessHash(qint64 accessHash) {
    m_accessHash = accessHash;
}

qint64 InputEncryptedChat::accessHash() const {
    return m_accessHash;
}

void InputEncryptedChat::setChatId(qint32 chatId) {
    m_chatId = chatId;
}

qint32 InputEncryptedChat::chatId() const {
    return m_chatId;
}

bool InputEncryptedChat::operator ==(const InputEncryptedChat &b) {
    return m_accessHash == b.m_accessHash &&
           m_chatId == b.m_chatId;
}

void InputEncryptedChat::setClassType(InputEncryptedChat::InputEncryptedChatType classType) {
    m_classType = classType;
}

InputEncryptedChat::InputEncryptedChatType InputEncryptedChat::classType() const {
    return m_classType;
}

bool InputEncryptedChat::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeInputEncryptedChat: {
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

bool InputEncryptedChat::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeInputEncryptedChat: {
        out->appendInt(m_chatId);
        out->appendLong(m_accessHash);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

