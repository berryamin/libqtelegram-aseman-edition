#ifndef LQTG_NEARESTDC
#define LQTG_NEARESTDC

#include "telegramtypeobject.h"
#include <QString>
#include <QtGlobal>

class NearestDc : public TelegramTypeObject
{
public:
    enum NearestDcType {
        typeNearestDc = 0x8e1a1775
    };

    NearestDc(NearestDcType classType = typeNearestDc, InboundPkt *in = 0);
    NearestDc(InboundPkt *in);
    virtual ~NearestDc();

    void setCountry(const QString &country);
    QString country() const;

    void setNearestDc(qint32 nearestDc);
    qint32 nearestDc() const;

    void setThisDc(qint32 thisDc);
    qint32 thisDc() const;

    void setClassType(NearestDcType classType);
    NearestDcType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const NearestDc &b);

private:
    QString m_country;
    qint32 m_nearestDc;
    qint32 m_thisDc;
    NearestDcType m_classType;
};

#endif // LQTG_NEARESTDC
