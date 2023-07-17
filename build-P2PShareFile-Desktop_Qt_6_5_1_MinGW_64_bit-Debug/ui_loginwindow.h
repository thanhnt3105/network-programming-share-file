/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *usernameLineEdit;
    QLineEdit *passLineEdit;
    QPushButton *LoginPushButton;
    QLabel *label_3;
    QLabel *label_4;
    QCommandLinkButton *registerLinkButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(660, 520);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 40, 261, 101));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 60, 61, 61));
        label_2->setAcceptDrops(false);
        label_2->setAutoFillBackground(false);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/login/assets/logo.png")));
        label_2->setScaledContents(true);
        usernameLineEdit = new QLineEdit(centralwidget);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(260, 190, 201, 31));
        passLineEdit = new QLineEdit(centralwidget);
        passLineEdit->setObjectName("passLineEdit");
        passLineEdit->setGeometry(QRect(260, 240, 201, 31));
        passLineEdit->setEchoMode(QLineEdit::Password);
        LoginPushButton = new QPushButton(centralwidget);
        LoginPushButton->setObjectName("LoginPushButton");
        LoginPushButton->setGeometry(QRect(290, 320, 83, 29));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 190, 91, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(170, 240, 91, 31));
        registerLinkButton = new QCommandLinkButton(centralwidget);
        registerLinkButton->setObjectName("registerLinkButton");
        registerLinkButton->setGeometry(QRect(190, 380, 281, 41));
        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 660, 25));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "FileTorrent", nullptr));
        label_2->setText(QString());
        usernameLineEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "username", nullptr));
        passLineEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "password", nullptr));
        LoginPushButton->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWindow", "Username", nullptr));
        label_4->setText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        registerLinkButton->setText(QCoreApplication::translate("LoginWindow", "Don't have account?, register now!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
