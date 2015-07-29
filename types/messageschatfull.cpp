#include "messageschatfull.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

MessagesChatFull::MessagesChatFull(MessagesChatFullType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

MessagesChatFull::MessagesChatFull(InboundPkt *in) :
    m_classType(typeMessagesChatFull)
{
    fetch(in);
}

void MessagesChatFull::setChats(const QList<Chat> &chats) {
    m_chats = chats;
}

QList<Chat> MessagesChatFull::chats() const {
    return m_chats;
}

void MessagesChatFull::setFullChat(const ChatFull &fullChat) {
    m_fullChat = fullChat;
}

ChatFull MessagesChatFull::fullChat() const {
    return m_fullChat;
}

void MessagesChatFull::setUsers(const QList<User> &users) {
    m_users = users;
}

QList<User> MessagesChatFull::users() const {
    return m_users;
}

bool MessagesChatFull::operator ==(const MessagesChatFull &b) {
    return m_chats == b.m_chats &&
           m_fullChat == b.m_fullChat &&
           m_users == b.m_users;
}

void MessagesChatFull::setClassType(MessagesChatFull::MessagesChatFullType classType) {
    m_classType = classType;
}

MessagesChatFull::MessagesChatFullType MessagesChatFull::classType() const {
    return m_classType;
}

bool MessagesChatFull::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeMessagesChatFull: {
        m_fullChat.fetch(in);
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_chats_length = in->fetchInt();
        m_chats.clear();
        for (qint32 i = 0; i < m_chats_length; i++) {
            Chat type;
            type.fetch(in);
            m_chats.append(type);
        }
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_users_length = in->fetchInt();
        m_users.clear();
        for (qint32 i = 0; i < m_users_length; i++) {
            User type;
            type.fetch(in);
            m_users.append(type);
        }
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool MessagesChatFull::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessagesChatFull: {
        m_fullChat.push(out);
        out->appendInt(TL_Vector);
        out->appendInt(m_chats.count());
        for (qint32 i = 0; i < m_chats.count(); i++) {
            m_chats[i].push(out);
        }
        out->appendInt(TL_Vector);
        out->appendInt(m_users.count());
        for (qint32 i = 0; i < m_users.count(); i++) {
            m_users[i].push(out);
        }
        return true;
    }
        break;
    
    default:
        return false;
    }
}

