#ifndef LQTG_INPUTPEER
#define LQTG_INPUTPEER

#include "telegramtypeobject.h"
#include <QtGlobal>

class InputPeer : public TelegramTypeObject
{
public:
    enum InputPeerType {
        typeInputPeerEmpty = 0x7f3b18ea,
        typeInputPeerSelf = 0x7da07ec9,
        typeInputPeerContact = 0x1023dbe8,
        typeInputPeerForeign = 0x9b447325,
        typeInputPeerChat = 0x179be863
    };

    InputPeer(InputPeerType classType = typeInputPeerEmpty, InboundPkt *in = 0);
    InputPeer(InboundPkt *in);
    virtual ~InputPeer();

    void setAccessHash(qint64 accessHash);
    qint64 accessHash() const;

    void setChatId(qint32 chatId);
    qint32 chatId() const;

    void setUserId(qint32 userId);
    qint32 userId() const;

    void setClassType(InputPeerType classType);
    InputPeerType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const InputPeer &b);

private:
    qint64 m_accessHash;
    qint32 m_chatId;
    qint32 m_userId;
    InputPeerType m_classType;
};

#endif // LQTG_INPUTPEER
