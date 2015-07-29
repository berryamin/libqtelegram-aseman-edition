#ifndef LQTG_AUTHORIZATION
#define LQTG_AUTHORIZATION

#include "telegramtypeobject.h"
#include <QtGlobal>
#include <QString>

class Authorization : public TelegramTypeObject
{
public:
    enum AuthorizationType {
        typeAuthorization = 0x7bf2e6f6
    };

    Authorization(AuthorizationType classType = typeAuthorization, InboundPkt *in = 0);
    Authorization(InboundPkt *in);
    virtual ~Authorization();

    void setApiId(qint32 apiId);
    qint32 apiId() const;

    void setAppName(const QString &appName);
    QString appName() const;

    void setAppVersion(const QString &appVersion);
    QString appVersion() const;

    void setCountry(const QString &country);
    QString country() const;

    void setDateActive(qint32 dateActive);
    qint32 dateActive() const;

    void setDateCreated(qint32 dateCreated);
    qint32 dateCreated() const;

    void setDeviceModel(const QString &deviceModel);
    QString deviceModel() const;

    void setFlags(qint32 flags);
    qint32 flags() const;

    void setHash(qint64 hash);
    qint64 hash() const;

    void setIp(const QString &ip);
    QString ip() const;

    void setPlatform(const QString &platform);
    QString platform() const;

    void setRegion(const QString &region);
    QString region() const;

    void setSystemVersion(const QString &systemVersion);
    QString systemVersion() const;

    void setClassType(AuthorizationType classType);
    AuthorizationType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const Authorization &b);

private:
    qint32 m_apiId;
    QString m_appName;
    QString m_appVersion;
    QString m_country;
    qint32 m_dateActive;
    qint32 m_dateCreated;
    QString m_deviceModel;
    qint32 m_flags;
    qint64 m_hash;
    QString m_ip;
    QString m_platform;
    QString m_region;
    QString m_systemVersion;
    AuthorizationType m_classType;
};

#endif // LQTG_AUTHORIZATION
