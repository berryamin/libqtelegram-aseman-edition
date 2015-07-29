#ifndef LQTG_EXPORTEDCHATINVITE
#define LQTG_EXPORTEDCHATINVITE

#include "telegramtypeobject.h"
#include <QString>

class ExportedChatInvite : public TelegramTypeObject
{
public:
    enum ExportedChatInviteType {
        typeChatInviteEmpty = 0x69df3769,
        typeChatInviteExported = 0xfc2e05bc
    };

    ExportedChatInvite(ExportedChatInviteType classType = typeChatInviteEmpty, InboundPkt *in = 0);
    ExportedChatInvite(InboundPkt *in);
    virtual ~ExportedChatInvite();

    void setLink(const QString &link);
    QString link() const;

    void setClassType(ExportedChatInviteType classType);
    ExportedChatInviteType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const ExportedChatInvite &b);

private:
    QString m_link;
    ExportedChatInviteType m_classType;
};

#endif // LQTG_EXPORTEDCHATINVITE
