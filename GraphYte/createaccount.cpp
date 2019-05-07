#include "createaccount.h"
#include "ui_createaccount.h"
#include <QMessageBox>
#include <string>
#include <QDebug>
#include "accountlist.h"

CreateAccount::CreateAccount(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateAccount)
{
    ui->setupUi(this);
	setWindowModality(Qt::ApplicationModal); // Locks Login until createaccount is closed
}

CreateAccount::~CreateAccount()
{
    delete ui;
}

void CreateAccount::on_pushButton_clicked()
{
    // Create new account in the datatbase
    QString name = ui->lineEdit_newname->text();
    QString email = ui->lineEdit_newemail->text();
    QString user = ui->lineEdit_newusername->text();
    QString password = ui->lineEdit_newpassword->text();

    std::ofstream fout;
    AccountList db;

    fout.open("db.txt", std::ios_base::app);
    fout << name.toStdString() << endl;
    fout << email.toStdString() << endl;
    fout << user.toStdString() << endl;
    fout << password.toStdString() << endl;
    fout.close();

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

bool usernameExists(string user){
    std::ifstream fin;
    fin.open("db.txt");
    string u;

    while(!fin.eof()){
        getline(fin,u);
        if(user.compare(u))
            break;
    }
    return user.compare(u);
}
