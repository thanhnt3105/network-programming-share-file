#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QBuffer>
#include <QIODevice>
#include <QByteArray>
#include <QJsonDocument>
#include <QtNetwork/QTcpSocket>
#include <QAbstractSocket>
#include <QHostAddress>
#include <QStandardPaths>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <message/auth/loginclientmessage.h>
#include <message/auth/registerclientmessage.h>
class Client : public QObject
{
    Q_OBJECT
private:
    QTcpSocket* socket;
    QString inputMessage;
    QString outputMessage;
public:
    explicit Client(QObject *parent = nullptr);
    static Client *getInstance();
    void connectToServer(const QString &host, quint16 port);

    QString getInputMessage() const;
    void setInputMessage(const QString &newInputMessage);

    QString getOutputMessage() const;
    void setOutputMessage(const QString &newOutputMessage);
public slots:
    void start();
    void onConnected();
    void onReadyRead();
    void onDisconnected();
    void login(QString username, QString password);
    void registers(QString username, QString password);
    void sendRequest(QString strMsgToSend);
//    void logout(quint64 id, QString username);
signals:
    void Finished(const QJsonDocument& response);
};

#endif // CLIENT_H
