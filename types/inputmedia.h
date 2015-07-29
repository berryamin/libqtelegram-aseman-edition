#ifndef LQTG_INPUTMEDIA
#define LQTG_INPUTMEDIA

#include "telegramtypeobject.h"
#include <QString>
#include <QList>
#include "documentattribute.h"
#include <QtGlobal>
#include "inputfile.h"
#include "inputgeopoint.h"
#include "inputaudio.h"
#include "inputdocument.h"
#include "inputphoto.h"
#include "inputvideo.h"

class InputMedia : public TelegramTypeObject
{
public:
    enum InputMediaType {
        typeInputMediaEmpty = 0x9664f57f,
        typeInputMediaUploadedPhoto = 0xf7aff1c0,
        typeInputMediaPhoto = 0xe9bfb4f3,
        typeInputMediaGeoPoint = 0xf9c44144,
        typeInputMediaContact = 0xa6e45987,
        typeInputMediaUploadedVideo = 0xe13fd4bc,
        typeInputMediaUploadedThumbVideo = 0x96fb97dc,
        typeInputMediaVideo = 0x936a4ebd,
        typeInputMediaUploadedAudio = 0x4e498cab,
        typeInputMediaAudio = 0x89938781,
        typeInputMediaUploadedDocument = 0xffe76b78,
        typeInputMediaUploadedThumbDocument = 0x41481486,
        typeInputMediaDocument = 0xd184e841,
        typeInputMediaVenue = 0x2827a81a
    };

    InputMedia(InputMediaType classType = typeInputMediaEmpty, InboundPkt *in = 0);
    InputMedia(InboundPkt *in);
    virtual ~InputMedia();

    void setAddress(const QString &address);
    QString address() const;

    void setAttributes(const QList<DocumentAttribute> &attributes);
    QList<DocumentAttribute> attributes() const;

    void setCaption(const QString &caption);
    QString caption() const;

    void setDuration(qint32 duration);
    qint32 duration() const;

    void setFile(const InputFile &file);
    InputFile file() const;

    void setFirstName(const QString &firstName);
    QString firstName() const;

    void setGeoPoint(const InputGeoPoint &geoPoint);
    InputGeoPoint geoPoint() const;

    void setH(qint32 h);
    qint32 h() const;

    void setIdInputAudio(const InputAudio &idInputAudio);
    InputAudio idInputAudio() const;

    void setIdInputDocument(const InputDocument &idInputDocument);
    InputDocument idInputDocument() const;

    void setIdInputPhoto(const InputPhoto &idInputPhoto);
    InputPhoto idInputPhoto() const;

    void setIdInputVideo(const InputVideo &idInputVideo);
    InputVideo idInputVideo() const;

    void setLastName(const QString &lastName);
    QString lastName() const;

    void setMimeType(const QString &mimeType);
    QString mimeType() const;

    void setPhoneNumber(const QString &phoneNumber);
    QString phoneNumber() const;

    void setProvider(const QString &provider);
    QString provider() const;

    void setThumb(const InputFile &thumb);
    InputFile thumb() const;

    void setTitle(const QString &title);
    QString title() const;

    void setVenueId(const QString &venueId);
    QString venueId() const;

    void setW(qint32 w);
    qint32 w() const;

    void setClassType(InputMediaType classType);
    InputMediaType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const InputMedia &b);

private:
    QString m_address;
    QList<DocumentAttribute> m_attributes;
    QString m_caption;
    qint32 m_duration;
    InputFile m_file;
    QString m_firstName;
    InputGeoPoint m_geoPoint;
    qint32 m_h;
    InputAudio m_idInputAudio;
    InputDocument m_idInputDocument;
    InputPhoto m_idInputPhoto;
    InputVideo m_idInputVideo;
    QString m_lastName;
    QString m_mimeType;
    QString m_phoneNumber;
    QString m_provider;
    InputFile m_thumb;
    QString m_title;
    QString m_venueId;
    qint32 m_w;
    InputMediaType m_classType;
};

#endif // LQTG_INPUTMEDIA
