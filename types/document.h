#ifndef LQTG_DOCUMENT
#define LQTG_DOCUMENT

#include "telegramtypeobject.h"
#include <QtGlobal>
#include <QList>
#include "documentattribute.h"
#include <QString>
#include "photosize.h"

class Document : public TelegramTypeObject
{
public:
    enum DocumentType {
        typeDocumentEmpty = 0x36f8c871,
        typeDocument = 0xf9a39f4f
    };

    Document(DocumentType classType = typeDocumentEmpty, InboundPkt *in = 0);
    Document(InboundPkt *in);
    virtual ~Document();

    void setAccessHash(qint64 accessHash);
    qint64 accessHash() const;

    void setAttributes(const QList<DocumentAttribute> &attributes);
    QList<DocumentAttribute> attributes() const;

    void setDate(qint32 date);
    qint32 date() const;

    void setDcId(qint32 dcId);
    qint32 dcId() const;

    void setId(qint64 id);
    qint64 id() const;

    void setMimeType(const QString &mimeType);
    QString mimeType() const;

    void setSize(qint32 size);
    qint32 size() const;

    void setThumb(const PhotoSize &thumb);
    PhotoSize thumb() const;

    void setClassType(DocumentType classType);
    DocumentType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const Document &b);

private:
    qint64 m_accessHash;
    QList<DocumentAttribute> m_attributes;
    qint32 m_date;
    qint32 m_dcId;
    qint64 m_id;
    QString m_mimeType;
    qint32 m_size;
    PhotoSize m_thumb;
    DocumentType m_classType;
};

#endif // LQTG_DOCUMENT
