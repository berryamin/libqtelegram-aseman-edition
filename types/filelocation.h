#ifndef LQTG_FILELOCATION
#define LQTG_FILELOCATION

#include "telegramtypeobject.h"
#include <QtGlobal>

class FileLocation : public TelegramTypeObject
{
public:
    enum FileLocationType {
        typeFileLocationUnavailable = 0x7c596b46,
        typeFileLocation = 0x53d69076
    };

    FileLocation(FileLocationType classType = typeFileLocationUnavailable, InboundPkt *in = 0);
    FileLocation(InboundPkt *in);
    virtual ~FileLocation();

    void setDcId(qint32 dcId);
    qint32 dcId() const;

    void setLocalId(qint32 localId);
    qint32 localId() const;

    void setSecret(qint64 secret);
    qint64 secret() const;

    void setVolumeId(qint64 volumeId);
    qint64 volumeId() const;

    void setClassType(FileLocationType classType);
    FileLocationType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const FileLocation &b);

private:
    qint32 m_dcId;
    qint32 m_localId;
    qint64 m_secret;
    qint64 m_volumeId;
    FileLocationType m_classType;
};

#endif // LQTG_FILELOCATION
