#ifndef LQTG_INPUTGEOPOINT
#define LQTG_INPUTGEOPOINT

#include "telegramtypeobject.h"
#include <QtGlobal>

class InputGeoPoint : public TelegramTypeObject
{
public:
    enum InputGeoPointType {
        typeInputGeoPointEmpty = 0xe4c123d6,
        typeInputGeoPoint = 0xf3b7acc9
    };

    InputGeoPoint(InputGeoPointType classType = typeInputGeoPointEmpty, InboundPkt *in = 0);
    InputGeoPoint(InboundPkt *in);
    virtual ~InputGeoPoint();

    void setLat(qreal lat);
    qreal lat() const;

    void setLongValue(qreal longValue);
    qreal longValue() const;

    void setClassType(InputGeoPointType classType);
    InputGeoPointType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const InputGeoPoint &b);

private:
    qreal m_lat;
    qreal m_longValue;
    InputGeoPointType m_classType;
};

#endif // LQTG_INPUTGEOPOINT
