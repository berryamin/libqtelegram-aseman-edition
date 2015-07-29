#include "inputpeernotifysettings.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

InputPeerNotifySettings::InputPeerNotifySettings(InputPeerNotifySettingsType classType, InboundPkt *in) :
    m_eventsMask(0),
    m_muteUntil(0),
    m_showPreviews(false),
    m_classType(classType)
{
    if(in) fetch(in);
}

InputPeerNotifySettings::InputPeerNotifySettings(InboundPkt *in) :
    m_eventsMask(0),
    m_muteUntil(0),
    m_showPreviews(false),
    m_classType(typeInputPeerNotifySettings)
{
    fetch(in);
}

void InputPeerNotifySettings::setEventsMask(qint32 eventsMask) {
    m_eventsMask = eventsMask;
}

qint32 InputPeerNotifySettings::eventsMask() const {
    return m_eventsMask;
}

void InputPeerNotifySettings::setMuteUntil(qint32 muteUntil) {
    m_muteUntil = muteUntil;
}

qint32 InputPeerNotifySettings::muteUntil() const {
    return m_muteUntil;
}

void InputPeerNotifySettings::setShowPreviews(bool showPreviews) {
    m_showPreviews = showPreviews;
}

bool InputPeerNotifySettings::showPreviews() const {
    return m_showPreviews;
}

void InputPeerNotifySettings::setSound(const QString &sound) {
    m_sound = sound;
}

QString InputPeerNotifySettings::sound() const {
    return m_sound;
}

bool InputPeerNotifySettings::operator ==(const InputPeerNotifySettings &b) {
    return m_eventsMask == b.m_eventsMask &&
           m_muteUntil == b.m_muteUntil &&
           m_showPreviews == b.m_showPreviews &&
           m_sound == b.m_sound;
}

void InputPeerNotifySettings::setClassType(InputPeerNotifySettings::InputPeerNotifySettingsType classType) {
    m_classType = classType;
}

InputPeerNotifySettings::InputPeerNotifySettingsType InputPeerNotifySettings::classType() const {
    return m_classType;
}

bool InputPeerNotifySettings::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeInputPeerNotifySettings: {
        m_muteUntil = in->fetchInt();
        m_sound = in->fetchQString();
        m_showPreviews = in->fetchBool();
        m_eventsMask = in->fetchInt();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool InputPeerNotifySettings::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeInputPeerNotifySettings: {
        out->appendInt(m_muteUntil);
        out->appendQString(m_sound);
        out->appendBool(m_showPreviews);
        out->appendInt(m_eventsMask);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

