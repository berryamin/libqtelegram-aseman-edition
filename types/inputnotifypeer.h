#ifndef LQTG_INPUTNOTIFYPEER
#define LQTG_INPUTNOTIFYPEER

#include "telegramtypeobject.h"
#include "inputgeochat.h"
#include "inputpeer.h"

class InputNotifyPeer : public TelegramTypeObject
{
public:
    enum InputNotifyPeerType {
        typeInputNotifyPeer = 0xb8bc5b0c,
        typeInputNotifyUsers = 0x193b4417,
        typeInputNotifyChats = 0x4a95e84e,
        typeInputNotifyAll = 0xa429b886,
        typeInputNotifyGeoChatPeer = 0x4d8ddec8
    };

    InputNotifyPeer(InputNotifyPeerType classType = typeInputNotifyPeer, InboundPkt *in = 0);
    InputNotifyPeer(InboundPkt *in);
    virtual ~InputNotifyPeer();

    void setPeerInputGeoChat(const InputGeoChat &peerInputGeoChat);
    InputGeoChat peerInputGeoChat() const;

    void setPeerInput(const InputPeer &peerInput);
    InputPeer peerInput() const;

    void setClassType(InputNotifyPeerType classType);
    InputNotifyPeerType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const InputNotifyPeer &b);

private:
    InputGeoChat m_peerInputGeoChat;
    InputPeer m_peerInput;
    InputNotifyPeerType m_classType;
};

#endif // LQTG_INPUTNOTIFYPEER
