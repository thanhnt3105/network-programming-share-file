#ifndef FILERESULT_H
#define FILERESULT_H

#include <QWidget>
#include <QHostAddress>
#include <peertopeer/localconnection.h>
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
    void on_pushButton_clicked();

private:
    Ui::FileResult *ui;
};

#endif // FILERESULT_H
