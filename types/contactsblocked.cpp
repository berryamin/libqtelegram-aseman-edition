#include "contactsblocked.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

ContactsBlocked::ContactsBlocked(ContactsBlockedType classType, InboundPkt *in) :
    m_count(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

ContactsBlocked::ContactsBlocked(InboundPkt *in) :
    m_count(0),
    m_classType(typeContactsBlocked)
{
    fetch(in);
}

void ContactsBlocked::setBlocked(const QList<ContactBlocked> &blocked) {
    m_blocked = blocked;
}

QList<ContactBlocked> ContactsBlocked::blocked() const {
    return m_blocked;
}

void ContactsBlocked::setCount(qint32 count) {
    m_count = count;
}

qint32 ContactsBlocked::count() const {
    return m_count;
}

void ContactsBlocked::setUsers(const QList<User> &users) {
    m_users = users;
}

QList<User> ContactsBlocked::users() const {
    return m_users;
}

bool ContactsBlocked::operator ==(const ContactsBlocked &b) {
    return m_blocked == b.m_blocked &&
           m_count == b.m_count &&
           m_users == b.m_users;
}

void ContactsBlocked::setClassType(ContactsBlocked::ContactsBlockedType classType) {
    m_classType = classType;
}

ContactsBlocked::ContactsBlockedType ContactsBlocked::classType() const {
    return m_classType;
}

bool ContactsBlocked::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeContactsBlocked: {
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_blocked_length = in->fetchInt();
        m_blocked.clear();
        for (qint32 i = 0; i < m_blocked_length; i++) {
            ContactBlocked type;
            type.fetch(in);
            m_blocked.append(type);
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
    
    case typeContactsBlockedSlice: {
        m_count = in->fetchInt();
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_blocked_length = in->fetchInt();
        m_blocked.clear();
        for (qint32 i = 0; i < m_blocked_length; i++) {
            ContactBlocked type;
            type.fetch(in);
            m_blocked.append(type);
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

bool ContactsBlocked::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeContactsBlocked: {
        out->appendInt(TL_Vector);
        out->appendInt(m_blocked.count());
        for (qint32 i = 0; i < m_blocked.count(); i++) {
            m_blocked[i].push(out);
        }
        out->appendInt(TL_Vector);
        out->appendInt(m_users.count());
        for (qint32 i = 0; i < m_users.count(); i++) {
            m_users[i].push(out);
        }
        return true;
    }
        break;
    
    case typeContactsBlockedSlice: {
        out->appendInt(m_count);
        out->appendInt(TL_Vector);
        out->appendInt(m_blocked.count());
        for (qint32 i = 0; i < m_blocked.count(); i++) {
            m_blocked[i].push(out);
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

