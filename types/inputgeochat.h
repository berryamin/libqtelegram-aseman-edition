#ifndef LQTG_INPUTGEOCHAT
#define LQTG_INPUTGEOCHAT

#include "telegramtypeobject.h"
#include <QtGlobal>

class InputGeoChat : public TelegramTypeObject
{
public:
    enum InputGeoChatType {
        typeInputGeoChat = 0x74d456fa
    };

    InputGeoChat(InputGeoChatType classType = typeInputGeoChat, InboundPkt *in = 0);
    InputGeoChat(InboundPkt *in);
    virtual ~InputGeoChat();

    void setAccessHash(qint64 accessHash);
    qint64 accessHash() const;

    void setChatId(qint32 chatId);
    qint32 chatId() const;

    void setClassType(InputGeoChatType classType);
    InputGeoChatType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const InputGeoChat &b);

private:
    qint64 m_accessHash;
    qint32 m_chatId;
    InputGeoChatType m_classType;
};

#endif // LQTG_INPUTGEOCHAT
