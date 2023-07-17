/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *fileNameLineEdit;
    QPushButton *searchButton;
    QGroupBox *groupBox_3;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox_4;
    QTextBrowser *textStatusBrowser;
    QGroupBox *groupBox_2;
    QPushButton *openButton;
    QPushButton *uploadButton;
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
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 60, 51, 16));
        fileNameLineEdit = new QLineEdit(groupBox);
        fileNameLineEdit->setObjectName("fileNameLineEdit");
        fileNameLineEdit->setGeometry(QRect(70, 60, 141, 21));
        searchButton = new QPushButton(groupBox);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(70, 110, 81, 32));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(270, 20, 381, 241));
        textBrowser = new QTextBrowser(groupBox_3);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 20, 361, 211));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(270, 300, 381, 121));
        textStatusBrowser = new QTextBrowser(groupBox_4);
        textStatusBrowser->setObjectName("textStatusBrowser");
        textStatusBrowser->setGeometry(QRect(10, 20, 361, 91));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(20, 240, 221, 181));
        openButton = new QPushButton(groupBox_2);
        openButton->setObjectName("openButton");
        openButton->setGeometry(QRect(50, 60, 111, 32));
        uploadButton = new QPushButton(groupBox_2);
        uploadButton->setObjectName("uploadButton");
        uploadButton->setGeometry(QRect(50, 120, 111, 32));
        currentUserLabel = new QLabel(centralwidget);
        currentUserLabel->setObjectName("currentUserLabel");
        currentUserLabel->setGeometry(QRect(470, 0, 161, 20));
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
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Search file", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "File Available", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Information", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Share File", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
        uploadButton->setText(QCoreApplication::translate("MainWindow", "Upload File", nullptr));
        currentUserLabel->setText(QCoreApplication::translate("MainWindow", "User:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
