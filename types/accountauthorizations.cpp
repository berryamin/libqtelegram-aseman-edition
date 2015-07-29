#include "accountauthorizations.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

AccountAuthorizations::AccountAuthorizations(AccountAuthorizationsType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

AccountAuthorizations::AccountAuthorizations(InboundPkt *in) :
    m_classType(typeAccountAuthorizations)
{
    fetch(in);
}

void AccountAuthorizations::setAuthorizations(const QList<Authorization> &authorizations) {
    m_authorizations = authorizations;
}

QList<Authorization> AccountAuthorizations::authorizations() const {
    return m_authorizations;
}

bool AccountAuthorizations::operator ==(const AccountAuthorizations &b) {
    return m_authorizations == b.m_authorizations;
}

void AccountAuthorizations::setClassType(AccountAuthorizations::AccountAuthorizationsType classType) {
    m_classType = classType;
}

AccountAuthorizations::AccountAuthorizationsType AccountAuthorizations::classType() const {
    return m_classType;
}

bool AccountAuthorizations::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeAccountAuthorizations: {
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_authorizations_length = in->fetchInt();
        m_authorizations.clear();
        for (qint32 i = 0; i < m_authorizations_length; i++) {
            Authorization type;
            type.fetch(in);
            m_authorizations.append(type);
        }
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool AccountAuthorizations::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeAccountAuthorizations: {
        out->appendInt(TL_Vector);
        out->appendInt(m_authorizations.count());
        for (qint32 i = 0; i < m_authorizations.count(); i++) {
            m_authorizations[i].push(out);
        }
        return true;
    }
        break;
    
    default:
        return false;
    }
}

