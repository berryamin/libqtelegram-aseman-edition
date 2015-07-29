#include "inputaudio.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

InputAudio::InputAudio(InputAudioType classType, InboundPkt *in) :
    m_accessHash(0),
    m_id(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

InputAudio::InputAudio(InboundPkt *in) :
    m_accessHash(0),
    m_id(0),
    m_classType(typeInputAudioEmpty)
{
    fetch(in);
}

void InputAudio::setAccessHash(qint64 accessHash) {
    m_accessHash = accessHash;
}

qint64 InputAudio::accessHash() const {
    return m_accessHash;
}

void InputAudio::setId(qint64 id) {
    m_id = id;
}

qint64 InputAudio::id() const {
    return m_id;
}

bool InputAudio::operator ==(const InputAudio &b) {
    return m_accessHash == b.m_accessHash &&
           m_id == b.m_id;
}

void InputAudio::setClassType(InputAudio::InputAudioType classType) {
    m_classType = classType;
}

InputAudio::InputAudioType InputAudio::classType() const {
    return m_classType;
}

bool InputAudio::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeInputAudioEmpty: {
        return true;
    }
        break;
    
    case typeInputAudio: {
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

bool InputAudio::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeInputAudioEmpty: {
        return true;
    }
        break;
    
    case typeInputAudio: {
        out->appendLong(m_id);
        out->appendLong(m_accessHash);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

