#include "geochatsmessages.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

GeochatsMessages::GeochatsMessages(GeochatsMessagesType classType, InboundPkt *in) :
    m_count(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

GeochatsMessages::GeochatsMessages(InboundPkt *in) :
    m_count(0),
    m_classType(typeGeochatsMessages)
{
    fetch(in);
}

void GeochatsMessages::setChats(const QList<Chat> &chats) {
    m_chats = chats;
}

QList<Chat> GeochatsMessages::chats() const {
    return m_chats;
}

void GeochatsMessages::setCount(qint32 count) {
    m_count = count;
}

qint32 GeochatsMessages::count() const {
    return m_count;
}

void GeochatsMessages::setMessages(const QList<GeoChatMessage> &messages) {
    m_messages = messages;
}

QList<GeoChatMessage> GeochatsMessages::messages() const {
    return m_messages;
}

void GeochatsMessages::setUsers(const QList<User> &users) {
    m_users = users;
}

QList<User> GeochatsMessages::users() const {
    return m_users;
}

bool GeochatsMessages::operator ==(const GeochatsMessages &b) {
    return m_chats == b.m_chats &&
           m_count == b.m_count &&
           m_messages == b.m_messages &&
           m_users == b.m_users;
}

void GeochatsMessages::setClassType(GeochatsMessages::GeochatsMessagesType classType) {
    m_classType = classType;
}

GeochatsMessages::GeochatsMessagesType GeochatsMessages::classType() const {
    return m_classType;
}

bool GeochatsMessages::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeGeochatsMessages: {
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_messages_length = in->fetchInt();
        m_messages.clear();
        for (qint32 i = 0; i < m_messages_length; i++) {
            GeoChatMessage type;
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
    
    case typeGeochatsMessagesSlice: {
        m_count = in->fetchInt();
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_messages_length = in->fetchInt();
        m_messages.clear();
        for (qint32 i = 0; i < m_messages_length; i++) {
            GeoChatMessage type;
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

bool GeochatsMessages::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeGeochatsMessages: {
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
    
    case typeGeochatsMessagesSlice: {
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

