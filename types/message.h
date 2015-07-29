#ifndef LQTG_MESSAGE
#define LQTG_MESSAGE

#include "telegramtypeobject.h"
#include "messageaction.h"
#include <QtGlobal>
#include "messagemedia.h"
#include <QString>
#include "peer.h"

class Message : public TelegramTypeObject
{
public:
    enum MessageType {
        typeMessageEmpty = 0x83e5de54,
        typeMessage = 0xa7ab1991,
        typeMessageService = 0x1d86f70e
    };

    Message(MessageType classType = typeMessageEmpty, InboundPkt *in = 0);
    Message(InboundPkt *in);
    virtual ~Message();

    void setAction(const MessageAction &action);
    MessageAction action() const;

    void setDate(qint32 date);
    qint32 date() const;

    void setFlags(qint32 flags);
    qint32 flags() const;

    void setFromId(qint32 fromId);
    qint32 fromId() const;

    void setFwdDate(qint32 fwdDate);
    qint32 fwdDate() const;

    void setFwdFromId(qint32 fwdFromId);
    qint32 fwdFromId() const;

    void setId(qint32 id);
    qint32 id() const;

    void setMedia(const MessageMedia &media);
    MessageMedia media() const;

    void setMessage(const QString &message);
    QString message() const;

    void setReplyToMsgId(qint32 replyToMsgId);
    qint32 replyToMsgId() const;

    void setToId(const Peer &toId);
    Peer toId() const;

    void setClassType(MessageType classType);
    MessageType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const Message &b);

private:
    MessageAction m_action;
    qint32 m_date;
    qint32 m_flags;
    qint32 m_fromId;
    qint32 m_fwdDate;
    qint32 m_fwdFromId;
    qint32 m_id;
    MessageMedia m_media;
    QString m_message;
    qint32 m_replyToMsgId;
    Peer m_toId;
    MessageType m_classType;
};

#endif // LQTG_MESSAGE
