#include "messagesaffectedhistory.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

MessagesAffectedHistory::MessagesAffectedHistory(MessagesAffectedHistoryType classType, InboundPkt *in) :
    m_offset(0),
    m_pts(0),
    m_ptsCount(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

MessagesAffectedHistory::MessagesAffectedHistory(InboundPkt *in) :
    m_offset(0),
    m_pts(0),
    m_ptsCount(0),
    m_classType(typeMessagesAffectedHistory)
{
    fetch(in);
}

void MessagesAffectedHistory::setOffset(qint32 offset) {
    m_offset = offset;
}

qint32 MessagesAffectedHistory::offset() const {
    return m_offset;
}

void MessagesAffectedHistory::setPts(qint32 pts) {
    m_pts = pts;
}

qint32 MessagesAffectedHistory::pts() const {
    return m_pts;
}

void MessagesAffectedHistory::setPtsCount(qint32 ptsCount) {
    m_ptsCount = ptsCount;
}

qint32 MessagesAffectedHistory::ptsCount() const {
    return m_ptsCount;
}

bool MessagesAffectedHistory::operator ==(const MessagesAffectedHistory &b) {
    return m_offset == b.m_offset &&
           m_pts == b.m_pts &&
           m_ptsCount == b.m_ptsCount;
}

void MessagesAffectedHistory::setClassType(MessagesAffectedHistory::MessagesAffectedHistoryType classType) {
    m_classType = classType;
}

MessagesAffectedHistory::MessagesAffectedHistoryType MessagesAffectedHistory::classType() const {
    return m_classType;
}

bool MessagesAffectedHistory::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeMessagesAffectedHistory: {
        m_pts = in->fetchInt();
        m_ptsCount = in->fetchInt();
        m_offset = in->fetchInt();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool MessagesAffectedHistory::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessagesAffectedHistory: {
        out->appendInt(m_pts);
        out->appendInt(m_ptsCount);
        out->appendInt(m_offset);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

