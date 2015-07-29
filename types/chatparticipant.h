#ifndef LQTG_CHATPARTICIPANT
#define LQTG_CHATPARTICIPANT

#include "telegramtypeobject.h"
#include <QtGlobal>

class ChatParticipant : public TelegramTypeObject
{
public:
    enum ChatParticipantType {
        typeChatParticipant = 0xc8d7493e
    };

    ChatParticipant(ChatParticipantType classType = typeChatParticipant, InboundPkt *in = 0);
    ChatParticipant(InboundPkt *in);
    virtual ~ChatParticipant();

    void setDate(qint32 date);
    qint32 date() const;

    void setInviterId(qint32 inviterId);
    qint32 inviterId() const;

    void setUserId(qint32 userId);
    qint32 userId() const;

    void setClassType(ChatParticipantType classType);
    ChatParticipantType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const ChatParticipant &b);

private:
    qint32 m_date;
    qint32 m_inviterId;
    qint32 m_userId;
    ChatParticipantType m_classType;
};

#endif // LQTG_CHATPARTICIPANT
