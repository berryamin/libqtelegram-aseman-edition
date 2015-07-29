#include "userprofilephoto.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

UserProfilePhoto::UserProfilePhoto(UserProfilePhotoType classType, InboundPkt *in) :
    m_photoId(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

UserProfilePhoto::UserProfilePhoto(InboundPkt *in) :
    m_photoId(0),
    m_classType(typeUserProfilePhotoEmpty)
{
    fetch(in);
}

void UserProfilePhoto::setPhotoBig(const FileLocation &photoBig) {
    m_photoBig = photoBig;
}

FileLocation UserProfilePhoto::photoBig() const {
    return m_photoBig;
}

void UserProfilePhoto::setPhotoId(qint64 photoId) {
    m_photoId = photoId;
}

qint64 UserProfilePhoto::photoId() const {
    return m_photoId;
}

void UserProfilePhoto::setPhotoSmall(const FileLocation &photoSmall) {
    m_photoSmall = photoSmall;
}

FileLocation UserProfilePhoto::photoSmall() const {
    return m_photoSmall;
}

bool UserProfilePhoto::operator ==(const UserProfilePhoto &b) {
    return m_photoBig == b.m_photoBig &&
           m_photoId == b.m_photoId &&
           m_photoSmall == b.m_photoSmall;
}

void UserProfilePhoto::setClassType(UserProfilePhoto::UserProfilePhotoType classType) {
    m_classType = classType;
}

UserProfilePhoto::UserProfilePhotoType UserProfilePhoto::classType() const {
    return m_classType;
}

bool UserProfilePhoto::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeUserProfilePhotoEmpty: {
        return true;
    }
        break;
    
    case typeUserProfilePhoto: {
        m_photoId = in->fetchLong();
        m_photoSmall.fetch(in);
        m_photoBig.fetch(in);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool UserProfilePhoto::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeUserProfilePhotoEmpty: {
        return true;
    }
        break;
    
    case typeUserProfilePhoto: {
        out->appendLong(m_photoId);
        m_photoSmall.push(out);
        m_photoBig.push(out);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

