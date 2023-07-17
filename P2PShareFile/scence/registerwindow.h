#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <entity/user.h>
#include <client/client.h>
#include <QDebug>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

    Client *getClientCore() const;
    void setClientCore(Client *newClientCore);

private slots:
    void on_registerLinkButton_clicked();

    void on_RegisterPushButton_clicked();
    void handleRegisterResponse(const QJsonDocument& response);
    void disconnectSignal();
private:
    Ui::RegisterWindow *ui;
    Client*client;
};

#endif // REGISTERWINDOW_H
