#ifndef LQTG_MESSAGESAFFECTEDHISTORY
#define LQTG_MESSAGESAFFECTEDHISTORY

#include "telegramtypeobject.h"
#include <QtGlobal>

class MessagesAffectedHistory : public TelegramTypeObject
{
public:
    enum MessagesAffectedHistoryType {
        typeMessagesAffectedHistory = 0xb45c69d1
    };

    MessagesAffectedHistory(MessagesAffectedHistoryType classType = typeMessagesAffectedHistory, InboundPkt *in = 0);
    MessagesAffectedHistory(InboundPkt *in);
    virtual ~MessagesAffectedHistory();

    void setOffset(qint32 offset);
    qint32 offset() const;

    void setPts(qint32 pts);
    qint32 pts() const;

    void setPtsCount(qint32 ptsCount);
    qint32 ptsCount() const;

    void setClassType(MessagesAffectedHistoryType classType);
    MessagesAffectedHistoryType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const MessagesAffectedHistory &b);

private:
    qint32 m_offset;
    qint32 m_pts;
    qint32 m_ptsCount;
    MessagesAffectedHistoryType m_classType;
};

#endif // LQTG_MESSAGESAFFECTEDHISTORY
