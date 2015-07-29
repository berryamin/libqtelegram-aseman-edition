#include "messagesdialogs.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

MessagesDialogs::MessagesDialogs(MessagesDialogsType classType, InboundPkt *in) :
    m_count(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

MessagesDialogs::MessagesDialogs(InboundPkt *in) :
    m_count(0),
    m_classType(typeMessagesDialogs)
{
    fetch(in);
}

void MessagesDialogs::setChats(const QList<Chat> &chats) {
    m_chats = chats;
}

QList<Chat> MessagesDialogs::chats() const {
    return m_chats;
}

void MessagesDialogs::setCount(qint32 count) {
    m_count = count;
}

qint32 MessagesDialogs::count() const {
    return m_count;
}

void MessagesDialogs::setDialogs(const QList<Dialog> &dialogs) {
    m_dialogs = dialogs;
}

QList<Dialog> MessagesDialogs::dialogs() const {
    return m_dialogs;
}

void MessagesDialogs::setMessages(const QList<Message> &messages) {
    m_messages = messages;
}

QList<Message> MessagesDialogs::messages() const {
    return m_messages;
}

void MessagesDialogs::setUsers(const QList<User> &users) {
    m_users = users;
}

QList<User> MessagesDialogs::users() const {
    return m_users;
}

bool MessagesDialogs::operator ==(const MessagesDialogs &b) {
    return m_chats == b.m_chats &&
           m_count == b.m_count &&
           m_dialogs == b.m_dialogs &&
           m_messages == b.m_messages &&
           m_users == b.m_users;
}

void MessagesDialogs::setClassType(MessagesDialogs::MessagesDialogsType classType) {
    m_classType = classType;
}

MessagesDialogs::MessagesDialogsType MessagesDialogs::classType() const {
    return m_classType;
}

bool MessagesDialogs::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeMessagesDialogs: {
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_dialogs_length = in->fetchInt();
        m_dialogs.clear();
        for (qint32 i = 0; i < m_dialogs_length; i++) {
            Dialog type;
            type.fetch(in);
            m_dialogs.append(type);
        }
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
    
    case typeMessagesDialogsSlice: {
        m_count = in->fetchInt();
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_dialogs_length = in->fetchInt();
        m_dialogs.clear();
        for (qint32 i = 0; i < m_dialogs_length; i++) {
            Dialog type;
            type.fetch(in);
            m_dialogs.append(type);
        }
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

bool MessagesDialogs::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessagesDialogs: {
        out->appendInt(TL_Vector);
        out->appendInt(m_dialogs.count());
        for (qint32 i = 0; i < m_dialogs.count(); i++) {
            m_dialogs[i].push(out);
        }
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
    
    case typeMessagesDialogsSlice: {
        out->appendInt(m_count);
        out->appendInt(TL_Vector);
        out->appendInt(m_dialogs.count());
        for (qint32 i = 0; i < m_dialogs.count(); i++) {
            m_dialogs[i].push(out);
        }
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

