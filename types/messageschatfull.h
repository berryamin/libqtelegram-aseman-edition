#ifndef LQTG_MESSAGESCHATFULL
#define LQTG_MESSAGESCHATFULL

#include "telegramtypeobject.h"
#include <QList>
#include "chat.h"
#include "chatfull.h"
#include "user.h"

class MessagesChatFull : public TelegramTypeObject
{
public:
    enum MessagesChatFullType {
        typeMessagesChatFull = 0xe5d7d19c
    };

    MessagesChatFull(MessagesChatFullType classType = typeMessagesChatFull, InboundPkt *in = 0);
    MessagesChatFull(InboundPkt *in);
    virtual ~MessagesChatFull();

    void setChats(const QList<Chat> &chats);
    QList<Chat> chats() const;

    void setFullChat(const ChatFull &fullChat);
    ChatFull fullChat() const;

    void setUsers(const QList<User> &users);
    QList<User> users() const;

    void setClassType(MessagesChatFullType classType);
    MessagesChatFullType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const MessagesChatFull &b);

private:
    QList<Chat> m_chats;
    ChatFull m_fullChat;
    QList<User> m_users;
    MessagesChatFullType m_classType;
};

#endif // LQTG_MESSAGESCHATFULL
