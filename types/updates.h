#ifndef LQTG_UPDATES
#define LQTG_UPDATES

#include "telegramtypeobject.h"
#include <QtGlobal>
#include <QList>
#include "chat.h"
#include <QString>
#include "update.h"
#include "user.h"

class Updates : public TelegramTypeObject
{
public:
    enum UpdatesType {
        typeUpdatesTooLong = 0xe317af7e,
        typeUpdateShortMessage = 0xed5c2127,
        typeUpdateShortChatMessage = 0x52238b3c,
        typeUpdateShort = 0x78d4dec1,
        typeUpdatesCombined = 0x725b04c3,
        typeUpdates = 0x74ae4240
    };

    Updates(UpdatesType classType = typeUpdatesTooLong, InboundPkt *in = 0);
    Updates(InboundPkt *in);
    virtual ~Updates();

    void setChatId(qint32 chatId);
    qint32 chatId() const;

    void setChats(const QList<Chat> &chats);
    QList<Chat> chats() const;

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

    void setMessage(const QString &message);
    QString message() const;

    void setPts(qint32 pts);
    qint32 pts() const;

    void setPtsCount(qint32 ptsCount);
    qint32 ptsCount() const;

    void setReplyToMsgId(qint32 replyToMsgId);
    qint32 replyToMsgId() const;

    void setSeq(qint32 seq);
    qint32 seq() const;

    void setSeqStart(qint32 seqStart);
    qint32 seqStart() const;

    void setUpdate(const Update &update);
    Update update() const;

    void setUpdates(const QList<Update> &updates);
    QList<Update> updates() const;

    void setUserId(qint32 userId);
    qint32 userId() const;

    void setUsers(const QList<User> &users);
    QList<User> users() const;

    void setClassType(UpdatesType classType);
    UpdatesType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const Updates &b);

private:
    qint32 m_chatId;
    QList<Chat> m_chats;
    qint32 m_date;
    qint32 m_flags;
    qint32 m_fromId;
    qint32 m_fwdDate;
    qint32 m_fwdFromId;
    qint32 m_id;
    QString m_message;
    qint32 m_pts;
    qint32 m_ptsCount;
    qint32 m_replyToMsgId;
    qint32 m_seq;
    qint32 m_seqStart;
    Update m_update;
    QList<Update> m_updates;
    qint32 m_userId;
    QList<User> m_users;
    UpdatesType m_classType;
};

#endif // LQTG_UPDATES
