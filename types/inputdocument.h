#ifndef LQTG_INPUTDOCUMENT
#define LQTG_INPUTDOCUMENT

#include "telegramtypeobject.h"
#include <QtGlobal>

class InputDocument : public TelegramTypeObject
{
public:
    enum InputDocumentType {
        typeInputDocumentEmpty = 0x72f0eaae,
        typeInputDocument = 0x18798952
    };

    InputDocument(InputDocumentType classType = typeInputDocumentEmpty, InboundPkt *in = 0);
    InputDocument(InboundPkt *in);
    virtual ~InputDocument();

    void setAccessHash(qint64 accessHash);
    qint64 accessHash() const;

    void setId(qint64 id);
    qint64 id() const;

    void setClassType(InputDocumentType classType);
    InputDocumentType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const InputDocument &b);

private:
    qint64 m_accessHash;
    qint64 m_id;
    InputDocumentType m_classType;
};

#endif // LQTG_INPUTDOCUMENT
