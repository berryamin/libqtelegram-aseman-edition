#ifndef LQTG_UPDATESDIFFERENCE
#define LQTG_UPDATESDIFFERENCE

#include "telegramtypeobject.h"
#include <QList>
#include "chat.h"
#include <QtGlobal>
#include "updatesstate.h"
#include "encryptedmessage.h"
#include "message.h"
#include "update.h"
#include "user.h"

class UpdatesDifference : public TelegramTypeObject
{
public:
    enum UpdatesDifferenceType {
        typeUpdatesDifferenceEmpty = 0x5d75a138,
        typeUpdatesDifference = 0xf49ca0,
        typeUpdatesDifferenceSlice = 0xa8fb1981
    };

    UpdatesDifference(UpdatesDifferenceType classType = typeUpdatesDifferenceEmpty, InboundPkt *in = 0);
    UpdatesDifference(InboundPkt *in);
    virtual ~UpdatesDifference();

    void setChats(const QList<Chat> &chats);
    QList<Chat> chats() const;

    void setDate(qint32 date);
    qint32 date() const;

    void setIntermediateState(const UpdatesState &intermediateState);
    UpdatesState intermediateState() const;

    void setNewEncryptedMessages(const QList<EncryptedMessage> &newEncryptedMessages);
    QList<EncryptedMessage> newEncryptedMessages() const;

    void setNewMessages(const QList<Message> &newMessages);
    QList<Message> newMessages() const;

    void setOtherUpdates(const QList<Update> &otherUpdates);
    QList<Update> otherUpdates() const;

    void setSeq(qint32 seq);
    qint32 seq() const;

    void setState(const UpdatesState &state);
    UpdatesState state() const;

    void setUsers(const QList<User> &users);
    QList<User> users() const;

    void setClassType(UpdatesDifferenceType classType);
    UpdatesDifferenceType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const UpdatesDifference &b);

private:
    QList<Chat> m_chats;
    qint32 m_date;
    UpdatesState m_intermediateState;
    QList<EncryptedMessage> m_newEncryptedMessages;
    QList<Message> m_newMessages;
    QList<Update> m_otherUpdates;
    qint32 m_seq;
    UpdatesState m_state;
    QList<User> m_users;
    UpdatesDifferenceType m_classType;
};

#endif // LQTG_UPDATESDIFFERENCE
