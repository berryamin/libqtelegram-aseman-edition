#ifndef LQTG_USERPROFILEPHOTO
#define LQTG_USERPROFILEPHOTO

#include "telegramtypeobject.h"
#include "filelocation.h"
#include <QtGlobal>

class UserProfilePhoto : public TelegramTypeObject
{
public:
    enum UserProfilePhotoType {
        typeUserProfilePhotoEmpty = 0x4f11bae1,
        typeUserProfilePhoto = 0xd559d8c8
    };

    UserProfilePhoto(UserProfilePhotoType classType = typeUserProfilePhotoEmpty, InboundPkt *in = 0);
    UserProfilePhoto(InboundPkt *in);
    virtual ~UserProfilePhoto();

    void setPhotoBig(const FileLocation &photoBig);
    FileLocation photoBig() const;

    void setPhotoId(qint64 photoId);
    qint64 photoId() const;

    void setPhotoSmall(const FileLocation &photoSmall);
    FileLocation photoSmall() const;

    void setClassType(UserProfilePhotoType classType);
    UserProfilePhotoType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const UserProfilePhoto &b);

private:
    FileLocation m_photoBig;
    qint64 m_photoId;
    FileLocation m_photoSmall;
    UserProfilePhotoType m_classType;
};

#endif // LQTG_USERPROFILEPHOTO
