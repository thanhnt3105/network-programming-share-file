#include <scence/mainwindow.h>
#include <scence/loginwindow.h>
#include <QApplication>
#include <database/connection.h>
#include <server/server.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection* connection = new Connection();
    if (!connection->isConnected()) {
        qDebug() << "Can not connect";
    }
    else {
        qDebug() << "Connect successfully";
    }

    Server*server = new Server();
    server->start();

    QThread thread1;
//    QThread thread2;

    LoginWindow l1 = LoginWindow();
//    LoginWindow l2 = LoginWindow();

    l1.moveToThread(&thread1);
//    l2.moveToThread(&thread2);

    QObject::connect(&thread1, &QThread::started, &l1, &MainWindow::show);
//    QObject::connect(&thread2, &QThread::started, &l2, &MainWindow::show);

    thread1.start();
//    thread2.start();


//    MainWindow w;
//    LoginWindow login = LoginWindow();
//    w.show();
//    login.show();
    return a.exec();
}
