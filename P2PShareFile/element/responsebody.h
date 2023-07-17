#ifndef RESPONSEBODY_H
#define RESPONSEBODY_H

#include <QObject>
#include <QJsonObject>
#include <QList>
#include <QJsonArray>
#include <QStringList>

class ResponseBody : public QObject
{
    Q_OBJECT
private:
    QJsonObject responseBody;
public:
    explicit ResponseBody(QObject *parent = nullptr);
public slots:
    void setResponseBody(QJsonObject responseBody);
    QJsonObject getResponseBody();
    void createLoginBody(quint64 id, QString username);
    void createLogoutBody(quint64 id, QString username);
    void createRegisterBody(QString username,QString password);

signals:

};

#endif // RESPONSEBODY_H
