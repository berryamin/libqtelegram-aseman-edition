#include "inputvideo.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

InputVideo::InputVideo(InputVideoType classType, InboundPkt *in) :
    m_accessHash(0),
    m_id(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

InputVideo::InputVideo(InboundPkt *in) :
    m_accessHash(0),
    m_id(0),
    m_classType(typeInputVideoEmpty)
{
    fetch(in);
}

void InputVideo::setAccessHash(qint64 accessHash) {
    m_accessHash = accessHash;
}

qint64 InputVideo::accessHash() const {
    return m_accessHash;
}

void InputVideo::setId(qint64 id) {
    m_id = id;
}

qint64 InputVideo::id() const {
    return m_id;
}

bool InputVideo::operator ==(const InputVideo &b) {
    return m_accessHash == b.m_accessHash &&
           m_id == b.m_id;
}

void InputVideo::setClassType(InputVideo::InputVideoType classType) {
    m_classType = classType;
}

InputVideo::InputVideoType InputVideo::classType() const {
    return m_classType;
}

bool InputVideo::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeInputVideoEmpty: {
        return true;
    }
        break;
    
    case typeInputVideo: {
        m_id = in->fetchLong();
        m_accessHash = in->fetchLong();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool InputVideo::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeInputVideoEmpty: {
        return true;
    }
        break;
    
    case typeInputVideo: {
        out->appendLong(m_id);
        out->appendLong(m_accessHash);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

