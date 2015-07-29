#ifndef LQTG_INPUTPEERNOTIFYSETTINGS
#define LQTG_INPUTPEERNOTIFYSETTINGS

#include "telegramtypeobject.h"
#include <QtGlobal>
#include <QString>

class InputPeerNotifySettings : public TelegramTypeObject
{
public:
    enum InputPeerNotifySettingsType {
        typeInputPeerNotifySettings = 0x46a2ce98
    };

    InputPeerNotifySettings(InputPeerNotifySettingsType classType = typeInputPeerNotifySettings, InboundPkt *in = 0);
    InputPeerNotifySettings(InboundPkt *in);
    virtual ~InputPeerNotifySettings();

    void setEventsMask(qint32 eventsMask);
    qint32 eventsMask() const;

    void setMuteUntil(qint32 muteUntil);
    qint32 muteUntil() const;

    void setShowPreviews(bool showPreviews);
    bool showPreviews() const;

    void setSound(const QString &sound);
    QString sound() const;

    void setClassType(InputPeerNotifySettingsType classType);
    InputPeerNotifySettingsType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const InputPeerNotifySettings &b);

private:
    qint32 m_eventsMask;
    qint32 m_muteUntil;
    bool m_showPreviews;
    QString m_sound;
    InputPeerNotifySettingsType m_classType;
};

#endif // LQTG_INPUTPEERNOTIFYSETTINGS
