#ifndef LQTG_MESSAGEMEDIA
#define LQTG_MESSAGEMEDIA

#include "telegramtypeobject.h"
#include <QString>
#include "audio.h"
#include "document.h"
#include "geopoint.h"
#include "photo.h"
#include <QtGlobal>
#include "video.h"
#include "webpage.h"

class MessageMedia : public TelegramTypeObject
{
public:
    enum MessageMediaType {
        typeMessageMediaEmpty = 0x3ded6320,
        typeMessageMediaPhoto = 0x3d8ce53d,
        typeMessageMediaVideo = 0x5bcf1675,
        typeMessageMediaGeo = 0x56e0d474,
        typeMessageMediaContact = 0x5e7d2f39,
        typeMessageMediaUnsupported = 0x9f84f49e,
        typeMessageMediaDocument = 0x2fda2204,
        typeMessageMediaAudio = 0xc6b68300,
        typeMessageMediaWebPage = 0xa32dd600,
        typeMessageMediaVenue = 0x7912b71f
    };

    MessageMedia(MessageMediaType classType = typeMessageMediaEmpty, InboundPkt *in = 0);
    MessageMedia(InboundPkt *in);
    virtual ~MessageMedia();

    void setAddress(const QString &address);
    QString address() const;

    void setAudio(const Audio &audio);
    Audio audio() const;

    void setCaption(const QString &caption);
    QString caption() const;

    void setDocument(const Document &document);
    Document document() const;

    void setFirstName(const QString &firstName);
    QString firstName() const;

    void setGeo(const GeoPoint &geo);
    GeoPoint geo() const;

    void setLastName(const QString &lastName);
    QString lastName() const;

    void setPhoneNumber(const QString &phoneNumber);
    QString phoneNumber() const;

    void setPhoto(const Photo &photo);
    Photo photo() const;

    void setProvider(const QString &provider);
    QString provider() const;

    void setTitle(const QString &title);
    QString title() const;

    void setUserId(qint32 userId);
    qint32 userId() const;

    void setVenueId(const QString &venueId);
    QString venueId() const;

    void setVideo(const Video &video);
    Video video() const;

    void setWebpage(const WebPage &webpage);
    WebPage webpage() const;

    void setClassType(MessageMediaType classType);
    MessageMediaType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const MessageMedia &b);

private:
    QString m_address;
    Audio m_audio;
    QString m_caption;
    Document m_document;
    QString m_firstName;
    GeoPoint m_geo;
    QString m_lastName;
    QString m_phoneNumber;
    Photo m_photo;
    QString m_provider;
    QString m_title;
    qint32 m_userId;
    QString m_venueId;
    Video m_video;
    WebPage m_webpage;
    MessageMediaType m_classType;
};

#endif // LQTG_MESSAGEMEDIA
