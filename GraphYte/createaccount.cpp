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
    QString user = ui->lineEdit_newusername->text();
    QString password = ui->lineEdit_newpassword->text();

    std::ofstream fout;
    fout.open("db.txt", std::ios_base::app);

    if(user.toStdString() == ""){
        QMessageBox::warning(this, "Account Creation Failded", "Account Creation Failed.\nUsername is Invalid!");
    }
    else if(password.toStdString() == ""){
        QMessageBox::warning(this, "Account Creation Failded", "Account Creation Failed.\nPassword is Invalid!");
    }
    else if(fout.eof()){
    fout << user.toStdString() << endl;
    fout << password.toStdString() << endl;
    fout.close();

    QMessageBox::information(this, "Account Created", "Your Account Was Created Successfully");
    this->hide();
    }
    else if(userExists(user.toStdString())){
        QMessageBox::warning(this, "Account Creation Failed", "This Account Username Already Exists");
        fout.close();
    }
    else{
        fout << user.toStdString() << endl;
        fout << password.toStdString() << endl;
        fout.close();

        QMessageBox::information(this, "Account Created", "Your Account Was Created Successfully");
        this->hide();
    }
}
