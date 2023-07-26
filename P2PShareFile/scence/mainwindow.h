#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QFile>
#include <QDebug>
#include <QLabel>
#include <client/client.h>
#include <entity/user.h>
#include <entity/file.h>
#include <QVBoxLayout>
#include <scence/fileresult.h>
#include <QVector>
#include <session/session.h>
#include <peertopeer/localserver.h>
#include <server/servercreatemessage.h>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    File*file;
    FileResult * fileResult;
    LocalServer* localServer;
    QTimer* timer;

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(QString host,quint16 port, QWidget *parent = nullptr);
    ~MainWindow();

    Client *getClientCore() const;
    void setClientCore(Client *newClientCore);



private slots:

    void on_searchButton_clicked();

    void handleGetFileResponse(const QJsonDocument &response);

    void on_openButton_clicked();

    void on_uploadButton_clicked();

    void handleUploadResponse(const QJsonDocument& response);
    void onReadyRead();
    void onDisconnected();
    void onNewConnection();
    void displayError(QAbstractSocket::SocketError); //显示错误
    void updateFileList();

    void openFile();  //打开文件
    void startTransferFile();  //发送文件大小等信息
    void updateClientProgress(qint64); //发送数据，更新进度条

    void updateServerProgress(); //接收数据，更新进度条

private:
    Ui::MainWindow *ui;
    Client*client;

    QTcpSocket *tcpClient;


    QTcpSocket *tcpSocket;

    quint16 blockSize;  //存放接收到的信息大小
    QFile *localFile;  //要发送的文件
    qint64 totalBytes;  //数据总大小
    qint64 bytesWritten;  //已经发送数据大小
    qint64 bytesToWrite;   //剩余数据大小
    qint64 loadSize;   //每次发送数据的大小
    QString fileName;  //保存文件路径
    QByteArray outBlock;  //数据缓冲区，即存放每次要发送的数据

    qint64 bytesReceived;  //已收到数据的大小
    qint64 fileNameSize;  //文件名的大小信息
    QByteArray inBlock;   //数据缓冲区

    QLabel* currentUserLabel;
};

#endif // MAINWINDOW_H
