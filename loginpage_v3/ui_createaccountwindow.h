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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateAccountWindow
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QFrame *frame;
    QSplitter *splitter_3;
    QLabel *label_title;
    QFrame *line;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QLabel *label_name;
    QLabel *label_email;
    QLabel *label_newusername;
    QLabel *label_newpassword;
    QFrame *line_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_newname;
    QLineEdit *lineEdit_newemail;
    QLineEdit *lineEdit_newusername;
    QLineEdit *lineEdit_newpassword;
    QFrame *line_3;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CreateAccountWindow)
    {
        if (CreateAccountWindow->objectName().isEmpty())
            CreateAccountWindow->setObjectName(QString::fromUtf8("CreateAccountWindow"));
        CreateAccountWindow->resize(357, 312);
        actionExit = new QAction(CreateAccountWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(CreateAccountWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 341, 261));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        splitter_3 = new QSplitter(frame);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setGeometry(QRect(1, 1, 331, 251));
        splitter_3->setOrientation(Qt::Vertical);
        label_title = new QLabel(splitter_3);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setAlignment(Qt::AlignCenter);
        splitter_3->addWidget(label_title);
        line = new QFrame(splitter_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        splitter_3->addWidget(line);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        label_name = new QLabel(splitter);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setAlignment(Qt::AlignCenter);
        splitter->addWidget(label_name);
        label_email = new QLabel(splitter);
        label_email->setObjectName(QString::fromUtf8("label_email"));
        label_email->setAlignment(Qt::AlignCenter);
        splitter->addWidget(label_email);
        label_newusername = new QLabel(splitter);
        label_newusername->setObjectName(QString::fromUtf8("label_newusername"));
        label_newusername->setAlignment(Qt::AlignCenter);
        splitter->addWidget(label_newusername);
        label_newpassword = new QLabel(splitter);
        label_newpassword->setObjectName(QString::fromUtf8("label_newpassword"));
        label_newpassword->setAlignment(Qt::AlignCenter);
        splitter->addWidget(label_newpassword);
        splitter_2->addWidget(splitter);
        line_2 = new QFrame(splitter_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        splitter_2->addWidget(line_2);
        widget = new QWidget(splitter_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_newname = new QLineEdit(widget);
        lineEdit_newname->setObjectName(QString::fromUtf8("lineEdit_newname"));

        verticalLayout_2->addWidget(lineEdit_newname);

        lineEdit_newemail = new QLineEdit(widget);
        lineEdit_newemail->setObjectName(QString::fromUtf8("lineEdit_newemail"));

        verticalLayout_2->addWidget(lineEdit_newemail);

        lineEdit_newusername = new QLineEdit(widget);
        lineEdit_newusername->setObjectName(QString::fromUtf8("lineEdit_newusername"));

        verticalLayout_2->addWidget(lineEdit_newusername);

        lineEdit_newpassword = new QLineEdit(widget);
        lineEdit_newpassword->setObjectName(QString::fromUtf8("lineEdit_newpassword"));

        verticalLayout_2->addWidget(lineEdit_newpassword);

        splitter_2->addWidget(widget);
        splitter_3->addWidget(splitter_2);
        line_3 = new QFrame(splitter_3);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        splitter_3->addWidget(line_3);
        pushButton = new QPushButton(splitter_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        splitter_3->addWidget(pushButton);
        CreateAccountWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CreateAccountWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 357, 17));
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
