#include "document.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

Document::Document(DocumentType classType, InboundPkt *in) :
    m_accessHash(0),
    m_date(0),
    m_dcId(0),
    m_id(0),
    m_size(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

Document::Document(InboundPkt *in) :
    m_accessHash(0),
    m_date(0),
    m_dcId(0),
    m_id(0),
    m_size(0),
    m_classType(typeDocumentEmpty)
{
    fetch(in);
}

void Document::setAccessHash(qint64 accessHash) {
    m_accessHash = accessHash;
}

qint64 Document::accessHash() const {
    return m_accessHash;
}

void Document::setAttributes(const QList<DocumentAttribute> &attributes) {
    m_attributes = attributes;
}

QList<DocumentAttribute> Document::attributes() const {
    return m_attributes;
}

void Document::setDate(qint32 date) {
    m_date = date;
}

qint32 Document::date() const {
    return m_date;
}

void Document::setDcId(qint32 dcId) {
    m_dcId = dcId;
}

qint32 Document::dcId() const {
    return m_dcId;
}

void Document::setId(qint64 id) {
    m_id = id;
}

qint64 Document::id() const {
    return m_id;
}

void Document::setMimeType(const QString &mimeType) {
    m_mimeType = mimeType;
}

QString Document::mimeType() const {
    return m_mimeType;
}

void Document::setSize(qint32 size) {
    m_size = size;
}

qint32 Document::size() const {
    return m_size;
}

void Document::setThumb(const PhotoSize &thumb) {
    m_thumb = thumb;
}

PhotoSize Document::thumb() const {
    return m_thumb;
}

bool Document::operator ==(const Document &b) {
    return m_accessHash == b.m_accessHash &&
           m_attributes == b.m_attributes &&
           m_date == b.m_date &&
           m_dcId == b.m_dcId &&
           m_id == b.m_id &&
           m_mimeType == b.m_mimeType &&
           m_size == b.m_size &&
           m_thumb == b.m_thumb;
}

void Document::setClassType(Document::DocumentType classType) {
    m_classType = classType;
}

Document::DocumentType Document::classType() const {
    return m_classType;
}

bool Document::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeDocumentEmpty: {
        m_id = in->fetchLong();
        return true;
    }
        break;
    
    case typeDocument: {
        m_id = in->fetchLong();
        m_accessHash = in->fetchLong();
        m_date = in->fetchInt();
        m_mimeType = in->fetchQString();
        m_size = in->fetchInt();
        m_thumb.fetch(in);
        m_dcId = in->fetchInt();
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_attributes_length = in->fetchInt();
        m_attributes.clear();
        for (qint32 i = 0; i < m_attributes_length; i++) {
            DocumentAttribute type;
            type.fetch(in);
            m_attributes.append(type);
        }
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool Document::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeDocumentEmpty: {
        out->appendLong(m_id);
        return true;
    }
        break;
    
    case typeDocument: {
        out->appendLong(m_id);
        out->appendLong(m_accessHash);
        out->appendInt(m_date);
        out->appendQString(m_mimeType);
        out->appendInt(m_size);
        m_thumb.push(out);
        out->appendInt(m_dcId);
        out->appendInt(TL_Vector);
        out->appendInt(m_attributes.count());
        for (qint32 i = 0; i < m_attributes.count(); i++) {
            m_attributes[i].push(out);
        }
        return true;
    }
        break;
    
    default:
        return false;
    }
}

