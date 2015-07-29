#include "updatesstate.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

UpdatesState::UpdatesState(UpdatesStateType classType, InboundPkt *in) :
    m_date(0),
    m_pts(0),
    m_qts(0),
    m_seq(0),
    m_unreadCount(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

UpdatesState::UpdatesState(InboundPkt *in) :
    m_date(0),
    m_pts(0),
    m_qts(0),
    m_seq(0),
    m_unreadCount(0),
    m_classType(typeUpdatesState)
{
    fetch(in);
}

void UpdatesState::setDate(qint32 date) {
    m_date = date;
}

qint32 UpdatesState::date() const {
    return m_date;
}

void UpdatesState::setPts(qint32 pts) {
    m_pts = pts;
}

qint32 UpdatesState::pts() const {
    return m_pts;
}

void UpdatesState::setQts(qint32 qts) {
    m_qts = qts;
}

qint32 UpdatesState::qts() const {
    return m_qts;
}

void UpdatesState::setSeq(qint32 seq) {
    m_seq = seq;
}

qint32 UpdatesState::seq() const {
    return m_seq;
}

void UpdatesState::setUnreadCount(qint32 unreadCount) {
    m_unreadCount = unreadCount;
}

qint32 UpdatesState::unreadCount() const {
    return m_unreadCount;
}

bool UpdatesState::operator ==(const UpdatesState &b) {
    return m_date == b.m_date &&
           m_pts == b.m_pts &&
           m_qts == b.m_qts &&
           m_seq == b.m_seq &&
           m_unreadCount == b.m_unreadCount;
}

void UpdatesState::setClassType(UpdatesState::UpdatesStateType classType) {
    m_classType = classType;
}

UpdatesState::UpdatesStateType UpdatesState::classType() const {
    return m_classType;
}

bool UpdatesState::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeUpdatesState: {
        m_pts = in->fetchInt();
        m_qts = in->fetchInt();
        m_date = in->fetchInt();
        m_seq = in->fetchInt();
        m_unreadCount = in->fetchInt();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool UpdatesState::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeUpdatesState: {
        out->appendInt(m_pts);
        out->appendInt(m_qts);
        out->appendInt(m_date);
        out->appendInt(m_seq);
        out->appendInt(m_unreadCount);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

