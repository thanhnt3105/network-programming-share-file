#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <scence/mainwindow.h>
#include <scence/registerwindow.h>
#include <database/connection.h>
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    this->client = new Client();
    this->client->start();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_LoginPushButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passLineEdit->text();
    this->client->login(username,password);
    connect(client, &Client::Finished, this, &LoginWindow::handleLoginResponse);
}

void LoginWindow::on_registerLinkButton_clicked()
{
    RegisterWindow *registerWindow = new RegisterWindow();
    registerWindow->show();
    this->hide();
}

void LoginWindow::handleLoginResponse(const QJsonDocument &response)
{
    QString errorMsg;
    QString username;
    quint64 id;
    if (!response.isNull() && response.isObject()) {

        QJsonObject jsonObject = response.object();
        if (jsonObject.contains("command_code") && jsonObject["command_code"].isString()) {
            if(jsonObject["command_code"].toString().compare("LOGIN")!=0) return;
        }
        if (jsonObject.contains("error") && jsonObject["error"].isString()) {
            errorMsg = jsonObject["error"].toString();
        }
        if (jsonObject.contains("info") && jsonObject["info"].isString()) {
            QString infoString = jsonObject["info"].toString();
            QJsonObject infoObject = QJsonDocument::fromJson(infoString.toUtf8()).object();

            // Lấy giá trị của key "username" từ QJsonObject "infoObject"
            if (infoObject.contains("username") && infoObject["username"].isString()) {
                username = infoObject["username"].toString();
            }
        }
    }
    if(errorMsg.compare("invalid username")==0 || errorMsg.compare("invalid password")==0) {
       QMessageBox::critical(nullptr, "Error", "Invalid Credentials");
    } else {
       MainWindow * mainWindow = new MainWindow();
       this->disconnectSignal();
       mainWindow->show();
       this->close();
    }
}

void LoginWindow::disconnectSignal()
{
    disconnect(client, &Client::Finished, this, &LoginWindow::handleLoginResponse);
}


