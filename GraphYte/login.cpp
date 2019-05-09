#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <fstream>

using std::fstream;

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
    success = false;
}

Login::~Login()
{
    delete ui;
    delete startup;
    delete createAccount;
}

void Login::on_pushButton_login_clicked(){
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    std::ofstream fout;

    fstream fin;
    fin.open("db.txt");
    if(username == "admin"){
        if(password == "password"){
            emit checkLoginSuccess(true);
            QMessageBox::information(this,"Login Successful", "The Login Attempt Was Successful");
            startup = new Startup();
            startup->setAttribute(Qt::WA_DeleteOnClose);
            startup->show();
            this->hide();
        }
        else {
            QMessageBox::warning(this, "Login Failed", "Login Failed.\nPassword is not correct");
            emit checkLoginSuccess(false);
        }
    }
    else if(usernameMatch(username.toStdString())){
        if(passwordMatch(username.toStdString(), password.toStdString())){
            QMessageBox::information(this,"Login Successful", "The Login Attempt Was Successful");
            startup = new Startup();
            startup->setAttribute(Qt::WA_DeleteOnClose);
            startup->show();
            emit checkLoginSuccess(true);
            this->hide();
        }
        else{
            QMessageBox::warning(this, "Login Failed", "Login Failed.\nPassword is incorrect!");
            emit checkLoginSuccess(false);
        }
    }
    else{
        QMessageBox::warning(this, "Login Failed", "Login Failed.\nUsername does not exist!");
        emit checkLoginSuccess(false);
    }

}

void Login::on_pushButton_createaccount_clicked()
{
    createAccount = new CreateAccount();
    createAccount->show();
}

void Login::on_actionExit_triggered()
{
    this->close();
}

bool Login::loginSuccess(){ return true; }

void Login::setSuccess(bool b){
    success = b;
}
