#include "messageschats.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

MessagesChats::MessagesChats(MessagesChatsType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

MessagesChats::MessagesChats(InboundPkt *in) :
    m_classType(typeMessagesChats)
{
    fetch(in);
}

void MessagesChats::setChats(const QList<Chat> &chats) {
    m_chats = chats;
}

QList<Chat> MessagesChats::chats() const {
    return m_chats;
}

bool MessagesChats::operator ==(const MessagesChats &b) {
    return m_chats == b.m_chats;
}

void MessagesChats::setClassType(MessagesChats::MessagesChatsType classType) {
    m_classType = classType;
}

MessagesChats::MessagesChatsType MessagesChats::classType() const {
    return m_classType;
}

bool MessagesChats::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeMessagesChats: {
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_chats_length = in->fetchInt();
        m_chats.clear();
        for (qint32 i = 0; i < m_chats_length; i++) {
            Chat type;
            type.fetch(in);
            m_chats.append(type);
        }
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool MessagesChats::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessagesChats: {
        out->appendInt(TL_Vector);
        out->appendInt(m_chats.count());
        for (qint32 i = 0; i < m_chats.count(); i++) {
            m_chats[i].push(out);
        }
        return true;
    }
        break;
    
    default:
        return false;
    }
}

