#ifndef LQTG_PHOTOSIZE
#define LQTG_PHOTOSIZE

#include "telegramtypeobject.h"
#include <QByteArray>
#include <QtGlobal>
#include "filelocation.h"
#include <QString>

class PhotoSize : public TelegramTypeObject
{
public:
    enum PhotoSizeType {
        typePhotoSizeEmpty = 0xe17e23c,
        typePhotoSize = 0x77bfb61b,
        typePhotoCachedSize = 0xe9a734fa
    };

    PhotoSize(PhotoSizeType classType = typePhotoSizeEmpty, InboundPkt *in = 0);
    PhotoSize(InboundPkt *in);
    virtual ~PhotoSize();

    void setBytes(const QByteArray &bytes);
    QByteArray bytes() const;

    void setH(qint32 h);
    qint32 h() const;

    void setLocation(const FileLocation &location);
    FileLocation location() const;

    void setSize(qint32 size);
    qint32 size() const;

    void setType(const QString &type);
    QString type() const;

    void setW(qint32 w);
    qint32 w() const;

    void setClassType(PhotoSizeType classType);
    PhotoSizeType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const PhotoSize &b);

private:
    QByteArray m_bytes;
    qint32 m_h;
    FileLocation m_location;
    qint32 m_size;
    QString m_type;
    qint32 m_w;
    PhotoSizeType m_classType;
};

#endif // LQTG_PHOTOSIZE
