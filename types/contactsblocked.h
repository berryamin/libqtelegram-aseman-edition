#ifndef LQTG_CONTACTSBLOCKED
#define LQTG_CONTACTSBLOCKED

#include "telegramtypeobject.h"
#include <QList>
#include "contactblocked.h"
#include <QtGlobal>
#include "user.h"

class ContactsBlocked : public TelegramTypeObject
{
public:
    enum ContactsBlockedType {
        typeContactsBlocked = 0x1c138d15,
        typeContactsBlockedSlice = 0x900802a1
    };

    ContactsBlocked(ContactsBlockedType classType = typeContactsBlocked, InboundPkt *in = 0);
    ContactsBlocked(InboundPkt *in);
    virtual ~ContactsBlocked();

    void setBlocked(const QList<ContactBlocked> &blocked);
    QList<ContactBlocked> blocked() const;

    void setCount(qint32 count);
    qint32 count() const;

    void setUsers(const QList<User> &users);
    QList<User> users() const;

    void setClassType(ContactsBlockedType classType);
    ContactsBlockedType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const ContactsBlocked &b);

private:
    QList<ContactBlocked> m_blocked;
    qint32 m_count;
    QList<User> m_users;
    ContactsBlockedType m_classType;
};

#endif // LQTG_CONTACTSBLOCKED
