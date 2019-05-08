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
            QMessageBox::information(this,"Login Successful", "The Login Attempt Was Successful");
            startup = new Startup();
            startup->setAttribute(Qt::WA_DeleteOnClose);
            startup->show();
            setSuccess(true);
            this->hide();
        }
        else {
            QMessageBox::warning(this, "Login Failed", "Login Failed.\nPassword is not correct");
            setSuccess(false);
        }
    }
    else if(userExists(username.toStdString())){
        if(passwordMatch(password.toStdString())){
            QMessageBox::information(this,"Login Successful", "The Login Attempt Was Successful");
            startup = new Startup();
            startup->setAttribute(Qt::WA_DeleteOnClose);
            startup->show();
            setSuccess(true);
            this->hide();
        }
        else{
            QMessageBox::warning(this, "Login Failed", "Login Failed.\nPassword is incorrect!");
            setSuccess(false);
        }
    }
    else{
        QMessageBox::warning(this, "Login Failed", "Login Failed.\nUsername does not exist!");
        setSuccess(false);
    }

}

void Login::on_pushButton_createaccount_clicked()
{
    createAccount = new CreateAccount();
    createAccount->setAttribute(Qt::WA_DeleteOnClose);
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
