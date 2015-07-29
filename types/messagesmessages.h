#ifndef LQTG_MESSAGESMESSAGES
#define LQTG_MESSAGESMESSAGES

#include "telegramtypeobject.h"
#include <QList>
#include "chat.h"
#include <QtGlobal>
#include "message.h"
#include "user.h"

class MessagesMessages : public TelegramTypeObject
{
public:
    enum MessagesMessagesType {
        typeMessagesMessages = 0x8c718e87,
        typeMessagesMessagesSlice = 0xb446ae3
    };

    MessagesMessages(MessagesMessagesType classType = typeMessagesMessages, InboundPkt *in = 0);
    MessagesMessages(InboundPkt *in);
    virtual ~MessagesMessages();

    void setChats(const QList<Chat> &chats);
    QList<Chat> chats() const;

    void setCount(qint32 count);
    qint32 count() const;

    void setMessages(const QList<Message> &messages);
    QList<Message> messages() const;

    void setUsers(const QList<User> &users);
    QList<User> users() const;

    void setClassType(MessagesMessagesType classType);
    MessagesMessagesType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const MessagesMessages &b);

private:
    QList<Chat> m_chats;
    qint32 m_count;
    QList<Message> m_messages;
    QList<User> m_users;
    MessagesMessagesType m_classType;
};

#endif // LQTG_MESSAGESMESSAGES
