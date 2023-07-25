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

FileResult::FileResult(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileResult)
{
    ui->setupUi(this);
}

FileResult::FileResult(QString fileName, QString filePath, QString user, QHostAddress host, int port, QWidget *parent):    QWidget(parent),
    ui(new Ui::FileResult)
{

    this->setFileName(fileName);
    this->setFilePath(filePath);
    this->setUser(user);
    this->setHost(host);
    this->setPort(port);

    ui->setupUi(this);
    this->ui->fileName->setText(fileName);
    this->ui->owner->setText(user);
}

FileResult::~FileResult()
{
    delete ui;
}
