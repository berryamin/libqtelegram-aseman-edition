#include "helpinvitetext.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

HelpInviteText::HelpInviteText(HelpInviteTextType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

HelpInviteText::HelpInviteText(InboundPkt *in) :
    m_classType(typeHelpInviteText)
{
    fetch(in);
}

void HelpInviteText::setMessage(const QString &message) {
    m_message = message;
}

QString HelpInviteText::message() const {
    return m_message;
}

bool HelpInviteText::operator ==(const HelpInviteText &b) {
    return m_message == b.m_message;
}

void HelpInviteText::setClassType(HelpInviteText::HelpInviteTextType classType) {
    m_classType = classType;
}

HelpInviteText::HelpInviteTextType HelpInviteText::classType() const {
    return m_classType;
}

bool HelpInviteText::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeHelpInviteText: {
        m_message = in->fetchQString();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool HelpInviteText::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeHelpInviteText: {
        out->appendQString(m_message);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

