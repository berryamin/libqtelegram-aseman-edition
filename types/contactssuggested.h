#ifndef LQTG_CONTACTSSUGGESTED
#define LQTG_CONTACTSSUGGESTED

#include "telegramtypeobject.h"
#include <QList>
#include "contactsuggested.h"
#include "user.h"

class ContactsSuggested : public TelegramTypeObject
{
public:
    enum ContactsSuggestedType {
        typeContactsSuggested = 0x5649dcc5
    };

    ContactsSuggested(ContactsSuggestedType classType = typeContactsSuggested, InboundPkt *in = 0);
    ContactsSuggested(InboundPkt *in);
    virtual ~ContactsSuggested();

    void setResults(const QList<ContactSuggested> &results);
    QList<ContactSuggested> results() const;

    void setUsers(const QList<User> &users);
    QList<User> users() const;

    void setClassType(ContactsSuggestedType classType);
    ContactsSuggestedType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const ContactsSuggested &b);

private:
    QList<ContactSuggested> m_results;
    QList<User> m_users;
    ContactsSuggestedType m_classType;
};

#endif // LQTG_CONTACTSSUGGESTED
