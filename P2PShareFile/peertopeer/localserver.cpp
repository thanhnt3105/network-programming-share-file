//#include "localserver.h"

//LocalServer::LocalServer(QObject *parent) :
//    QTcpServer(parent)
//{
//    this->myIp = QHostAddress::AnyIPv4;
//    this->myPort = 9001;
//}

//void LocalServer::setLocalServerInfo(QHostAddress &ip, int &port)
//{
//    this->myIp = ip;
//    this->myPort = port;
//}

//bool LocalServer::startServer()
//{
//    return this->listen(this->myIp, this->myPort);
//}

//void LocalServer::incomingConnection(qintptr socketDescriptor)
//{
//    LocalConnection *connection = new LocalConnection(this);
//    connection->setSocketDescriptor(socketDescriptor);
//    emit newLocalConnection(connection);
//}
