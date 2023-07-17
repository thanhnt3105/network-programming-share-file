/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

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

class Ui_RegisterWindow
{
public:
    QWidget *centralwidget;
    QPushButton *RegisterPushButton;
    QLabel *label;
    QLineEdit *passLineEdit;
    QLabel *label_4;
    QLabel *label_3;
    QCommandLinkButton *registerLinkButton;
    QLabel *label_2;
    QLineEdit *usernameLineEdit;
    QLabel *label_5;
    QLineEdit *reEnterPassLineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(660, 520);
        centralwidget = new QWidget(RegisterWindow);
        centralwidget->setObjectName("centralwidget");
        RegisterPushButton = new QPushButton(centralwidget);
        RegisterPushButton->setObjectName("RegisterPushButton");
        RegisterPushButton->setGeometry(QRect(280, 340, 83, 29));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 40, 261, 101));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        passLineEdit = new QLineEdit(centralwidget);
        passLineEdit->setObjectName("passLineEdit");
        passLineEdit->setGeometry(QRect(260, 240, 201, 31));
        passLineEdit->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(170, 240, 91, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 190, 91, 31));
        registerLinkButton = new QCommandLinkButton(centralwidget);
        registerLinkButton->setObjectName("registerLinkButton");
        registerLinkButton->setGeometry(QRect(190, 380, 281, 41));
        registerLinkButton->setLayoutDirection(Qt::LeftToRight);
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
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(170, 290, 91, 31));
        reEnterPassLineEdit = new QLineEdit(centralwidget);
        reEnterPassLineEdit->setObjectName("reEnterPassLineEdit");
        reEnterPassLineEdit->setGeometry(QRect(260, 290, 201, 31));
        reEnterPassLineEdit->setEchoMode(QLineEdit::Password);
        RegisterWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RegisterWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 660, 25));
        RegisterWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RegisterWindow);
        statusbar->setObjectName("statusbar");
        RegisterWindow->setStatusBar(statusbar);

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "MainWindow", nullptr));
        RegisterPushButton->setText(QCoreApplication::translate("RegisterWindow", "Register", nullptr));
        label->setText(QCoreApplication::translate("RegisterWindow", "FileTorrent", nullptr));
        passLineEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "password", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterWindow", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterWindow", "Username", nullptr));
        registerLinkButton->setText(QCoreApplication::translate("RegisterWindow", "Go to login", nullptr));
        label_2->setText(QString());
        usernameLineEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "username", nullptr));
        label_5->setText(QCoreApplication::translate("RegisterWindow", "ReEnter", nullptr));
        reEnterPassLineEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
