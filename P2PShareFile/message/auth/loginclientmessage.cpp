#include "loginclientmessage.h"

QString LoginClientMessage::getHost() const
{
    return host;
}

void LoginClientMessage::setHost(const QString &newHost)
{
    host = newHost;
}

quint16 LoginClientMessage::getPort() const
{
    return port;
}

void LoginClientMessage::setPort(quint16 newPort)
{
    port = newPort;
}

LoginClientMessage::LoginClientMessage(QObject *parent)
    : ClientMessage{parent}
{

}

LoginClientMessage::LoginClientMessage(QString input, QObject *parent) : ClientMessage(input, parent) {
    this->username = this->requestBody->getRequestBody().value("username").toString();
    this->password = this->requestBody->getRequestBody().value("password").toString();
}

LoginClientMessage::LoginClientMessage(QString username, QString password,QString host, quint16 port, QObject *parent) : ClientMessage(parent) {
    this->username = username;
    this->password = password;
    this->host = host;
    this->port = port;

    this->addCommandCode(command->toCommand("LOGIN"));
    this->requestBody->createLoginBody(username, password,host,port);

    this->finalizeMessageObject();
}


void LoginClientMessage::setUsername(QString username) {
    this->username = username;
}

void LoginClientMessage::setPassword(QString password) {
    this->password = password;
}

QString LoginClientMessage::getPassword() {
    return this->password;
}

QString LoginClientMessage::getUsername() {
    return this->username;
}

