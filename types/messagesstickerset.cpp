#include "messagesstickerset.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

MessagesStickerSet::MessagesStickerSet(MessagesStickerSetType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

MessagesStickerSet::MessagesStickerSet(InboundPkt *in) :
    m_classType(typeMessagesStickerSet)
{
    fetch(in);
}

void MessagesStickerSet::setDocuments(const QList<Document> &documents) {
    m_documents = documents;
}

QList<Document> MessagesStickerSet::documents() const {
    return m_documents;
}

void MessagesStickerSet::setPacks(const QList<StickerPack> &packs) {
    m_packs = packs;
}

QList<StickerPack> MessagesStickerSet::packs() const {
    return m_packs;
}

void MessagesStickerSet::setSet(const StickerSet &set) {
    m_set = set;
}

StickerSet MessagesStickerSet::set() const {
    return m_set;
}

bool MessagesStickerSet::operator ==(const MessagesStickerSet &b) {
    return m_documents == b.m_documents &&
           m_packs == b.m_packs &&
           m_set == b.m_set;
}

void MessagesStickerSet::setClassType(MessagesStickerSet::MessagesStickerSetType classType) {
    m_classType = classType;
}

MessagesStickerSet::MessagesStickerSetType MessagesStickerSet::classType() const {
    return m_classType;
}

bool MessagesStickerSet::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeMessagesStickerSet: {
        m_set.fetch(in);
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_packs_length = in->fetchInt();
        m_packs.clear();
        for (qint32 i = 0; i < m_packs_length; i++) {
            StickerPack type;
            type.fetch(in);
            m_packs.append(type);
        }
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_documents_length = in->fetchInt();
        m_documents.clear();
        for (qint32 i = 0; i < m_documents_length; i++) {
            Document type;
            type.fetch(in);
            m_documents.append(type);
        }
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool MessagesStickerSet::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessagesStickerSet: {
        m_set.push(out);
        out->appendInt(TL_Vector);
        out->appendInt(m_packs.count());
        for (qint32 i = 0; i < m_packs.count(); i++) {
            m_packs[i].push(out);
        }
        out->appendInt(TL_Vector);
        out->appendInt(m_documents.count());
        for (qint32 i = 0; i < m_documents.count(); i++) {
            m_documents[i].push(out);
        }
        return true;
    }
        break;
    
    default:
        return false;
    }
}

