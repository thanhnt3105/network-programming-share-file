#ifndef REQUESTPROCESSING_H
#define REQUESTPROCESSING_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDateTime>
#include <QList>
#include <QThread>
#include <QNetworkInterface>

#include <controller/logincontroller.h>
#include <controller/registercontroller.h>

class RequestProcessing : public QObject
{
    Q_OBJECT
private:
    QJsonObject message;
    User* user;
    QString ouputMsg;
    QList<User*> users;
    QList<QString> usernames;
public:
    explicit RequestProcessing(QObject *parent = nullptr);

    QJsonObject getMessage() const;
    void setMessage(const QJsonObject &newMessage);

    User *getUser() const;
    void setUser(User *newUser);

    QString getOuputMsg() const;
    void setOuputMsg(const QString &newOuputMsg);

    QList<User *> getUsers() const;
    void setUsers(const QList<User *> &newUsers);

    QList<QString> getUsernames() const;
    void setUsernames(const QList<QString> &newUsernames);

public slots:
    QString handle();
    QString login();
    QString registers();

signals:

};

#endif // REQUESTPROCESSING_H
