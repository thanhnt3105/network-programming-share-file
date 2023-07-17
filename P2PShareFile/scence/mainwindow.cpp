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
    this->file->setFileName(fileName);
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
//    QString errorMsg;
//    if (!response.isNull() && response.isObject()) {
//        QJsonObject jsonObject = response.object();
//        qDebug() << "data file: "<< jsonObject["command_code"].toString();
//        if (jsonObject.contains("command_code") && jsonObject["command_code"].isString()) {
//            if(jsonObject["command_code"].toString().compare("SEARCHFILE")!=0) return;
//        }
//        if (jsonObject.contains("error") && jsonObject["error"].isString()) {
//            errorMsg = jsonObject["error"].toString();
//        }
//        if (jsonObject.contains("info") && jsonObject["info"].isString()) {
//            QString infoString = jsonObject["info"].toString();
//            QJsonObject infoObject = QJsonDocument::fromJson(infoString.toUtf8()).object();
//        }
//    }
//    if(errorMsg.compare("file not found")==0) {
//        QMessageBox::critical(nullptr, "Error", "Can not find your file");
//    } else {
//        QMessageBox::critical(nullptr, "Error", "File found!");
//    }
}

