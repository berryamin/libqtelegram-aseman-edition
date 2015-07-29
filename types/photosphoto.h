#ifndef LQTG_PHOTOSPHOTO
#define LQTG_PHOTOSPHOTO

#include "telegramtypeobject.h"
#include "photo.h"
#include <QList>
#include "user.h"

class PhotosPhoto : public TelegramTypeObject
{
public:
    enum PhotosPhotoType {
        typePhotosPhoto = 0x20212ca8
    };

    PhotosPhoto(PhotosPhotoType classType = typePhotosPhoto, InboundPkt *in = 0);
    PhotosPhoto(InboundPkt *in);
    virtual ~PhotosPhoto();

    void setPhoto(const Photo &photo);
    Photo photo() const;

    void setUsers(const QList<User> &users);
    QList<User> users() const;

    void setClassType(PhotosPhotoType classType);
    PhotosPhotoType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const PhotosPhoto &b);

private:
    Photo m_photo;
    QList<User> m_users;
    PhotosPhotoType m_classType;
};

#endif // LQTG_PHOTOSPHOTO
