#include "wallpaper.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

WallPaper::WallPaper(WallPaperType classType, InboundPkt *in) :
    m_bgColor(0),
    m_color(0),
    m_id(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

WallPaper::WallPaper(InboundPkt *in) :
    m_bgColor(0),
    m_color(0),
    m_id(0),
    m_classType(typeWallPaper)
{
    fetch(in);
}

void WallPaper::setBgColor(qint32 bgColor) {
    m_bgColor = bgColor;
}

qint32 WallPaper::bgColor() const {
    return m_bgColor;
}

void WallPaper::setColor(qint32 color) {
    m_color = color;
}

qint32 WallPaper::color() const {
    return m_color;
}

void WallPaper::setId(qint32 id) {
    m_id = id;
}

qint32 WallPaper::id() const {
    return m_id;
}

void WallPaper::setSizes(const QList<PhotoSize> &sizes) {
    m_sizes = sizes;
}

QList<PhotoSize> WallPaper::sizes() const {
    return m_sizes;
}

void WallPaper::setTitle(const QString &title) {
    m_title = title;
}

QString WallPaper::title() const {
    return m_title;
}

bool WallPaper::operator ==(const WallPaper &b) {
    return m_bgColor == b.m_bgColor &&
           m_color == b.m_color &&
           m_id == b.m_id &&
           m_sizes == b.m_sizes &&
           m_title == b.m_title;
}

void WallPaper::setClassType(WallPaper::WallPaperType classType) {
    m_classType = classType;
}

WallPaper::WallPaperType WallPaper::classType() const {
    return m_classType;
}

bool WallPaper::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeWallPaper: {
        m_id = in->fetchInt();
        m_title = in->fetchQString();
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_sizes_length = in->fetchInt();
        m_sizes.clear();
        for (qint32 i = 0; i < m_sizes_length; i++) {
            PhotoSize type;
            type.fetch(in);
            m_sizes.append(type);
        }
        m_color = in->fetchInt();
        return true;
    }
        break;
    
    case typeWallPaperSolid: {
        m_id = in->fetchInt();
        m_title = in->fetchQString();
        m_bgColor = in->fetchInt();
        m_color = in->fetchInt();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool WallPaper::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeWallPaper: {
        out->appendInt(m_id);
        out->appendQString(m_title);
        out->appendInt(TL_Vector);
        out->appendInt(m_sizes.count());
        for (qint32 i = 0; i < m_sizes.count(); i++) {
            m_sizes[i].push(out);
        }
        out->appendInt(m_color);
        return true;
    }
        break;
    
    case typeWallPaperSolid: {
        out->appendInt(m_id);
        out->appendQString(m_title);
        out->appendInt(m_bgColor);
        out->appendInt(m_color);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

