#ifndef LQTG_INPUTSTICKERSET
#define LQTG_INPUTSTICKERSET

#include "telegramtypeobject.h"
#include <QtGlobal>
#include <QString>

class InputStickerSet : public TelegramTypeObject
{
public:
    enum InputStickerSetType {
        typeInputStickerSetEmpty = 0xffb62b95,
        typeInputStickerSetID = 0x9de7a269,
        typeInputStickerSetShortName = 0x861cc8a0
    };

    InputStickerSet(InputStickerSetType classType = typeInputStickerSetEmpty, InboundPkt *in = 0);
    InputStickerSet(InboundPkt *in);
    virtual ~InputStickerSet();

    void setAccessHash(qint64 accessHash);
    qint64 accessHash() const;

    void setId(qint64 id);
    qint64 id() const;

    void setShortName(const QString &shortName);
    QString shortName() const;

    void setClassType(InputStickerSetType classType);
    InputStickerSetType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const InputStickerSet &b);

private:
    qint64 m_accessHash;
    qint64 m_id;
    QString m_shortName;
    InputStickerSetType m_classType;
};

#endif // LQTG_INPUTSTICKERSET
