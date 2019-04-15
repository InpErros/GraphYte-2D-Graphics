/********************************************************************************
** Form generated from reading UI file 'createaccountwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEACCOUNTWINDOW_H
#define UI_CREATEACCOUNTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateAccountWindow
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label_title;
    QFrame *line;
    QLabel *label_name;
    QLabel *label_email;
    QLabel *label_newusername;
    QLabel *label_newpassword;
    QFrame *line_2;
    QFrame *line_3;
    QPushButton *pushButton;
    QLineEdit *lineEdit_newname;
    QLineEdit *lineEdit_newemail;
    QLineEdit *lineEdit_newusername;
    QLineEdit *lineEdit_newpassword;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CreateAccountWindow)
    {
        if (CreateAccountWindow->objectName().isEmpty())
            CreateAccountWindow->setObjectName(QString::fromUtf8("CreateAccountWindow"));
        CreateAccountWindow->resize(263, 269);
        actionExit = new QAction(CreateAccountWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(CreateAccountWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 241, 211));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        label_title = new QLabel(frame);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(40, 0, 161, 31));
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 20, 241, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_name = new QLabel(frame);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(10, 40, 51, 21));
        label_email = new QLabel(frame);
        label_email->setObjectName(QString::fromUtf8("label_email"));
        label_email->setGeometry(QRect(10, 70, 71, 16));
        label_newusername = new QLabel(frame);
        label_newusername->setObjectName(QString::fromUtf8("label_newusername"));
        label_newusername->setGeometry(QRect(10, 100, 51, 16));
        label_newpassword = new QLabel(frame);
        label_newpassword->setObjectName(QString::fromUtf8("label_newpassword"));
        label_newpassword->setGeometry(QRect(10, 130, 47, 13));
        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(70, 30, 20, 131));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(frame);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(0, 150, 241, 21));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 170, 221, 31));
        lineEdit_newname = new QLineEdit(frame);
        lineEdit_newname->setObjectName(QString::fromUtf8("lineEdit_newname"));
        lineEdit_newname->setGeometry(QRect(90, 40, 141, 20));
        lineEdit_newemail = new QLineEdit(frame);
        lineEdit_newemail->setObjectName(QString::fromUtf8("lineEdit_newemail"));
        lineEdit_newemail->setGeometry(QRect(90, 70, 141, 20));
        lineEdit_newusername = new QLineEdit(frame);
        lineEdit_newusername->setObjectName(QString::fromUtf8("lineEdit_newusername"));
        lineEdit_newusername->setGeometry(QRect(90, 100, 141, 20));
        lineEdit_newpassword = new QLineEdit(frame);
        lineEdit_newpassword->setObjectName(QString::fromUtf8("lineEdit_newpassword"));
        lineEdit_newpassword->setGeometry(QRect(90, 130, 141, 20));
        CreateAccountWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CreateAccountWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 263, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        CreateAccountWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CreateAccountWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CreateAccountWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionExit);

        retranslateUi(CreateAccountWindow);

        QMetaObject::connectSlotsByName(CreateAccountWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CreateAccountWindow)
    {
        CreateAccountWindow->setWindowTitle(QApplication::translate("CreateAccountWindow", "Create Account", nullptr));
        actionExit->setText(QApplication::translate("CreateAccountWindow", "Exit", nullptr));
        label_title->setText(QApplication::translate("CreateAccountWindow", "Enter Your Account Information", nullptr));
        label_name->setText(QApplication::translate("CreateAccountWindow", "Name", nullptr));
        label_email->setText(QApplication::translate("CreateAccountWindow", "Email Address", nullptr));
        label_newusername->setText(QApplication::translate("CreateAccountWindow", "Username", nullptr));
        label_newpassword->setText(QApplication::translate("CreateAccountWindow", "Password", nullptr));
        pushButton->setText(QApplication::translate("CreateAccountWindow", "Create Account", nullptr));
        menuFile->setTitle(QApplication::translate("CreateAccountWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateAccountWindow: public Ui_CreateAccountWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEACCOUNTWINDOW_H
