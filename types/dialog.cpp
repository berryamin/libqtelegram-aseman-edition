#include "dialog.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

Dialog::Dialog(DialogType classType, InboundPkt *in) :
    m_readInboxMaxId(0),
    m_topMessage(0),
    m_unreadCount(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

Dialog::Dialog(InboundPkt *in) :
    m_readInboxMaxId(0),
    m_topMessage(0),
    m_unreadCount(0),
    m_classType(typeDialog)
{
    fetch(in);
}

void Dialog::setNotifySettings(const PeerNotifySettings &notifySettings) {
    m_notifySettings = notifySettings;
}

PeerNotifySettings Dialog::notifySettings() const {
    return m_notifySettings;
}

void Dialog::setPeer(const Peer &peer) {
    m_peer = peer;
}

Peer Dialog::peer() const {
    return m_peer;
}

void Dialog::setReadInboxMaxId(qint32 readInboxMaxId) {
    m_readInboxMaxId = readInboxMaxId;
}

qint32 Dialog::readInboxMaxId() const {
    return m_readInboxMaxId;
}

void Dialog::setTopMessage(qint32 topMessage) {
    m_topMessage = topMessage;
}

qint32 Dialog::topMessage() const {
    return m_topMessage;
}

void Dialog::setUnreadCount(qint32 unreadCount) {
    m_unreadCount = unreadCount;
}

qint32 Dialog::unreadCount() const {
    return m_unreadCount;
}

bool Dialog::operator ==(const Dialog &b) {
    return m_notifySettings == b.m_notifySettings &&
           m_peer == b.m_peer &&
           m_readInboxMaxId == b.m_readInboxMaxId &&
           m_topMessage == b.m_topMessage &&
           m_unreadCount == b.m_unreadCount;
}

void Dialog::setClassType(Dialog::DialogType classType) {
    m_classType = classType;
}

Dialog::DialogType Dialog::classType() const {
    return m_classType;
}

bool Dialog::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeDialog: {
        m_peer.fetch(in);
        m_topMessage = in->fetchInt();
        m_readInboxMaxId = in->fetchInt();
        m_unreadCount = in->fetchInt();
        m_notifySettings.fetch(in);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool Dialog::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeDialog: {
        m_peer.push(out);
        out->appendInt(m_topMessage);
        out->appendInt(m_readInboxMaxId);
        out->appendInt(m_unreadCount);
        m_notifySettings.push(out);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

