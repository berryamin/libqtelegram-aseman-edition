#include "geochatsstatedmessage.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

GeochatsStatedMessage::GeochatsStatedMessage(GeochatsStatedMessageType classType, InboundPkt *in) :
    m_seq(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

GeochatsStatedMessage::GeochatsStatedMessage(InboundPkt *in) :
    m_seq(0),
    m_classType(typeGeochatsStatedMessage)
{
    fetch(in);
}

void GeochatsStatedMessage::setChats(const QList<Chat> &chats) {
    m_chats = chats;
}

QList<Chat> GeochatsStatedMessage::chats() const {
    return m_chats;
}

void GeochatsStatedMessage::setMessage(const GeoChatMessage &message) {
    m_message = message;
}

GeoChatMessage GeochatsStatedMessage::message() const {
    return m_message;
}

void GeochatsStatedMessage::setSeq(qint32 seq) {
    m_seq = seq;
}

qint32 GeochatsStatedMessage::seq() const {
    return m_seq;
}

void GeochatsStatedMessage::setUsers(const QList<User> &users) {
    m_users = users;
}

QList<User> GeochatsStatedMessage::users() const {
    return m_users;
}

bool GeochatsStatedMessage::operator ==(const GeochatsStatedMessage &b) {
    return m_chats == b.m_chats &&
           m_message == b.m_message &&
           m_seq == b.m_seq &&
           m_users == b.m_users;
}

void GeochatsStatedMessage::setClassType(GeochatsStatedMessage::GeochatsStatedMessageType classType) {
    m_classType = classType;
}

GeochatsStatedMessage::GeochatsStatedMessageType GeochatsStatedMessage::classType() const {
    return m_classType;
}

bool GeochatsStatedMessage::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeGeochatsStatedMessage: {
        m_message.fetch(in);
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
        m_seq = in->fetchInt();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool GeochatsStatedMessage::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeGeochatsStatedMessage: {
        m_message.push(out);
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
        out->appendInt(m_seq);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

