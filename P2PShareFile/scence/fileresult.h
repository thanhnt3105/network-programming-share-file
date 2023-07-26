#ifndef FILERESULT_H
#define FILERESULT_H

#include <QWidget>
#include <QHostAddress>
#include <peertopeer/localconnection.h>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QMessageBox>
namespace Ui {
class FileResult;
}

class FileResult : public QWidget
{
    Q_OBJECT

private:
    QString fileName;
    QString filePath;
    QString user;
    QHostAddress host;
    int port;


public:
    explicit FileResult(QWidget *parent = nullptr);
    explicit FileResult(QString fileName,QString filePath, QString user,QHostAddress host, int port, QWidget *parent = nullptr);
    ~FileResult();

    QString getFileName() const;
    void setFileName(const QString &newFileName);

    QString getFilePath() const;
    void setFilePath(const QString &newFilePath);

    QString getUser() const;
    void setUser(const QString &newUser);

    int getPort() const;
    void setPort(int newPort);

    QHostAddress getHost() const;
    void setHost(const QHostAddress &newHost);

private slots:
    void connectServer();  //连接服务器
    void haveconnected(); // 已连接状态
    void displayError(QAbstractSocket::SocketError); //显示错误

    void startTransferFile();  //发送文件大小等信息
    void updateClientProgress(qint64); //发送文件数据，更新进度条

    void updateServerProgress(); //接收数据，更新进度条

    void on_pushButton_clicked();

private:
    Ui::FileResult *ui;
    QTcpSocket *tcpClient;

    quint16 blockSize;  //存放接收到的信息大小
    QFile *localFile;  //要发送的文件
    qint64 totalBytes;  //数据总大小
    qint64 bytesWritten;  //已经发送数据大小
    qint64 bytesToWrite;   //剩余数据大小
    qint64 loadSize;   //每次发送数据的大小  //保存文件路径
    QByteArray outBlock;  //数据缓冲区，即存放每次要发送的数据

    qint64 bytesReceived;  //已收到数据的大小
    qint64 fileNameSize;  //文件名的大小信息
    QByteArray inBlock;   //数据缓冲区
};

#endif // FILERESULT_H
