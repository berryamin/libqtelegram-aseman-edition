#include "updatesdifference.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

UpdatesDifference::UpdatesDifference(UpdatesDifferenceType classType, InboundPkt *in) :
    m_date(0),
    m_seq(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

UpdatesDifference::UpdatesDifference(InboundPkt *in) :
    m_date(0),
    m_seq(0),
    m_classType(typeUpdatesDifferenceEmpty)
{
    fetch(in);
}

void UpdatesDifference::setChats(const QList<Chat> &chats) {
    m_chats = chats;
}

QList<Chat> UpdatesDifference::chats() const {
    return m_chats;
}

void UpdatesDifference::setDate(qint32 date) {
    m_date = date;
}

qint32 UpdatesDifference::date() const {
    return m_date;
}

void UpdatesDifference::setIntermediateState(const UpdatesState &intermediateState) {
    m_intermediateState = intermediateState;
}

UpdatesState UpdatesDifference::intermediateState() const {
    return m_intermediateState;
}

void UpdatesDifference::setNewEncryptedMessages(const QList<EncryptedMessage> &newEncryptedMessages) {
    m_newEncryptedMessages = newEncryptedMessages;
}

QList<EncryptedMessage> UpdatesDifference::newEncryptedMessages() const {
    return m_newEncryptedMessages;
}

void UpdatesDifference::setNewMessages(const QList<Message> &newMessages) {
    m_newMessages = newMessages;
}

QList<Message> UpdatesDifference::newMessages() const {
    return m_newMessages;
}

void UpdatesDifference::setOtherUpdates(const QList<Update> &otherUpdates) {
    m_otherUpdates = otherUpdates;
}

QList<Update> UpdatesDifference::otherUpdates() const {
    return m_otherUpdates;
}

void UpdatesDifference::setSeq(qint32 seq) {
    m_seq = seq;
}

qint32 UpdatesDifference::seq() const {
    return m_seq;
}

void UpdatesDifference::setState(const UpdatesState &state) {
    m_state = state;
}

UpdatesState UpdatesDifference::state() const {
    return m_state;
}

void UpdatesDifference::setUsers(const QList<User> &users) {
    m_users = users;
}

QList<User> UpdatesDifference::users() const {
    return m_users;
}

bool UpdatesDifference::operator ==(const UpdatesDifference &b) {
    return m_chats == b.m_chats &&
           m_date == b.m_date &&
           m_intermediateState == b.m_intermediateState &&
           m_newEncryptedMessages == b.m_newEncryptedMessages &&
           m_newMessages == b.m_newMessages &&
           m_otherUpdates == b.m_otherUpdates &&
           m_seq == b.m_seq &&
           m_state == b.m_state &&
           m_users == b.m_users;
}

void UpdatesDifference::setClassType(UpdatesDifference::UpdatesDifferenceType classType) {
    m_classType = classType;
}

UpdatesDifference::UpdatesDifferenceType UpdatesDifference::classType() const {
    return m_classType;
}

bool UpdatesDifference::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeUpdatesDifferenceEmpty: {
        m_date = in->fetchInt();
        m_seq = in->fetchInt();
        return true;
    }
        break;
    
    case typeUpdatesDifference: {
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_newMessages_length = in->fetchInt();
        m_newMessages.clear();
        for (qint32 i = 0; i < m_newMessages_length; i++) {
            Message type;
            type.fetch(in);
            m_newMessages.append(type);
        }
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_newEncryptedMessages_length = in->fetchInt();
        m_newEncryptedMessages.clear();
        for (qint32 i = 0; i < m_newEncryptedMessages_length; i++) {
            EncryptedMessage type;
            type.fetch(in);
            m_newEncryptedMessages.append(type);
        }
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_otherUpdates_length = in->fetchInt();
        m_otherUpdates.clear();
        for (qint32 i = 0; i < m_otherUpdates_length; i++) {
            Update type;
            type.fetch(in);
            m_otherUpdates.append(type);
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
        m_state.fetch(in);
        return true;
    }
        break;
    
    case typeUpdatesDifferenceSlice: {
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_newMessages_length = in->fetchInt();
        m_newMessages.clear();
        for (qint32 i = 0; i < m_newMessages_length; i++) {
            Message type;
            type.fetch(in);
            m_newMessages.append(type);
        }
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_newEncryptedMessages_length = in->fetchInt();
        m_newEncryptedMessages.clear();
        for (qint32 i = 0; i < m_newEncryptedMessages_length; i++) {
            EncryptedMessage type;
            type.fetch(in);
            m_newEncryptedMessages.append(type);
        }
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_otherUpdates_length = in->fetchInt();
        m_otherUpdates.clear();
        for (qint32 i = 0; i < m_otherUpdates_length; i++) {
            Update type;
            type.fetch(in);
            m_otherUpdates.append(type);
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
        m_intermediateState.fetch(in);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool UpdatesDifference::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeUpdatesDifferenceEmpty: {
        out->appendInt(m_date);
        out->appendInt(m_seq);
        return true;
    }
        break;
    
    case typeUpdatesDifference: {
        out->appendInt(TL_Vector);
        out->appendInt(m_newMessages.count());
        for (qint32 i = 0; i < m_newMessages.count(); i++) {
            m_newMessages[i].push(out);
        }
        out->appendInt(TL_Vector);
        out->appendInt(m_newEncryptedMessages.count());
        for (qint32 i = 0; i < m_newEncryptedMessages.count(); i++) {
            m_newEncryptedMessages[i].push(out);
        }
        out->appendInt(TL_Vector);
        out->appendInt(m_otherUpdates.count());
        for (qint32 i = 0; i < m_otherUpdates.count(); i++) {
            m_otherUpdates[i].push(out);
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
        m_state.push(out);
        return true;
    }
        break;
    
    case typeUpdatesDifferenceSlice: {
        out->appendInt(TL_Vector);
        out->appendInt(m_newMessages.count());
        for (qint32 i = 0; i < m_newMessages.count(); i++) {
            m_newMessages[i].push(out);
        }
        out->appendInt(TL_Vector);
        out->appendInt(m_newEncryptedMessages.count());
        for (qint32 i = 0; i < m_newEncryptedMessages.count(); i++) {
            m_newEncryptedMessages[i].push(out);
        }
        out->appendInt(TL_Vector);
        out->appendInt(m_otherUpdates.count());
        for (qint32 i = 0; i < m_otherUpdates.count(); i++) {
            m_otherUpdates[i].push(out);
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
        m_intermediateState.push(out);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

