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
    this->ui->portSpinBox->setRange(1024, 65535);
    this->ui->portSpinBox->setValue(9001);
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach( QHostAddress address, list )
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
            this->ui->HostComboBox->addItem(address.toString());
    }
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_LoginPushButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passLineEdit->text();
    quint16 port = ui->portSpinBox->value();
    QString host = ui->HostComboBox->currentText();
    this->client->login(username,password,host,port);
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
    QString id;
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
            if (infoObject.contains("id")) {
                id = infoObject["id"].toString();
            }
        }
    }
    if(errorMsg.compare("invalid username")==0 || errorMsg.compare("invalid password")==0) {
       QMessageBox::critical(nullptr, "Error", "Invalid Credentials");
    } else if(errorMsg.compare("invalid port")==0) {
       QMessageBox::critical(nullptr, "Error", "Invalid Port! Please choose another port!");
    }
    else {
       Session::getInstance()->setUsername(username);
       Session::getInstance()->setUserId(id.toInt());
       quint16 port = ui->portSpinBox->value();
       QString host = ui->HostComboBox->currentText();

       MainWindow * mainWindow = new MainWindow(host,port);
       this->disconnectSignal();
       mainWindow->show();
       this->close();
    }
}

void LoginWindow::disconnectSignal()
{
    disconnect(client, &Client::Finished, this, &LoginWindow::handleLoginResponse);
}


