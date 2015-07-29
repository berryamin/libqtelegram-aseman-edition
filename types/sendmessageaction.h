#ifndef LQTG_SENDMESSAGEACTION
#define LQTG_SENDMESSAGEACTION

#include "telegramtypeobject.h"
#include <QtGlobal>

class SendMessageAction : public TelegramTypeObject
{
public:
    enum SendMessageActionType {
        typeSendMessageTypingAction = 0x16bf744e,
        typeSendMessageCancelAction = 0xfd5ec8f5,
        typeSendMessageRecordVideoAction = 0xa187d66f,
        typeSendMessageUploadVideoAction = 0xe9763aec,
        typeSendMessageRecordAudioAction = 0xd52f73f7,
        typeSendMessageUploadAudioAction = 0xf351d7ab,
        typeSendMessageUploadPhotoAction = 0xd1d34a26,
        typeSendMessageUploadDocumentAction = 0xaa0cd9e4,
        typeSendMessageGeoLocationAction = 0x176f8ba1,
        typeSendMessageChooseContactAction = 0x628cbc6f
    };

    SendMessageAction(SendMessageActionType classType = typeSendMessageTypingAction, InboundPkt *in = 0);
    SendMessageAction(InboundPkt *in);
    virtual ~SendMessageAction();

    void setProgress(qint32 progress);
    qint32 progress() const;

    void setClassType(SendMessageActionType classType);
    SendMessageActionType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const SendMessageAction &b);

private:
    qint32 m_progress;
    SendMessageActionType m_classType;
};

#endif // LQTG_SENDMESSAGEACTION
