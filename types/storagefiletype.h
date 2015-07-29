#ifndef LQTG_STORAGEFILETYPE
#define LQTG_STORAGEFILETYPE

#include "telegramtypeobject.h"

class StorageFileType : public TelegramTypeObject
{
public:
    enum StorageFileTypeType {
        typeStorageFileUnknown = 0xaa963b05,
        typeStorageFileJpeg = 0x7efe0e,
        typeStorageFileGif = 0xcae1aadf,
        typeStorageFilePng = 0xa4f63c0,
        typeStorageFilePdf = 0xae1e508d,
        typeStorageFileMp3 = 0x528a0677,
        typeStorageFileMov = 0x4b09ebbc,
        typeStorageFilePartial = 0x40bc6f52,
        typeStorageFileMp4 = 0xb3cea0e4,
        typeStorageFileWebp = 0x1081464c
    };

    StorageFileType(StorageFileTypeType classType = typeStorageFileUnknown, InboundPkt *in = 0);
    StorageFileType(InboundPkt *in);
    virtual ~StorageFileType();

    void setClassType(StorageFileTypeType classType);
    StorageFileTypeType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const StorageFileType &b);

private:
    StorageFileTypeType m_classType;
};

#endif // LQTG_STORAGEFILETYPE
