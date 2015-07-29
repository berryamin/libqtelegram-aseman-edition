#ifndef LQTG_MESSAGESDIALOGS
#define LQTG_MESSAGESDIALOGS

#include "telegramtypeobject.h"
#include <QList>
#include "chat.h"
#include <QtGlobal>
#include "dialog.h"
#include "message.h"
#include "user.h"

class MessagesDialogs : public TelegramTypeObject
{
public:
    enum MessagesDialogsType {
        typeMessagesDialogs = 0x15ba6c40,
        typeMessagesDialogsSlice = 0x71e094f3
    };

    MessagesDialogs(MessagesDialogsType classType = typeMessagesDialogs, InboundPkt *in = 0);
    MessagesDialogs(InboundPkt *in);
    virtual ~MessagesDialogs();

    void setChats(const QList<Chat> &chats);
    QList<Chat> chats() const;

    void setCount(qint32 count);
    qint32 count() const;

    void setDialogs(const QList<Dialog> &dialogs);
    QList<Dialog> dialogs() const;

    void setMessages(const QList<Message> &messages);
    QList<Message> messages() const;

    void setUsers(const QList<User> &users);
    QList<User> users() const;

    void setClassType(MessagesDialogsType classType);
    MessagesDialogsType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const MessagesDialogs &b);

private:
    QList<Chat> m_chats;
    qint32 m_count;
    QList<Dialog> m_dialogs;
    QList<Message> m_messages;
    QList<User> m_users;
    MessagesDialogsType m_classType;
};

#endif // LQTG_MESSAGESDIALOGS
