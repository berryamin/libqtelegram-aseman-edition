#ifndef LQTG_INPUTENCRYPTEDFILE
#define LQTG_INPUTENCRYPTEDFILE

#include "telegramtypeobject.h"
#include <QtGlobal>
#include <QString>

class InputEncryptedFile : public TelegramTypeObject
{
public:
    enum InputEncryptedFileType {
        typeInputEncryptedFileEmpty = 0x1837c364,
        typeInputEncryptedFileUploaded = 0x64bd0306,
        typeInputEncryptedFile = 0x5a17b5e5,
        typeInputEncryptedFileBigUploaded = 0x2dc173c8
    };

    InputEncryptedFile(InputEncryptedFileType classType = typeInputEncryptedFileEmpty, InboundPkt *in = 0);
    InputEncryptedFile(InboundPkt *in);
    virtual ~InputEncryptedFile();

    void setAccessHash(qint64 accessHash);
    qint64 accessHash() const;

    void setId(qint64 id);
    qint64 id() const;

    void setKeyFingerprint(qint32 keyFingerprint);
    qint32 keyFingerprint() const;

    void setMd5Checksum(const QString &md5Checksum);
    QString md5Checksum() const;

    void setParts(qint32 parts);
    qint32 parts() const;

    void setClassType(InputEncryptedFileType classType);
    InputEncryptedFileType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const InputEncryptedFile &b);

private:
    qint64 m_accessHash;
    qint64 m_id;
    qint32 m_keyFingerprint;
    QString m_md5Checksum;
    qint32 m_parts;
    InputEncryptedFileType m_classType;
};

#endif // LQTG_INPUTENCRYPTEDFILE
