#include "contactsimportedcontacts.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

ContactsImportedContacts::ContactsImportedContacts(ContactsImportedContactsType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

ContactsImportedContacts::ContactsImportedContacts(InboundPkt *in) :
    m_classType(typeContactsImportedContacts)
{
    fetch(in);
}

void ContactsImportedContacts::setImported(const QList<ImportedContact> &imported) {
    m_imported = imported;
}

QList<ImportedContact> ContactsImportedContacts::imported() const {
    return m_imported;
}

void ContactsImportedContacts::setRetryContacts(const QList<qint64> &retryContacts) {
    m_retryContacts = retryContacts;
}

QList<qint64> ContactsImportedContacts::retryContacts() const {
    return m_retryContacts;
}

void ContactsImportedContacts::setUsers(const QList<User> &users) {
    m_users = users;
}

QList<User> ContactsImportedContacts::users() const {
    return m_users;
}

bool ContactsImportedContacts::operator ==(const ContactsImportedContacts &b) {
    return m_imported == b.m_imported &&
           m_retryContacts == b.m_retryContacts &&
           m_users == b.m_users;
}

void ContactsImportedContacts::setClassType(ContactsImportedContacts::ContactsImportedContactsType classType) {
    m_classType = classType;
}

ContactsImportedContacts::ContactsImportedContactsType ContactsImportedContacts::classType() const {
    return m_classType;
}

bool ContactsImportedContacts::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeContactsImportedContacts: {
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_imported_length = in->fetchInt();
        m_imported.clear();
        for (qint32 i = 0; i < m_imported_length; i++) {
            ImportedContact type;
            type.fetch(in);
            m_imported.append(type);
        }
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_retryContacts_length = in->fetchInt();
        m_retryContacts.clear();
        for (qint32 i = 0; i < m_retryContacts_length; i++) {
            qint64 type;
            type = in->fetchLong();
            m_retryContacts.append(type);
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

bool ContactsImportedContacts::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeContactsImportedContacts: {
        out->appendInt(TL_Vector);
        out->appendInt(m_imported.count());
        for (qint32 i = 0; i < m_imported.count(); i++) {
            m_imported[i].push(out);
        }
        out->appendInt(TL_Vector);
        out->appendInt(m_retryContacts.count());
        for (qint32 i = 0; i < m_retryContacts.count(); i++) {
            out->appendLong(m_retryContacts[i]);
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

