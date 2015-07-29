#include "messagesallstickers.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

MessagesAllStickers::MessagesAllStickers(MessagesAllStickersType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

MessagesAllStickers::MessagesAllStickers(InboundPkt *in) :
    m_classType(typeMessagesAllStickersNotModified)
{
    fetch(in);
}

void MessagesAllStickers::setDocuments(const QList<Document> &documents) {
    m_documents = documents;
}

QList<Document> MessagesAllStickers::documents() const {
    return m_documents;
}

void MessagesAllStickers::setHash(const QString &hash) {
    m_hash = hash;
}

QString MessagesAllStickers::hash() const {
    return m_hash;
}

void MessagesAllStickers::setPacks(const QList<StickerPack> &packs) {
    m_packs = packs;
}

QList<StickerPack> MessagesAllStickers::packs() const {
    return m_packs;
}

void MessagesAllStickers::setSets(const QList<StickerSet> &sets) {
    m_sets = sets;
}

QList<StickerSet> MessagesAllStickers::sets() const {
    return m_sets;
}

bool MessagesAllStickers::operator ==(const MessagesAllStickers &b) {
    return m_documents == b.m_documents &&
           m_hash == b.m_hash &&
           m_packs == b.m_packs &&
           m_sets == b.m_sets;
}

void MessagesAllStickers::setClassType(MessagesAllStickers::MessagesAllStickersType classType) {
    m_classType = classType;
}

MessagesAllStickers::MessagesAllStickersType MessagesAllStickers::classType() const {
    return m_classType;
}

bool MessagesAllStickers::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeMessagesAllStickersNotModified: {
        return true;
    }
        break;
    
    case typeMessagesAllStickers: {
        m_hash = in->fetchQString();
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_packs_length = in->fetchInt();
        m_packs.clear();
        for (qint32 i = 0; i < m_packs_length; i++) {
            StickerPack type;
            type.fetch(in);
            m_packs.append(type);
        }
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_sets_length = in->fetchInt();
        m_sets.clear();
        for (qint32 i = 0; i < m_sets_length; i++) {
            StickerSet type;
            type.fetch(in);
            m_sets.append(type);
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

bool MessagesAllStickers::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessagesAllStickersNotModified: {
        return true;
    }
        break;
    
    case typeMessagesAllStickers: {
        out->appendQString(m_hash);
        out->appendInt(TL_Vector);
        out->appendInt(m_packs.count());
        for (qint32 i = 0; i < m_packs.count(); i++) {
            m_packs[i].push(out);
        }
        out->appendInt(TL_Vector);
        out->appendInt(m_sets.count());
        for (qint32 i = 0; i < m_sets.count(); i++) {
            m_sets[i].push(out);
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

