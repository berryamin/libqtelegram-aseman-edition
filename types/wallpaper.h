#ifndef LQTG_WALLPAPER
#define LQTG_WALLPAPER

#include "telegramtypeobject.h"
#include <QtGlobal>
#include <QList>
#include "photosize.h"
#include <QString>

class WallPaper : public TelegramTypeObject
{
public:
    enum WallPaperType {
        typeWallPaper = 0xccb03657,
        typeWallPaperSolid = 0x63117f24
    };

    WallPaper(WallPaperType classType = typeWallPaper, InboundPkt *in = 0);
    WallPaper(InboundPkt *in);
    virtual ~WallPaper();

    void setBgColor(qint32 bgColor);
    qint32 bgColor() const;

    void setColor(qint32 color);
    qint32 color() const;

    void setId(qint32 id);
    qint32 id() const;

    void setSizes(const QList<PhotoSize> &sizes);
    QList<PhotoSize> sizes() const;

    void setTitle(const QString &title);
    QString title() const;

    void setClassType(WallPaperType classType);
    WallPaperType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const WallPaper &b);

private:
    qint32 m_bgColor;
    qint32 m_color;
    qint32 m_id;
    QList<PhotoSize> m_sizes;
    QString m_title;
    WallPaperType m_classType;
};

#endif // LQTG_WALLPAPER
