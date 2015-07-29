#include "inputphoto.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

InputPhoto::InputPhoto(InputPhotoType classType, InboundPkt *in) :
    m_accessHash(0),
    m_id(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

InputPhoto::InputPhoto(InboundPkt *in) :
    m_accessHash(0),
    m_id(0),
    m_classType(typeInputPhotoEmpty)
{
    fetch(in);
}

void InputPhoto::setAccessHash(qint64 accessHash) {
    m_accessHash = accessHash;
}

qint64 InputPhoto::accessHash() const {
    return m_accessHash;
}

void InputPhoto::setId(qint64 id) {
    m_id = id;
}

qint64 InputPhoto::id() const {
    return m_id;
}

bool InputPhoto::operator ==(const InputPhoto &b) {
    return m_accessHash == b.m_accessHash &&
           m_id == b.m_id;
}

void InputPhoto::setClassType(InputPhoto::InputPhotoType classType) {
    m_classType = classType;
}

InputPhoto::InputPhotoType InputPhoto::classType() const {
    return m_classType;
}

bool InputPhoto::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeInputPhotoEmpty: {
        return true;
    }
        break;
    
    case typeInputPhoto: {
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

bool InputPhoto::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeInputPhotoEmpty: {
        return true;
    }
        break;
    
    case typeInputPhoto: {
        out->appendLong(m_id);
        out->appendLong(m_accessHash);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

