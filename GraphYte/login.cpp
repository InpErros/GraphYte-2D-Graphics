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
            startup = new Startup();
            startup->setAttribute(Qt::WA_DeleteOnClose);
            startup->show();
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

bool Login::loginSuccess(){


    return true;
}


void Login::on_pushButton_clicked()
{
    this->hide();
}
