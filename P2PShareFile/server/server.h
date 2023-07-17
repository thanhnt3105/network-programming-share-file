#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>

#include <server/requestprocessing.h>
#include <query/userquery.h>
#include <message/auth/loginservermessage.h>
#include <server/servercreatemessage.h>

class Server : public QObject
{
    Q_OBJECT

private:
    QTcpServer *server;
    QMap<quint64, QTcpSocket*> connectionSet;
//    ServerCreateMessage* serverCreateMessage;
    QHash<QTcpSocket*, ServerCreateMessage*> serverCreateMessageManager;
public:
    explicit Server(QObject *parent = nullptr);

    QMap<quint64, QTcpSocket *> getConnectionSet() const;
    void setConnectionSet(const QMap<quint64, QTcpSocket *> &newConnectionSet);
public slots:
    void start();
    void onNewConnection();
    void onReadyRead();
    void onDisconnected();

signals:

};

#endif // SERVER_H
