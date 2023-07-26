#include "fileresult.h"
#include "ui_fileresult.h"

QString FileResult::getFileName() const
{
    return fileName;
}

void FileResult::setFileName(const QString &newFileName)
{
    fileName = newFileName;
}

QString FileResult::getFilePath() const
{
    return filePath;
}

void FileResult::setFilePath(const QString &newFilePath)
{
    filePath = newFilePath;
}

QString FileResult::getUser() const
{
    return user;
}

void FileResult::setUser(const QString &newUser)
{
    user = newUser;
}


int FileResult::getPort() const
{
    return port;
}

void FileResult::setPort(int newPort)
{
    port = newPort;
}

QHostAddress FileResult::getHost() const
{
    return host;
}

void FileResult::setHost(const QHostAddress &newHost)
{
    host = newHost;
}

void FileResult::connectServer()
{
    loadSize = 4*1024;  //将整个大的文件分成很多小的部分进行发送，每部分为4字节
    totalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    blockSize = 0; //初始化其为0
    // 连接服务器
    qDebug() <<"port and host" << port << host;
    tcpClient->connectToHost(this->host, this->port); //连接
}

void FileResult::haveconnected()
{
    QJsonObject data = QJsonObject();
    data.insert("filePath",this->getFilePath());
    data.insert("username",this->getUser());
    data.insert("type","GREETING");

    QJsonDocument jsonDocument(data);
    QString dataString = jsonDocument.toJson(QJsonDocument::Compact);

    QByteArray dataSent = dataString.toUtf8();
    QBuffer* buffer = new QBuffer(this);
    buffer->setData(dataSent);
    buffer->open(QIODevice::ReadWrite);
    this->tcpClient->write(buffer->data());
    this->tcpClient->waitForBytesWritten();

    connect(tcpClient, SIGNAL(bytesWritten(qint64)), this, SLOT(updateClientProgress(qint64)));// 当有数据发送成功时，更新进度条


    connect(tcpClient, SIGNAL(readyRead()), this, SLOT(updateServerProgress()));// 当有数据接收成功时，更新进度条

    connect(tcpClient, SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));  // 绑定错误处理
}

void FileResult::displayError(QAbstractSocket::SocketError)
{
    qDebug() << "ERROR";
}

void FileResult::startTransferFile()
{
    localFile = new QFile(fileName);
    if(!localFile->open(QFile::ReadOnly))
    {
        qDebug() << "打开文件出错";
        return;
    }
    totalBytes = localFile->size(); //文件总大小

    QDataStream sendOut(&outBlock, QIODevice::WriteOnly);//将发送缓冲区outBlock封装在一个QDataStream类型的变量
    sendOut.setVersion(QDataStream::Qt_5_0);
    QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);//通过QString类的right()函数去掉文件的路径部分，仅将文件部分保存在currentFile变量中
    sendOut << qint64(0) << qint64(0) << currentFileName;//文件头结构由三个字段组成，分别是64位的总长度(包括文件数据长度和文件头自身长度)，64位的文件名长度和文件名。

    totalBytes += outBlock.size();//这里的总大小是文件名大小等信息和实际文件大小的总和
    sendOut.device()->seek(0);//函数将读写操作指向从头开始
    sendOut<<totalBytes<<qint64((outBlock.size() - sizeof(qint64)*2));//用实际的总长度大小信息和文件名长度信息代替两个qint64(0)空间
    bytesToWrite = totalBytes - tcpClient->write(outBlock);//发送完头数据后剩余数据的大小
    outBlock.resize(0);//清空发送缓冲区以备下次使用
}

void FileResult::updateClientProgress(qint64 numBytes)
{
    //已经发送数据的大小
    bytesWritten += (int)numBytes;
    if(bytesToWrite > 0) //如果已经发送了数据
    {
        //每次发送loadSize大小的数据，这里设置为4KB，如果剩余的数据不足4KB，就发送剩余数据的大小
        outBlock = localFile->read(qMin(bytesToWrite, loadSize));

        //发送完一次数据后还剩余数据的大小
        bytesToWrite -= (int)tcpClient->write(outBlock);

        //清空发送缓冲区
        outBlock.resize(0);
    }
    else
    {
        //如果没有发送任何数据，则关闭文件
        qDebug() <<"Done 111" ;
        localFile->close();


    }

    if(bytesWritten == totalBytes) //发送完毕
    {
        this->tcpClient->close();
        QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
        outBlock.resize(0);
        localFile->close();
        bytesWritten = 0; // 为下次发送做准备
        bytesToWrite = 0;
        totalBytes = 0;
    }
}

void FileResult::updateServerProgress()
{
    QDataStream sendIn(tcpClient);
    sendIn.setVersion(QDataStream::Qt_5_0);
    if(bytesReceived <= sizeof(qint64)*2)  //如果接收到的数据小于等于16个字节，那么是刚开始接收数据，保存为头文件信息
    {
        //接收数据总大小信息和文件名大小信息
        if((tcpClient->bytesAvailable() >= sizeof(qint64)*2) && (fileNameSize == 0))//确保至少有16字节的可用数据且文件名长度为0(表示未从TCP连接接收文件名长度字段，仍处于第一步操作)
        {
            sendIn >> totalBytes >> fileNameSize;//读取总共需接收的数据和文件名长度
            bytesReceived += sizeof(qint64) * 2;
        }

        //接收文件名，并建立文件
        if((tcpClient->bytesAvailable() >= fileNameSize) && (fileNameSize != 0))//确保连接上的数据已包含完整的文件名且文件名长度不为0(表示已从TCP连接接收文件名长度字段，处于第二步操作中)
        {
            sendIn >> fileName;
            bytesReceived += fileNameSize;

            localFile = new QFile(fileName);
            if(!localFile->open(QFile::WriteOnly))
            {
                qDebug() << "写入文件错误";
                return;
            }
        }
        else
            return;

    }

    //如果接收的数据小于总数据，那么写入文件
    if(bytesReceived < totalBytes)
    {
        bytesReceived += tcpClient->bytesAvailable();
        inBlock = tcpClient->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }

    //接收数据完成时
    if(bytesReceived == totalBytes)
    {
        localFile->close();
        bytesReceived = 0; // 为下次接收做准备
        totalBytes = 0;
        fileNameSize = 0;
    }
}

FileResult::FileResult(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileResult)
{
    ui->setupUi(this);

    loadSize = 4*1024;  //将整个大的文件分成很多小的部分进行发送，每部分为4字节
    totalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    this->tcpClient = new QTcpSocket(this);

    connect(tcpClient, SIGNAL(connected()), this, SLOT(haveconnected()));// 当连接服务器成功时，发出connected()信号，自动调用haveconnected()函数


    connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));// 绑定错误处理 连接失败时被调用

}

FileResult::FileResult(QString fileName, QString filePath, QString user, QHostAddress host, int port, QWidget *parent):    QWidget(parent),
    ui(new Ui::FileResult)
{
    this->tcpClient = new QTcpSocket(this);
    this->setFileName(fileName);
    this->setFilePath(filePath);
    this->setUser(user);
    this->setHost(host);
    this->setPort(port);

    ui->setupUi(this);
    this->ui->fileName->setText(fileName);
    this->ui->owner->setText(user);

    loadSize = 4*1024;  //将整个大的文件分成很多小的部分进行发送，每部分为4字节
    totalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;
    bytesReceived = 0;
    fileNameSize = 0;

    connect(tcpClient, SIGNAL(connected()), this, SLOT(haveconnected()));// 当连接服务器成功时，发出connected()信号，自动调用haveconnected()函数
    connect(tcpClient, SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
}

FileResult::~FileResult()
{
    delete ui;
}

void FileResult::on_pushButton_clicked()
{
    this->connectServer();
}

