#ifndef LQTG_PEERNOTIFYSETTINGS
#define LQTG_PEERNOTIFYSETTINGS

#include "telegramtypeobject.h"
#include <QtGlobal>
#include <QString>

class PeerNotifySettings : public TelegramTypeObject
{
public:
    enum PeerNotifySettingsType {
        typePeerNotifySettingsEmpty = 0x70a68512,
        typePeerNotifySettings = 0x8d5e11ee
    };

    PeerNotifySettings(PeerNotifySettingsType classType = typePeerNotifySettingsEmpty, InboundPkt *in = 0);
    PeerNotifySettings(InboundPkt *in);
    virtual ~PeerNotifySettings();

    void setEventsMask(qint32 eventsMask);
    qint32 eventsMask() const;

    void setMuteUntil(qint32 muteUntil);
    qint32 muteUntil() const;

    void setShowPreviews(bool showPreviews);
    bool showPreviews() const;

    void setSound(const QString &sound);
    QString sound() const;

    void setClassType(PeerNotifySettingsType classType);
    PeerNotifySettingsType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const PeerNotifySettings &b);

private:
    qint32 m_eventsMask;
    qint32 m_muteUntil;
    bool m_showPreviews;
    QString m_sound;
    PeerNotifySettingsType m_classType;
};

#endif // LQTG_PEERNOTIFYSETTINGS
