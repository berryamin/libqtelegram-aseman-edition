#include "update.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"

Update::Update(UpdateType classType, InboundPkt *in) :
    m_authKeyId(0),
    m_blocked(false),
    m_chatId(0),
    m_date(0),
    m_id(0),
    m_inviterId(0),
    m_maxDate(0),
    m_maxId(0),
    m_popup(false),
    m_previous(false),
    m_pts(0),
    m_ptsCount(0),
    m_qts(0),
    m_randomId(0),
    m_userId(0),
    m_version(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

Update::Update(InboundPkt *in) :
    m_authKeyId(0),
    m_blocked(false),
    m_chatId(0),
    m_date(0),
    m_id(0),
    m_inviterId(0),
    m_maxDate(0),
    m_maxId(0),
    m_popup(false),
    m_previous(false),
    m_pts(0),
    m_ptsCount(0),
    m_qts(0),
    m_randomId(0),
    m_userId(0),
    m_version(0),
    m_classType(typeUpdateNewMessage)
{
    fetch(in);
}

void Update::setAction(const SendMessageAction &action) {
    m_action = action;
}

SendMessageAction Update::action() const {
    return m_action;
}

void Update::setAuthKeyId(qint64 authKeyId) {
    m_authKeyId = authKeyId;
}

qint64 Update::authKeyId() const {
    return m_authKeyId;
}

void Update::setBlocked(bool blocked) {
    m_blocked = blocked;
}

bool Update::blocked() const {
    return m_blocked;
}

void Update::setChat(const EncryptedChat &chat) {
    m_chat = chat;
}

EncryptedChat Update::chat() const {
    return m_chat;
}

void Update::setChatId(qint32 chatId) {
    m_chatId = chatId;
}

qint32 Update::chatId() const {
    return m_chatId;
}

void Update::setDate(qint32 date) {
    m_date = date;
}

qint32 Update::date() const {
    return m_date;
}

void Update::setDcOptions(const QList<DcOption> &dcOptions) {
    m_dcOptions = dcOptions;
}

QList<DcOption> Update::dcOptions() const {
    return m_dcOptions;
}

void Update::setDevice(const QString &device) {
    m_device = device;
}

QString Update::device() const {
    return m_device;
}

void Update::setFirstName(const QString &firstName) {
    m_firstName = firstName;
}

QString Update::firstName() const {
    return m_firstName;
}

void Update::setForeignLink(const ContactLink &foreignLink) {
    m_foreignLink = foreignLink;
}

ContactLink Update::foreignLink() const {
    return m_foreignLink;
}

void Update::setId(qint32 id) {
    m_id = id;
}

qint32 Update::id() const {
    return m_id;
}

void Update::setInviterId(qint32 inviterId) {
    m_inviterId = inviterId;
}

qint32 Update::inviterId() const {
    return m_inviterId;
}

void Update::setKey(const PrivacyKey &key) {
    m_key = key;
}

PrivacyKey Update::key() const {
    return m_key;
}

void Update::setLastName(const QString &lastName) {
    m_lastName = lastName;
}

QString Update::lastName() const {
    return m_lastName;
}

void Update::setLocation(const QString &location) {
    m_location = location;
}

QString Update::location() const {
    return m_location;
}

void Update::setMaxDate(qint32 maxDate) {
    m_maxDate = maxDate;
}

qint32 Update::maxDate() const {
    return m_maxDate;
}

void Update::setMaxId(qint32 maxId) {
    m_maxId = maxId;
}

qint32 Update::maxId() const {
    return m_maxId;
}

void Update::setMedia(const MessageMedia &media) {
    m_media = media;
}

MessageMedia Update::media() const {
    return m_media;
}

void Update::setMessageEncrypted(const EncryptedMessage &messageEncrypted) {
    m_messageEncrypted = messageEncrypted;
}

EncryptedMessage Update::messageEncrypted() const {
    return m_messageEncrypted;
}

void Update::setMessageGeoChat(const GeoChatMessage &messageGeoChat) {
    m_messageGeoChat = messageGeoChat;
}

GeoChatMessage Update::messageGeoChat() const {
    return m_messageGeoChat;
}

void Update::setMessage(const Message &message) {
    m_message = message;
}

Message Update::message() const {
    return m_message;
}

void Update::setMessageString(const QString &messageString) {
    m_messageString = messageString;
}

QString Update::messageString() const {
    return m_messageString;
}

void Update::setMessages(const QList<qint32> &messages) {
    m_messages = messages;
}

QList<qint32> Update::messages() const {
    return m_messages;
}

void Update::setMyLink(const ContactLink &myLink) {
    m_myLink = myLink;
}

ContactLink Update::myLink() const {
    return m_myLink;
}

void Update::setNotifySettings(const PeerNotifySettings &notifySettings) {
    m_notifySettings = notifySettings;
}

PeerNotifySettings Update::notifySettings() const {
    return m_notifySettings;
}

void Update::setParticipants(const ChatParticipants &participants) {
    m_participants = participants;
}

ChatParticipants Update::participants() const {
    return m_participants;
}

void Update::setPeerNotify(const NotifyPeer &peerNotify) {
    m_peerNotify = peerNotify;
}

NotifyPeer Update::peerNotify() const {
    return m_peerNotify;
}

void Update::setPeer(const Peer &peer) {
    m_peer = peer;
}

Peer Update::peer() const {
    return m_peer;
}

void Update::setPhone(const QString &phone) {
    m_phone = phone;
}

QString Update::phone() const {
    return m_phone;
}

void Update::setPhoto(const UserProfilePhoto &photo) {
    m_photo = photo;
}

UserProfilePhoto Update::photo() const {
    return m_photo;
}

void Update::setPopup(bool popup) {
    m_popup = popup;
}

bool Update::popup() const {
    return m_popup;
}

void Update::setPrevious(bool previous) {
    m_previous = previous;
}

bool Update::previous() const {
    return m_previous;
}

void Update::setPts(qint32 pts) {
    m_pts = pts;
}

qint32 Update::pts() const {
    return m_pts;
}

void Update::setPtsCount(qint32 ptsCount) {
    m_ptsCount = ptsCount;
}

qint32 Update::ptsCount() const {
    return m_ptsCount;
}

void Update::setQts(qint32 qts) {
    m_qts = qts;
}

qint32 Update::qts() const {
    return m_qts;
}

void Update::setRandomId(qint64 randomId) {
    m_randomId = randomId;
}

qint64 Update::randomId() const {
    return m_randomId;
}

void Update::setRules(const QList<PrivacyRule> &rules) {
    m_rules = rules;
}

QList<PrivacyRule> Update::rules() const {
    return m_rules;
}

void Update::setStatus(const UserStatus &status) {
    m_status = status;
}

UserStatus Update::status() const {
    return m_status;
}

void Update::setType(const QString &type) {
    m_type = type;
}

QString Update::type() const {
    return m_type;
}

void Update::setUserId(qint32 userId) {
    m_userId = userId;
}

qint32 Update::userId() const {
    return m_userId;
}

void Update::setUsername(const QString &username) {
    m_username = username;
}

QString Update::username() const {
    return m_username;
}

void Update::setVersion(qint32 version) {
    m_version = version;
}

qint32 Update::version() const {
    return m_version;
}

void Update::setWebpage(const WebPage &webpage) {
    m_webpage = webpage;
}

WebPage Update::webpage() const {
    return m_webpage;
}

bool Update::operator ==(const Update &b) {
    return m_action == b.m_action &&
           m_authKeyId == b.m_authKeyId &&
           m_blocked == b.m_blocked &&
           m_chat == b.m_chat &&
           m_chatId == b.m_chatId &&
           m_date == b.m_date &&
           m_dcOptions == b.m_dcOptions &&
           m_device == b.m_device &&
           m_firstName == b.m_firstName &&
           m_foreignLink == b.m_foreignLink &&
           m_id == b.m_id &&
           m_inviterId == b.m_inviterId &&
           m_key == b.m_key &&
           m_lastName == b.m_lastName &&
           m_location == b.m_location &&
           m_maxDate == b.m_maxDate &&
           m_maxId == b.m_maxId &&
           m_media == b.m_media &&
           m_messageEncrypted == b.m_messageEncrypted &&
           m_messageGeoChat == b.m_messageGeoChat &&
           m_message == b.m_message &&
           m_messageString == b.m_messageString &&
           m_messages == b.m_messages &&
           m_myLink == b.m_myLink &&
           m_notifySettings == b.m_notifySettings &&
           m_participants == b.m_participants &&
           m_peerNotify == b.m_peerNotify &&
           m_peer == b.m_peer &&
           m_phone == b.m_phone &&
           m_photo == b.m_photo &&
           m_popup == b.m_popup &&
           m_previous == b.m_previous &&
           m_pts == b.m_pts &&
           m_ptsCount == b.m_ptsCount &&
           m_qts == b.m_qts &&
           m_randomId == b.m_randomId &&
           m_rules == b.m_rules &&
           m_status == b.m_status &&
           m_type == b.m_type &&
           m_userId == b.m_userId &&
           m_username == b.m_username &&
           m_version == b.m_version &&
           m_webpage == b.m_webpage;
}

void Update::setClassType(Update::UpdateType classType) {
    m_classType = classType;
}

Update::UpdateType Update::classType() const {
    return m_classType;
}

bool Update::fetch(InboundPkt *in) {

    int x = in->fetchInt();
    switch(x) {
    case typeUpdateNewMessage: {
        m_message.fetch(in);
        m_pts = in->fetchInt();
        m_ptsCount = in->fetchInt();
        return true;
    }
        break;
    
    case typeUpdateMessageID: {
        m_id = in->fetchInt();
        m_randomId = in->fetchLong();
        return true;
    }
        break;
    
    case typeUpdateDeleteMessages: {
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_messages_length = in->fetchInt();
        m_messages.clear();
        for (qint32 i = 0; i < m_messages_length; i++) {
            qint32 type;
            type = in->fetchInt();
            m_messages.append(type);
        }
        m_pts = in->fetchInt();
        m_ptsCount = in->fetchInt();
        return true;
    }
        break;
    
    case typeUpdateUserTyping: {
        m_userId = in->fetchInt();
        m_action.fetch(in);
        return true;
    }
        break;
    
    case typeUpdateChatUserTyping: {
        m_chatId = in->fetchInt();
        m_userId = in->fetchInt();
        m_action.fetch(in);
        return true;
    }
        break;
    
    case typeUpdateChatParticipants: {
        m_participants.fetch(in);
        return true;
    }
        break;
    
    case typeUpdateUserStatus: {
        m_userId = in->fetchInt();
        m_status.fetch(in);
        return true;
    }
        break;
    
    case typeUpdateUserName: {
        m_userId = in->fetchInt();
        m_firstName = in->fetchQString();
        m_lastName = in->fetchQString();
        m_username = in->fetchQString();
        return true;
    }
        break;
    
    case typeUpdateUserPhoto: {
        m_userId = in->fetchInt();
        m_date = in->fetchInt();
        m_photo.fetch(in);
        m_previous = in->fetchBool();
        return true;
    }
        break;
    
    case typeUpdateContactRegistered: {
        m_userId = in->fetchInt();
        m_date = in->fetchInt();
        return true;
    }
        break;
    
    case typeUpdateContactLink: {
        m_userId = in->fetchInt();
        m_myLink.fetch(in);
        m_foreignLink.fetch(in);
        return true;
    }
        break;
    
    case typeUpdateNewAuthorization: {
        m_authKeyId = in->fetchLong();
        m_date = in->fetchInt();
        m_device = in->fetchQString();
        m_location = in->fetchQString();
        return true;
    }
        break;
    
    case typeUpdateNewGeoChatMessage: {
        m_messageGeoChat.fetch(in);
        return true;
    }
        break;
    
    case typeUpdateNewEncryptedMessage: {
        m_messageEncrypted.fetch(in);
        m_qts = in->fetchInt();
        return true;
    }
        break;
    
    case typeUpdateEncryptedChatTyping: {
        m_chatId = in->fetchInt();
        return true;
    }
        break;
    
    case typeUpdateEncryption: {
        m_chat.fetch(in);
        m_date = in->fetchInt();
        return true;
    }
        break;
    
    case typeUpdateEncryptedMessagesRead: {
        m_chatId = in->fetchInt();
        m_maxDate = in->fetchInt();
        m_date = in->fetchInt();
        return true;
    }
        break;
    
    case typeUpdateChatParticipantAdd: {
        m_chatId = in->fetchInt();
        m_userId = in->fetchInt();
        m_inviterId = in->fetchInt();
        m_version = in->fetchInt();
        return true;
    }
        break;
    
    case typeUpdateChatParticipantDelete: {
        m_chatId = in->fetchInt();
        m_userId = in->fetchInt();
        m_version = in->fetchInt();
        return true;
    }
        break;
    
    case typeUpdateDcOptions: {
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_dcOptions_length = in->fetchInt();
        m_dcOptions.clear();
        for (qint32 i = 0; i < m_dcOptions_length; i++) {
            DcOption type;
            type.fetch(in);
            m_dcOptions.append(type);
        }
        return true;
    }
        break;
    
    case typeUpdateUserBlocked: {
        m_userId = in->fetchInt();
        m_blocked = in->fetchBool();
        return true;
    }
        break;
    
    case typeUpdateNotifySettings: {
        m_peerNotify.fetch(in);
        m_notifySettings.fetch(in);
        return true;
    }
        break;
    
    case typeUpdateServiceNotification: {
        m_type = in->fetchQString();
        m_messageString = in->fetchQString();
        m_media.fetch(in);
        m_popup = in->fetchBool();
        return true;
    }
        break;
    
    case typeUpdatePrivacy: {
        m_key.fetch(in);
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_rules_length = in->fetchInt();
        m_rules.clear();
        for (qint32 i = 0; i < m_rules_length; i++) {
            PrivacyRule type;
            type.fetch(in);
            m_rules.append(type);
        }
        return true;
    }
        break;
    
    case typeUpdateUserPhone: {
        m_userId = in->fetchInt();
        m_phone = in->fetchQString();
        return true;
    }
        break;
    
    case typeUpdateReadHistoryInbox: {
        m_peer.fetch(in);
        m_maxId = in->fetchInt();
        m_pts = in->fetchInt();
        m_ptsCount = in->fetchInt();
        return true;
    }
        break;
    
    case typeUpdateReadHistoryOutbox: {
        m_peer.fetch(in);
        m_maxId = in->fetchInt();
        m_pts = in->fetchInt();
        m_ptsCount = in->fetchInt();
        return true;
    }
        break;
    
    case typeUpdateWebPage: {
        m_webpage.fetch(in);
        return true;
    }
        break;
    
    case typeUpdateReadMessagesContents: {
        if(in->fetchInt() != (qint32)TL_Vector) return false;
        qint32 m_messages_length = in->fetchInt();
        m_messages.clear();
        for (qint32 i = 0; i < m_messages_length; i++) {
            qint32 type;
            type = in->fetchInt();
            m_messages.append(type);
        }
        m_pts = in->fetchInt();
        m_ptsCount = in->fetchInt();
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool Update::push(OutboundPkt *out) const {

    out->appendInt(m_classType);
    switch(m_classType) {
    case typeUpdateNewMessage: {
        m_message.push(out);
        out->appendInt(m_pts);
        out->appendInt(m_ptsCount);
        return true;
    }
        break;
    
    case typeUpdateMessageID: {
        out->appendInt(m_id);
        out->appendLong(m_randomId);
        return true;
    }
        break;
    
    case typeUpdateDeleteMessages: {
        out->appendInt(TL_Vector);
        out->appendInt(m_messages.count());
        for (qint32 i = 0; i < m_messages.count(); i++) {
            out->appendInt(m_messages[i]);
        }
        out->appendInt(m_pts);
        out->appendInt(m_ptsCount);
        return true;
    }
        break;
    
    case typeUpdateUserTyping: {
        out->appendInt(m_userId);
        m_action.push(out);
        return true;
    }
        break;
    
    case typeUpdateChatUserTyping: {
        out->appendInt(m_chatId);
        out->appendInt(m_userId);
        m_action.push(out);
        return true;
    }
        break;
    
    case typeUpdateChatParticipants: {
        m_participants.push(out);
        return true;
    }
        break;
    
    case typeUpdateUserStatus: {
        out->appendInt(m_userId);
        m_status.push(out);
        return true;
    }
        break;
    
    case typeUpdateUserName: {
        out->appendInt(m_userId);
        out->appendQString(m_firstName);
        out->appendQString(m_lastName);
        out->appendQString(m_username);
        return true;
    }
        break;
    
    case typeUpdateUserPhoto: {
        out->appendInt(m_userId);
        out->appendInt(m_date);
        m_photo.push(out);
        out->appendBool(m_previous);
        return true;
    }
        break;
    
    case typeUpdateContactRegistered: {
        out->appendInt(m_userId);
        out->appendInt(m_date);
        return true;
    }
        break;
    
    case typeUpdateContactLink: {
        out->appendInt(m_userId);
        m_myLink.push(out);
        m_foreignLink.push(out);
        return true;
    }
        break;
    
    case typeUpdateNewAuthorization: {
        out->appendLong(m_authKeyId);
        out->appendInt(m_date);
        out->appendQString(m_device);
        out->appendQString(m_location);
        return true;
    }
        break;
    
    case typeUpdateNewGeoChatMessage: {
        m_messageGeoChat.push(out);
        return true;
    }
        break;
    
    case typeUpdateNewEncryptedMessage: {
        m_messageEncrypted.push(out);
        out->appendInt(m_qts);
        return true;
    }
        break;
    
    case typeUpdateEncryptedChatTyping: {
        out->appendInt(m_chatId);
        return true;
    }
        break;
    
    case typeUpdateEncryption: {
        m_chat.push(out);
        out->appendInt(m_date);
        return true;
    }
        break;
    
    case typeUpdateEncryptedMessagesRead: {
        out->appendInt(m_chatId);
        out->appendInt(m_maxDate);
        out->appendInt(m_date);
        return true;
    }
        break;
    
    case typeUpdateChatParticipantAdd: {
        out->appendInt(m_chatId);
        out->appendInt(m_userId);
        out->appendInt(m_inviterId);
        out->appendInt(m_version);
        return true;
    }
        break;
    
    case typeUpdateChatParticipantDelete: {
        out->appendInt(m_chatId);
        out->appendInt(m_userId);
        out->appendInt(m_version);
        return true;
    }
        break;
    
    case typeUpdateDcOptions: {
        out->appendInt(TL_Vector);
        out->appendInt(m_dcOptions.count());
        for (qint32 i = 0; i < m_dcOptions.count(); i++) {
            m_dcOptions[i].push(out);
        }
        return true;
    }
        break;
    
    case typeUpdateUserBlocked: {
        out->appendInt(m_userId);
        out->appendBool(m_blocked);
        return true;
    }
        break;
    
    case typeUpdateNotifySettings: {
        m_peerNotify.push(out);
        m_notifySettings.push(out);
        return true;
    }
        break;
    
    case typeUpdateServiceNotification: {
        out->appendQString(m_type);
        out->appendQString(m_messageString);
        m_media.push(out);
        out->appendBool(m_popup);
        return true;
    }
        break;
    
    case typeUpdatePrivacy: {
        m_key.push(out);
        out->appendInt(TL_Vector);
        out->appendInt(m_rules.count());
        for (qint32 i = 0; i < m_rules.count(); i++) {
            m_rules[i].push(out);
        }
        return true;
    }
        break;
    
    case typeUpdateUserPhone: {
        out->appendInt(m_userId);
        out->appendQString(m_phone);
        return true;
    }
        break;
    
    case typeUpdateReadHistoryInbox: {
        m_peer.push(out);
        out->appendInt(m_maxId);
        out->appendInt(m_pts);
        out->appendInt(m_ptsCount);
        return true;
    }
        break;
    
    case typeUpdateReadHistoryOutbox: {
        m_peer.push(out);
        out->appendInt(m_maxId);
        out->appendInt(m_pts);
        out->appendInt(m_ptsCount);
        return true;
    }
        break;
    
    case typeUpdateWebPage: {
        m_webpage.push(out);
        return true;
    }
        break;
    
    case typeUpdateReadMessagesContents: {
        out->appendInt(TL_Vector);
        out->appendInt(m_messages.count());
        for (qint32 i = 0; i < m_messages.count(); i++) {
            out->appendInt(m_messages[i]);
        }
        out->appendInt(m_pts);
        out->appendInt(m_ptsCount);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

