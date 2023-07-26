#include "client.h"

QString Client::getInputMessage() const
{
    return inputMessage;
}

void Client::setInputMessage(const QString &newInputMessage)
{
    inputMessage = newInputMessage;
}

QString Client::getOutputMessage() const
{
    return outputMessage;
}

void Client::setOutputMessage(const QString &newOutputMessage)
{
    outputMessage = newOutputMessage;
}
Client::Client(QObject *parent)
    : QObject{parent}
{
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::connected, this, &Client::onConnected);
    connect(socket, &QTcpSocket::readyRead, this, &Client::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Client::onDisconnected);
}

Client *Client::getInstance()
{
    static Client instance;
    return &instance;
}

void Client::connectToServer(const QString &host, quint16 port)
{
    socket->connectToHost(host, port);
}

void Client::onConnected()
{
    qDebug() << "Connected to server!";
}

void Client::onReadyRead()
{
    QByteArray responseData = this->socket->readAll();
    // Process the responseData received from the server
    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);

    emit Finished(jsonDoc);
    //    emit Finished(QString::fromUtf8(responseData));
    //    this->outputMessage = QString::fromUtf8(responseData);
}

void Client::onDisconnected()
{
    qDebug() << "Disconnected from server!";
}


void Client::start() {
    socket->connectToHost(QHostAddress::LocalHost,8080);

    if(socket->waitForConnected())
        qDebug() << "Connect to server";
    else{
        qDebug() << QString("The following error occurred: %1.").arg(socket->errorString());
        exit(EXIT_FAILURE);
    }
}

void Client::sendRequest(QString strMsgToSend) {
    QByteArray data = strMsgToSend.toUtf8();
    QBuffer* buffer = new QBuffer(this);
    buffer->setData(data);
    buffer->open(QIODevice::ReadWrite);
    socket->write(buffer->data());
    socket->waitForBytesWritten();
}

void Client::getAllFile()
{
    FileClientMessage*fileMsg= new FileClientMessage();
    sendRequest(fileMsg->toString());
}

void Client::searchFile(QString fileName)
{
    FileClientMessage*fileMsg = new FileClientMessage(fileName);
    qDebug()<<"file request" << fileMsg->toString();
    sendRequest(fileMsg->toString());
}

void Client::uploadFile(QString fileName, QString filePath,quint64 userId)
{
    FileClientMessage*fileMsg = new FileClientMessage(fileName,filePath,userId);
    sendRequest(fileMsg->toString());
}

void Client::login(QString username, QString password,QString host, quint16 port) {
    LoginClientMessage* clientMsg = new LoginClientMessage(username, password,host,port);
    sendRequest(clientMsg->toString());
}

void Client::registers(QString username, QString password)
{
    RegisterClientMessage* clientMsg = new RegisterClientMessage(username, password);
    sendRequest(clientMsg->toString());
}

//void Client::logout(quint64 id, QString username) {
//    LogoutClientMessage* clientMsg = new LogoutClientMessage(id, username);
//    sendRequest((clientMsg->toString()));
//}

//void Client::registers(QString username, QString password) {

//}


