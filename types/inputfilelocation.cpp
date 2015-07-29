#include "inputfilelocation.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

InputFileLocation::InputFileLocation(InputFileLocationType classType, InboundPkt *in) :
    m_accessHash(0),
    m_id(0),
    m_localId(0),
    m_secret(0),
    m_volumeId(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

InputFileLocation::InputFileLocation(InboundPkt *in) :
    m_accessHash(0),
    m_id(0),
    m_localId(0),
    m_secret(0),
    m_volumeId(0),
    m_classType(typeInputFileLocation)
{
    fetch(in);
}

void InputFileLocation::setAccessHash(qint64 accessHash) {
    m_accessHash = accessHash;
}

qint64 InputFileLocation::accessHash() const {
    return m_accessHash;
}

void InputFileLocation::setId(qint64 id) {
    m_id = id;
}

qint64 InputFileLocation::id() const {
    return m_id;
}

void InputFileLocation::setLocalId(qint32 localId) {
    m_localId = localId;
}

qint32 InputFileLocation::localId() const {
    return m_localId;
}

void InputFileLocation::setSecret(qint64 secret) {
    m_secret = secret;
}

qint64 InputFileLocation::secret() const {
    return m_secret;
}

void InputFileLocation::setVolumeId(qint64 volumeId) {
    m_volumeId = volumeId;
}

qint64 InputFileLocation::volumeId() const {
    return m_volumeId;
}

bool InputFileLocation::operator ==(const InputFileLocation &b) {
    return m_accessHash == b.m_accessHash &&
           m_id == b.m_id &&
           m_localId == b.m_localId &&
           m_secret == b.m_secret &&
           m_volumeId == b.m_volumeId;
}

void InputFileLocation::setClassType(InputFileLocation::InputFileLocationType classType) {
    m_classType = classType;
}

InputFileLocation::InputFileLocationType InputFileLocation::classType() const {
    return m_classType;
}

bool InputFileLocation::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeInputFileLocation: {
        m_volumeId = in->fetchLong();
        m_localId = in->fetchInt();
        m_secret = in->fetchLong();
        return true;
    }
        break;
    
    case typeInputVideoFileLocation: {
        m_id = in->fetchLong();
        m_accessHash = in->fetchLong();
        return true;
    }
        break;
    
    case typeInputEncryptedFileLocation: {
        m_id = in->fetchLong();
        m_accessHash = in->fetchLong();
        return true;
    }
        break;
    
    case typeInputAudioFileLocation: {
        m_id = in->fetchLong();
        m_accessHash = in->fetchLong();
        return true;
    }
        break;
    
    case typeInputDocumentFileLocation: {
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

bool InputFileLocation::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeInputFileLocation: {
        out->appendLong(m_volumeId);
        out->appendInt(m_localId);
        out->appendLong(m_secret);
        return true;
    }
        break;
    
    case typeInputVideoFileLocation: {
        out->appendLong(m_id);
        out->appendLong(m_accessHash);
        return true;
    }
        break;
    
    case typeInputEncryptedFileLocation: {
        out->appendLong(m_id);
        out->appendLong(m_accessHash);
        return true;
    }
        break;
    
    case typeInputAudioFileLocation: {
        out->appendLong(m_id);
        out->appendLong(m_accessHash);
        return true;
    }
        break;
    
    case typeInputDocumentFileLocation: {
        out->appendLong(m_id);
        out->appendLong(m_accessHash);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

