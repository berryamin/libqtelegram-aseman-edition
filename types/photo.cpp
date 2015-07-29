#include "photo.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

Photo::Photo(PhotoType classType, InboundPkt *in) :
    m_accessHash(0),
    m_date(0),
    m_id(0),
    m_userId(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

Photo::Photo(InboundPkt *in) :
    m_accessHash(0),
    m_date(0),
    m_id(0),
    m_userId(0),
    m_classType(typePhotoEmpty)
{
    fetch(in);
}

void Photo::setAccessHash(qint64 accessHash) {
    m_accessHash = accessHash;
}

qint64 Photo::accessHash() const {
    return m_accessHash;
}

void Photo::setDate(qint32 date) {
    m_date = date;
}

qint32 Photo::date() const {
    return m_date;
}

void Photo::setGeo(const GeoPoint &geo) {
    m_geo = geo;
}

GeoPoint Photo::geo() const {
    return m_geo;
}

void Photo::setId(qint64 id) {
    m_id = id;
}

qint64 Photo::id() const {
    return m_id;
}

void Photo::setSizes(const QList<PhotoSize> &sizes) {
    m_sizes = sizes;
}

QList<PhotoSize> Photo::sizes() const {
    return m_sizes;
}

void Photo::setUserId(qint32 userId) {
    m_userId = userId;
}

qint32 Photo::userId() const {
    return m_userId;
}

bool Photo::operator ==(const Photo &b) {
    return m_accessHash == b.m_accessHash &&
           m_date == b.m_date &&
           m_geo == b.m_geo &&
           m_id == b.m_id &&
           m_sizes == b.m_sizes &&
           m_userId == b.m_userId;
}

void Photo::setClassType(Photo::PhotoType classType) {
    m_classType = classType;
}

Photo::PhotoType Photo::classType() const {
    return m_classType;
}

bool Photo::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typePhotoEmpty: {
        m_id = in->fetchLong();
        return true;
    }
        break;
    
    case typePhoto: {
        m_id = in->fetchLong();
        m_accessHash = in->fetchLong();
        m_userId = in->fetchInt();
        m_date = in->fetchInt();
        m_geo.fetch(in);
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_sizes_length = in->fetchInt();
        m_sizes.clear();
        for (qint32 i = 0; i < m_sizes_length; i++) {
            PhotoSize type;
            type.fetch(in);
            m_sizes.append(type);
        }
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool Photo::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typePhotoEmpty: {
        out->appendLong(m_id);
        return true;
    }
        break;
    
    case typePhoto: {
        out->appendLong(m_id);
        out->appendLong(m_accessHash);
        out->appendInt(m_userId);
        out->appendInt(m_date);
        m_geo.push(out);
        out->appendInt(TL_Vector);
        out->appendInt(m_sizes.count());
        for (qint32 i = 0; i < m_sizes.count(); i++) {
            m_sizes[i].push(out);
        }
        return true;
    }
        break;
    
    default:
        return false;
    }
}

