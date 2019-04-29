#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "accountlist.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->groupBox_login);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{

    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    AccountList db;
    db.fillList();
    fstream fin;
    fin.open("db.txt");
    if(db.isEmpty(fin)){
        QMessageBox::warning(this,"Error","Error 0x0001\nMissing Account Information");
        fin.close();
        return;
    }

    if(db.usernameExists(username.toStdString())){
        if(db.passwordMatch(password.toStdString())){
            QMessageBox::information(this,"Login Successful", "The Login Attempt Was Successful");
            introWindow = new IntroWindow();
            introWindow->setAttribute(Qt::WA_DeleteOnClose);
            introWindow->show();
            this->hide();
        }
        else{
            QMessageBox::warning(this, "Login Failed", "Login Failed.\nPassword is incorrect!");
        }
    }
    else{
        QMessageBox::warning(this, "Login Failed", "Login Failed.\nUsername does not exist!");
    }

}

void MainWindow::on_pushButton_createaccount_clicked()
{
    createAccountWindow = new CreateAccountWindow();
    createAccountWindow->setAttribute(Qt::WA_DeleteOnClose);
    createAccountWindow->show();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}
