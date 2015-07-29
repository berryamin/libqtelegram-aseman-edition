#ifndef LQTG_UPDATE
#define LQTG_UPDATE

#include "telegramtypeobject.h"
#include "sendmessageaction.h"
#include <QtGlobal>
#include "encryptedchat.h"
#include <QList>
#include "dcoption.h"
#include <QString>
#include "contactlink.h"
#include "privacykey.h"
#include "messagemedia.h"
#include "encryptedmessage.h"
#include "geochatmessage.h"
#include "message.h"
#include "peernotifysettings.h"
#include "chatparticipants.h"
#include "notifypeer.h"
#include "peer.h"
#include "userprofilephoto.h"
#include "privacyrule.h"
#include "userstatus.h"
#include "webpage.h"

class Update : public TelegramTypeObject
{
public:
    enum UpdateType {
        typeUpdateNewMessage = 0x1f2b0afd,
        typeUpdateMessageID = 0x4e90bfd6,
        typeUpdateDeleteMessages = 0xa20db0e5,
        typeUpdateUserTyping = 0x5c486927,
        typeUpdateChatUserTyping = 0x9a65ea1f,
        typeUpdateChatParticipants = 0x7761198,
        typeUpdateUserStatus = 0x1bfbd823,
        typeUpdateUserName = 0xa7332b73,
        typeUpdateUserPhoto = 0x95313b0c,
        typeUpdateContactRegistered = 0x2575bbb9,
        typeUpdateContactLink = 0x9d2e67c5,
        typeUpdateNewAuthorization = 0x8f06529a,
        typeUpdateNewGeoChatMessage = 0x5a68e3f7,
        typeUpdateNewEncryptedMessage = 0x12bcbd9a,
        typeUpdateEncryptedChatTyping = 0x1710f156,
        typeUpdateEncryption = 0xb4a2e88d,
        typeUpdateEncryptedMessagesRead = 0x38fe25b7,
        typeUpdateChatParticipantAdd = 0x3a0eeb22,
        typeUpdateChatParticipantDelete = 0x6e5f8c22,
        typeUpdateDcOptions = 0x8e5e9873,
        typeUpdateUserBlocked = 0x80ece81a,
        typeUpdateNotifySettings = 0xbec268ef,
        typeUpdateServiceNotification = 0x382dd3e4,
        typeUpdatePrivacy = 0xee3b272a,
        typeUpdateUserPhone = 0x12b9417b,
        typeUpdateReadHistoryInbox = 0x9961fd5c,
        typeUpdateReadHistoryOutbox = 0x2f2f21bf,
        typeUpdateWebPage = 0x2cc36971,
        typeUpdateReadMessagesContents = 0x68c13933
    };

    Update(UpdateType classType = typeUpdateNewMessage, InboundPkt *in = 0);
    Update(InboundPkt *in);
    virtual ~Update();

    void setAction(const SendMessageAction &action);
    SendMessageAction action() const;

    void setAuthKeyId(qint64 authKeyId);
    qint64 authKeyId() const;

    void setBlocked(bool blocked);
    bool blocked() const;

    void setChat(const EncryptedChat &chat);
    EncryptedChat chat() const;

    void setChatId(qint32 chatId);
    qint32 chatId() const;

    void setDate(qint32 date);
    qint32 date() const;

    void setDcOptions(const QList<DcOption> &dcOptions);
    QList<DcOption> dcOptions() const;

    void setDevice(const QString &device);
    QString device() const;

    void setFirstName(const QString &firstName);
    QString firstName() const;

    void setForeignLink(const ContactLink &foreignLink);
    ContactLink foreignLink() const;

    void setId(qint32 id);
    qint32 id() const;

    void setInviterId(qint32 inviterId);
    qint32 inviterId() const;

    void setKey(const PrivacyKey &key);
    PrivacyKey key() const;

    void setLastName(const QString &lastName);
    QString lastName() const;

    void setLocation(const QString &location);
    QString location() const;

    void setMaxDate(qint32 maxDate);
    qint32 maxDate() const;

    void setMaxId(qint32 maxId);
    qint32 maxId() const;

    void setMedia(const MessageMedia &media);
    MessageMedia media() const;

    void setMessageEncrypted(const EncryptedMessage &messageEncrypted);
    EncryptedMessage messageEncrypted() const;

    void setMessageGeoChat(const GeoChatMessage &messageGeoChat);
    GeoChatMessage messageGeoChat() const;

    void setMessage(const Message &message);
    Message message() const;

    void setMessageString(const QString &messageString);
    QString messageString() const;

    void setMessages(const QList<qint32> &messages);
    QList<qint32> messages() const;

    void setMyLink(const ContactLink &myLink);
    ContactLink myLink() const;

    void setNotifySettings(const PeerNotifySettings &notifySettings);
    PeerNotifySettings notifySettings() const;

    void setParticipants(const ChatParticipants &participants);
    ChatParticipants participants() const;

    void setPeerNotify(const NotifyPeer &peerNotify);
    NotifyPeer peerNotify() const;

    void setPeer(const Peer &peer);
    Peer peer() const;

    void setPhone(const QString &phone);
    QString phone() const;

    void setPhoto(const UserProfilePhoto &photo);
    UserProfilePhoto photo() const;

    void setPopup(bool popup);
    bool popup() const;

    void setPrevious(bool previous);
    bool previous() const;

    void setPts(qint32 pts);
    qint32 pts() const;

    void setPtsCount(qint32 ptsCount);
    qint32 ptsCount() const;

    void setQts(qint32 qts);
    qint32 qts() const;

    void setRandomId(qint64 randomId);
    qint64 randomId() const;

    void setRules(const QList<PrivacyRule> &rules);
    QList<PrivacyRule> rules() const;

    void setStatus(const UserStatus &status);
    UserStatus status() const;

    void setType(const QString &type);
    QString type() const;

    void setUserId(qint32 userId);
    qint32 userId() const;

    void setUsername(const QString &username);
    QString username() const;

    void setVersion(qint32 version);
    qint32 version() const;

    void setWebpage(const WebPage &webpage);
    WebPage webpage() const;

    void setClassType(UpdateType classType);
    UpdateType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const Update &b);

private:
    SendMessageAction m_action;
    qint64 m_authKeyId;
    bool m_blocked;
    EncryptedChat m_chat;
    qint32 m_chatId;
    qint32 m_date;
    QList<DcOption> m_dcOptions;
    QString m_device;
    QString m_firstName;
    ContactLink m_foreignLink;
    qint32 m_id;
    qint32 m_inviterId;
    PrivacyKey m_key;
    QString m_lastName;
    QString m_location;
    qint32 m_maxDate;
    qint32 m_maxId;
    MessageMedia m_media;
    EncryptedMessage m_messageEncrypted;
    GeoChatMessage m_messageGeoChat;
    Message m_message;
    QString m_messageString;
    QList<qint32> m_messages;
    ContactLink m_myLink;
    PeerNotifySettings m_notifySettings;
    ChatParticipants m_participants;
    NotifyPeer m_peerNotify;
    Peer m_peer;
    QString m_phone;
    UserProfilePhoto m_photo;
    bool m_popup;
    bool m_previous;
    qint32 m_pts;
    qint32 m_ptsCount;
    qint32 m_qts;
    qint64 m_randomId;
    QList<PrivacyRule> m_rules;
    UserStatus m_status;
    QString m_type;
    qint32 m_userId;
    QString m_username;
    qint32 m_version;
    WebPage m_webpage;
    UpdateType m_classType;
};

#endif // LQTG_UPDATE
