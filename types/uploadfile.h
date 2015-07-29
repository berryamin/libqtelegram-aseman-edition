#ifndef LQTG_UPLOADFILE
#define LQTG_UPLOADFILE

#include "telegramtypeobject.h"
#include <QByteArray>
#include <QtGlobal>
#include "storagefiletype.h"

class UploadFile : public TelegramTypeObject
{
public:
    enum UploadFileType {
        typeUploadFile = 0x96a18d5
    };

    UploadFile(UploadFileType classType = typeUploadFile, InboundPkt *in = 0);
    UploadFile(InboundPkt *in);
    virtual ~UploadFile();

    void setBytes(const QByteArray &bytes);
    QByteArray bytes() const;

    void setMtime(qint32 mtime);
    qint32 mtime() const;

    void setType(const StorageFileType &type);
    StorageFileType type() const;

    void setClassType(UploadFileType classType);
    UploadFileType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const UploadFile &b);

private:
    QByteArray m_bytes;
    qint32 m_mtime;
    StorageFileType m_type;
    UploadFileType m_classType;
};

#endif // LQTG_UPLOADFILE
