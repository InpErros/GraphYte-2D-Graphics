#include "createaccountwindow.h"
#include "ui_createaccountwindow.h"
#include <QMessageBox>

CreateAccountWindow::CreateAccountWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateAccountWindow)
{
    ui->setupUi(this);
}

CreateAccountWindow::~CreateAccountWindow()
{
    delete ui;
}

void CreateAccountWindow::on_pushButton_clicked()
{
    // Create new account in the datatbase

    QMessageBox::information(this, "Account Created", "Your Account Was Created Successfully");
    this->hide();

    if(false){ // in the future this will activate when the account username already exists
        QMessageBox::warning(this, "Account Creation Failed", "This Account Username Already Exists");
    }

}
