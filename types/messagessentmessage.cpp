#include "messagessentmessage.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

MessagesSentMessage::MessagesSentMessage(MessagesSentMessageType classType, InboundPkt *in) :
    m_date(0),
    m_id(0),
    m_pts(0),
    m_ptsCount(0),
    m_seq(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

MessagesSentMessage::MessagesSentMessage(InboundPkt *in) :
    m_date(0),
    m_id(0),
    m_pts(0),
    m_ptsCount(0),
    m_seq(0),
    m_classType(typeMessagesSentMessage)
{
    fetch(in);
}

void MessagesSentMessage::setDate(qint32 date) {
    m_date = date;
}

qint32 MessagesSentMessage::date() const {
    return m_date;
}

void MessagesSentMessage::setId(qint32 id) {
    m_id = id;
}

qint32 MessagesSentMessage::id() const {
    return m_id;
}

void MessagesSentMessage::setLinks(const QList<ContactsLink> &links) {
    m_links = links;
}

QList<ContactsLink> MessagesSentMessage::links() const {
    return m_links;
}

void MessagesSentMessage::setMedia(const MessageMedia &media) {
    m_media = media;
}

MessageMedia MessagesSentMessage::media() const {
    return m_media;
}

void MessagesSentMessage::setPts(qint32 pts) {
    m_pts = pts;
}

qint32 MessagesSentMessage::pts() const {
    return m_pts;
}

void MessagesSentMessage::setPtsCount(qint32 ptsCount) {
    m_ptsCount = ptsCount;
}

qint32 MessagesSentMessage::ptsCount() const {
    return m_ptsCount;
}

void MessagesSentMessage::setSeq(qint32 seq) {
    m_seq = seq;
}

qint32 MessagesSentMessage::seq() const {
    return m_seq;
}

bool MessagesSentMessage::operator ==(const MessagesSentMessage &b) {
    return m_date == b.m_date &&
           m_id == b.m_id &&
           m_links == b.m_links &&
           m_media == b.m_media &&
           m_pts == b.m_pts &&
           m_ptsCount == b.m_ptsCount &&
           m_seq == b.m_seq;
}

void MessagesSentMessage::setClassType(MessagesSentMessage::MessagesSentMessageType classType) {
    m_classType = classType;
}

MessagesSentMessage::MessagesSentMessageType MessagesSentMessage::classType() const {
    return m_classType;
}

bool MessagesSentMessage::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeMessagesSentMessage: {
        m_id = in->fetchInt();
        m_date = in->fetchInt();
        m_media.fetch(in);
        m_pts = in->fetchInt();
        m_ptsCount = in->fetchInt();
        return true;
    }
        break;
    
    case typeMessagesSentMessageLink: {
        m_id = in->fetchInt();
        m_date = in->fetchInt();
        m_media.fetch(in);
        m_pts = in->fetchInt();
        m_ptsCount = in->fetchInt();
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_links_length = in->fetchInt();
        m_links.clear();
        for (qint32 i = 0; i < m_links_length; i++) {
            ContactsLink type;
            type.fetch(in);
            m_links.append(type);
        }
        m_seq = in->fetchInt();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool MessagesSentMessage::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessagesSentMessage: {
        out->appendInt(m_id);
        out->appendInt(m_date);
        m_media.push(out);
        out->appendInt(m_pts);
        out->appendInt(m_ptsCount);
        return true;
    }
        break;
    
    case typeMessagesSentMessageLink: {
        out->appendInt(m_id);
        out->appendInt(m_date);
        m_media.push(out);
        out->appendInt(m_pts);
        out->appendInt(m_ptsCount);
        out->appendInt(TL_Vector);
        out->appendInt(m_links.count());
        for (qint32 i = 0; i < m_links.count(); i++) {
            m_links[i].push(out);
        }
        out->appendInt(m_seq);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

