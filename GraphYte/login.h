#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "startup.h"
#include "createaccount.h"
#include "accountlist.h"
#include "account.h"
#include <QTimer>

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
    void setSuccess(bool);

signals:
    void checkLoginSuccess(const bool& Success);

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_createaccount_clicked();

    void on_actionExit_triggered();

    void closeStartup();

private:
    Ui::Login *ui;
    Startup * startup;
    CreateAccount * createAccount;
    QTimer *timer;
};

#endif // LOGIN_H
