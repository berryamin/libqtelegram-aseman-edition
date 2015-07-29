#ifndef LQTG_INPUTCHATPHOTO
#define LQTG_INPUTCHATPHOTO

#include "telegramtypeobject.h"
#include "inputphotocrop.h"
#include "inputfile.h"
#include "inputphoto.h"

class InputChatPhoto : public TelegramTypeObject
{
public:
    enum InputChatPhotoType {
        typeInputChatPhotoEmpty = 0x1ca48f57,
        typeInputChatUploadedPhoto = 0x94254732,
        typeInputChatPhoto = 0xb2e1bf08
    };

    InputChatPhoto(InputChatPhotoType classType = typeInputChatPhotoEmpty, InboundPkt *in = 0);
    InputChatPhoto(InboundPkt *in);
    virtual ~InputChatPhoto();

    void setCrop(const InputPhotoCrop &crop);
    InputPhotoCrop crop() const;

    void setFile(const InputFile &file);
    InputFile file() const;

    void setId(const InputPhoto &id);
    InputPhoto id() const;

    void setClassType(InputChatPhotoType classType);
    InputChatPhotoType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const InputChatPhoto &b);

private:
    InputPhotoCrop m_crop;
    InputFile m_file;
    InputPhoto m_id;
    InputChatPhotoType m_classType;
};

#endif // LQTG_INPUTCHATPHOTO
