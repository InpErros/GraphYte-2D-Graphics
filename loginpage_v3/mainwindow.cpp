#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "username" && password == "password"){
        QMessageBox::information(this,"Login Successful", "The Login Attempt Was Successful");
        introWindow = new IntroWindow();
        introWindow->setAttribute(Qt::WA_DeleteOnClose);
        introWindow->show();
        this->hide();
    }
    else{
        QMessageBox::warning(this, "Login Failed", "The Login Attempt Failed");
    }
}

void MainWindow::on_pushButton_createaccount_clicked()
{
    createAccountWindow = new CreateAccountWindow();
    createAccountWindow->setAttribute(Qt::WA_DeleteOnClose);
    createAccountWindow->show();
}
