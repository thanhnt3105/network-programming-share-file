#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QFile>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void connectServer();
    void haveconnected(); // status connection
    void displayError(QAbstractSocket::SocketError); //Display error

    void openFile();//Open file
    void startTransferFile();  //Send file size information
    void updateClientProgress(qint64); //Send file data, update progress

    void updateServerProgress(); //Receive data and update the progress bar

    void on_openButton_clicked();
    void on_connectButton_clicked();
    void on_disconnectButton_clicked();
    void on_sendFileButton_clicked();
    void on_openFolderButton_clicked();
    void on_textBrowser_textChanged();

private:
    Ui::MainWindow *ui;

    QUdpSocket *UdpSender;
    QUdpSocket *UdpReader;
    QString localMessage; // 存放本地要发送的信息
    QString serverMessage;  //存放从服务器接收到的信息

    QTcpSocket *tcpClient;

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

    QFile *historyMessage;
    void setKeyvalue(bool connectKey, bool disconnectKey,bool openFileKey,bool sendFileKey);


    QLabel* currentUserLabel;
};

#endif // MAINWINDOW_H
