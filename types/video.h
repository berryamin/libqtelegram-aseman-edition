#ifndef LQTG_VIDEO
#define LQTG_VIDEO

#include "telegramtypeobject.h"
#include <QtGlobal>
#include "photosize.h"

class Video : public TelegramTypeObject
{
public:
    enum VideoType {
        typeVideoEmpty = 0xc10658a8,
        typeVideo = 0xee9f4a4d
    };

    Video(VideoType classType = typeVideoEmpty, InboundPkt *in = 0);
    Video(InboundPkt *in);
    virtual ~Video();

    void setAccessHash(qint64 accessHash);
    qint64 accessHash() const;

    void setDate(qint32 date);
    qint32 date() const;

    void setDcId(qint32 dcId);
    qint32 dcId() const;

    void setDuration(qint32 duration);
    qint32 duration() const;

    void setH(qint32 h);
    qint32 h() const;

    void setId(qint64 id);
    qint64 id() const;

    void setSize(qint32 size);
    qint32 size() const;

    void setThumb(const PhotoSize &thumb);
    PhotoSize thumb() const;

    void setUserId(qint32 userId);
    qint32 userId() const;

    void setW(qint32 w);
    qint32 w() const;

    void setClassType(VideoType classType);
    VideoType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const Video &b);

private:
    qint64 m_accessHash;
    qint32 m_date;
    qint32 m_dcId;
    qint32 m_duration;
    qint32 m_h;
    qint64 m_id;
    qint32 m_size;
    PhotoSize m_thumb;
    qint32 m_userId;
    qint32 m_w;
    VideoType m_classType;
};

#endif // LQTG_VIDEO
