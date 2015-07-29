#ifndef LQTG_UPDATESSTATE
#define LQTG_UPDATESSTATE

#include "telegramtypeobject.h"
#include <QtGlobal>

class UpdatesState : public TelegramTypeObject
{
public:
    enum UpdatesStateType {
        typeUpdatesState = 0xa56c2a3e
    };

    UpdatesState(UpdatesStateType classType = typeUpdatesState, InboundPkt *in = 0);
    UpdatesState(InboundPkt *in);
    virtual ~UpdatesState();

    void setDate(qint32 date);
    qint32 date() const;

    void setPts(qint32 pts);
    qint32 pts() const;

    void setQts(qint32 qts);
    qint32 qts() const;

    void setSeq(qint32 seq);
    qint32 seq() const;

    void setUnreadCount(qint32 unreadCount);
    qint32 unreadCount() const;

    void setClassType(UpdatesStateType classType);
    UpdatesStateType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const UpdatesState &b);

private:
    qint32 m_date;
    qint32 m_pts;
    qint32 m_qts;
    qint32 m_seq;
    qint32 m_unreadCount;
    UpdatesStateType m_classType;
};

#endif // LQTG_UPDATESSTATE
