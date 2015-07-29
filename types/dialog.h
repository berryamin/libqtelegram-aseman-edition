#ifndef LQTG_DIALOG
#define LQTG_DIALOG

#include "telegramtypeobject.h"
#include "peernotifysettings.h"
#include "peer.h"
#include <QtGlobal>

class Dialog : public TelegramTypeObject
{
public:
    enum DialogType {
        typeDialog = 0xc1dd804a
    };

    Dialog(DialogType classType = typeDialog, InboundPkt *in = 0);
    Dialog(InboundPkt *in);
    virtual ~Dialog();

    void setNotifySettings(const PeerNotifySettings &notifySettings);
    PeerNotifySettings notifySettings() const;

    void setPeer(const Peer &peer);
    Peer peer() const;

    void setReadInboxMaxId(qint32 readInboxMaxId);
    qint32 readInboxMaxId() const;

    void setTopMessage(qint32 topMessage);
    qint32 topMessage() const;

    void setUnreadCount(qint32 unreadCount);
    qint32 unreadCount() const;

    void setClassType(DialogType classType);
    DialogType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const Dialog &b);

private:
    PeerNotifySettings m_notifySettings;
    Peer m_peer;
    qint32 m_readInboxMaxId;
    qint32 m_topMessage;
    qint32 m_unreadCount;
    DialogType m_classType;
};

#endif // LQTG_DIALOG
