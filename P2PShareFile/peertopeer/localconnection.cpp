#include "localconnection.h"

static const int TransferTimeout = 30 * 1000;
static const char SeparatorToken = ' ';


LocalConnection::LocalConnection(QObject *parent) :
    QTcpSocket(parent)
{
    this->greetingMessage = QObject::tr("undefined");
    this->userName = QObject::tr("unknown");
    this->state = WaitingForGreeting;
    this->currentDataType = UNDEFINED;
    this->numBytesForCurrentDataType = -1;
    this->transferTimerId = 0;
    this->isGreetingMessageSent = false;

    connect(this, SIGNAL(readyRead()), this, SLOT(processReadyRead()));
    connect(this, SIGNAL(connected()), this, SLOT(sendGreetingMessage()));
    connect(this, SIGNAL(disconnected()), this, SLOT(handleDisconnected()));
    connect(this, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(handleSocketError(QAbstractSocket::SocketError)));

}


QString LocalConnection::getPeerName()
{
    return this->userName;
}


QString LocalConnection::getPeerIP()
{
    return this->ip.toString();
}


int LocalConnection::getPeerPort()
{
    return this->port;
}

void LocalConnection::handleSocketError(QAbstractSocket::SocketError error)
{
    emit this->socketError(this, error);
}

void LocalConnection::handleDisconnected()
{
    emit this->disconnectedLocal(this);
}


void LocalConnection::setGreetingMessage(QString greet)
{
    this->greetingMessage = greet;
}


void LocalConnection::timerEvent(QTimerEvent *timerEvent)
{
//    if(timerEvent->timerId() == this->transferTimerId)
//    {
//        this->abort();
//        this->killTimer(transferTimerId);
//        transferTimerId = 0;
//    }
}


bool LocalConnection::sendMessage(const QString message)
{
    if(message.isEmpty())
        return false;

    QByteArray msg = message.toUtf8();
    QByteArray data = "MESSAGE " + QByteArray::number(msg.size()) + ' ' + msg;
    return this->write(data) == data.size();
}


void LocalConnection::sendGreetingMessage()
{
    QByteArray greeting = this->greetingMessage.toUtf8();
    QByteArray data = "GREETING " + QByteArray::number(greeting.size()) + ' ' + greeting;
    if( this->write(data) == data.size() )
        isGreetingMessageSent = true;
}


int LocalConnection::readDataIntoBuffer(int maxSize)
{
//    if(maxSize > MaxBufferSize)
//        return 0;

//    int numBytesBeforeRead = this->buffer.size();

//    if(numBytesBeforeRead == MaxBufferSize)
//    {
//        this->abort();
//        return 0;
//    }

//    while(bytesAvailable() > 0 && buffer.size() < maxSize)
//    {
//        buffer.append(this->read(1));
//        if(buffer.endsWith(SeparatorToken))
//            break;
//    }

//    return buffer.size() - numBytesBeforeRead;
}


int LocalConnection::dataLengthForCurrentDataType()
{
//    if(this->bytesAvailable() <= 0 || readDataIntoBuffer(MaxBufferSize) <= 0 || !buffer.endsWith(SeparatorToken))
//        return 0;

//    this->buffer.chop(1);
//    int length = buffer.toInt();
//    this->buffer.clear();
//    return length;
}


bool LocalConnection::readProtocolHeader()
{
    if(this->transferTimerId != 0)
    {
        this->killTimer(this->transferTimerId);
        this->transferTimerId = 0;
    }

    if(this->readDataIntoBuffer() <= 0)
    {
        this->transferTimerId = this->startTimer(TransferTimeout);
        return false;
    }

    if(buffer == "MESSAGE ")
        this->currentDataType = MESSAGE;
    else if(buffer == "GREETING ")
        this->currentDataType = GREETING;
    else
    {
        this->currentDataType = UNDEFINED;
        this->abort();
        return false;
    }

    buffer.clear();
    this->numBytesForCurrentDataType = this->dataLengthForCurrentDataType();
    return true;
}

bool LocalConnection::hasEnoughData()
{
    if(this->transferTimerId)
    {
        this->killTimer(transferTimerId);
        transferTimerId = 0;
    }

    if (numBytesForCurrentDataType <= 0)
        numBytesForCurrentDataType = this->dataLengthForCurrentDataType();

    if (bytesAvailable() < numBytesForCurrentDataType
        || numBytesForCurrentDataType <= 0)
    {
        this->transferTimerId = this->startTimer(TransferTimeout);
        return false;
    }

    return true;
}


void LocalConnection::processReadyRead()
{
    if(this->state == WaitingForGreeting)
    {
        if(!this->readProtocolHeader())
            return;
        if(this->currentDataType != GREETING)
        {
            this->abort();
            return;
        }
        this->state = ReadingGreeting;
    }

    if(this->state == ReadingGreeting)
    {
        if(!this->hasEnoughData())
            return;

        this->buffer = read(this->numBytesForCurrentDataType);
        if(buffer.size() != this->numBytesForCurrentDataType)
        {
            this->abort();
            return;
        }

        QString greeting = QString::fromUtf8(this->buffer);

        qDebug() << "Get greeting message: " << greeting;

        QStringList addrList = greeting.split(":");
        this->userName = addrList.at(0);
        QString ipStr = addrList.at(1);
        QString portStr = addrList.at(2);
        this->ip = QHostAddress(ipStr);
        this->port = portStr.toInt();

        this->currentDataType = UNDEFINED;
        this->numBytesForCurrentDataType = 0;
        this->buffer.clear();

        if(!this->isValid())
        {
            this->abort();
            return;
        }

        if(!this->isGreetingMessageSent)
            this->sendGreetingMessage();

        this->state = ReadyForUse;
        emit this->endGreeting(this);
    }

    do
    {
        if(this->currentDataType == UNDEFINED)
        {
            if(!readProtocolHeader())
                return;
        }
        if(!this->hasEnoughData())
            return;
        this->processData();
    }while(this->bytesAvailable() > 0);
}


void LocalConnection::processData()
{
    this->buffer = this->read(this->numBytesForCurrentDataType);
    if(buffer.size() != this->numBytesForCurrentDataType)
    {
        this->abort();
        return;
    }

    switch (currentDataType) {
    case MESSAGE:
        emit newMessage(this->userName, QString::fromUtf8(buffer));
        break;
    default:
        break;
    }

    this->currentDataType = UNDEFINED;
    this->numBytesForCurrentDataType = -1;
    this->buffer.clear();
}

