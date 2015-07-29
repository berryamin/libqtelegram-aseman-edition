#ifndef LQTG_GEOCHATSMESSAGES
#define LQTG_GEOCHATSMESSAGES

#include "telegramtypeobject.h"
#include <QList>
#include "chat.h"
#include <QtGlobal>
#include "geochatmessage.h"
#include "user.h"

class GeochatsMessages : public TelegramTypeObject
{
public:
    enum GeochatsMessagesType {
        typeGeochatsMessages = 0xd1526db1,
        typeGeochatsMessagesSlice = 0xbc5863e8
    };

    GeochatsMessages(GeochatsMessagesType classType = typeGeochatsMessages, InboundPkt *in = 0);
    GeochatsMessages(InboundPkt *in);
    virtual ~GeochatsMessages();

    void setChats(const QList<Chat> &chats);
    QList<Chat> chats() const;

    void setCount(qint32 count);
    qint32 count() const;

    void setMessages(const QList<GeoChatMessage> &messages);
    QList<GeoChatMessage> messages() const;

    void setUsers(const QList<User> &users);
    QList<User> users() const;

    void setClassType(GeochatsMessagesType classType);
    GeochatsMessagesType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const GeochatsMessages &b);

private:
    QList<Chat> m_chats;
    qint32 m_count;
    QList<GeoChatMessage> m_messages;
    QList<User> m_users;
    GeochatsMessagesType m_classType;
};

#endif // LQTG_GEOCHATSMESSAGES
