#ifndef LQTG_ENCRYPTEDCHAT
#define LQTG_ENCRYPTEDCHAT

#include "telegramtypeobject.h"
#include <QtGlobal>
#include <QByteArray>

class EncryptedChat : public TelegramTypeObject
{
public:
    enum EncryptedChatType {
        typeEncryptedChatEmpty = 0xab7ec0a0,
        typeEncryptedChatWaiting = 0x3bf703dc,
        typeEncryptedChatRequested = 0xc878527e,
        typeEncryptedChat = 0xfa56ce36,
        typeEncryptedChatDiscarded = 0x13d6dd27
    };

    EncryptedChat(EncryptedChatType classType = typeEncryptedChatEmpty, InboundPkt *in = 0);
    EncryptedChat(InboundPkt *in);
    virtual ~EncryptedChat();

    void setAccessHash(qint64 accessHash);
    qint64 accessHash() const;

    void setAdminId(qint32 adminId);
    qint32 adminId() const;

    void setDate(qint32 date);
    qint32 date() const;

    void setGA(const QByteArray &gA);
    QByteArray gA() const;

    void setGAOrB(const QByteArray &gAOrB);
    QByteArray gAOrB() const;

    void setId(qint32 id);
    qint32 id() const;

    void setKeyFingerprint(qint64 keyFingerprint);
    qint64 keyFingerprint() const;

    void setParticipantId(qint32 participantId);
    qint32 participantId() const;

    void setClassType(EncryptedChatType classType);
    EncryptedChatType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const EncryptedChat &b);

private:
    qint64 m_accessHash;
    qint32 m_adminId;
    qint32 m_date;
    QByteArray m_gA;
    QByteArray m_gAOrB;
    qint32 m_id;
    qint64 m_keyFingerprint;
    qint32 m_participantId;
    EncryptedChatType m_classType;
};

#endif // LQTG_ENCRYPTEDCHAT
