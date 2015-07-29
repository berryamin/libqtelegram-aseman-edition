#include "messageaction.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

MessageAction::MessageAction(MessageActionType classType, InboundPkt *in) :
    m_inviterId(0),
    m_userId(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

MessageAction::MessageAction(InboundPkt *in) :
    m_inviterId(0),
    m_userId(0),
    m_classType(typeMessageActionEmpty)
{
    fetch(in);
}

void MessageAction::setAddress(const QString &address) {
    m_address = address;
}

QString MessageAction::address() const {
    return m_address;
}

void MessageAction::setInviterId(qint32 inviterId) {
    m_inviterId = inviterId;
}

qint32 MessageAction::inviterId() const {
    return m_inviterId;
}

void MessageAction::setPhoto(const Photo &photo) {
    m_photo = photo;
}

Photo MessageAction::photo() const {
    return m_photo;
}

void MessageAction::setTitle(const QString &title) {
    m_title = title;
}

QString MessageAction::title() const {
    return m_title;
}

void MessageAction::setUserId(qint32 userId) {
    m_userId = userId;
}

qint32 MessageAction::userId() const {
    return m_userId;
}

void MessageAction::setUsers(const QList<qint32> &users) {
    m_users = users;
}

QList<qint32> MessageAction::users() const {
    return m_users;
}

bool MessageAction::operator ==(const MessageAction &b) {
    return m_address == b.m_address &&
           m_inviterId == b.m_inviterId &&
           m_photo == b.m_photo &&
           m_title == b.m_title &&
           m_userId == b.m_userId &&
           m_users == b.m_users;
}

void MessageAction::setClassType(MessageAction::MessageActionType classType) {
    m_classType = classType;
}

MessageAction::MessageActionType MessageAction::classType() const {
    return m_classType;
}

bool MessageAction::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeMessageActionEmpty: {
        return true;
    }
        break;
    
    case typeMessageActionChatCreate: {
        m_title = in->fetchQString();
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_users_length = in->fetchInt();
        m_users.clear();
        for (qint32 i = 0; i < m_users_length; i++) {
            qint32 type;
            type = in->fetchInt();
            m_users.append(type);
        }
        return true;
    }
        break;
    
    case typeMessageActionChatEditTitle: {
        m_title = in->fetchQString();
        return true;
    }
        break;
    
    case typeMessageActionChatEditPhoto: {
        m_photo.fetch(in);
        return true;
    }
        break;
    
    case typeMessageActionChatDeletePhoto: {
        return true;
    }
        break;
    
    case typeMessageActionChatAddUser: {
        m_userId = in->fetchInt();
        return true;
    }
        break;
    
    case typeMessageActionChatDeleteUser: {
        m_userId = in->fetchInt();
        return true;
    }
        break;
    
    case typeMessageActionGeoChatCreate: {
        m_title = in->fetchQString();
        m_address = in->fetchQString();
        return true;
    }
        break;
    
    case typeMessageActionGeoChatCheckin: {
        return true;
    }
        break;
    
    case typeMessageActionChatJoinedByLink: {
        m_inviterId = in->fetchInt();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool MessageAction::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessageActionEmpty: {
        return true;
    }
        break;
    
    case typeMessageActionChatCreate: {
        out->appendQString(m_title);
        out->appendInt(TL_Vector);
        out->appendInt(m_users.count());
        for (qint32 i = 0; i < m_users.count(); i++) {
            out->appendInt(m_users[i]);
        }
        return true;
    }
        break;
    
    case typeMessageActionChatEditTitle: {
        out->appendQString(m_title);
        return true;
    }
        break;
    
    case typeMessageActionChatEditPhoto: {
        m_photo.push(out);
        return true;
    }
        break;
    
    case typeMessageActionChatDeletePhoto: {
        return true;
    }
        break;
    
    case typeMessageActionChatAddUser: {
        out->appendInt(m_userId);
        return true;
    }
        break;
    
    case typeMessageActionChatDeleteUser: {
        out->appendInt(m_userId);
        return true;
    }
        break;
    
    case typeMessageActionGeoChatCreate: {
        out->appendQString(m_title);
        out->appendQString(m_address);
        return true;
    }
        break;
    
    case typeMessageActionGeoChatCheckin: {
        return true;
    }
        break;
    
    case typeMessageActionChatJoinedByLink: {
        out->appendInt(m_inviterId);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

