#ifndef LQTG_HELPAPPUPDATE
#define LQTG_HELPAPPUPDATE

#include "telegramtypeobject.h"
#include <QtGlobal>
#include <QString>

class HelpAppUpdate : public TelegramTypeObject
{
public:
    enum HelpAppUpdateType {
        typeHelpAppUpdate = 0x8987f311,
        typeHelpNoAppUpdate = 0xc45a6536
    };

    HelpAppUpdate(HelpAppUpdateType classType = typeHelpAppUpdate, InboundPkt *in = 0);
    HelpAppUpdate(InboundPkt *in);
    virtual ~HelpAppUpdate();

    void setCritical(bool critical);
    bool critical() const;

    void setId(qint32 id);
    qint32 id() const;

    void setText(const QString &text);
    QString text() const;

    void setUrl(const QString &url);
    QString url() const;

    void setClassType(HelpAppUpdateType classType);
    HelpAppUpdateType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const HelpAppUpdate &b);

private:
    bool m_critical;
    qint32 m_id;
    QString m_text;
    QString m_url;
    HelpAppUpdateType m_classType;
};

#endif // LQTG_HELPAPPUPDATE
