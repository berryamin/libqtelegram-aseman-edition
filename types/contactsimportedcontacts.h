#ifndef LQTG_CONTACTSIMPORTEDCONTACTS
#define LQTG_CONTACTSIMPORTEDCONTACTS

#include "telegramtypeobject.h"
#include <QList>
#include "importedcontact.h"
#include <QtGlobal>
#include "user.h"

class ContactsImportedContacts : public TelegramTypeObject
{
public:
    enum ContactsImportedContactsType {
        typeContactsImportedContacts = 0xad524315
    };

    ContactsImportedContacts(ContactsImportedContactsType classType = typeContactsImportedContacts, InboundPkt *in = 0);
    ContactsImportedContacts(InboundPkt *in);
    virtual ~ContactsImportedContacts();

    void setImported(const QList<ImportedContact> &imported);
    QList<ImportedContact> imported() const;

    void setRetryContacts(const QList<qint64> &retryContacts);
    QList<qint64> retryContacts() const;

    void setUsers(const QList<User> &users);
    QList<User> users() const;

    void setClassType(ContactsImportedContactsType classType);
    ContactsImportedContactsType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const ContactsImportedContacts &b);

private:
    QList<ImportedContact> m_imported;
    QList<qint64> m_retryContacts;
    QList<User> m_users;
    ContactsImportedContactsType m_classType;
};

#endif // LQTG_CONTACTSIMPORTEDCONTACTS
