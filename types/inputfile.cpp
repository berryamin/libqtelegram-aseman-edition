#include "inputfile.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

InputFile::InputFile(InputFileType classType, InboundPkt *in) :
    m_id(0),
    m_parts(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

InputFile::InputFile(InboundPkt *in) :
    m_id(0),
    m_parts(0),
    m_classType(typeInputFile)
{
    fetch(in);
}

void InputFile::setId(qint64 id) {
    m_id = id;
}

qint64 InputFile::id() const {
    return m_id;
}

void InputFile::setMd5Checksum(const QString &md5Checksum) {
    m_md5Checksum = md5Checksum;
}

QString InputFile::md5Checksum() const {
    return m_md5Checksum;
}

void InputFile::setName(const QString &name) {
    m_name = name;
}

QString InputFile::name() const {
    return m_name;
}

void InputFile::setParts(qint32 parts) {
    m_parts = parts;
}

qint32 InputFile::parts() const {
    return m_parts;
}

bool InputFile::operator ==(const InputFile &b) {
    return m_id == b.m_id &&
           m_md5Checksum == b.m_md5Checksum &&
           m_name == b.m_name &&
           m_parts == b.m_parts;
}

void InputFile::setClassType(InputFile::InputFileType classType) {
    m_classType = classType;
}

InputFile::InputFileType InputFile::classType() const {
    return m_classType;
}

bool InputFile::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeInputFile: {
        m_id = in->fetchLong();
        m_parts = in->fetchInt();
        m_name = in->fetchQString();
        m_md5Checksum = in->fetchQString();
        return true;
    }
        break;
    
    case typeInputFileBig: {
        m_id = in->fetchLong();
        m_parts = in->fetchInt();
        m_name = in->fetchQString();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool InputFile::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeInputFile: {
        out->appendLong(m_id);
        out->appendInt(m_parts);
        out->appendQString(m_name);
        out->appendQString(m_md5Checksum);
        return true;
    }
        break;
    
    case typeInputFileBig: {
        out->appendLong(m_id);
        out->appendInt(m_parts);
        out->appendQString(m_name);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

