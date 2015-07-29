#include "messagesaffectedmessages.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

MessagesAffectedMessages::MessagesAffectedMessages(MessagesAffectedMessagesType classType, InboundPkt *in) :
    m_pts(0),
    m_ptsCount(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

MessagesAffectedMessages::MessagesAffectedMessages(InboundPkt *in) :
    m_pts(0),
    m_ptsCount(0),
    m_classType(typeMessagesAffectedMessages)
{
    fetch(in);
}

void MessagesAffectedMessages::setPts(qint32 pts) {
    m_pts = pts;
}

qint32 MessagesAffectedMessages::pts() const {
    return m_pts;
}

void MessagesAffectedMessages::setPtsCount(qint32 ptsCount) {
    m_ptsCount = ptsCount;
}

qint32 MessagesAffectedMessages::ptsCount() const {
    return m_ptsCount;
}

bool MessagesAffectedMessages::operator ==(const MessagesAffectedMessages &b) {
    return m_pts == b.m_pts &&
           m_ptsCount == b.m_ptsCount;
}

void MessagesAffectedMessages::setClassType(MessagesAffectedMessages::MessagesAffectedMessagesType classType) {
    m_classType = classType;
}

MessagesAffectedMessages::MessagesAffectedMessagesType MessagesAffectedMessages::classType() const {
    return m_classType;
}

bool MessagesAffectedMessages::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeMessagesAffectedMessages: {
        m_pts = in->fetchInt();
        m_ptsCount = in->fetchInt();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool MessagesAffectedMessages::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessagesAffectedMessages: {
        out->appendInt(m_pts);
        out->appendInt(m_ptsCount);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

