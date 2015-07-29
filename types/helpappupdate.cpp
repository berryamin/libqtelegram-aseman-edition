#include "helpappupdate.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

HelpAppUpdate::HelpAppUpdate(HelpAppUpdateType classType, InboundPkt *in) :
    m_critical(false),
    m_id(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

HelpAppUpdate::HelpAppUpdate(InboundPkt *in) :
    m_critical(false),
    m_id(0),
    m_classType(typeHelpAppUpdate)
{
    fetch(in);
}

void HelpAppUpdate::setCritical(bool critical) {
    m_critical = critical;
}

bool HelpAppUpdate::critical() const {
    return m_critical;
}

void HelpAppUpdate::setId(qint32 id) {
    m_id = id;
}

qint32 HelpAppUpdate::id() const {
    return m_id;
}

void HelpAppUpdate::setText(const QString &text) {
    m_text = text;
}

QString HelpAppUpdate::text() const {
    return m_text;
}

void HelpAppUpdate::setUrl(const QString &url) {
    m_url = url;
}

QString HelpAppUpdate::url() const {
    return m_url;
}

bool HelpAppUpdate::operator ==(const HelpAppUpdate &b) {
    return m_critical == b.m_critical &&
           m_id == b.m_id &&
           m_text == b.m_text &&
           m_url == b.m_url;
}

void HelpAppUpdate::setClassType(HelpAppUpdate::HelpAppUpdateType classType) {
    m_classType = classType;
}

HelpAppUpdate::HelpAppUpdateType HelpAppUpdate::classType() const {
    return m_classType;
}

bool HelpAppUpdate::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeHelpAppUpdate: {
        m_id = in->fetchInt();
        m_critical = in->fetchBool();
        m_url = in->fetchQString();
        m_text = in->fetchQString();
        return true;
    }
        break;
    
    case typeHelpNoAppUpdate: {
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool HelpAppUpdate::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeHelpAppUpdate: {
        out->appendInt(m_id);
        out->appendBool(m_critical);
        out->appendQString(m_url);
        out->appendQString(m_text);
        return true;
    }
        break;
    
    case typeHelpNoAppUpdate: {
        return true;
    }
        break;
    
    default:
        return false;
    }
}

