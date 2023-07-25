#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QObject>
#include <QMessageBox>
#include <QProcess>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),currentUserLabel(nullptr)
{
    ui->setupUi(this);
    this->client = new Client();
    this->client->start();
    this->file = new File();

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
                    QHostAddress address = QHostAddress("127.0.0.1");
                    int port = 1234;
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
        QMessageBox::critical(nullptr, "Error", "File found!");
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
        QMessageBox::critical(nullptr, "Error", "Upload file successfully");
    }
}

