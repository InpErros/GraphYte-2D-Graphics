#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QMainWindow>
#include "account.h"

namespace Ui {
class CreateAccount;
}

class CreateAccount : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateAccount(QWidget *parent = nullptr);
    ~CreateAccount();

private slots:
	void on_pushButton_clicked();

private:
    Ui::CreateAccount *ui;
};

#endif // CREATEACCOUNT_H
