#ifndef LQTG_AUDIO
#define LQTG_AUDIO

#include "telegramtypeobject.h"
#include <QtGlobal>
#include <QString>

class Audio : public TelegramTypeObject
{
public:
    enum AudioType {
        typeAudioEmpty = 0x586988d8,
        typeAudio = 0xc7ac6496
    };

    Audio(AudioType classType = typeAudioEmpty, InboundPkt *in = 0);
    Audio(InboundPkt *in);
    virtual ~Audio();

    void setAccessHash(qint64 accessHash);
    qint64 accessHash() const;

    void setDate(qint32 date);
    qint32 date() const;

    void setDcId(qint32 dcId);
    qint32 dcId() const;

    void setDuration(qint32 duration);
    qint32 duration() const;

    void setId(qint64 id);
    qint64 id() const;

    void setMimeType(const QString &mimeType);
    QString mimeType() const;

    void setSize(qint32 size);
    qint32 size() const;

    void setUserId(qint32 userId);
    qint32 userId() const;

    void setClassType(AudioType classType);
    AudioType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const Audio &b);

private:
    qint64 m_accessHash;
    qint32 m_date;
    qint32 m_dcId;
    qint32 m_duration;
    qint64 m_id;
    QString m_mimeType;
    qint32 m_size;
    qint32 m_userId;
    AudioType m_classType;
};

#endif // LQTG_AUDIO
