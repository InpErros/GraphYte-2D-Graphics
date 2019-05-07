#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "startup.h"
#include "createaccount.h"
#include "accountlist.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    bool loginSuccess();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_createaccount_clicked();

    void on_actionExit_triggered();

    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    Startup * startup;
    CreateAccount * createAccount;
};

#endif // LOGIN_H
