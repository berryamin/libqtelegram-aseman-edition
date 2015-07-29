#include "filelocation.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

FileLocation::FileLocation(FileLocationType classType, InboundPkt *in) :
    m_dcId(0),
    m_localId(0),
    m_secret(0),
    m_volumeId(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

FileLocation::FileLocation(InboundPkt *in) :
    m_dcId(0),
    m_localId(0),
    m_secret(0),
    m_volumeId(0),
    m_classType(typeFileLocationUnavailable)
{
    fetch(in);
}

void FileLocation::setDcId(qint32 dcId) {
    m_dcId = dcId;
}

qint32 FileLocation::dcId() const {
    return m_dcId;
}

void FileLocation::setLocalId(qint32 localId) {
    m_localId = localId;
}

qint32 FileLocation::localId() const {
    return m_localId;
}

void FileLocation::setSecret(qint64 secret) {
    m_secret = secret;
}

qint64 FileLocation::secret() const {
    return m_secret;
}

void FileLocation::setVolumeId(qint64 volumeId) {
    m_volumeId = volumeId;
}

qint64 FileLocation::volumeId() const {
    return m_volumeId;
}

bool FileLocation::operator ==(const FileLocation &b) {
    return m_dcId == b.m_dcId &&
           m_localId == b.m_localId &&
           m_secret == b.m_secret &&
           m_volumeId == b.m_volumeId;
}

void FileLocation::setClassType(FileLocation::FileLocationType classType) {
    m_classType = classType;
}

FileLocation::FileLocationType FileLocation::classType() const {
    return m_classType;
}

bool FileLocation::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeFileLocationUnavailable: {
        m_volumeId = in->fetchLong();
        m_localId = in->fetchInt();
        m_secret = in->fetchLong();
        return true;
    }
        break;
    
    case typeFileLocation: {
        m_dcId = in->fetchInt();
        m_volumeId = in->fetchLong();
        m_localId = in->fetchInt();
        m_secret = in->fetchLong();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool FileLocation::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeFileLocationUnavailable: {
        out->appendLong(m_volumeId);
        out->appendInt(m_localId);
        out->appendLong(m_secret);
        return true;
    }
        break;
    
    case typeFileLocation: {
        out->appendInt(m_dcId);
        out->appendLong(m_volumeId);
        out->appendInt(m_localId);
        out->appendLong(m_secret);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

