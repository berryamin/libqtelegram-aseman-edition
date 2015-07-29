#ifndef LQTG_PHOTOSPHOTOS
#define LQTG_PHOTOSPHOTOS

#include "telegramtypeobject.h"
#include <QtGlobal>
#include <QList>
#include "photo.h"
#include "user.h"

class PhotosPhotos : public TelegramTypeObject
{
public:
    enum PhotosPhotosType {
        typePhotosPhotos = 0x8dca6aa5,
        typePhotosPhotosSlice = 0x15051f54
    };

    PhotosPhotos(PhotosPhotosType classType = typePhotosPhotos, InboundPkt *in = 0);
    PhotosPhotos(InboundPkt *in);
    virtual ~PhotosPhotos();

    void setCount(qint32 count);
    qint32 count() const;

    void setPhotos(const QList<Photo> &photos);
    QList<Photo> photos() const;

    void setUsers(const QList<User> &users);
    QList<User> users() const;

    void setClassType(PhotosPhotosType classType);
    PhotosPhotosType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const PhotosPhotos &b);

private:
    qint32 m_count;
    QList<Photo> m_photos;
    QList<User> m_users;
    PhotosPhotosType m_classType;
};

#endif // LQTG_PHOTOSPHOTOS
