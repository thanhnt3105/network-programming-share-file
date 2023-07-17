/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLineEdit *portLineEdit;
    QLabel *label;
    QLineEdit *hostLineEdit;
    QLabel *label_2;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QPushButton *sendMesButton;
    QLabel *currentStatusLabel;
    QGroupBox *groupBox_3;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox_4;
    QTextEdit *inputTextEdit;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QProgressBar *clientProgressBar;
    QPushButton *openButton;
    QPushButton *sendFileButton;
    QPushButton *openFolderButton;
    QLabel *currentUserLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(660, 520);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 20, 221, 171));
        portLineEdit = new QLineEdit(groupBox);
        portLineEdit->setObjectName("portLineEdit");
        portLineEdit->setGeometry(QRect(70, 60, 131, 21));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 51, 16));
        hostLineEdit = new QLineEdit(groupBox);
        hostLineEdit->setObjectName("hostLineEdit");
        hostLineEdit->setGeometry(QRect(70, 20, 131, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 60, 51, 16));
        connectButton = new QPushButton(groupBox);
        connectButton->setObjectName("connectButton");
        connectButton->setGeometry(QRect(20, 110, 81, 32));
        disconnectButton = new QPushButton(groupBox);
        disconnectButton->setObjectName("disconnectButton");
        disconnectButton->setGeometry(QRect(124, 110, 81, 32));
        sendMesButton = new QPushButton(centralwidget);
        sendMesButton->setObjectName("sendMesButton");
        sendMesButton->setGeometry(QRect(560, 430, 75, 32));
        currentStatusLabel = new QLabel(centralwidget);
        currentStatusLabel->setObjectName("currentStatusLabel");
        currentStatusLabel->setGeometry(QRect(20, 440, 371, 16));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(270, 20, 381, 241));
        textBrowser = new QTextBrowser(groupBox_3);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 20, 361, 211));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(270, 300, 381, 121));
        inputTextEdit = new QTextEdit(groupBox_4);
        inputTextEdit->setObjectName("inputTextEdit");
        inputTextEdit->setGeometry(QRect(10, 20, 361, 91));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(20, 240, 221, 181));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 30, 31, 16));
        clientProgressBar = new QProgressBar(groupBox_2);
        clientProgressBar->setObjectName("clientProgressBar");
        clientProgressBar->setGeometry(QRect(60, 30, 151, 21));
        clientProgressBar->setValue(0);
        openButton = new QPushButton(groupBox_2);
        openButton->setObjectName("openButton");
        openButton->setGeometry(QRect(20, 70, 75, 32));
        sendFileButton = new QPushButton(groupBox_2);
        sendFileButton->setObjectName("sendFileButton");
        sendFileButton->setGeometry(QRect(130, 70, 75, 32));
        openFolderButton = new QPushButton(groupBox_2);
        openFolderButton->setObjectName("openFolderButton");
        openFolderButton->setGeometry(QRect(50, 120, 121, 32));
        currentUserLabel = new QLabel(centralwidget);
        currentUserLabel->setObjectName("currentUserLabel");
        currentUserLabel->setGeometry(QRect(452, 0, 161, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 660, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Connection Information", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "IP", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        connectButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        disconnectButton->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        sendMesButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        currentStatusLabel->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Chat", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Information", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "File Share", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Pro", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        sendFileButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        openFolderButton->setText(QCoreApplication::translate("MainWindow", "Open Folder", nullptr));
        currentUserLabel->setText(QCoreApplication::translate("MainWindow", "User:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
