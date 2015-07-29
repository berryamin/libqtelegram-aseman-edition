#ifndef LQTG_CONFIG
#define LQTG_CONFIG

#include "telegramtypeobject.h"
#include <QtGlobal>
#include <QList>
#include "dcoption.h"
#include "disabledfeature.h"

class Config : public TelegramTypeObject
{
public:
    enum ConfigType {
        typeConfig = 0x4e32b894
    };

    Config(ConfigType classType = typeConfig, InboundPkt *in = 0);
    Config(InboundPkt *in);
    virtual ~Config();

    void setBroadcastSizeMax(qint32 broadcastSizeMax);
    qint32 broadcastSizeMax() const;

    void setChatBigSize(qint32 chatBigSize);
    qint32 chatBigSize() const;

    void setChatSizeMax(qint32 chatSizeMax);
    qint32 chatSizeMax() const;

    void setDate(qint32 date);
    qint32 date() const;

    void setDcOptions(const QList<DcOption> &dcOptions);
    QList<DcOption> dcOptions() const;

    void setDisabledFeatures(const QList<DisabledFeature> &disabledFeatures);
    QList<DisabledFeature> disabledFeatures() const;

    void setExpires(qint32 expires);
    qint32 expires() const;

    void setForwardedCountMax(qint32 forwardedCountMax);
    qint32 forwardedCountMax() const;

    void setNotifyCloudDelayMs(qint32 notifyCloudDelayMs);
    qint32 notifyCloudDelayMs() const;

    void setNotifyDefaultDelayMs(qint32 notifyDefaultDelayMs);
    qint32 notifyDefaultDelayMs() const;

    void setOfflineBlurTimeoutMs(qint32 offlineBlurTimeoutMs);
    qint32 offlineBlurTimeoutMs() const;

    void setOfflineIdleTimeoutMs(qint32 offlineIdleTimeoutMs);
    qint32 offlineIdleTimeoutMs() const;

    void setOnlineCloudTimeoutMs(qint32 onlineCloudTimeoutMs);
    qint32 onlineCloudTimeoutMs() const;

    void setOnlineUpdatePeriodMs(qint32 onlineUpdatePeriodMs);
    qint32 onlineUpdatePeriodMs() const;

    void setPushChatLimit(qint32 pushChatLimit);
    qint32 pushChatLimit() const;

    void setPushChatPeriodMs(qint32 pushChatPeriodMs);
    qint32 pushChatPeriodMs() const;

    void setTestMode(bool testMode);
    bool testMode() const;

    void setThisDc(qint32 thisDc);
    qint32 thisDc() const;

    void setClassType(ConfigType classType);
    ConfigType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const Config &b);

private:
    qint32 m_broadcastSizeMax;
    qint32 m_chatBigSize;
    qint32 m_chatSizeMax;
    qint32 m_date;
    QList<DcOption> m_dcOptions;
    QList<DisabledFeature> m_disabledFeatures;
    qint32 m_expires;
    qint32 m_forwardedCountMax;
    qint32 m_notifyCloudDelayMs;
    qint32 m_notifyDefaultDelayMs;
    qint32 m_offlineBlurTimeoutMs;
    qint32 m_offlineIdleTimeoutMs;
    qint32 m_onlineCloudTimeoutMs;
    qint32 m_onlineUpdatePeriodMs;
    qint32 m_pushChatLimit;
    qint32 m_pushChatPeriodMs;
    bool m_testMode;
    qint32 m_thisDc;
    ConfigType m_classType;
};

#endif // LQTG_CONFIG
