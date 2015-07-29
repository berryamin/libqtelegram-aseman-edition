#include "contactsfound.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

ContactsFound::ContactsFound(ContactsFoundType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

ContactsFound::ContactsFound(InboundPkt *in) :
    m_classType(typeContactsFound)
{
    fetch(in);
}

void ContactsFound::setResults(const QList<ContactFound> &results) {
    m_results = results;
}

QList<ContactFound> ContactsFound::results() const {
    return m_results;
}

void ContactsFound::setUsers(const QList<User> &users) {
    m_users = users;
}

QList<User> ContactsFound::users() const {
    return m_users;
}

bool ContactsFound::operator ==(const ContactsFound &b) {
    return m_results == b.m_results &&
           m_users == b.m_users;
}

void ContactsFound::setClassType(ContactsFound::ContactsFoundType classType) {
    m_classType = classType;
}

ContactsFound::ContactsFoundType ContactsFound::classType() const {
    return m_classType;
}

bool ContactsFound::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeContactsFound: {
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_results_length = in->fetchInt();
        m_results.clear();
        for (qint32 i = 0; i < m_results_length; i++) {
            ContactFound type;
            type.fetch(in);
            m_results.append(type);
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

bool ContactsFound::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeContactsFound: {
        out->appendInt(TL_Vector);
        out->appendInt(m_results.count());
        for (qint32 i = 0; i < m_results.count(); i++) {
            m_results[i].push(out);
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

