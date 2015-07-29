#include "userfull.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

UserFull::UserFull(UserFullType classType, InboundPkt *in) :
    m_blocked(false),
    m_classType(classType)
{
    if(in) fetch(in);
}

UserFull::UserFull(InboundPkt *in) :
    m_blocked(false),
    m_classType(typeUserFull)
{
    fetch(in);
}

void UserFull::setBlocked(bool blocked) {
    m_blocked = blocked;
}

bool UserFull::blocked() const {
    return m_blocked;
}

void UserFull::setLink(const ContactsLink &link) {
    m_link = link;
}

ContactsLink UserFull::link() const {
    return m_link;
}

void UserFull::setNotifySettings(const PeerNotifySettings &notifySettings) {
    m_notifySettings = notifySettings;
}

PeerNotifySettings UserFull::notifySettings() const {
    return m_notifySettings;
}

void UserFull::setProfilePhoto(const Photo &profilePhoto) {
    m_profilePhoto = profilePhoto;
}

Photo UserFull::profilePhoto() const {
    return m_profilePhoto;
}

void UserFull::setRealFirstName(const QString &realFirstName) {
    m_realFirstName = realFirstName;
}

QString UserFull::realFirstName() const {
    return m_realFirstName;
}

void UserFull::setRealLastName(const QString &realLastName) {
    m_realLastName = realLastName;
}

QString UserFull::realLastName() const {
    return m_realLastName;
}

void UserFull::setUser(const User &user) {
    m_user = user;
}

User UserFull::user() const {
    return m_user;
}

bool UserFull::operator ==(const UserFull &b) {
    return m_blocked == b.m_blocked &&
           m_link == b.m_link &&
           m_notifySettings == b.m_notifySettings &&
           m_profilePhoto == b.m_profilePhoto &&
           m_realFirstName == b.m_realFirstName &&
           m_realLastName == b.m_realLastName &&
           m_user == b.m_user;
}

void UserFull::setClassType(UserFull::UserFullType classType) {
    m_classType = classType;
}

UserFull::UserFullType UserFull::classType() const {
    return m_classType;
}

bool UserFull::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeUserFull: {
        m_user.fetch(in);
        m_link.fetch(in);
        m_profilePhoto.fetch(in);
        m_notifySettings.fetch(in);
        m_blocked = in->fetchBool();
        m_realFirstName = in->fetchQString();
        m_realLastName = in->fetchQString();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool UserFull::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeUserFull: {
        m_user.push(out);
        m_link.push(out);
        m_profilePhoto.push(out);
        m_notifySettings.push(out);
        out->appendBool(m_blocked);
        out->appendQString(m_realFirstName);
        out->appendQString(m_realLastName);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

