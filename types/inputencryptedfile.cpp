#include "inputencryptedfile.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

InputEncryptedFile::InputEncryptedFile(InputEncryptedFileType classType, InboundPkt *in) :
    m_accessHash(0),
    m_id(0),
    m_keyFingerprint(0),
    m_parts(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

InputEncryptedFile::InputEncryptedFile(InboundPkt *in) :
    m_accessHash(0),
    m_id(0),
    m_keyFingerprint(0),
    m_parts(0),
    m_classType(typeInputEncryptedFileEmpty)
{
    fetch(in);
}

void InputEncryptedFile::setAccessHash(qint64 accessHash) {
    m_accessHash = accessHash;
}

qint64 InputEncryptedFile::accessHash() const {
    return m_accessHash;
}

void InputEncryptedFile::setId(qint64 id) {
    m_id = id;
}

qint64 InputEncryptedFile::id() const {
    return m_id;
}

void InputEncryptedFile::setKeyFingerprint(qint32 keyFingerprint) {
    m_keyFingerprint = keyFingerprint;
}

qint32 InputEncryptedFile::keyFingerprint() const {
    return m_keyFingerprint;
}

void InputEncryptedFile::setMd5Checksum(const QString &md5Checksum) {
    m_md5Checksum = md5Checksum;
}

QString InputEncryptedFile::md5Checksum() const {
    return m_md5Checksum;
}

void InputEncryptedFile::setParts(qint32 parts) {
    m_parts = parts;
}

qint32 InputEncryptedFile::parts() const {
    return m_parts;
}

bool InputEncryptedFile::operator ==(const InputEncryptedFile &b) {
    return m_accessHash == b.m_accessHash &&
           m_id == b.m_id &&
           m_keyFingerprint == b.m_keyFingerprint &&
           m_md5Checksum == b.m_md5Checksum &&
           m_parts == b.m_parts;
}

void InputEncryptedFile::setClassType(InputEncryptedFile::InputEncryptedFileType classType) {
    m_classType = classType;
}

InputEncryptedFile::InputEncryptedFileType InputEncryptedFile::classType() const {
    return m_classType;
}

bool InputEncryptedFile::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeInputEncryptedFileEmpty: {
        return true;
    }
        break;
    
    case typeInputEncryptedFileUploaded: {
        m_id = in->fetchLong();
        m_parts = in->fetchInt();
        m_md5Checksum = in->fetchQString();
        m_keyFingerprint = in->fetchInt();
        return true;
    }
        break;
    
    case typeInputEncryptedFile: {
        m_id = in->fetchLong();
        m_accessHash = in->fetchLong();
        return true;
    }
        break;
    
    case typeInputEncryptedFileBigUploaded: {
        m_id = in->fetchLong();
        m_parts = in->fetchInt();
        m_keyFingerprint = in->fetchInt();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool InputEncryptedFile::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeInputEncryptedFileEmpty: {
        return true;
    }
        break;
    
    case typeInputEncryptedFileUploaded: {
        out->appendLong(m_id);
        out->appendInt(m_parts);
        out->appendQString(m_md5Checksum);
        out->appendInt(m_keyFingerprint);
        return true;
    }
        break;
    
    case typeInputEncryptedFile: {
        out->appendLong(m_id);
        out->appendLong(m_accessHash);
        return true;
    }
        break;
    
    case typeInputEncryptedFileBigUploaded: {
        out->appendLong(m_id);
        out->appendInt(m_parts);
        out->appendInt(m_keyFingerprint);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

