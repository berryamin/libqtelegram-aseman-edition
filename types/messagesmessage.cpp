#include "messagesmessage.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

MessagesMessage::MessagesMessage(MessagesMessageType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

MessagesMessage::MessagesMessage(InboundPkt *in) :
    m_classType(typeMessagesMessageEmpty)
{
    fetch(in);
}

bool MessagesMessage::operator ==(const MessagesMessage &b) {
    Q_UNUSED(b);
    return true;
}

void MessagesMessage::setClassType(MessagesMessage::MessagesMessageType classType) {
    m_classType = classType;
}

MessagesMessage::MessagesMessageType MessagesMessage::classType() const {
    return m_classType;
}

bool MessagesMessage::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeMessagesMessageEmpty: {
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool MessagesMessage::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessagesMessageEmpty: {
        return true;
    }
        break;
    
    default:
        return false;
    }
}

