#ifndef LQTG_GEOPOINT
#define LQTG_GEOPOINT

#include "telegramtypeobject.h"
#include <QtGlobal>

class GeoPoint : public TelegramTypeObject
{
public:
    enum GeoPointType {
        typeGeoPointEmpty = 0x1117dd5f,
        typeGeoPoint = 0x2049d70c
    };

    GeoPoint(GeoPointType classType = typeGeoPointEmpty, InboundPkt *in = 0);
    GeoPoint(InboundPkt *in);
    virtual ~GeoPoint();

    void setLat(qreal lat);
    qreal lat() const;

    void setLongValue(qreal longValue);
    qreal longValue() const;

    void setClassType(GeoPointType classType);
    GeoPointType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const GeoPoint &b);

private:
    qreal m_lat;
    qreal m_longValue;
    GeoPointType m_classType;
};

#endif // LQTG_GEOPOINT
