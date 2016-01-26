// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "inputbotinlineresultobject.h"

InputBotInlineResultObject::InputBotInlineResultObject(const InputBotInlineResult &core, QObject *parent) :
    TelegramTypeQObject(parent),
    m_sendMessage(0),
    m_core(core)
{
    m_sendMessage = new InputBotInlineMessageObject(m_core.sendMessage(), this);
    connect(m_sendMessage.data(), &InputBotInlineMessageObject::coreChanged, this, &InputBotInlineResultObject::coreSendMessageChanged);
}

InputBotInlineResultObject::InputBotInlineResultObject(QObject *parent) :
    TelegramTypeQObject(parent),
    m_sendMessage(0),
    m_core()
{
    m_sendMessage = new InputBotInlineMessageObject(m_core.sendMessage(), this);
    connect(m_sendMessage.data(), &InputBotInlineMessageObject::coreChanged, this, &InputBotInlineResultObject::coreSendMessageChanged);
}

InputBotInlineResultObject::~InputBotInlineResultObject() {
}

void InputBotInlineResultObject::setContentType(const QString &contentType) {
    if(m_core.contentType() == contentType) return;
    m_core.setContentType(contentType);
    Q_EMIT contentTypeChanged();
    Q_EMIT coreChanged();
}

QString InputBotInlineResultObject::contentType() const {
    return m_core.contentType();
}

void InputBotInlineResultObject::setContentUrl(const QString &contentUrl) {
    if(m_core.contentUrl() == contentUrl) return;
    m_core.setContentUrl(contentUrl);
    Q_EMIT contentUrlChanged();
    Q_EMIT coreChanged();
}

QString InputBotInlineResultObject::contentUrl() const {
    return m_core.contentUrl();
}

void InputBotInlineResultObject::setDescription(const QString &description) {
    if(m_core.description() == description) return;
    m_core.setDescription(description);
    Q_EMIT descriptionChanged();
    Q_EMIT coreChanged();
}

QString InputBotInlineResultObject::description() const {
    return m_core.description();
}

void InputBotInlineResultObject::setDuration(qint32 duration) {
    if(m_core.duration() == duration) return;
    m_core.setDuration(duration);
    Q_EMIT durationChanged();
    Q_EMIT coreChanged();
}

qint32 InputBotInlineResultObject::duration() const {
    return m_core.duration();
}

void InputBotInlineResultObject::setFlags(qint32 flags) {
    if(m_core.flags() == flags) return;
    m_core.setFlags(flags);
    Q_EMIT flagsChanged();
    Q_EMIT coreChanged();
}

qint32 InputBotInlineResultObject::flags() const {
    return m_core.flags();
}

void InputBotInlineResultObject::setH(qint32 h) {
    if(m_core.h() == h) return;
    m_core.setH(h);
    Q_EMIT hChanged();
    Q_EMIT coreChanged();
}

qint32 InputBotInlineResultObject::h() const {
    return m_core.h();
}

void InputBotInlineResultObject::setId(const QString &id) {
    if(m_core.id() == id) return;
    m_core.setId(id);
    Q_EMIT idChanged();
    Q_EMIT coreChanged();
}

QString InputBotInlineResultObject::id() const {
    return m_core.id();
}

void InputBotInlineResultObject::setSendMessage(InputBotInlineMessageObject* sendMessage) {
    if(m_sendMessage == sendMessage) return;
    if(m_sendMessage) delete m_sendMessage;
    m_sendMessage = sendMessage;
    if(m_sendMessage) {
        m_sendMessage->setParent(this);
        m_core.setSendMessage(m_sendMessage->core());
        connect(m_sendMessage.data(), &InputBotInlineMessageObject::coreChanged, this, &InputBotInlineResultObject::coreSendMessageChanged);
    }
    Q_EMIT sendMessageChanged();
    Q_EMIT coreChanged();
}

InputBotInlineMessageObject*  InputBotInlineResultObject::sendMessage() const {
    return m_sendMessage;
}

void InputBotInlineResultObject::setThumbUrl(const QString &thumbUrl) {
    if(m_core.thumbUrl() == thumbUrl) return;
    m_core.setThumbUrl(thumbUrl);
    Q_EMIT thumbUrlChanged();
    Q_EMIT coreChanged();
}

QString InputBotInlineResultObject::thumbUrl() const {
    return m_core.thumbUrl();
}

void InputBotInlineResultObject::setTitle(const QString &title) {
    if(m_core.title() == title) return;
    m_core.setTitle(title);
    Q_EMIT titleChanged();
    Q_EMIT coreChanged();
}

QString InputBotInlineResultObject::title() const {
    return m_core.title();
}

void InputBotInlineResultObject::setType(const QString &type) {
    if(m_core.type() == type) return;
    m_core.setType(type);
    Q_EMIT typeChanged();
    Q_EMIT coreChanged();
}

QString InputBotInlineResultObject::type() const {
    return m_core.type();
}

void InputBotInlineResultObject::setUrl(const QString &url) {
    if(m_core.url() == url) return;
    m_core.setUrl(url);
    Q_EMIT urlChanged();
    Q_EMIT coreChanged();
}

QString InputBotInlineResultObject::url() const {
    return m_core.url();
}

void InputBotInlineResultObject::setW(qint32 w) {
    if(m_core.w() == w) return;
    m_core.setW(w);
    Q_EMIT wChanged();
    Q_EMIT coreChanged();
}

qint32 InputBotInlineResultObject::w() const {
    return m_core.w();
}

InputBotInlineResultObject &InputBotInlineResultObject::operator =(const InputBotInlineResult &b) {
    if(m_core == b) return *this;
    m_core = b;
    m_sendMessage->setCore(b.sendMessage());

    Q_EMIT contentTypeChanged();
    Q_EMIT contentUrlChanged();
    Q_EMIT descriptionChanged();
    Q_EMIT durationChanged();
    Q_EMIT flagsChanged();
    Q_EMIT hChanged();
    Q_EMIT idChanged();
    Q_EMIT sendMessageChanged();
    Q_EMIT thumbUrlChanged();
    Q_EMIT titleChanged();
    Q_EMIT typeChanged();
    Q_EMIT urlChanged();
    Q_EMIT wChanged();
    Q_EMIT coreChanged();
    return *this;
}

bool InputBotInlineResultObject::operator ==(const InputBotInlineResult &b) const {
    return m_core == b;
}

void InputBotInlineResultObject::setClassType(int classType) {
    InputBotInlineResult::InputBotInlineResultType result;
    switch(classType) {
    case TypeInputBotInlineResult:
        result = InputBotInlineResult::typeInputBotInlineResult;
        break;
    }

    if(m_core.classType() == result) return;
    m_core.setClassType(result);
    Q_EMIT classTypeChanged();
    Q_EMIT coreChanged();
}

int InputBotInlineResultObject::classType() const {
    int result;
    switch(static_cast<qint64>(m_core.classType())) {
    case InputBotInlineResult::typeInputBotInlineResult:
        result = TypeInputBotInlineResult;
        break;
    }

    return result;
}

void InputBotInlineResultObject::setCore(const InputBotInlineResult &core) {
    operator =(core);
}

InputBotInlineResult InputBotInlineResultObject::core() const {
    return m_core;
}

void InputBotInlineResultObject::coreSendMessageChanged() {
    if(m_core.sendMessage() == m_sendMessage->core()) return;
    m_core.setSendMessage(m_sendMessage->core());
    Q_EMIT sendMessageChanged();
    Q_EMIT coreChanged();
}
