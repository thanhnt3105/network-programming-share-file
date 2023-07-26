#include <scence/mainwindow.h>
#include <scence/loginwindow.h>
#include <QApplication>
#include <database/connection.h>
#include <server/server.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow l1 = LoginWindow();
    l1.show();
    return a.exec();
}
