#include "video.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

Video::Video(VideoType classType, InboundPkt *in) :
    m_accessHash(0),
    m_date(0),
    m_dcId(0),
    m_duration(0),
    m_h(0),
    m_id(0),
    m_size(0),
    m_userId(0),
    m_w(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

Video::Video(InboundPkt *in) :
    m_accessHash(0),
    m_date(0),
    m_dcId(0),
    m_duration(0),
    m_h(0),
    m_id(0),
    m_size(0),
    m_userId(0),
    m_w(0),
    m_classType(typeVideoEmpty)
{
    fetch(in);
}

void Video::setAccessHash(qint64 accessHash) {
    m_accessHash = accessHash;
}

qint64 Video::accessHash() const {
    return m_accessHash;
}

void Video::setDate(qint32 date) {
    m_date = date;
}

qint32 Video::date() const {
    return m_date;
}

void Video::setDcId(qint32 dcId) {
    m_dcId = dcId;
}

qint32 Video::dcId() const {
    return m_dcId;
}

void Video::setDuration(qint32 duration) {
    m_duration = duration;
}

qint32 Video::duration() const {
    return m_duration;
}

void Video::setH(qint32 h) {
    m_h = h;
}

qint32 Video::h() const {
    return m_h;
}

void Video::setId(qint64 id) {
    m_id = id;
}

qint64 Video::id() const {
    return m_id;
}

void Video::setSize(qint32 size) {
    m_size = size;
}

qint32 Video::size() const {
    return m_size;
}

void Video::setThumb(const PhotoSize &thumb) {
    m_thumb = thumb;
}

PhotoSize Video::thumb() const {
    return m_thumb;
}

void Video::setUserId(qint32 userId) {
    m_userId = userId;
}

qint32 Video::userId() const {
    return m_userId;
}

void Video::setW(qint32 w) {
    m_w = w;
}

qint32 Video::w() const {
    return m_w;
}

bool Video::operator ==(const Video &b) {
    return m_accessHash == b.m_accessHash &&
           m_date == b.m_date &&
           m_dcId == b.m_dcId &&
           m_duration == b.m_duration &&
           m_h == b.m_h &&
           m_id == b.m_id &&
           m_size == b.m_size &&
           m_thumb == b.m_thumb &&
           m_userId == b.m_userId &&
           m_w == b.m_w;
}

void Video::setClassType(Video::VideoType classType) {
    m_classType = classType;
}

Video::VideoType Video::classType() const {
    return m_classType;
}

bool Video::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeVideoEmpty: {
        m_id = in->fetchLong();
        return true;
    }
        break;
    
    case typeVideo: {
        m_id = in->fetchLong();
        m_accessHash = in->fetchLong();
        m_userId = in->fetchInt();
        m_date = in->fetchInt();
        m_duration = in->fetchInt();
        m_size = in->fetchInt();
        m_thumb.fetch(in);
        m_dcId = in->fetchInt();
        m_w = in->fetchInt();
        m_h = in->fetchInt();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool Video::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeVideoEmpty: {
        out->appendLong(m_id);
        return true;
    }
        break;
    
    case typeVideo: {
        out->appendLong(m_id);
        out->appendLong(m_accessHash);
        out->appendInt(m_userId);
        out->appendInt(m_date);
        out->appendInt(m_duration);
        out->appendInt(m_size);
        m_thumb.push(out);
        out->appendInt(m_dcId);
        out->appendInt(m_w);
        out->appendInt(m_h);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

