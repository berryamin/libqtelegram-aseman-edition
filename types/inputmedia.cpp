#include "inputmedia.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

InputMedia::InputMedia(InputMediaType classType, InboundPkt *in) :
    m_duration(0),
    m_h(0),
    m_w(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

InputMedia::InputMedia(InboundPkt *in) :
    m_duration(0),
    m_h(0),
    m_w(0),
    m_classType(typeInputMediaEmpty)
{
    fetch(in);
}

void InputMedia::setAddress(const QString &address) {
    m_address = address;
}

QString InputMedia::address() const {
    return m_address;
}

void InputMedia::setAttributes(const QList<DocumentAttribute> &attributes) {
    m_attributes = attributes;
}

QList<DocumentAttribute> InputMedia::attributes() const {
    return m_attributes;
}

void InputMedia::setCaption(const QString &caption) {
    m_caption = caption;
}

QString InputMedia::caption() const {
    return m_caption;
}

void InputMedia::setDuration(qint32 duration) {
    m_duration = duration;
}

qint32 InputMedia::duration() const {
    return m_duration;
}

void InputMedia::setFile(const InputFile &file) {
    m_file = file;
}

InputFile InputMedia::file() const {
    return m_file;
}

void InputMedia::setFirstName(const QString &firstName) {
    m_firstName = firstName;
}

QString InputMedia::firstName() const {
    return m_firstName;
}

void InputMedia::setGeoPoint(const InputGeoPoint &geoPoint) {
    m_geoPoint = geoPoint;
}

InputGeoPoint InputMedia::geoPoint() const {
    return m_geoPoint;
}

void InputMedia::setH(qint32 h) {
    m_h = h;
}

qint32 InputMedia::h() const {
    return m_h;
}

void InputMedia::setIdInputAudio(const InputAudio &idInputAudio) {
    m_idInputAudio = idInputAudio;
}

InputAudio InputMedia::idInputAudio() const {
    return m_idInputAudio;
}

void InputMedia::setIdInputDocument(const InputDocument &idInputDocument) {
    m_idInputDocument = idInputDocument;
}

InputDocument InputMedia::idInputDocument() const {
    return m_idInputDocument;
}

void InputMedia::setIdInputPhoto(const InputPhoto &idInputPhoto) {
    m_idInputPhoto = idInputPhoto;
}

InputPhoto InputMedia::idInputPhoto() const {
    return m_idInputPhoto;
}

void InputMedia::setIdInputVideo(const InputVideo &idInputVideo) {
    m_idInputVideo = idInputVideo;
}

InputVideo InputMedia::idInputVideo() const {
    return m_idInputVideo;
}

void InputMedia::setLastName(const QString &lastName) {
    m_lastName = lastName;
}

QString InputMedia::lastName() const {
    return m_lastName;
}

void InputMedia::setMimeType(const QString &mimeType) {
    m_mimeType = mimeType;
}

QString InputMedia::mimeType() const {
    return m_mimeType;
}

void InputMedia::setPhoneNumber(const QString &phoneNumber) {
    m_phoneNumber = phoneNumber;
}

QString InputMedia::phoneNumber() const {
    return m_phoneNumber;
}

void InputMedia::setProvider(const QString &provider) {
    m_provider = provider;
}

QString InputMedia::provider() const {
    return m_provider;
}

void InputMedia::setThumb(const InputFile &thumb) {
    m_thumb = thumb;
}

InputFile InputMedia::thumb() const {
    return m_thumb;
}

void InputMedia::setTitle(const QString &title) {
    m_title = title;
}

QString InputMedia::title() const {
    return m_title;
}

void InputMedia::setVenueId(const QString &venueId) {
    m_venueId = venueId;
}

QString InputMedia::venueId() const {
    return m_venueId;
}

void InputMedia::setW(qint32 w) {
    m_w = w;
}

qint32 InputMedia::w() const {
    return m_w;
}

bool InputMedia::operator ==(const InputMedia &b) {
    return m_address == b.m_address &&
           m_attributes == b.m_attributes &&
           m_caption == b.m_caption &&
           m_duration == b.m_duration &&
           m_file == b.m_file &&
           m_firstName == b.m_firstName &&
           m_geoPoint == b.m_geoPoint &&
           m_h == b.m_h &&
           m_idInputAudio == b.m_idInputAudio &&
           m_idInputDocument == b.m_idInputDocument &&
           m_idInputPhoto == b.m_idInputPhoto &&
           m_idInputVideo == b.m_idInputVideo &&
           m_lastName == b.m_lastName &&
           m_mimeType == b.m_mimeType &&
           m_phoneNumber == b.m_phoneNumber &&
           m_provider == b.m_provider &&
           m_thumb == b.m_thumb &&
           m_title == b.m_title &&
           m_venueId == b.m_venueId &&
           m_w == b.m_w;
}

void InputMedia::setClassType(InputMedia::InputMediaType classType) {
    m_classType = classType;
}

InputMedia::InputMediaType InputMedia::classType() const {
    return m_classType;
}

bool InputMedia::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeInputMediaEmpty: {
        return true;
    }
        break;
    
    case typeInputMediaUploadedPhoto: {
        m_file.fetch(in);
        m_caption = in->fetchQString();
        return true;
    }
        break;
    
    case typeInputMediaPhoto: {
        m_idInputPhoto.fetch(in);
        m_caption = in->fetchQString();
        return true;
    }
        break;
    
    case typeInputMediaGeoPoint: {
        m_geoPoint.fetch(in);
        return true;
    }
        break;
    
    case typeInputMediaContact: {
        m_phoneNumber = in->fetchQString();
        m_firstName = in->fetchQString();
        m_lastName = in->fetchQString();
        return true;
    }
        break;
    
    case typeInputMediaUploadedVideo: {
        m_file.fetch(in);
        m_duration = in->fetchInt();
        m_w = in->fetchInt();
        m_h = in->fetchInt();
        m_caption = in->fetchQString();
        return true;
    }
        break;
    
    case typeInputMediaUploadedThumbVideo: {
        m_file.fetch(in);
        m_thumb.fetch(in);
        m_duration = in->fetchInt();
        m_w = in->fetchInt();
        m_h = in->fetchInt();
        m_caption = in->fetchQString();
        return true;
    }
        break;
    
    case typeInputMediaVideo: {
        m_idInputVideo.fetch(in);
        m_caption = in->fetchQString();
        return true;
    }
        break;
    
    case typeInputMediaUploadedAudio: {
        m_file.fetch(in);
        m_duration = in->fetchInt();
        m_mimeType = in->fetchQString();
        return true;
    }
        break;
    
    case typeInputMediaAudio: {
        m_idInputAudio.fetch(in);
        return true;
    }
        break;
    
    case typeInputMediaUploadedDocument: {
        m_file.fetch(in);
        m_mimeType = in->fetchQString();
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_attributes_length = in->fetchInt();
        m_attributes.clear();
        for (qint32 i = 0; i < m_attributes_length; i++) {
            DocumentAttribute type;
            type.fetch(in);
            m_attributes.append(type);
        }
        return true;
    }
        break;
    
    case typeInputMediaUploadedThumbDocument: {
        m_file.fetch(in);
        m_thumb.fetch(in);
        m_mimeType = in->fetchQString();
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_attributes_length = in->fetchInt();
        m_attributes.clear();
        for (qint32 i = 0; i < m_attributes_length; i++) {
            DocumentAttribute type;
            type.fetch(in);
            m_attributes.append(type);
        }
        return true;
    }
        break;
    
    case typeInputMediaDocument: {
        m_idInputDocument.fetch(in);
        return true;
    }
        break;
    
    case typeInputMediaVenue: {
        m_geoPoint.fetch(in);
        m_title = in->fetchQString();
        m_address = in->fetchQString();
        m_provider = in->fetchQString();
        m_venueId = in->fetchQString();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool InputMedia::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeInputMediaEmpty: {
        return true;
    }
        break;
    
    case typeInputMediaUploadedPhoto: {
        m_file.push(out);
        out->appendQString(m_caption);
        return true;
    }
        break;
    
    case typeInputMediaPhoto: {
        m_idInputPhoto.push(out);
        out->appendQString(m_caption);
        return true;
    }
        break;
    
    case typeInputMediaGeoPoint: {
        m_geoPoint.push(out);
        return true;
    }
        break;
    
    case typeInputMediaContact: {
        out->appendQString(m_phoneNumber);
        out->appendQString(m_firstName);
        out->appendQString(m_lastName);
        return true;
    }
        break;
    
    case typeInputMediaUploadedVideo: {
        m_file.push(out);
        out->appendInt(m_duration);
        out->appendInt(m_w);
        out->appendInt(m_h);
        out->appendQString(m_caption);
        return true;
    }
        break;
    
    case typeInputMediaUploadedThumbVideo: {
        m_file.push(out);
        m_thumb.push(out);
        out->appendInt(m_duration);
        out->appendInt(m_w);
        out->appendInt(m_h);
        out->appendQString(m_caption);
        return true;
    }
        break;
    
    case typeInputMediaVideo: {
        m_idInputVideo.push(out);
        out->appendQString(m_caption);
        return true;
    }
        break;
    
    case typeInputMediaUploadedAudio: {
        m_file.push(out);
        out->appendInt(m_duration);
        out->appendQString(m_mimeType);
        return true;
    }
        break;
    
    case typeInputMediaAudio: {
        m_idInputAudio.push(out);
        return true;
    }
        break;
    
    case typeInputMediaUploadedDocument: {
        m_file.push(out);
        out->appendQString(m_mimeType);
        out->appendInt(TL_Vector);
        out->appendInt(m_attributes.count());
        for (qint32 i = 0; i < m_attributes.count(); i++) {
            m_attributes[i].push(out);
        }
        return true;
    }
        break;
    
    case typeInputMediaUploadedThumbDocument: {
        m_file.push(out);
        m_thumb.push(out);
        out->appendQString(m_mimeType);
        out->appendInt(TL_Vector);
        out->appendInt(m_attributes.count());
        for (qint32 i = 0; i < m_attributes.count(); i++) {
            m_attributes[i].push(out);
        }
        return true;
    }
        break;
    
    case typeInputMediaDocument: {
        m_idInputDocument.push(out);
        return true;
    }
        break;
    
    case typeInputMediaVenue: {
        m_geoPoint.push(out);
        out->appendQString(m_title);
        out->appendQString(m_address);
        out->appendQString(m_provider);
        out->appendQString(m_venueId);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

