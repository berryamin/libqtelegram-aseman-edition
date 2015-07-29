#include "stickerset.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

StickerSet::StickerSet(StickerSetType classType, InboundPkt *in) :
    m_accessHash(0),
    m_id(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

StickerSet::StickerSet(InboundPkt *in) :
    m_accessHash(0),
    m_id(0),
    m_classType(typeStickerSet)
{
    fetch(in);
}

void StickerSet::setAccessHash(qint64 accessHash) {
    m_accessHash = accessHash;
}

qint64 StickerSet::accessHash() const {
    return m_accessHash;
}

void StickerSet::setId(qint64 id) {
    m_id = id;
}

qint64 StickerSet::id() const {
    return m_id;
}

void StickerSet::setShortName(const QString &shortName) {
    m_shortName = shortName;
}

QString StickerSet::shortName() const {
    return m_shortName;
}

void StickerSet::setTitle(const QString &title) {
    m_title = title;
}

QString StickerSet::title() const {
    return m_title;
}

bool StickerSet::operator ==(const StickerSet &b) {
    return m_accessHash == b.m_accessHash &&
           m_id == b.m_id &&
           m_shortName == b.m_shortName &&
           m_title == b.m_title;
}

void StickerSet::setClassType(StickerSet::StickerSetType classType) {
    m_classType = classType;
}

StickerSet::StickerSetType StickerSet::classType() const {
    return m_classType;
}

bool StickerSet::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeStickerSet: {
        m_id = in->fetchLong();
        m_accessHash = in->fetchLong();
        m_title = in->fetchQString();
        m_shortName = in->fetchQString();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool StickerSet::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeStickerSet: {
        out->appendLong(m_id);
        out->appendLong(m_accessHash);
        out->appendQString(m_title);
        out->appendQString(m_shortName);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

