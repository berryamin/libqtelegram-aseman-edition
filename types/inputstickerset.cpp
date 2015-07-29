#include "inputstickerset.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

InputStickerSet::InputStickerSet(InputStickerSetType classType, InboundPkt *in) :
    m_accessHash(0),
    m_id(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

InputStickerSet::InputStickerSet(InboundPkt *in) :
    m_accessHash(0),
    m_id(0),
    m_classType(typeInputStickerSetEmpty)
{
    fetch(in);
}

void InputStickerSet::setAccessHash(qint64 accessHash) {
    m_accessHash = accessHash;
}

qint64 InputStickerSet::accessHash() const {
    return m_accessHash;
}

void InputStickerSet::setId(qint64 id) {
    m_id = id;
}

qint64 InputStickerSet::id() const {
    return m_id;
}

void InputStickerSet::setShortName(const QString &shortName) {
    m_shortName = shortName;
}

QString InputStickerSet::shortName() const {
    return m_shortName;
}

bool InputStickerSet::operator ==(const InputStickerSet &b) {
    return m_accessHash == b.m_accessHash &&
           m_id == b.m_id &&
           m_shortName == b.m_shortName;
}

void InputStickerSet::setClassType(InputStickerSet::InputStickerSetType classType) {
    m_classType = classType;
}

InputStickerSet::InputStickerSetType InputStickerSet::classType() const {
    return m_classType;
}

bool InputStickerSet::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeInputStickerSetEmpty: {
        return true;
    }
        break;
    
    case typeInputStickerSetID: {
        m_id = in->fetchLong();
        m_accessHash = in->fetchLong();
        return true;
    }
        break;
    
    case typeInputStickerSetShortName: {
        m_shortName = in->fetchQString();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool InputStickerSet::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeInputStickerSetEmpty: {
        return true;
    }
        break;
    
    case typeInputStickerSetID: {
        out->appendLong(m_id);
        out->appendLong(m_accessHash);
        return true;
    }
        break;
    
    case typeInputStickerSetShortName: {
        out->appendQString(m_shortName);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

