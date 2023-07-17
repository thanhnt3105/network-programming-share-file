#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <scence/loginwindow.h>
#include <QSqlQuery>
#include <scence/mainwindow.h>

RegisterWindow::RegisterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    setTabOrder(ui->usernameLineEdit, ui->passLineEdit);
    setTabOrder(ui->passLineEdit, ui->reEnterPassLineEdit);
    this->client = new Client();
    this->client->start();
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_RegisterPushButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passLineEdit->text();
    QString reEnterPass = ui->reEnterPassLineEdit->text();

    if (password != reEnterPass) {
        QMessageBox::critical(this, "Error", "Passwords do not match.");
        return;
    }

    this->client->registers(username, password);
    connect(client, &Client::Finished, this, &RegisterWindow::handleRegisterResponse);
}

void RegisterWindow::handleRegisterResponse(const QJsonDocument &response)
{
    QString errorMsg;
    QString username;
    quint64 id;
    if (!response.isNull() && response.isObject()) {
        QJsonObject jsonObject = response.object();
        qDebug() <<"dddd" << jsonObject["error"].toString();
        if (jsonObject.contains("command_code") && jsonObject["command_code"].isString()) {
            if(jsonObject["command_code"].toString().compare("REGISTER")!=0) return;
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
    if(errorMsg.compare("username exist")==0) {
        QMessageBox::critical(nullptr, "Error", "Username has been existed");
    } else {
        MainWindow * mainWindow = new MainWindow();
        this->disconnectSignal();
        mainWindow->show();
        this->close();
    }
}

void RegisterWindow::disconnectSignal()
{
    disconnect(client, &Client::Finished, this, &RegisterWindow::handleRegisterResponse);
}



void RegisterWindow::on_registerLinkButton_clicked()
{
    LoginWindow *loginWindow = new LoginWindow();
    loginWindow->show();
    this->hide();
}




