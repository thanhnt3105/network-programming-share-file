#ifndef LOCALCONNECTION_H
#define LOCALCONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QBuffer>
class LocalConnection : public QTcpSocket
{
    Q_OBJECT
public:
    explicit LocalConnection(QObject *parent = 0);

    enum LocalConnectionState{
        WaitingForGreeting,
        ReadingGreeting,
        ReadyForUse
    };

    enum DataType{
        MESSAGE,
        GREETING,
        UNDEFINED
    };

    QString getPeerName();
    QString getPeerIP();
    int getPeerPort();
    void setGreetingMessage(QString message);
    bool sendMessage(QString message);

signals:
    void endGreeting(LocalConnection *);
    void newMessage(QString from, QString message);
    void disconnectedLocal(LocalConnection *);
    void socketError(LocalConnection *, QAbstractSocket::SocketError);

protected:
    void timerEvent(QTimerEvent *);

private slots:
    void processReadyRead();
    void sendGreetingMessage();
    void handleDisconnected();
    void handleSocketError(QAbstractSocket::SocketError);

private:
    int readDataIntoBuffer(int maxSize = 1024);
    int dataLengthForCurrentDataType();
    bool readProtocolHeader();
    bool hasEnoughData();
    void processData();

    QString userName;
    QHostAddress ip;
    int port;
    QString greetingMessage;
    QByteArray buffer;
    enum LocalConnectionState state;
    enum DataType currentDataType;
    int numBytesForCurrentDataType;
    int transferTimerId;
    bool isGreetingMessageSent;
};

#endif // LOCALCONNECTION_H
