#include "photosphotos.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

PhotosPhotos::PhotosPhotos(PhotosPhotosType classType, InboundPkt *in) :
    m_count(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

PhotosPhotos::PhotosPhotos(InboundPkt *in) :
    m_count(0),
    m_classType(typePhotosPhotos)
{
    fetch(in);
}

void PhotosPhotos::setCount(qint32 count) {
    m_count = count;
}

qint32 PhotosPhotos::count() const {
    return m_count;
}

void PhotosPhotos::setPhotos(const QList<Photo> &photos) {
    m_photos = photos;
}

QList<Photo> PhotosPhotos::photos() const {
    return m_photos;
}

void PhotosPhotos::setUsers(const QList<User> &users) {
    m_users = users;
}

QList<User> PhotosPhotos::users() const {
    return m_users;
}

bool PhotosPhotos::operator ==(const PhotosPhotos &b) {
    return m_count == b.m_count &&
           m_photos == b.m_photos &&
           m_users == b.m_users;
}

void PhotosPhotos::setClassType(PhotosPhotos::PhotosPhotosType classType) {
    m_classType = classType;
}

PhotosPhotos::PhotosPhotosType PhotosPhotos::classType() const {
    return m_classType;
}

bool PhotosPhotos::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typePhotosPhotos: {
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_photos_length = in->fetchInt();
        m_photos.clear();
        for (qint32 i = 0; i < m_photos_length; i++) {
            Photo type;
            type.fetch(in);
            m_photos.append(type);
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
    
    case typePhotosPhotosSlice: {
        m_count = in->fetchInt();
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_photos_length = in->fetchInt();
        m_photos.clear();
        for (qint32 i = 0; i < m_photos_length; i++) {
            Photo type;
            type.fetch(in);
            m_photos.append(type);
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

bool PhotosPhotos::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typePhotosPhotos: {
        out->appendInt(TL_Vector);
        out->appendInt(m_photos.count());
        for (qint32 i = 0; i < m_photos.count(); i++) {
            m_photos[i].push(out);
        }
        out->appendInt(TL_Vector);
        out->appendInt(m_users.count());
        for (qint32 i = 0; i < m_users.count(); i++) {
            m_users[i].push(out);
        }
        return true;
    }
        break;
    
    case typePhotosPhotosSlice: {
        out->appendInt(m_count);
        out->appendInt(TL_Vector);
        out->appendInt(m_photos.count());
        for (qint32 i = 0; i < m_photos.count(); i++) {
            m_photos[i].push(out);
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

