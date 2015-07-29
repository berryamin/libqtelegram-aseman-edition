#include "receivednotifymessage.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

ReceivedNotifyMessage::ReceivedNotifyMessage(ReceivedNotifyMessageType classType, InboundPkt *in) :
    m_flags(0),
    m_id(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

ReceivedNotifyMessage::ReceivedNotifyMessage(InboundPkt *in) :
    m_flags(0),
    m_id(0),
    m_classType(typeReceivedNotifyMessage)
{
    fetch(in);
}

void ReceivedNotifyMessage::setFlags(qint32 flags) {
    m_flags = flags;
}

qint32 ReceivedNotifyMessage::flags() const {
    return m_flags;
}

void ReceivedNotifyMessage::setId(qint32 id) {
    m_id = id;
}

qint32 ReceivedNotifyMessage::id() const {
    return m_id;
}

bool ReceivedNotifyMessage::operator ==(const ReceivedNotifyMessage &b) {
    return m_flags == b.m_flags &&
           m_id == b.m_id;
}

void ReceivedNotifyMessage::setClassType(ReceivedNotifyMessage::ReceivedNotifyMessageType classType) {
    m_classType = classType;
}

ReceivedNotifyMessage::ReceivedNotifyMessageType ReceivedNotifyMessage::classType() const {
    return m_classType;
}

bool ReceivedNotifyMessage::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeReceivedNotifyMessage: {
        m_id = in->fetchInt();
        m_flags = in->fetchInt();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool ReceivedNotifyMessage::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeReceivedNotifyMessage: {
        out->appendInt(m_id);
        out->appendInt(m_flags);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

