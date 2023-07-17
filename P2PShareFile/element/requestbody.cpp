#include "requestbody.h"

RequestBody::RequestBody(QObject *parent)
    : QObject{parent}
{

}

QJsonObject RequestBody::getRequestBody() {
    return this->requestBody;
}

void RequestBody::setRequestBody(QJsonObject body) {
    this->requestBody = body;
}

void RequestBody::createLoginBody(QString username, QString password) {
    this->requestBody = QJsonObject();

    this->requestBody.insert("username", username);
    this->requestBody.insert("password", password);
}

void RequestBody::createLogoutBody(quint64 id, QString username) {
    this->requestBody = QJsonObject();

    this->requestBody.insert("id", QString::number(id));
    this->requestBody.insert("username", username);
}

void RequestBody::createRegisterBody(QString username, QString password) {
    this->requestBody = QJsonObject();

    this->requestBody.insert("username", username);
    this->requestBody.insert("password", password);
}

void RequestBody::createUploadFileBody(QString fileName,QString filePath)
{
    this->requestBody = QJsonObject();

    this->requestBody.insert("fileName",fileName);
    this->requestBody.insert("filePath",filePath);
}

void RequestBody::createSearchFileBody(QString fileName)
{
    this->requestBody = QJsonObject();

    this->requestBody.insert("fileName",fileName);
}
