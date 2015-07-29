#ifndef LQTG_CONTACTSFOUND
#define LQTG_CONTACTSFOUND

#include "telegramtypeobject.h"
#include <QList>
#include "contactfound.h"
#include "user.h"

class ContactsFound : public TelegramTypeObject
{
public:
    enum ContactsFoundType {
        typeContactsFound = 0x566000e
    };

    ContactsFound(ContactsFoundType classType = typeContactsFound, InboundPkt *in = 0);
    ContactsFound(InboundPkt *in);
    virtual ~ContactsFound();

    void setResults(const QList<ContactFound> &results);
    QList<ContactFound> results() const;

    void setUsers(const QList<User> &users);
    QList<User> users() const;

    void setClassType(ContactsFoundType classType);
    ContactsFoundType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const ContactsFound &b);

private:
    QList<ContactFound> m_results;
    QList<User> m_users;
    ContactsFoundType m_classType;
};

#endif // LQTG_CONTACTSFOUND
