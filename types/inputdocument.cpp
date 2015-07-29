#include "inputdocument.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

InputDocument::InputDocument(InputDocumentType classType, InboundPkt *in) :
    m_accessHash(0),
    m_id(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

InputDocument::InputDocument(InboundPkt *in) :
    m_accessHash(0),
    m_id(0),
    m_classType(typeInputDocumentEmpty)
{
    fetch(in);
}

void InputDocument::setAccessHash(qint64 accessHash) {
    m_accessHash = accessHash;
}

qint64 InputDocument::accessHash() const {
    return m_accessHash;
}

void InputDocument::setId(qint64 id) {
    m_id = id;
}

qint64 InputDocument::id() const {
    return m_id;
}

bool InputDocument::operator ==(const InputDocument &b) {
    return m_accessHash == b.m_accessHash &&
           m_id == b.m_id;
}

void InputDocument::setClassType(InputDocument::InputDocumentType classType) {
    m_classType = classType;
}

InputDocument::InputDocumentType InputDocument::classType() const {
    return m_classType;
}

bool InputDocument::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeInputDocumentEmpty: {
        return true;
    }
        break;
    
    case typeInputDocument: {
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

bool InputDocument::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeInputDocumentEmpty: {
        return true;
    }
        break;
    
    case typeInputDocument: {
        out->appendLong(m_id);
        out->appendLong(m_accessHash);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

