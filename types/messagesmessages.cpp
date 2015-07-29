#include "messagesmessages.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

MessagesMessages::MessagesMessages(MessagesMessagesType classType, InboundPkt *in) :
    m_count(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

MessagesMessages::MessagesMessages(InboundPkt *in) :
    m_count(0),
    m_classType(typeMessagesMessages)
{
    fetch(in);
}

void MessagesMessages::setChats(const QList<Chat> &chats) {
    m_chats = chats;
}

QList<Chat> MessagesMessages::chats() const {
    return m_chats;
}

void MessagesMessages::setCount(qint32 count) {
    m_count = count;
}

qint32 MessagesMessages::count() const {
    return m_count;
}

void MessagesMessages::setMessages(const QList<Message> &messages) {
    m_messages = messages;
}

QList<Message> MessagesMessages::messages() const {
    return m_messages;
}

void MessagesMessages::setUsers(const QList<User> &users) {
    m_users = users;
}

QList<User> MessagesMessages::users() const {
    return m_users;
}

bool MessagesMessages::operator ==(const MessagesMessages &b) {
    return m_chats == b.m_chats &&
           m_count == b.m_count &&
           m_messages == b.m_messages &&
           m_users == b.m_users;
}

void MessagesMessages::setClassType(MessagesMessages::MessagesMessagesType classType) {
    m_classType = classType;
}

MessagesMessages::MessagesMessagesType MessagesMessages::classType() const {
    return m_classType;
}

bool MessagesMessages::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeMessagesMessages: {
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_messages_length = in->fetchInt();
        m_messages.clear();
        for (qint32 i = 0; i < m_messages_length; i++) {
            Message type;
            type.fetch(in);
            m_messages.append(type);
        }
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
    
    case typeMessagesMessagesSlice: {
        m_count = in->fetchInt();
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_messages_length = in->fetchInt();
        m_messages.clear();
        for (qint32 i = 0; i < m_messages_length; i++) {
            Message type;
            type.fetch(in);
            m_messages.append(type);
        }
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

bool MessagesMessages::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessagesMessages: {
        out->appendInt(TL_Vector);
        out->appendInt(m_messages.count());
        for (qint32 i = 0; i < m_messages.count(); i++) {
            m_messages[i].push(out);
        }
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
    
    case typeMessagesMessagesSlice: {
        out->appendInt(m_count);
        out->appendInt(TL_Vector);
        out->appendInt(m_messages.count());
        for (qint32 i = 0; i < m_messages.count(); i++) {
            m_messages[i].push(out);
        }
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

