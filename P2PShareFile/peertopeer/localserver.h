#ifndef LOCALSERVER_H
#define LOCALSERVER_H

#include <peertopeer/localconnection.h>
#include <QObject>
#include <QTcpServer>
#include <QMessageBox>

class LocalServer : public QTcpServer
{
    Q_OBJECT

private:
    QHostAddress myIp;
    int myPort;

public:
    explicit LocalServer(QObject *parent = 0);

    void setLocalServerInfo(QHostAddress &ip, int port);
    bool startServer();

signals:
    void newLocalConnection(LocalConnection *connection);

protected:
    void incomingConnection(qintptr socketDescriptor);


};

#endif // LOCALSERVER_H
