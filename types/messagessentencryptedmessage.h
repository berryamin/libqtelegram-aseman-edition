#ifndef LQTG_MESSAGESSENTENCRYPTEDMESSAGE
#define LQTG_MESSAGESSENTENCRYPTEDMESSAGE

#include "telegramtypeobject.h"
#include <QtGlobal>
#include "encryptedfile.h"

class MessagesSentEncryptedMessage : public TelegramTypeObject
{
public:
    enum MessagesSentEncryptedMessageType {
        typeMessagesSentEncryptedMessage = 0x560f8935,
        typeMessagesSentEncryptedFile = 0x9493ff32
    };

    MessagesSentEncryptedMessage(MessagesSentEncryptedMessageType classType = typeMessagesSentEncryptedMessage, InboundPkt *in = 0);
    MessagesSentEncryptedMessage(InboundPkt *in);
    virtual ~MessagesSentEncryptedMessage();

    void setDate(qint32 date);
    qint32 date() const;

    void setFile(const EncryptedFile &file);
    EncryptedFile file() const;

    void setClassType(MessagesSentEncryptedMessageType classType);
    MessagesSentEncryptedMessageType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const MessagesSentEncryptedMessage &b);

private:
    qint32 m_date;
    EncryptedFile m_file;
    MessagesSentEncryptedMessageType m_classType;
};

#endif // LQTG_MESSAGESSENTENCRYPTEDMESSAGE
