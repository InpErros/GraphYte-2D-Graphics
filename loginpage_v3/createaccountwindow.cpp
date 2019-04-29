#include "createaccountwindow.h"
#include "ui_createaccountwindow.h"
#include <QMessageBox>
#include <string>
#include <QDebug>
#include "accountlist.h"

using std::string;

CreateAccountWindow::CreateAccountWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateAccountWindow)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
}

CreateAccountWindow::~CreateAccountWindow()
{
    delete ui;
}

void CreateAccountWindow::on_pushButton_clicked()
{
    // Create new account in the datatbase
    QString name = ui->lineEdit_newname->text();
    QString email = ui->lineEdit_newemail->text();
    QString user = ui->lineEdit_newusername->text();
    QString password = ui->lineEdit_newpassword->text();

    AccountList db;
    db.fillList();
    fstream fin("db.txt");

    if(fin.is_open()){
        qDebug() << "WORKING" << endl;
    }
    else{
        qDebug() << "FUCKING BROKEN GODDAMIT" << endl;
    }
    if(db.isEmpty(fin)){
        fin << name.toStdString() << endl;
        fin << email.toStdString() << endl;
        fin << user.toStdString() << endl;
        fin << password.toStdString() << endl;

        fin.close();
        QMessageBox::information(this, "Account Created", "Your Account Was Created Successfully");
        this->hide();

        return;
    }
    else
        fin.close();
    if(name.toStdString() == ""){
        QMessageBox::warning(this,"Account Creation Failed", "Account Creation Failed.\nName is Invalid!");
    }
    else if(email.toStdString() == ""){
        QMessageBox::warning(this, "Account Creation Failded", "Account Creation Failed.\nEmail Address is Invalid!");
    }
    else if(user.toStdString() == ""){
        QMessageBox::warning(this, "Account Creation Failded", "Account Creation Failed.\nUsername is Invalid!");
    }
    else if(password.toStdString() == ""){
        QMessageBox::warning(this, "Account Creation Failded", "Account Creation Failed.\nPassword is Invalid!");
    }
    else if(db.usernameExists(user.toStdString())){
        QMessageBox::warning(this, "Account Creation Failed", "This Account Username Already Exists");
    }
    else{
        db.pushNewMember(name.toStdString(),email.toStdString(),user.toStdString(),password.toStdString());
        db.pushList();

        QMessageBox::information(this, "Account Created", "Your Account Was Created Successfully");
        this->hide();
    }
}
