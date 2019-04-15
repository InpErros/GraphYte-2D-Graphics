/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QGroupBox *groupBox_login;
    QLineEdit *lineEdit_username;
    QLabel *label_username;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_login;
    QPushButton *pushButton_createaccount;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(291, 264);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox_login = new QGroupBox(centralWidget);
        groupBox_login->setObjectName(QString::fromUtf8("groupBox_login"));
        groupBox_login->setGeometry(QRect(10, 10, 271, 191));
        lineEdit_username = new QLineEdit(groupBox_login);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(70, 30, 191, 20));
        label_username = new QLabel(groupBox_login);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        label_username->setGeometry(QRect(10, 30, 51, 21));
        label_password = new QLabel(groupBox_login);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(10, 60, 51, 16));
        lineEdit_password = new QLineEdit(groupBox_login);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(70, 60, 191, 20));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        pushButton_login = new QPushButton(groupBox_login);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(14, 100, 251, 23));
        pushButton_createaccount = new QPushButton(groupBox_login);
        pushButton_createaccount->setObjectName(QString::fromUtf8("pushButton_createaccount"));
        pushButton_createaccount->setGeometry(QRect(90, 140, 101, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 291, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFile->setContextMenuPolicy(Qt::NoContextMenu);
        menuFile->setTearOffEnabled(false);
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Login | GrapYte - 2D Graphics Generator", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        groupBox_login->setTitle(QApplication::translate("MainWindow", "Login", nullptr));
        label_username->setText(QApplication::translate("MainWindow", "Username", nullptr));
        label_password->setText(QApplication::translate("MainWindow", "Password", nullptr));
        pushButton_login->setText(QApplication::translate("MainWindow", "Login", nullptr));
        pushButton_createaccount->setText(QApplication::translate("MainWindow", "Create an Account", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
