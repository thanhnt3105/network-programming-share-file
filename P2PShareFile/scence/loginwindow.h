#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <entity/user.h>
#include <client/client.h>
#include <QDebug>
#include <QNetworkInterface>
#include <session/session.h>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

    Client *getClientCore() const;
    void setClientCore(Client *newClientCore);

private slots:
    void on_LoginPushButton_clicked();

    void on_registerLinkButton_clicked();
    void handleLoginResponse(const QJsonDocument& response);
    void disconnectSignal();
private:
    Ui::LoginWindow *ui;
    Client*client;
};

#endif // LOGINWINDOW_H
