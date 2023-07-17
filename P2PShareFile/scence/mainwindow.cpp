#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QObject>
#include <QMessageBox>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),currentUserLabel(nullptr)
{
    ui->setupUi(this);

//    UdpSender = new QUdpSocket(this);
//    UdpReader = new QUdpSocket(this);

//    UdpReader->bind(7171, QUdpSocket::ShareAddress); // 将UdpReader绑定到广播地址的7171端口，接收发到这个端口的信息
//    connect(UdpReader, SIGNAL(readyRead()), this, SLOT(readMessage()));//当有数据到达QUdpSocket时，发出readyRead()信号，触发readMessage()信号

//    loadSize = 4*1024;  //将整个大的文件分成很多小的部分进行发送，每部分为4字节
//    totalBytes = 0;
//    bytesWritten = 0;
//    bytesToWrite = 0;
//    bytesReceived = 0;
//    fileNameSize = 0;
//    tcpClient = new QTcpSocket(this);


//    connect(tcpClient, SIGNAL(connected()), this, SLOT(haveconnected()));// 当连接服务器成功时，发出connected()信号，自动调用haveconnected()函数


//    connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));// 绑定错误处理 连接失败时被调用

//    setKeyvalue(true,false,false,false);//批量设置按钮可用性


//    ui->hostLineEdit->setText("127.0.0.1");// 服务器的缺省值
//    ui->portLineEdit->setText("9628");

//    historyMessage = new QFile("historyMessage.txt");
//    if(!historyMessage->open(QFile::Append))
//    {
//        qDebug() << "写入历史文件错误";
//        return;
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Connect to the server
void MainWindow::connectServer()
{
//    loadSize = 4*1024;  //Divide the entire large file into many small parts for sending, each part is 4 bytes
//    totalBytes = 0;
//    bytesWritten = 0;
//    bytesToWrite = 0;
//    bytesReceived = 0;
//    fileNameSize = 0;
//    blockSize = 0; //初始化其为0
//    ui->currentStatusLabel->setText("Connecting");
//    // Connect to the server by port and host
//    tcpClient->connectToHost(ui->hostLineEdit->text(), ui->portLineEdit->text().toInt());
}

// Dialog prompt after connection
void MainWindow::haveconnected()
{
//    connect(tcpClient, SIGNAL(bytesWritten(qint64)), this, SLOT(updateClientProgress(qint64)));// When data is sent successfully, update the progress bar
//    connect(tcpClient, SIGNAL(readyRead()), this, SLOT(updateServerProgress()));// When data is received successfully, update the progress bar
//    connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));  // Binding Error Handling
//    setKeyvalue(false,true,true,false);//Batch settings button availability
//    ui->currentStatusLabel->setText("Waiting for file transfer");
}

// 打开文件
void MainWindow::openFile()
{
//    fileName = QFileDialog::getOpenFileName(this);
//    if(!fileName.isEmpty())
//    {
//        QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
//        ui->currentStatusLabel->setText(tr(u8"成功打开文件 %1").arg(currentFileName));
//        setKeyvalue(false,true,true,true);//批量设置按钮可用性
//    }
}

// 实现文件大小等信息的发送
void MainWindow::startTransferFile()
{
//    setKeyvalue(false,false,false,false);//批量设置按钮可用性
//    localFile = new QFile(fileName);
//    if(!localFile->open(QFile::ReadOnly))
//    {
//        qDebug() << "打开文件出错";
//        return;
//    }
//    totalBytes = localFile->size(); //文件总大小

//    QDataStream sendOut(&outBlock, QIODevice::WriteOnly);//将发送缓冲区outBlock封装在一个QDataStream类型的变量
//    sendOut.setVersion(QDataStream::Qt_5_0);
//    QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);//通过QString类的right()函数去掉文件的路径部分，仅将文件部分保存在currentFile变量中
//    sendOut << qint64(0) << qint64(0) << currentFileName;//文件头结构由三个字段组成，分别是64位的总长度(包括文件数据长度和文件头自身长度)，64位的文件名长度和文件名。

//    totalBytes += outBlock.size();//这里的总大小是文件名大小等信息和实际文件大小的总和
//    sendOut.device()->seek(0);//函数将读写操作指向从头开始
//    sendOut<<totalBytes<<qint64((outBlock.size() - sizeof(qint64)*2));//用实际的总长度大小信息和文件名长度信息代替两个qint64(0)空间
//    bytesToWrite = totalBytes - tcpClient->write(outBlock);//发送完头数据后剩余数据的大小
//    ui->currentStatusLabel->setText(tr(u8"正在发送%1").arg(currentFileName));
//    outBlock.resize(0);//清空发送缓冲区以备下次使用
}

// 更新进度条，实现文件的传送
void MainWindow::updateClientProgress(qint64 numBytes)
{
//    //已经发送数据的大小
//    bytesWritten += (int)numBytes;
//    if(bytesToWrite > 0) //如果已经发送了数据
//    {
//        //每次发送loadSize大小的数据，这里设置为4KB，如果剩余的数据不足4KB，就发送剩余数据的大小
//        outBlock = localFile->read(qMin(bytesToWrite, loadSize));

//        //发送完一次数据后还剩余数据的大小
//        bytesToWrite -= (int)tcpClient->write(outBlock);

//        //清空发送缓冲区
//        outBlock.resize(0);
//    }
//    else
//    {
//        //如果没有发送任何数据，则关闭文件
//        localFile->close();
//    }

//    //更新进度条
//    ui->clientProgressBar->setMaximum(totalBytes);
//    ui->clientProgressBar->setValue(bytesWritten);

//    if(bytesWritten == totalBytes) //发送完毕
//    {
//        QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
//        ui->currentStatusLabel->setText(tr(u8"成功发送文件%1 ...").arg(currentFileName));
//        setKeyvalue(false,true,true,false);//批量设置按钮可用性
//        outBlock.resize(0);
//        localFile->close();
//        bytesWritten = 0; // 为下次发送做准备
//        bytesToWrite = 0;
//        totalBytes = 0;

//    }
}


// 更新进度条，实现文件的接收
//从TCP数据流中接收前16个字节(两个qint64结构长)，用来确定总共需接收的字节数和文件名长度，并将这两个值保存在私有成员TotalBytes和fileNameSize中，然后根据fileNameSize值接收文件名。
void MainWindow::updateServerProgress()
{
//    QDataStream sendIn(tcpClient);
//    sendIn.setVersion(QDataStream::Qt_5_0);
//    if(bytesReceived <= sizeof(qint64)*2)  //如果接收到的数据小于等于16个字节，那么是刚开始接收数据，保存为头文件信息
//    {
//        //接收数据总大小信息和文件名大小信息
//        if((tcpClient->bytesAvailable() >= sizeof(qint64)*2) && (fileNameSize == 0))//确保至少有16字节的可用数据且文件名长度为0(表示未从TCP连接接收文件名长度字段，仍处于第一步操作)
//        {
//            sendIn >> totalBytes >> fileNameSize;//读取总共需接收的数据和文件名长度
//            bytesReceived += sizeof(qint64) * 2;
//        }

//        //接收文件名，并建立文件
//        if((tcpClient->bytesAvailable() >= fileNameSize) && (fileNameSize != 0))//确保连接上的数据已包含完整的文件名且文件名长度不为0(表示已从TCP连接接收文件名长度字段，处于第二步操作中)
//        {
//            sendIn >> fileName;
//            ui->currentStatusLabel->setText(tr(u8"正在接收文件 %1 ...").arg(fileName));
//            setKeyvalue(false,false,false,false);
//            bytesReceived += fileNameSize;

//            localFile = new QFile(fileName);
//            if(!localFile->open(QFile::WriteOnly))
//            {
//                qDebug() << "写入文件错误";
//                return;
//            }
//        }
//        else
//            return;

//    }

//    //如果接收的数据小于总数据，那么写入文件
//    if(bytesReceived < totalBytes)
//    {
//        bytesReceived += tcpClient->bytesAvailable();
//        inBlock = tcpClient->readAll();
//        localFile->write(inBlock);
//        inBlock.resize(0);
//    }

//    //更新进度条
//    ui->clientProgressBar->setMaximum(totalBytes);
//    ui->clientProgressBar->setValue(bytesReceived);

//    //接收数据完成时
//    if(bytesReceived == totalBytes)
//    {
//        localFile->close();
//        setKeyvalue(false,true,true,false);//批量设置按钮可用性
//        ui->currentStatusLabel->setText(tr(u8"成功接收文件 %1").arg(fileName));
//        bytesReceived = 0; // 为下次接收做准备
//        totalBytes = 0;
//        fileNameSize = 0;
//    }
}

// 显示错误
void MainWindow::displayError(QAbstractSocket::SocketError)
{
//    qDebug() << tcpClient->errorString();
//    tcpClient->close();
//    ui->clientProgressBar->reset();
//    ui->currentStatusLabel->setText(tr(u8"连接错误，请重试"));
//    setKeyvalue(true,false,false,false);//批量设置按钮可用性
//    loadSize = 4*1024;  //将整个大的文件分成很多小的部分进行发送，每部分为4字节
//    totalBytes = 0;//总文件大小
//    bytesWritten = 0;//已经写入的文件大小
//    bytesToWrite = 0;//要写入的文件
//    bytesReceived = 0;//已经收到的文件大小
//    fileNameSize = 0;//文件名的大小
//    outBlock.resize(0);
//    inBlock.resize(0);
//    //localFile->close();
}

// 建立会话连接
void MainWindow::on_connectButton_clicked()
{
//    connectServer();
//    setKeyvalue(false,true,false,false);//批量设置按钮可用性
}

// 断开连接
void MainWindow::on_disconnectButton_clicked()
{
//    tcpClient->disconnectFromHost();
//    tcpClient->close();
//    setKeyvalue(true,false,false,false);//批量设置按钮可用性
//    loadSize = 4*1024;  //将整个大的文件分成很多小的部分进行发送，每部分为4字节
//    totalBytes = 0;//总文件大小
//    bytesWritten = 0;//已经写入的文件大小
//    bytesToWrite = 0;//要写入的文件
//    bytesReceived = 0;//已经收到的文件大小
//    fileNameSize = 0;//文件名的大小
//    ui->clientProgressBar->reset();
//    outBlock.resize(0);
//    inBlock.resize(0);
    //localFile->close();
}
// 打开文件
void MainWindow::on_openButton_clicked()
{
    openFile();
}

// 发送文件
void MainWindow::on_sendFileButton_clicked()
{
    startTransferFile();
}

// 打开文件夹
void MainWindow::on_openFolderButton_clicked()
{
    QString path=QDir::currentPath();//获取程序当前目录
    path.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
    QProcess::startDetached("explorer "+path);//打开上面获取的目录
}

// 关闭程序

// 文字多了增加滚动条
void MainWindow::on_textBrowser_textChanged()
{
    ui->textBrowser->moveCursor(QTextCursor::End);
}
void MainWindow::setKeyvalue(bool connectKey, bool disconnectKey,bool openFileKey,bool sendFileKey)
{
    ui->connectButton->setEnabled(connectKey);
    ui->disconnectButton->setEnabled(disconnectKey);
    ui->openButton->setEnabled(openFileKey);
    ui->sendFileButton->setEnabled(sendFileKey);
}
