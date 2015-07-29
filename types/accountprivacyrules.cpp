#include "accountprivacyrules.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

AccountPrivacyRules::AccountPrivacyRules(AccountPrivacyRulesType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

AccountPrivacyRules::AccountPrivacyRules(InboundPkt *in) :
    m_classType(typeAccountPrivacyRules)
{
    fetch(in);
}

void AccountPrivacyRules::setRules(const QList<PrivacyRule> &rules) {
    m_rules = rules;
}

QList<PrivacyRule> AccountPrivacyRules::rules() const {
    return m_rules;
}

void AccountPrivacyRules::setUsers(const QList<User> &users) {
    m_users = users;
}

QList<User> AccountPrivacyRules::users() const {
    return m_users;
}

bool AccountPrivacyRules::operator ==(const AccountPrivacyRules &b) {
    return m_rules == b.m_rules &&
           m_users == b.m_users;
}

void AccountPrivacyRules::setClassType(AccountPrivacyRules::AccountPrivacyRulesType classType) {
    m_classType = classType;
}

AccountPrivacyRules::AccountPrivacyRulesType AccountPrivacyRules::classType() const {
    return m_classType;
}

bool AccountPrivacyRules::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeAccountPrivacyRules: {
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_rules_length = in->fetchInt();
        m_rules.clear();
        for (qint32 i = 0; i < m_rules_length; i++) {
            PrivacyRule type;
            type.fetch(in);
            m_rules.append(type);
        }
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_users_length = in->fetchInt();
        m_users.clear();
        for (qint32 i = 0; i < m_users_length; i++) {
            User type;
            type.fetch(in);
            m_users.append(type);
        }
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool AccountPrivacyRules::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeAccountPrivacyRules: {
        out->appendInt(TL_Vector);
        out->appendInt(m_rules.count());
        for (qint32 i = 0; i < m_rules.count(); i++) {
            m_rules[i].push(out);
        }
        out->appendInt(TL_Vector);
        out->appendInt(m_users.count());
        for (qint32 i = 0; i < m_users.count(); i++) {
            m_users[i].push(out);
        }
        return true;
    }
        break;
    
    default:
        return false;
    }
}

