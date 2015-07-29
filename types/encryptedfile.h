#ifndef LQTG_ENCRYPTEDFILE
#define LQTG_ENCRYPTEDFILE

#include "telegramtypeobject.h"
#include <QtGlobal>

class EncryptedFile : public TelegramTypeObject
{
public:
    enum EncryptedFileType {
        typeEncryptedFileEmpty = 0xc21f497e,
        typeEncryptedFile = 0x4a70994c
    };

    EncryptedFile(EncryptedFileType classType = typeEncryptedFileEmpty, InboundPkt *in = 0);
    EncryptedFile(InboundPkt *in);
    virtual ~EncryptedFile();

    void setAccessHash(qint64 accessHash);
    qint64 accessHash() const;

    void setDcId(qint32 dcId);
    qint32 dcId() const;

    void setId(qint64 id);
    qint64 id() const;

    void setKeyFingerprint(qint32 keyFingerprint);
    qint32 keyFingerprint() const;

    void setSize(qint32 size);
    qint32 size() const;

    void setClassType(EncryptedFileType classType);
    EncryptedFileType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const EncryptedFile &b);

private:
    qint64 m_accessHash;
    qint32 m_dcId;
    qint64 m_id;
    qint32 m_keyFingerprint;
    qint32 m_size;
    EncryptedFileType m_classType;
};

#endif // LQTG_ENCRYPTEDFILE
