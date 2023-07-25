
#include "server.h"

QMap<quint64, QTcpSocket *> Server::getConnectionSet() const
{
    return connectionSet;
}

void Server::setConnectionSet(const QMap<quint64, QTcpSocket *> &newConnectionSet)
{
    connectionSet = newConnectionSet;
}

Server::Server(QObject *parent)
    : QObject{parent}
{
    this->server = new QTcpServer(this);
//    this->serverCreateMessage = new ServerCreateMessage();
    connect(server, &QTcpServer::newConnection, this, &Server::onNewConnection);

}

void Server::start() {
    if(this->server->listen(QHostAddress::Any, 8080))
    {
        connect(this->server, &QTcpServer::newConnection, this, &Server::onNewConnection);
        qDebug() << ("Server is listening...");
    }
    else
    {
        qDebug() << QString("Unable to start the server: %1.").arg(this->server->errorString());
        exit(EXIT_FAILURE);
    }
}

void Server::onNewConnection() {
    QTcpSocket *clientSocket = this->server->nextPendingConnection();

    ServerCreateMessage* serverCreateMessage = new ServerCreateMessage();
    this->serverCreateMessageManager.insert(clientSocket, serverCreateMessage);

    // Handle the new client connection asynchronously
    connect(clientSocket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &Server::onDisconnected);

    // Add the client socket to a list or data structure for managing multiple clients
    //    this->connectionSet.append(clientSocket);

    QHostAddress clientAddress = clientSocket->peerAddress();
    quint16 clientPort = clientSocket->peerPort();

    qDebug() << "New connection from host:" << clientAddress.toString() << "port:" << clientPort;

    qDebug() << "New client connected!";
}

void Server::onReadyRead() {
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    ServerCreateMessage* serverCreateMessage = this->serverCreateMessageManager.value(clientSocket);
    QString responseString;

    if (clientSocket)
    {
        // Read and process data from the client
        QByteArray requestData = clientSocket->readAll();
        // Process the requestData as needed
        QJsonDocument jsonDoc = QJsonDocument::fromJson(requestData);
        QString msg;


        qDebug() << "server core client: " << clientSocket;
        // Kiểm tra xem dữ liệu có đúng định dạng JSON không
        if (!jsonDoc.isNull() && jsonDoc.isObject()) {
            // Chuyển đổi QJsonDocument thành QJsonObject
            QJsonObject jsonObject = jsonDoc.object();
            serverCreateMessage->getRequestProcessing()->setMessage(jsonObject);
            msg = serverCreateMessage->getRequestProcessing()->handle();
            responseString = serverCreateMessage->createMessage(msg);

            if(msg.compare("login successfully")==0) {
                connectionSet.insert(serverCreateMessage->getRequestProcessing()->getUser()->getId(), clientSocket);
            }
        }

        qDebug() << "Server receive:" << msg;

//        if(msg.contains("requestjoin")) {
//            quint64 ownerId;
//            QStringList parts = msg.split(" ");
//            if (parts.size() == 2) {
//                QString ownerIdStr = parts[1];
//                ownerId = ownerIdStr.toInt();
//            } else {
//                qDebug() << "Invalid string format";
//            }
//            QByteArray responseData = responseString.toUtf8();
//            qDebug() << "server core owner: " << ownerId;
//            qDebug() << "server core keys: " << connectionSet.keys();
//            connectionSet.value(ownerId)->write(responseData);
//        }
        if(msg.compare("save file successfully")==0) {
            qDebug() <<"Send to client" << responseString;
        }

//        else if(msg.compare("afk")==0) {
//            Room* room = serverCreateMessage->getRequestProcessing()->getRoom();
//            QList<User*> users = room->getUserAndPoint().keys();
//            for(User* user : users) {
//                this->serverCreateMessageManager.value(connectionSet.value(user->getId()))->getRequestProcessing()->removeUser(serverCreateMessage->getRequestProcessing()->getUser());
//            }
//            serverCreateMessage->getRequestProcessing()->afkGame();
//            //            clientSocket->write(responseString.toUtf8());
//        }

        else {
//            if(msg.compare("finish")==0) {
//                QList<User*> users = serverCreateMessage->getRequestProcessing()->getRoom()->getUserAndPoint().keys();
//                QString content = serverCreateMessage->getRequestProcessing()->extractLogFile();
//                for(User* user : users) {
//                    QTcpSocket* tcpSocket = connectionSet.value(user->getId());
//                    // Lấy địa chỉ IP từ QTcpSocket
//                    QHostAddress ipAddress = tcpSocket->peerAddress();
//                    // Chuyển địa chỉ IP thành chuỗi
//                    QString ipString = ipAddress.toString();
//                    content = content + ipString + "\n";
//                }
//                serverCreateMessage->getRequestProcessing()->writeLog(content);
//                serverCreateMessage->getRequestProcessing()->setRoom(nullptr);
//            }

            QByteArray responseData = responseString.toUtf8();
            // Send response back to the client
            clientSocket->write(responseData);
        }
    }
}

void Server::onDisconnected() {
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (clientSocket)
    {
        // Remove the client socket from the list or data structure
        //        connectionSet.removeOne(clientSocket);
        //        connectionSet.remove(2);
        auto it = connectionSet.begin();
        while (it != connectionSet.end()) {
            if (it.value() == clientSocket) {
                it = connectionSet.erase(it);
            } else {
                ++it;
            }
        }

        // Clean up the socket
        clientSocket->deleteLater();

        qDebug() << "Client disconnected!";
    }
}
