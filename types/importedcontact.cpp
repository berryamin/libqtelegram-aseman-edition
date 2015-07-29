#include "importedcontact.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

ImportedContact::ImportedContact(ImportedContactType classType, InboundPkt *in) :
    m_clientId(0),
    m_userId(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

ImportedContact::ImportedContact(InboundPkt *in) :
    m_clientId(0),
    m_userId(0),
    m_classType(typeImportedContact)
{
    fetch(in);
}

void ImportedContact::setClientId(qint64 clientId) {
    m_clientId = clientId;
}

qint64 ImportedContact::clientId() const {
    return m_clientId;
}

void ImportedContact::setUserId(qint32 userId) {
    m_userId = userId;
}

qint32 ImportedContact::userId() const {
    return m_userId;
}

bool ImportedContact::operator ==(const ImportedContact &b) {
    return m_clientId == b.m_clientId &&
           m_userId == b.m_userId;
}

void ImportedContact::setClassType(ImportedContact::ImportedContactType classType) {
    m_classType = classType;
}

ImportedContact::ImportedContactType ImportedContact::classType() const {
    return m_classType;
}

bool ImportedContact::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeImportedContact: {
        m_userId = in->fetchInt();
        m_clientId = in->fetchLong();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool ImportedContact::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeImportedContact: {
        out->appendInt(m_userId);
        out->appendLong(m_clientId);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

