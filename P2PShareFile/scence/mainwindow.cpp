#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QObject>
#include <QMessageBox>
#include <QProcess>
#include <QJsonArray>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),currentUserLabel(nullptr),fileInfoDialog(nullptr)
{
    ui->setupUi(this);
    this->client = new Client();
    this->client->start();
    this->file = new File();
    QString user = "User: "+Session::getInstance()->getUsername();
    this->ui->currentUserLabel->setText(user);
}

MainWindow::MainWindow(QString host, quint16 port, QWidget *parent):QMainWindow(parent)
    , ui(new Ui::MainWindow),currentUserLabel(nullptr)
{
    timer = new QTimer();
    connect(this->timer,SIGNAL(timeout()), this, SLOT(updateFileList()));
    timer->start(10000);

    ui->setupUi(this);
    this->client = new Client();
    this->client->start();
    this->file = new File();
    QString user = "User: "+Session::getInstance()->getUsername();
    this->ui->currentUserLabel->setText(user);

    loadSize = 4*1024;  //将整个大的文件分成很多小的部分进行发送，每部分为4字节
    totalBytes = 0;//总文件大小
    bytesWritten = 0;//已经写入的文件大小
    bytesToWrite = 0;//要写入的文件
    bytesReceived = 0;//已经收到的文件大小
    fileNameSize = 0;//文件名的大小

    this->localServer = new LocalServer(this);

    QHostAddress ip = QHostAddress(host);
    this->localServer->setLocalServerInfo(ip,static_cast<int>(port));

    bool check =  this->localServer->startServer();
    qDebug() << "check" << check;
    connect(this->localServer, &QTcpServer::newConnection, this, &MainWindow::onNewConnection);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_searchButton_clicked()
{
    QString fileName = ui->fileNameLineEdit->text();
    this->client->searchFile(fileName);
    connect(client, &Client::Finished, this, &MainWindow::handleGetFileResponse);
}

void MainWindow::handleGetFileResponse(const QJsonDocument &response)
{
    qDebug() <<"response"<<response;
    QString errorMsg;
    QLayoutItem* child;
    while(this->ui->fileResultLayout->count()!=0)
    {
        child = this->ui->fileResultLayout->takeAt(0);
        if(child->widget() != 0)
        {
            delete child->widget();
        }
        delete child;
    }
    if (!response.isNull() && response.isObject()) {
        QJsonObject jsonObject = response.object();
        qDebug() << "data file: "<< jsonObject["command_code"].toString();
        if (jsonObject.contains("command_code") && jsonObject["command_code"].isString()) {
            if(jsonObject["command_code"].toString().compare("SEARCHFILE")!=0) return;
        }
        if (jsonObject.contains("error") && jsonObject["error"].isString()) {
            errorMsg = jsonObject["error"].toString();
        }
        if (jsonObject.contains("info") && jsonObject["info"].isString()) {
            QString infoString = jsonObject["info"].toString();
            QJsonObject infoObject = QJsonDocument::fromJson(infoString.toUtf8()).object();
            if(infoObject.contains("files")&& infoObject["files"].isArray()){
                QJsonArray fileArray = infoObject.value("files").toArray();
                for(int i=0;i < fileArray.size();++i){
                    QJsonObject fileDataObject = fileArray.at(i).toObject();
                    QString fileName = fileDataObject.value("file_name").toString();
                    QString filePath = fileDataObject.value("file_path").toString();
                    QString username = fileDataObject.value("username").toString();
                    QHostAddress address = QHostAddress(fileDataObject.value("host").toString());
                    int port =fileDataObject.value("post").toInt();
                    qDebug() << "HERE";
                    qDebug() << "file name -------" << fileName << filePath << username;
                    FileResult* fileResult = new FileResult(fileName, filePath,username,address,port);
                    qDebug() << "HERE 2";
                    this->ui->fileResultLayout->addWidget(fileResult);


                }
            }

        }
    }
    if(errorMsg.compare("file not found")==0) {
        QMessageBox::critical(nullptr, "Error", "Can not find your file");
    } else {

    }
}

void MainWindow::on_openButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Select File to Share");
    QFileInfo fileInfo(filePath);
    QString fileNameData = fileInfo.fileName();
    if (!filePath.isEmpty()) {
        QString text = QString("File location: %1\nFile name: %2").arg(filePath).arg(fileNameData);
        ui->textStatusBrowser->setText(text);
    }
    this->file->setFileName(fileNameData);
    this->file->setFilePath(filePath);
}


void MainWindow::on_uploadButton_clicked()
{
    this->client->uploadFile(this->file->getFileName(),this->file->getFilePath(),1);
    connect(client, &Client::Finished, this, &MainWindow::handleUploadResponse);
}

void MainWindow::handleUploadResponse(const QJsonDocument &response)
{
    qDebug() <<"response"<<response;
    QString errorMsg;
    if (!response.isNull() && response.isObject()) {
        QJsonObject jsonObject = response.object();
        qDebug() << "data file: "<< jsonObject["command_code"].toString();
        if (jsonObject.contains("command_code") && jsonObject["command_code"].isString()) {
            if(jsonObject["command_code"].toString().compare("UPLOADFILE")!=0) return;
        }
        if (jsonObject.contains("error") && jsonObject["error"].isString()) {
            errorMsg = jsonObject["error"].toString();
        }
        if (jsonObject.contains("info") && jsonObject["info"].isString()) {
            QString infoString = jsonObject["info"].toString();
            QJsonObject infoObject = QJsonDocument::fromJson(infoString.toUtf8()).object();
        }
    }
    if(errorMsg.compare("file not found")==0) {
        QMessageBox::critical(nullptr, "Error", "Can not find your file");
    } else {
        QMessageBox::critical(nullptr, "Success", "Upload file successfully");
    }
}

void MainWindow::handleGetOwnFileResponse(const QJsonDocument &response)
{
    qDebug() <<"response"<<response;
    QString errorMsg;
    QJsonArray fileArrayData;
    if (!response.isNull() && response.isObject()) {
        QJsonObject jsonObject = response.object();
        if (jsonObject.contains("command_code") && jsonObject["command_code"].isString()) {
            if(jsonObject["command_code"].toString().compare("GETFILEBYUSERID")!=0) return;
        }
        if (jsonObject.contains("error") && jsonObject["error"].isString()) {
            errorMsg = jsonObject["error"].toString();
        }
        if (jsonObject.contains("info") && jsonObject["info"].isString()) {
            QString infoString = jsonObject["info"].toString();
            QJsonObject infoObject = QJsonDocument::fromJson(infoString.toUtf8()).object();
            if(infoObject.contains("files")&& infoObject["files"].isArray()){
                QJsonArray fileArray = infoObject.value("files").toArray();
                fileArrayData=fileArray;
            }
        }
    }
    if(errorMsg.compare("cannot find your files")==0) {
        QMessageBox::critical(nullptr, "Error", "Can not find your files");
    }else{
        qDebug() << "fileArrayData size:" << fileArrayData.size();
        fileInfoDialog = new FileInfoDialog(fileArrayData);
        fileInfoDialog->show();
    }
}

void MainWindow::openFile()
{
    fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
    }
}

void MainWindow::onNewConnection() {

    this->tcpSocket = new QTcpSocket();

    tcpSocket = this->localServer->nextPendingConnection();

    // 当有数据发送成功时，更新进度条并继续发送
    connect(tcpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(updateClientProgress(qint64)));//通过槽函数传递参数

    // 当有数据接收成功时，更新进度条并继续接收
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(updateServerProgress()));

    // 绑定错误处理
    connect(tcpSocket, SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
}

void MainWindow::onReadyRead() {
}

void MainWindow::onDisconnected() {

    qDebug() << "Client disconnected!";
}

void MainWindow::startTransferFile()
{
    localFile = new QFile(fileName);
    if(!localFile->open(QFile::ReadOnly))
    {
        qDebug() << "打开文件出错";
        return;
    }
    totalBytes = localFile->size(); //文件实际总大小

    QDataStream sendOut(&outBlock, QIODevice::WriteOnly);//将发送缓冲区outBlock封装在一个QDataStream类型的变量
    sendOut.setVersion(QDataStream::Qt_5_0);
    QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);//通过QString类的right()函数去掉文件的路径部分，仅将文件部分保存在currentFile变量中
    sendOut << qint64(0) << qint64(0) << currentFileName;//文件头结构由三个字段组成，分别是64位的总长度(包括文件数据长度和文件头自身长度)，64位的文件名长度和文件名。

    totalBytes += outBlock.size();//这里的总大小是文件名大小等信息和实际文件大小的总和
    sendOut.device()->seek(0);//函数将读写操作指向从头开始
    sendOut<<totalBytes<<qint64((outBlock.size() - sizeof(qint64)*2));//用实际的总长度大小信息和文件名长度信息代替两个qint64(0)空间
    bytesToWrite = totalBytes - tcpSocket->write(outBlock);//发送完头数据后剩余数据的大小
    outBlock.resize(0);//清空发送缓冲区以备下次使用
}

void MainWindow::updateClientProgress(qint64 numBytes)
{
    //已经发送数据的大小
    bytesWritten += (int)numBytes;
    if(bytesToWrite > 0) //如果已经发送了数据
    {
        outBlock = localFile->read(qMin(bytesToWrite, loadSize));//每次发送loadSize大小的数据，这里设置为4KB，如果剩余的数据不足4KB，就发送剩余数据的大小
        bytesToWrite -= (int)tcpSocket->write(outBlock);//发送完一次数据后还剩余数据的大小

        //清空发送缓冲区
        outBlock.resize(0);
    }
    else
    {
        //如果没有发送任何数据，则关闭文件
        localFile->close();
    }

    if(bytesWritten == totalBytes) //发送完毕
    {
        QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
        outBlock.resize(0);
        localFile->close();
        bytesWritten = 0; // 为下次发送做准备
        bytesToWrite = 0;
        totalBytes = 0;
    }
}

void MainWindow::updateServerProgress()
{

    if (this->tcpSocket)
    {
        // Read and process data from the client
        QByteArray requestData = this->tcpSocket->readAll();
        // Process the requestData as needed
        QJsonDocument jsonDoc = QJsonDocument::fromJson(requestData);
        QString msg;
        QString username;
        QString filePath;
        QString type;

        // Kiểm tra xem dữ liệu có đúng định dạng JSON không
        if (!jsonDoc.isNull() && jsonDoc.isObject()) {
            // Chuyển đổi QJsonDocument thành QJsonObject
            QJsonObject jsonObject = jsonDoc.object();

            // Lấy giá trị của key "username" va password từ QJsonObject "infoObject"
            if (jsonObject.contains("username") && jsonObject["username"].isString()) {
                username = jsonObject["username"].toString();
            }
            if (jsonObject.contains("filePath") && jsonObject["filePath"].isString()) {
                filePath = jsonObject["filePath"].toString();
            }
            if (jsonObject.contains("type") && jsonObject["type"].isString()) {
                type = jsonObject["type"].toString();
            }
            QString message = tr("User %1 wants to download your file at '%2'.\nDo you want to share your file?")
                                  .arg(username)
                                  .arg(filePath);

            int ret = QMessageBox::warning(this, tr("Notification"), message, QMessageBox::Yes | QMessageBox::Cancel);

            if(ret == QMessageBox::Yes){
                this->fileName = filePath;
                startTransferFile();
            }

        }
    }

}

void MainWindow::displayError(QAbstractSocket::SocketError)
{
    qDebug() << tcpSocket->errorString();
    tcpSocket->close();
    loadSize = 4*1024;  //将整个大的文件分成很多小的部分进行发送，每部分为4字节
    totalBytes = 0;//总文件大小
    bytesWritten = 0;//已经写入的文件大小
    bytesToWrite = 0;//要写入的文件
    bytesReceived = 0;//已经收到的文件大小
    fileNameSize = 0;//文件名的大小
    outBlock.resize(0);
    inBlock.resize(0);
    //    localFile->close();
}

void MainWindow::updateFileList()
{
//    this->client->
}


//void MainWindow::on_myFilePushButton_clicked()
//{

//}


void MainWindow::on_myFilePushButton_clicked()
{
        qDebug()<<"Session::getInstance()->getUserId()"<<Session::getInstance()->getUserId();
        this->client->getFileByUserId(Session::getInstance()->getUserId());
        connect(client, &Client::Finished, this, &MainWindow::handleGetOwnFileResponse);
}

