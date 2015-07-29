#include "message.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

Message::Message(MessageType classType, InboundPkt *in) :
    m_date(0),
    m_flags(0),
    m_fromId(0),
    m_fwdDate(0),
    m_fwdFromId(0),
    m_id(0),
    m_replyToMsgId(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

Message::Message(InboundPkt *in) :
    m_date(0),
    m_flags(0),
    m_fromId(0),
    m_fwdDate(0),
    m_fwdFromId(0),
    m_id(0),
    m_replyToMsgId(0),
    m_classType(typeMessageEmpty)
{
    fetch(in);
}

void Message::setAction(const MessageAction &action) {
    m_action = action;
}

MessageAction Message::action() const {
    return m_action;
}

void Message::setDate(qint32 date) {
    m_date = date;
}

qint32 Message::date() const {
    return m_date;
}

void Message::setFlags(qint32 flags) {
    m_flags = flags;
}

qint32 Message::flags() const {
    return m_flags;
}

void Message::setFromId(qint32 fromId) {
    m_fromId = fromId;
}

qint32 Message::fromId() const {
    return m_fromId;
}

void Message::setFwdDate(qint32 fwdDate) {
    m_fwdDate = fwdDate;
}

qint32 Message::fwdDate() const {
    return m_fwdDate;
}

void Message::setFwdFromId(qint32 fwdFromId) {
    m_fwdFromId = fwdFromId;
}

qint32 Message::fwdFromId() const {
    return m_fwdFromId;
}

void Message::setId(qint32 id) {
    m_id = id;
}

qint32 Message::id() const {
    return m_id;
}

void Message::setMedia(const MessageMedia &media) {
    m_media = media;
}

MessageMedia Message::media() const {
    return m_media;
}

void Message::setMessage(const QString &message) {
    m_message = message;
}

QString Message::message() const {
    return m_message;
}

void Message::setReplyToMsgId(qint32 replyToMsgId) {
    m_replyToMsgId = replyToMsgId;
}

qint32 Message::replyToMsgId() const {
    return m_replyToMsgId;
}

void Message::setToId(const Peer &toId) {
    m_toId = toId;
}

Peer Message::toId() const {
    return m_toId;
}

bool Message::operator ==(const Message &b) {
    return m_action == b.m_action &&
           m_date == b.m_date &&
           m_flags == b.m_flags &&
           m_fromId == b.m_fromId &&
           m_fwdDate == b.m_fwdDate &&
           m_fwdFromId == b.m_fwdFromId &&
           m_id == b.m_id &&
           m_media == b.m_media &&
           m_message == b.m_message &&
           m_replyToMsgId == b.m_replyToMsgId &&
           m_toId == b.m_toId;
}

void Message::setClassType(Message::MessageType classType) {
    m_classType = classType;
}

Message::MessageType Message::classType() const {
    return m_classType;
}

bool Message::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeMessageEmpty: {
        m_id = in->fetchInt();
        return true;
    }
        break;
    
    case typeMessage: {
        m_flags = in->fetchInt();
        m_id = in->fetchInt();
        m_fromId = in->fetchInt();
        m_toId.fetch(in);
        if(m_flags & 1<<2) {
            m_fwdFromId = in->fetchInt();
        }
        if(m_flags & 1<<2) {
            m_fwdDate = in->fetchInt();
        }
        if(m_flags & 1<<3) {
            m_replyToMsgId = in->fetchInt();
        }
        m_date = in->fetchInt();
        m_message = in->fetchQString();
        m_media.fetch(in);
        return true;
    }
        break;
    
    case typeMessageService: {
        m_flags = in->fetchInt();
        m_id = in->fetchInt();
        m_fromId = in->fetchInt();
        m_toId.fetch(in);
        m_date = in->fetchInt();
        m_action.fetch(in);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool Message::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessageEmpty: {
        out->appendInt(m_id);
        return true;
    }
        break;
    
    case typeMessage: {
        out->appendInt(m_flags);
        out->appendInt(m_id);
        out->appendInt(m_fromId);
        m_toId.push(out);
        out->appendInt(m_fwdFromId);
        out->appendInt(m_fwdDate);
        out->appendInt(m_replyToMsgId);
        out->appendInt(m_date);
        out->appendQString(m_message);
        m_media.push(out);
        return true;
    }
        break;
    
    case typeMessageService: {
        out->appendInt(m_flags);
        out->appendInt(m_id);
        out->appendInt(m_fromId);
        m_toId.push(out);
        out->appendInt(m_date);
        m_action.push(out);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

